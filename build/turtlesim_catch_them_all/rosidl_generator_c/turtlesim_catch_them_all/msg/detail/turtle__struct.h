// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from turtlesim_catch_them_all:msg/Turtle.idl
// generated code does not contain a copyright notice

#ifndef TURTLESIM_CATCH_THEM_ALL__MSG__DETAIL__TURTLE__STRUCT_H_
#define TURTLESIM_CATCH_THEM_ALL__MSG__DETAIL__TURTLE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Turtle in the package turtlesim_catch_them_all.
/**
  * Turtle
 */
typedef struct turtlesim_catch_them_all__msg__Turtle
{
  rosidl_runtime_c__String name;
  double x;
  double y;
} turtlesim_catch_them_all__msg__Turtle;

// Struct for a sequence of turtlesim_catch_them_all__msg__Turtle.
typedef struct turtlesim_catch_them_all__msg__Turtle__Sequence
{
  turtlesim_catch_them_all__msg__Turtle * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turtlesim_catch_them_all__msg__Turtle__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TURTLESIM_CATCH_THEM_ALL__MSG__DETAIL__TURTLE__STRUCT_H_
