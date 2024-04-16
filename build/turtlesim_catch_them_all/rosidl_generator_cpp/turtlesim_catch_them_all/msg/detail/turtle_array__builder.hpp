// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from turtlesim_catch_them_all:msg/TurtleArray.idl
// generated code does not contain a copyright notice

#ifndef TURTLESIM_CATCH_THEM_ALL__MSG__DETAIL__TURTLE_ARRAY__BUILDER_HPP_
#define TURTLESIM_CATCH_THEM_ALL__MSG__DETAIL__TURTLE_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "turtlesim_catch_them_all/msg/detail/turtle_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace turtlesim_catch_them_all
{

namespace msg
{

namespace builder
{

class Init_TurtleArray_turtles
{
public:
  Init_TurtleArray_turtles()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::turtlesim_catch_them_all::msg::TurtleArray turtles(::turtlesim_catch_them_all::msg::TurtleArray::_turtles_type arg)
  {
    msg_.turtles = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtlesim_catch_them_all::msg::TurtleArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtlesim_catch_them_all::msg::TurtleArray>()
{
  return turtlesim_catch_them_all::msg::builder::Init_TurtleArray_turtles();
}

}  // namespace turtlesim_catch_them_all

#endif  // TURTLESIM_CATCH_THEM_ALL__MSG__DETAIL__TURTLE_ARRAY__BUILDER_HPP_
