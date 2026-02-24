// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sabry_hardware:srv/ChangeTool.idl
// generated code does not contain a copyright notice

#ifndef SABRY_HARDWARE__SRV__DETAIL__CHANGE_TOOL__BUILDER_HPP_
#define SABRY_HARDWARE__SRV__DETAIL__CHANGE_TOOL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sabry_hardware/srv/detail/change_tool__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace sabry_hardware
{

namespace srv
{

namespace builder
{

class Init_ChangeTool_Request_tool_name
{
public:
  Init_ChangeTool_Request_tool_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::sabry_hardware::srv::ChangeTool_Request tool_name(::sabry_hardware::srv::ChangeTool_Request::_tool_name_type arg)
  {
    msg_.tool_name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sabry_hardware::srv::ChangeTool_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::sabry_hardware::srv::ChangeTool_Request>()
{
  return sabry_hardware::srv::builder::Init_ChangeTool_Request_tool_name();
}

}  // namespace sabry_hardware


namespace sabry_hardware
{

namespace srv
{

namespace builder
{

class Init_ChangeTool_Response_message
{
public:
  explicit Init_ChangeTool_Response_message(::sabry_hardware::srv::ChangeTool_Response & msg)
  : msg_(msg)
  {}
  ::sabry_hardware::srv::ChangeTool_Response message(::sabry_hardware::srv::ChangeTool_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sabry_hardware::srv::ChangeTool_Response msg_;
};

class Init_ChangeTool_Response_success
{
public:
  Init_ChangeTool_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ChangeTool_Response_message success(::sabry_hardware::srv::ChangeTool_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_ChangeTool_Response_message(msg_);
  }

private:
  ::sabry_hardware::srv::ChangeTool_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::sabry_hardware::srv::ChangeTool_Response>()
{
  return sabry_hardware::srv::builder::Init_ChangeTool_Response_success();
}

}  // namespace sabry_hardware

#endif  // SABRY_HARDWARE__SRV__DETAIL__CHANGE_TOOL__BUILDER_HPP_
