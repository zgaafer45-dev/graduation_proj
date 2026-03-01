#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient

from sabry_hardware.srv import ChangeTool
from moveit_msgs.action import MoveGroup
from moveit_msgs.msg import Constraints, PositionConstraint, BoundingVolume
from shape_msgs.msg import SolidPrimitive
from geometry_msgs.msg import PoseStamped


class Operation(Node):

    def __init__(self):
        super().__init__("operation_manager")

        # Service client
        self.tool_client = self.create_client(ChangeTool, "change_tool")
        while not self.tool_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("Waiting for change_tool service...")

        # MoveIt action client
        self.move_action_client = ActionClient(self, MoveGroup, "/move_action")
        while not self.move_action_client.wait_for_server(timeout_sec=1.0):
            self.get_logger().info("Waiting for MoveIt action server...")

        self.get_logger().info("OperationManager ready")

        self.operation_sequence()

    # -----------------------------
    # OPERATION SEQUENCE
    # -----------------------------

    def operation_sequence(self):
        self.attach_gripper()

    # -----------------------------
    # CHANGE TOOL SERVICE
    # -----------------------------

    def attach_gripper(self):
        request = ChangeTool.Request()
        request.tool_name = "gripper"

        future = self.tool_client.call_async(request)
        future.add_done_callback(self.gripper_attached_cb)

    def gripper_attached_cb(self, future):
        response = future.result()
        if response.success:
            self.get_logger().info("Gripper attached successfully")
            self.move_tool(0.4, 0.2, 0.3)
        else:
            self.get_logger().error("Failed to attach gripper")
            self.move_tool(0.4, 0.2, 0.3)

    def detach_gripper(self):
        request = ChangeTool.Request()
        request.tool_name = "none"

        future = self.tool_client.call_async(request)
        future.add_done_callback(self.gripper_detached_cb)

    def gripper_detached_cb(self, future):
        response = future.result()
        if response.success:
            self.get_logger().info("Gripper detached successfully")

    # -----------------------------
    # MOVE TOOL USING MOVEIT ACTION
    # -----------------------------

    def move_tool(self, x, y, z):

        goal_msg = MoveGroup.Goal()

        goal_msg.request.group_name = "arm"
        goal_msg.request.num_planning_attempts = 10
        goal_msg.request.allowed_planning_time = 15.0

        pose = PoseStamped()
        pose.header.frame_id = "base_link"
        pose.pose.position.x = x
        pose.pose.position.y = y
        pose.pose.position.z = z
        pose.pose.orientation.w = 1.0  

        goal_msg.request.goal_constraints.append(
            self.create_position_constraint(pose)
        )

        self.get_logger().info(f"Sending MoveIt goal to ({x}, {y}, {z})")

        send_goal_future = self.move_action_client.send_goal_async(goal_msg)
        send_goal_future.add_done_callback(self.move_goal_response_cb)

    def create_position_constraint(self, pose):

        constraint = Constraints()

        pos_constraint = PositionConstraint()
        pos_constraint.header = pose.header
        pos_constraint.link_name = "tool_mount_link"

        primitive = SolidPrimitive()
        primitive.type = SolidPrimitive.SPHERE
        primitive.dimensions = [0.01]

        bounding_volume = BoundingVolume()
        bounding_volume.primitives.append(primitive)
        bounding_volume.primitive_poses.append(pose.pose)

        pos_constraint.constraint_region = bounding_volume
        pos_constraint.weight = 1.0

        constraint.position_constraints.append(pos_constraint)

        return constraint

    def move_goal_response_cb(self, future):
        goal_handle = future.result()

        if not goal_handle.accepted:
            self.get_logger().error("Move goal rejected")
            return

        self.get_logger().info("Move goal accepted")

        result_future = goal_handle.get_result_async()
        result_future.add_done_callback(self.move_result_cb)

    def move_result_cb(self, future):
        result = future.result().result
        self.get_logger().info("Move completed")

        # After movement, detach tool
        self.detach_gripper()


# -----------------------------
# MAIN
# -----------------------------

def main(args=None):
    rclpy.init(args=args)
    node = Operation()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
