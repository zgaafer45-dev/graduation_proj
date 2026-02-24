// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sabry_hardware:srv/ChangeTool.idl
// generated code does not contain a copyright notice

#ifndef SABRY_HARDWARE__SRV__DETAIL__CHANGE_TOOL__STRUCT_H_
#define SABRY_HARDWARE__SRV__DETAIL__CHANGE_TOOL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'tool_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ChangeTool in the package sabry_hardware.
typedef struct sabry_hardware__srv__ChangeTool_Request
{
  rosidl_runtime_c__String tool_name;
} sabry_hardware__srv__ChangeTool_Request;

// Struct for a sequence of sabry_hardware__srv__ChangeTool_Request.
typedef struct sabry_hardware__srv__ChangeTool_Request__Sequence
{
  sabry_hardware__srv__ChangeTool_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sabry_hardware__srv__ChangeTool_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ChangeTool in the package sabry_hardware.
typedef struct sabry_hardware__srv__ChangeTool_Response
{
  bool success;
  rosidl_runtime_c__String message;
} sabry_hardware__srv__ChangeTool_Response;

// Struct for a sequence of sabry_hardware__srv__ChangeTool_Response.
typedef struct sabry_hardware__srv__ChangeTool_Response__Sequence
{
  sabry_hardware__srv__ChangeTool_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sabry_hardware__srv__ChangeTool_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SABRY_HARDWARE__SRV__DETAIL__CHANGE_TOOL__STRUCT_H_
