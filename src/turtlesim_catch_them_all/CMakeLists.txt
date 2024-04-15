cmake_minimum_required(VERSION 3.8)
project(turtlesim_catch_them_all)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(turtlesim REQUIRED)

# Declare a C++ executable
add_executable(turtle_controller src/turtle_controller.cpp)

# Specify libraries to link a library or executable target against
ament_target_dependencies(
  turtle_controller
  rclcpp
  geometry_msgs
  turtlesim
  )

install(TARGETS
  turtle_controller
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
