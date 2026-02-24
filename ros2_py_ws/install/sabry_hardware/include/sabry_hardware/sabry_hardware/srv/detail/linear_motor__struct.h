// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sabry_hardware:srv/LinearMotor.idl
// generated code does not contain a copyright notice

#ifndef SABRY_HARDWARE__SRV__DETAIL__LINEAR_MOTOR__STRUCT_H_
#define SABRY_HARDWARE__SRV__DETAIL__LINEAR_MOTOR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/LinearMotor in the package sabry_hardware.
typedef struct sabry_hardware__srv__LinearMotor_Request
{
  int8_t command;
} sabry_hardware__srv__LinearMotor_Request;

// Struct for a sequence of sabry_hardware__srv__LinearMotor_Request.
typedef struct sabry_hardware__srv__LinearMotor_Request__Sequence
{
  sabry_hardware__srv__LinearMotor_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sabry_hardware__srv__LinearMotor_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/LinearMotor in the package sabry_hardware.
typedef struct sabry_hardware__srv__LinearMotor_Response
{
  bool success;
  rosidl_runtime_c__String message;
} sabry_hardware__srv__LinearMotor_Response;

// Struct for a sequence of sabry_hardware__srv__LinearMotor_Response.
typedef struct sabry_hardware__srv__LinearMotor_Response__Sequence
{
  sabry_hardware__srv__LinearMotor_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sabry_hardware__srv__LinearMotor_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SABRY_HARDWARE__SRV__DETAIL__LINEAR_MOTOR__STRUCT_H_
