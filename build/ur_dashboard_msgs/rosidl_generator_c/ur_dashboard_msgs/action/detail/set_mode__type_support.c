// generated from rosidl_generator_c/resource/idl__type_support.c.em
// with input from ur_dashboard_msgs:action/SetMode.idl
// generated code does not contain a copyright notice

#include <string.h>

#include "ur_dashboard_msgs/action/detail/set_mode__struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "ur_dashboard_msgs/action/detail/set_mode__type_support.h"
#include "ur_dashboard_msgs/action/detail/set_mode__functions.h"

#ifdef __cplusplus
extern "C"
{
#endif


void *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
  rosidl_typesupport_c,
  ur_dashboard_msgs,
  action,
  SetMode_SendGoal
)(
  const rosidl_service_introspection_info_t * info,
  rcutils_allocator_t * allocator,
  const void * request_message,
  const void * response_message)
{
  if (!allocator || !info) {
    return NULL;
  }
  ur_dashboard_msgs__action__SetMode_SendGoal_Event * event_msg = (ur_dashboard_msgs__action__SetMode_SendGoal_Event *)(allocator->allocate(sizeof(ur_dashboard_msgs__action__SetMode_SendGoal_Event), allocator->state));
  if (!ur_dashboard_msgs__action__SetMode_SendGoal_Event__init(event_msg)) {
    allocator->deallocate(event_msg, allocator->state);
    return NULL;
  }

  event_msg->info.event_type = info->event_type;
  event_msg->info.sequence_number = info->sequence_number;
  event_msg->info.stamp.sec = info->stamp_sec;
  event_msg->info.stamp.nanosec = info->stamp_nanosec;
  memcpy(event_msg->info.client_gid, info->client_gid, 16);
  if (request_message) {
    ur_dashboard_msgs__action__SetMode_SendGoal_Request__Sequence__init(
      &event_msg->request,
      1);
    if (!ur_dashboard_msgs__action__SetMode_SendGoal_Request__copy((const ur_dashboard_msgs__action__SetMode_SendGoal_Request *)(request_message), event_msg->request.data)) {
      allocator->deallocate(event_msg, allocator->state);
      return NULL;
    }
  }
  if (response_message) {
    ur_dashboard_msgs__action__SetMode_SendGoal_Response__Sequence__init(
      &event_msg->response,
      1);
    if (!ur_dashboard_msgs__action__SetMode_SendGoal_Response__copy((const ur_dashboard_msgs__action__SetMode_SendGoal_Response *)(response_message), event_msg->response.data)) {
      allocator->deallocate(event_msg, allocator->state);
      return NULL;
    }
  }
  return event_msg;
}

// Forward declare the get type support functions for this type.
bool
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
  rosidl_typesupport_c,
  ur_dashboard_msgs,
  action,
  SetMode_SendGoal
)(
  void * event_msg,
  rcutils_allocator_t * allocator)
{
  if (!allocator) {
    return false;
  }
  if (NULL == event_msg) {
    return false;
  }
  ur_dashboard_msgs__action__SetMode_SendGoal_Event * _event_msg = (ur_dashboard_msgs__action__SetMode_SendGoal_Event *)(event_msg);

  ur_dashboard_msgs__action__SetMode_SendGoal_Event__fini((ur_dashboard_msgs__action__SetMode_SendGoal_Event *)(_event_msg));
  if (_event_msg->request.data) {
    allocator->deallocate(_event_msg->request.data, allocator->state);
  }
  if (_event_msg->response.data) {
    allocator->deallocate(_event_msg->response.data, allocator->state);
  }
  allocator->deallocate(_event_msg, allocator->state);
  return true;
}


void *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
  rosidl_typesupport_c,
  ur_dashboard_msgs,
  action,
  SetMode_GetResult
)(
  const rosidl_service_introspection_info_t * info,
  rcutils_allocator_t * allocator,
  const void * request_message,
  const void * response_message)
{
  if (!allocator || !info) {
    return NULL;
  }
  ur_dashboard_msgs__action__SetMode_GetResult_Event * event_msg = (ur_dashboard_msgs__action__SetMode_GetResult_Event *)(allocator->allocate(sizeof(ur_dashboard_msgs__action__SetMode_GetResult_Event), allocator->state));
  if (!ur_dashboard_msgs__action__SetMode_GetResult_Event__init(event_msg)) {
    allocator->deallocate(event_msg, allocator->state);
    return NULL;
  }

  event_msg->info.event_type = info->event_type;
  event_msg->info.sequence_number = info->sequence_number;
  event_msg->info.stamp.sec = info->stamp_sec;
  event_msg->info.stamp.nanosec = info->stamp_nanosec;
  memcpy(event_msg->info.client_gid, info->client_gid, 16);
  if (request_message) {
    ur_dashboard_msgs__action__SetMode_GetResult_Request__Sequence__init(
      &event_msg->request,
      1);
    if (!ur_dashboard_msgs__action__SetMode_GetResult_Request__copy((const ur_dashboard_msgs__action__SetMode_GetResult_Request *)(request_message), event_msg->request.data)) {
      allocator->deallocate(event_msg, allocator->state);
      return NULL;
    }
  }
  if (response_message) {
    ur_dashboard_msgs__action__SetMode_GetResult_Response__Sequence__init(
      &event_msg->response,
      1);
    if (!ur_dashboard_msgs__action__SetMode_GetResult_Response__copy((const ur_dashboard_msgs__action__SetMode_GetResult_Response *)(response_message), event_msg->response.data)) {
      allocator->deallocate(event_msg, allocator->state);
      return NULL;
    }
  }
  return event_msg;
}

// Forward declare the get type support functions for this type.
bool
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
  rosidl_typesupport_c,
  ur_dashboard_msgs,
  action,
  SetMode_GetResult
)(
  void * event_msg,
  rcutils_allocator_t * allocator)
{
  if (!allocator) {
    return false;
  }
  if (NULL == event_msg) {
    return false;
  }
  ur_dashboard_msgs__action__SetMode_GetResult_Event * _event_msg = (ur_dashboard_msgs__action__SetMode_GetResult_Event *)(event_msg);

  ur_dashboard_msgs__action__SetMode_GetResult_Event__fini((ur_dashboard_msgs__action__SetMode_GetResult_Event *)(_event_msg));
  if (_event_msg->request.data) {
    allocator->deallocate(_event_msg->request.data, allocator->state);
  }
  if (_event_msg->response.data) {
    allocator->deallocate(_event_msg->response.data, allocator->state);
  }
  allocator->deallocate(_event_msg, allocator->state);
  return true;
}

#ifdef __cplusplus
}
#endif
