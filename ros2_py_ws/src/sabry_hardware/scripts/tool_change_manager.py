#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
from moveit_msgs.srv import ApplyPlanningScene
from moveit_msgs.msg import PlanningScene, CollisionObject, AttachedCollisionObject, RobotState, AllowedCollisionEntry
from shape_msgs.msg import SolidPrimitive
from sabry_hardware.srv import ChangeTool, LinearMotor
from rclpy.action import ActionClient
from moveit_msgs.action import MoveGroup
from moveit_msgs.msg import Constraints, PositionConstraint, OrientationConstraint
from sensor_msgs.msg import JointState
from functools import partial
import time

class ToolChangeManager(Node):

    def __init__(self):
        super().__init__('tool_change_manager')

        self.server_ = self.create_service(ChangeTool, "change_tool", self.change_tool_callback)
        self.get_logger().info("Tool Change Manager Ready")

        # MoveGroup action client
        self._move_group_client = ActionClient(self, MoveGroup, "/move_action")
        while not self._move_group_client.wait_for_server(timeout_sec=1.0):
            self.get_logger().info("Waiting for move_group action server...")

        # Planning scene service
        self.ps_client = self.create_client(ApplyPlanningScene, "apply_planning_scene")
        while not self.ps_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("Waiting for apply_planning_scene service...")

        # Tool changer client
        self.tool_client = self.create_client(LinearMotor,'tool_changer/set_state')
        while not self.tool_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("Waiting for tool_changer service...")

        # State
        self.current_tool = None

        # Internal variables for async sequence
        self._pose_sequence = []
        self._sequence_index = 0
        self._current_request = None

    # ------------------------
    # Service callback
    # ------------------------
    def change_tool_callback(self, request: ChangeTool.Request, response: ChangeTool.Response):
        target_tool = request.tool_name
        self.get_logger().info("Starting tool change service")

        if target_tool != "gripper":
            response.success = False
            response.message = "Only gripper implemented"
            return response

        if self.current_tool == "gripper":
            response.success = True
            response.message = "Gripper already attached"
            return response

        # Start async gripper pickup sequence
        self.start_pickup_sequence(request, response)
        return response

    # ------------------------
    # Async sequence
    # ------------------------
    def start_pickup_sequence(self, request, response):
        # Define poses
        dock_pose = self.get_gripper_dock_pose()
        approach_pose = self.offset_pose(dock_pose, dz=0.10)
        lift_pose = self.offset_pose(dock_pose, dz=0.15)

        self._pose_sequence = [approach_pose, dock_pose, lift_pose]
        self._sequence_index = 0
        self._current_request = (request, response)

        # Start first pose
        self.send_next_pose()

    def send_next_pose(self):
        if self._sequence_index >= len(self._pose_sequence):
            # Sequence complete
            self.current_tool = "gripper"
            self.get_logger().info("Gripper pickup complete")
            req, resp = self._current_request
            resp.success = True
            resp.message = "Gripper attached"
            return

        pose = self._pose_sequence[self._sequence_index]
        goal_msg = self.create_move_group_goal(pose)

        self.get_logger().info(f"Sending goal for pose {self._sequence_index + 1}...")
        send_future = self._move_group_client.send_goal_async(goal_msg)
        send_future.add_done_callback(self.goal_response_callback)

    # ------------------------
    # MoveGroup helpers
    # ------------------------
    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().error("MoveIt 2 goal rejected")
            req, resp = self._current_request
            resp.success = False
            resp.message = "Goal rejected"
            return

        result_future = goal_handle.get_result_async()
        result_future.add_done_callback(self.result_callback)

    def result_callback(self, future):
        result = future.result().result
        if result.error_code.val != 1:
            self.get_logger().error(f"Execution failed with error code {result.error_code.val}")
            req, resp = self._current_request
            resp.success = False
            resp.message = f"Execution failed (code {result.error_code.val})"
            return

        # Move to next pose
        self._sequence_index += 1

        # Special handling: after reaching dock, attach gripper
        if self._sequence_index == 2:  # after dock_pose
            self.unlock_actuator()
            self.attach_gripper_collision()
            self.remove_gripper_from_world()
            
            self.lock_actuator()

        self.send_next_pose()

    def create_move_group_goal(self, pose: PoseStamped):
        pos_constraint = PositionConstraint()
        pos_constraint.header.frame_id = pose.header.frame_id
        pos_constraint.link_name = "tool_mount_link"
        pos_constraint.target_point_offset.x = 0.0
        pos_constraint.target_point_offset.y = 0.0
        pos_constraint.target_point_offset.z = 0.0
        pos_constraint.constraint_region.primitives.append(SolidPrimitive(type=SolidPrimitive.BOX, dimensions=[0.01, 0.01, 0.01]))
        pos_constraint.constraint_region.primitive_poses.append(pose.pose)
        pos_constraint.weight = 1.0

        ori_constraint = OrientationConstraint()
        ori_constraint.header.frame_id = pose.header.frame_id
        ori_constraint.link_name = "tool_mount_link"
        ori_constraint.orientation = pose.pose.orientation
        ori_constraint.absolute_x_axis_tolerance = 0.3
        ori_constraint.absolute_y_axis_tolerance = 0.3
        ori_constraint.absolute_z_axis_tolerance = 0.3

        ori_constraint.weight = 1.0

        constraints = Constraints()
        constraints.position_constraints.append(pos_constraint)
        constraints.orientation_constraints.append(ori_constraint)

        goal_msg = MoveGroup.Goal()
        goal_msg.request.workspace_parameters.min_corner.x = -1.0
        goal_msg.request.workspace_parameters.min_corner.y = -1.0
        goal_msg.request.workspace_parameters.min_corner.z = 0.0
        goal_msg.request.workspace_parameters.max_corner.x = 1.0
        goal_msg.request.workspace_parameters.max_corner.y = 1.0
        goal_msg.request.workspace_parameters.max_corner.z = 1.5
        goal_msg.request.goal_constraints.append(constraints)
        goal_msg.request.group_name = "arm"
        goal_msg.request.pipeline_id = "ompl"
        goal_msg.request.num_planning_attempts = 10
        goal_msg.request.allowed_planning_time = 15.0
        goal_msg.request.max_velocity_scaling_factor = 1.0
        goal_msg.request.max_acceleration_scaling_factor = 1.0
        goal_msg.request.start_state = RobotState()
        goal_msg.request.start_state.is_diff = False
        goal_msg.request.start_state = self.get_current_robot_state()

        return goal_msg
    

    def get_current_robot_state(self):
        state = RobotState()
        # Fill with current joint positions or leave empty if you want MoveIt to auto-fill
        state.is_diff = True
        return state

    # ------------------------
    # Utility functions
    # ------------------------
    def get_gripper_dock_pose(self):
        pose = PoseStamped()
        pose.header.frame_id = "world"
        pose.pose.position.x = 0.193
        pose.pose.position.y = -0.287
        pose.pose.position.z = 0.238
        pose.pose.orientation.x = 1.0
        pose.pose.orientation.y = 0.0
        pose.pose.orientation.z = 0.0
        pose.pose.orientation.w = 0.0
        return pose

    def offset_pose(self, base_pose, dx=0.0, dy=0.0, dz=0.0):
        new_pose = PoseStamped()
        new_pose.header.frame_id = base_pose.header.frame_id
        new_pose.pose.position.x = base_pose.pose.position.x + dx
        new_pose.pose.position.y = base_pose.pose.position.y + dy
        new_pose.pose.position.z = base_pose.pose.position.z + dz
        new_pose.pose.orientation = base_pose.pose.orientation
        return new_pose
    
    def remove_gripper_from_world(self):

        co = CollisionObject()
        co.id = "gripper"
        co.header.frame_id = "world"
        co.operation = CollisionObject.REMOVE

        ps = PlanningScene()
        ps.is_diff = True
        ps.world.collision_objects.append(co)

        req = ApplyPlanningScene.Request()
        req.scene = ps

        future = self.ps_client.call_async(req)
        rclpy.spin_until_future_complete(self, future, timeout_sec=5.0)

        self.get_logger().info("Gripper removed from world")

    def attach_gripper_collision(self):
        co = CollisionObject()
        co.id = "gripper"
        co.header.frame_id = "tool_mount_link"
        primitive = SolidPrimitive()
        primitive.type = SolidPrimitive.CYLINDER
        primitive.dimensions = [0.12, 0.012]
        co.primitives.append(primitive)
        co.primitive_poses.append(self.create_gripper_relative_pose().pose)
        co.operation = CollisionObject.ADD
        aco = AttachedCollisionObject()
        aco.object = co
        aco.link_name = "tool_mount_link"
        aco.touch_links = ["tool_mount_link","gripper_base","gripper","screwdriver_base"]


        ps = PlanningScene()
        ps.is_diff = True
        ps.robot_state.is_diff = True
        ps.robot_state.attached_collision_objects.append(aco)
        

        req = ApplyPlanningScene.Request()
        req.scene = ps
        # future = self.ps_client.call_async(req)
        # time.sleep(2)
        # # # Non-blocking, let it complete in the background
        # future.add_done_callback(lambda f: self.get_logger().info("Gripper attached to planning scene"))
        # time.sleep(2)

        future = self.ps_client.call_async(req)
        rclpy.spin_until_future_complete(self, future)
        self.get_logger().info("Gripper attached to planning scene")


    def create_gripper_relative_pose(self):
        pose = PoseStamped()
        pose.header.frame_id = "tool_mount_link"
        pose.pose.position.x = 0.0
        pose.pose.position.y = 0.0
        pose.pose.position.z = 0.075
        pose.pose.orientation.w = 1.0
        return pose

    def unlock_actuator(self):
        self.get_logger().info("Unlocking tool changer...")
        req = LinearMotor.Request()
        req.command = 2  # Unlock

        future = self.tool_client.call_async(req)
        rclpy.spin_until_future_complete(self, future)

        if future.result() is not None:
            result = future.result()
            if result.success:
                self.get_logger().info(f"Unlock success: {result.message}")
            else:
                self.get_logger().error(f"Unlock failed: {result.message}")
        else:
            self.get_logger().error("Failed to call tool_changer service")

    def lock_actuator(self):
        self.get_logger().info("Locking tool changer...")
        req = LinearMotor.Request()
        req.command = 1  # Lock

        future = self.tool_client.call_async(req)
        rclpy.spin_until_future_complete(self, future)

        if future.result() is not None:
            result = future.result()
            if result.success:
                self.get_logger().info(f"Lock success: {result.message}")
            else:
                self.get_logger().error(f"Lock failed: {result.message}")
        else:
            self.get_logger().error("Failed to call tool_changer service")


# ------------------------
# Main
# ------------------------
def main(args=None):
    rclpy.init(args=args)
    node = ToolChangeManager()
    executor = rclpy.executors.MultiThreadedExecutor()
    executor.add_node(node)
    executor.spin()
    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
