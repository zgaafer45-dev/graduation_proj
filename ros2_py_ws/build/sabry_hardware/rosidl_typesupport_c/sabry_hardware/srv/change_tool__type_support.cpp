// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from sabry_hardware:srv/ChangeTool.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "sabry_hardware/srv/detail/change_tool__struct.h"
#include "sabry_hardware/srv/detail/change_tool__type_support.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace sabry_hardware
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _ChangeTool_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ChangeTool_Request_type_support_ids_t;

static const _ChangeTool_Request_type_support_ids_t _ChangeTool_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _ChangeTool_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ChangeTool_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ChangeTool_Request_type_support_symbol_names_t _ChangeTool_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, sabry_hardware, srv, ChangeTool_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sabry_hardware, srv, ChangeTool_Request)),
  }
};

typedef struct _ChangeTool_Request_type_support_data_t
{
  void * data[2];
} _ChangeTool_Request_type_support_data_t;

static _ChangeTool_Request_type_support_data_t _ChangeTool_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ChangeTool_Request_message_typesupport_map = {
  2,
  "sabry_hardware",
  &_ChangeTool_Request_message_typesupport_ids.typesupport_identifier[0],
  &_ChangeTool_Request_message_typesupport_symbol_names.symbol_name[0],
  &_ChangeTool_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ChangeTool_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ChangeTool_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace sabry_hardware

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, sabry_hardware, srv, ChangeTool_Request)() {
  return &::sabry_hardware::srv::rosidl_typesupport_c::ChangeTool_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "sabry_hardware/srv/detail/change_tool__struct.h"
// already included above
// #include "sabry_hardware/srv/detail/change_tool__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace sabry_hardware
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _ChangeTool_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ChangeTool_Response_type_support_ids_t;

static const _ChangeTool_Response_type_support_ids_t _ChangeTool_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _ChangeTool_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ChangeTool_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ChangeTool_Response_type_support_symbol_names_t _ChangeTool_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, sabry_hardware, srv, ChangeTool_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sabry_hardware, srv, ChangeTool_Response)),
  }
};

typedef struct _ChangeTool_Response_type_support_data_t
{
  void * data[2];
} _ChangeTool_Response_type_support_data_t;

static _ChangeTool_Response_type_support_data_t _ChangeTool_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ChangeTool_Response_message_typesupport_map = {
  2,
  "sabry_hardware",
  &_ChangeTool_Response_message_typesupport_ids.typesupport_identifier[0],
  &_ChangeTool_Response_message_typesupport_symbol_names.symbol_name[0],
  &_ChangeTool_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ChangeTool_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ChangeTool_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace sabry_hardware

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, sabry_hardware, srv, ChangeTool_Response)() {
  return &::sabry_hardware::srv::rosidl_typesupport_c::ChangeTool_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "sabry_hardware/srv/detail/change_tool__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace sabry_hardware
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _ChangeTool_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ChangeTool_type_support_ids_t;

static const _ChangeTool_type_support_ids_t _ChangeTool_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _ChangeTool_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ChangeTool_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ChangeTool_type_support_symbol_names_t _ChangeTool_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, sabry_hardware, srv, ChangeTool)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sabry_hardware, srv, ChangeTool)),
  }
};

typedef struct _ChangeTool_type_support_data_t
{
  void * data[2];
} _ChangeTool_type_support_data_t;

static _ChangeTool_type_support_data_t _ChangeTool_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ChangeTool_service_typesupport_map = {
  2,
  "sabry_hardware",
  &_ChangeTool_service_typesupport_ids.typesupport_identifier[0],
  &_ChangeTool_service_typesupport_symbol_names.symbol_name[0],
  &_ChangeTool_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t ChangeTool_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ChangeTool_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace sabry_hardware

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, sabry_hardware, srv, ChangeTool)() {
  return &::sabry_hardware::srv::rosidl_typesupport_c::ChangeTool_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif
