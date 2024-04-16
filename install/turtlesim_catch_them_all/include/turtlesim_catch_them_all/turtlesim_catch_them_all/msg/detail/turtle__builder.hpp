// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from turtlesim_catch_them_all:msg/Turtle.idl
// generated code does not contain a copyright notice

#ifndef TURTLESIM_CATCH_THEM_ALL__MSG__DETAIL__TURTLE__BUILDER_HPP_
#define TURTLESIM_CATCH_THEM_ALL__MSG__DETAIL__TURTLE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "turtlesim_catch_them_all/msg/detail/turtle__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace turtlesim_catch_them_all
{

namespace msg
{

namespace builder
{

class Init_Turtle_y
{
public:
  explicit Init_Turtle_y(::turtlesim_catch_them_all::msg::Turtle & msg)
  : msg_(msg)
  {}
  ::turtlesim_catch_them_all::msg::Turtle y(::turtlesim_catch_them_all::msg::Turtle::_y_type arg)
  {
    msg_.y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtlesim_catch_them_all::msg::Turtle msg_;
};

class Init_Turtle_x
{
public:
  explicit Init_Turtle_x(::turtlesim_catch_them_all::msg::Turtle & msg)
  : msg_(msg)
  {}
  Init_Turtle_y x(::turtlesim_catch_them_all::msg::Turtle::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Turtle_y(msg_);
  }

private:
  ::turtlesim_catch_them_all::msg::Turtle msg_;
};

class Init_Turtle_name
{
public:
  Init_Turtle_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Turtle_x name(::turtlesim_catch_them_all::msg::Turtle::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_Turtle_x(msg_);
  }

private:
  ::turtlesim_catch_them_all::msg::Turtle msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtlesim_catch_them_all::msg::Turtle>()
{
  return turtlesim_catch_them_all::msg::builder::Init_Turtle_name();
}

}  // namespace turtlesim_catch_them_all

#endif  // TURTLESIM_CATCH_THEM_ALL__MSG__DETAIL__TURTLE__BUILDER_HPP_
