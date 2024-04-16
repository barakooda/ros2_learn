// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from turtlesim_catch_them_all:msg/Turtle.idl
// generated code does not contain a copyright notice

#ifndef TURTLESIM_CATCH_THEM_ALL__MSG__DETAIL__TURTLE__TRAITS_HPP_
#define TURTLESIM_CATCH_THEM_ALL__MSG__DETAIL__TURTLE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "turtlesim_catch_them_all/msg/detail/turtle__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace turtlesim_catch_them_all
{

namespace msg
{

inline void to_flow_style_yaml(
  const Turtle & msg,
  std::ostream & out)
{
  out << "{";
  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Turtle & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << "\n";
  }

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Turtle & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace turtlesim_catch_them_all

namespace rosidl_generator_traits
{

[[deprecated("use turtlesim_catch_them_all::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const turtlesim_catch_them_all::msg::Turtle & msg,
  std::ostream & out, size_t indentation = 0)
{
  turtlesim_catch_them_all::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use turtlesim_catch_them_all::msg::to_yaml() instead")]]
inline std::string to_yaml(const turtlesim_catch_them_all::msg::Turtle & msg)
{
  return turtlesim_catch_them_all::msg::to_yaml(msg);
}

template<>
inline const char * data_type<turtlesim_catch_them_all::msg::Turtle>()
{
  return "turtlesim_catch_them_all::msg::Turtle";
}

template<>
inline const char * name<turtlesim_catch_them_all::msg::Turtle>()
{
  return "turtlesim_catch_them_all/msg/Turtle";
}

template<>
struct has_fixed_size<turtlesim_catch_them_all::msg::Turtle>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<turtlesim_catch_them_all::msg::Turtle>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<turtlesim_catch_them_all::msg::Turtle>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TURTLESIM_CATCH_THEM_ALL__MSG__DETAIL__TURTLE__TRAITS_HPP_
