// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sabry_hardware:srv/LinearMotor.idl
// generated code does not contain a copyright notice

#ifndef SABRY_HARDWARE__SRV__DETAIL__LINEAR_MOTOR__BUILDER_HPP_
#define SABRY_HARDWARE__SRV__DETAIL__LINEAR_MOTOR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sabry_hardware/srv/detail/linear_motor__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace sabry_hardware
{

namespace srv
{

namespace builder
{

class Init_LinearMotor_Request_command
{
public:
  Init_LinearMotor_Request_command()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::sabry_hardware::srv::LinearMotor_Request command(::sabry_hardware::srv::LinearMotor_Request::_command_type arg)
  {
    msg_.command = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sabry_hardware::srv::LinearMotor_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::sabry_hardware::srv::LinearMotor_Request>()
{
  return sabry_hardware::srv::builder::Init_LinearMotor_Request_command();
}

}  // namespace sabry_hardware


namespace sabry_hardware
{

namespace srv
{

namespace builder
{

class Init_LinearMotor_Response_message
{
public:
  explicit Init_LinearMotor_Response_message(::sabry_hardware::srv::LinearMotor_Response & msg)
  : msg_(msg)
  {}
  ::sabry_hardware::srv::LinearMotor_Response message(::sabry_hardware::srv::LinearMotor_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sabry_hardware::srv::LinearMotor_Response msg_;
};

class Init_LinearMotor_Response_success
{
public:
  Init_LinearMotor_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LinearMotor_Response_message success(::sabry_hardware::srv::LinearMotor_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_LinearMotor_Response_message(msg_);
  }

private:
  ::sabry_hardware::srv::LinearMotor_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::sabry_hardware::srv::LinearMotor_Response>()
{
  return sabry_hardware::srv::builder::Init_LinearMotor_Response_success();
}

}  // namespace sabry_hardware

#endif  // SABRY_HARDWARE__SRV__DETAIL__LINEAR_MOTOR__BUILDER_HPP_
