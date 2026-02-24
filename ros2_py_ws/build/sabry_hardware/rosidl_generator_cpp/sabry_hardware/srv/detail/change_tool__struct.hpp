// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from sabry_hardware:srv/ChangeTool.idl
// generated code does not contain a copyright notice

#ifndef SABRY_HARDWARE__SRV__DETAIL__CHANGE_TOOL__STRUCT_HPP_
#define SABRY_HARDWARE__SRV__DETAIL__CHANGE_TOOL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__sabry_hardware__srv__ChangeTool_Request __attribute__((deprecated))
#else
# define DEPRECATED__sabry_hardware__srv__ChangeTool_Request __declspec(deprecated)
#endif

namespace sabry_hardware
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ChangeTool_Request_
{
  using Type = ChangeTool_Request_<ContainerAllocator>;

  explicit ChangeTool_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->tool_name = "";
    }
  }

  explicit ChangeTool_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : tool_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->tool_name = "";
    }
  }

  // field types and members
  using _tool_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _tool_name_type tool_name;

  // setters for named parameter idiom
  Type & set__tool_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->tool_name = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sabry_hardware::srv::ChangeTool_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const sabry_hardware::srv::ChangeTool_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sabry_hardware::srv::ChangeTool_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sabry_hardware::srv::ChangeTool_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sabry_hardware::srv::ChangeTool_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sabry_hardware::srv::ChangeTool_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sabry_hardware::srv::ChangeTool_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sabry_hardware::srv::ChangeTool_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sabry_hardware::srv::ChangeTool_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sabry_hardware::srv::ChangeTool_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sabry_hardware__srv__ChangeTool_Request
    std::shared_ptr<sabry_hardware::srv::ChangeTool_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sabry_hardware__srv__ChangeTool_Request
    std::shared_ptr<sabry_hardware::srv::ChangeTool_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ChangeTool_Request_ & other) const
  {
    if (this->tool_name != other.tool_name) {
      return false;
    }
    return true;
  }
  bool operator!=(const ChangeTool_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ChangeTool_Request_

// alias to use template instance with default allocator
using ChangeTool_Request =
  sabry_hardware::srv::ChangeTool_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace sabry_hardware


#ifndef _WIN32
# define DEPRECATED__sabry_hardware__srv__ChangeTool_Response __attribute__((deprecated))
#else
# define DEPRECATED__sabry_hardware__srv__ChangeTool_Response __declspec(deprecated)
#endif

namespace sabry_hardware
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ChangeTool_Response_
{
  using Type = ChangeTool_Response_<ContainerAllocator>;

  explicit ChangeTool_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit ChangeTool_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sabry_hardware::srv::ChangeTool_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const sabry_hardware::srv::ChangeTool_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sabry_hardware::srv::ChangeTool_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sabry_hardware::srv::ChangeTool_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sabry_hardware::srv::ChangeTool_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sabry_hardware::srv::ChangeTool_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sabry_hardware::srv::ChangeTool_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sabry_hardware::srv::ChangeTool_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sabry_hardware::srv::ChangeTool_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sabry_hardware::srv::ChangeTool_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sabry_hardware__srv__ChangeTool_Response
    std::shared_ptr<sabry_hardware::srv::ChangeTool_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sabry_hardware__srv__ChangeTool_Response
    std::shared_ptr<sabry_hardware::srv::ChangeTool_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ChangeTool_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const ChangeTool_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ChangeTool_Response_

// alias to use template instance with default allocator
using ChangeTool_Response =
  sabry_hardware::srv::ChangeTool_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace sabry_hardware

namespace sabry_hardware
{

namespace srv
{

struct ChangeTool
{
  using Request = sabry_hardware::srv::ChangeTool_Request;
  using Response = sabry_hardware::srv::ChangeTool_Response;
};

}  // namespace srv

}  // namespace sabry_hardware

#endif  // SABRY_HARDWARE__SRV__DETAIL__CHANGE_TOOL__STRUCT_HPP_
