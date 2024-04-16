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
find_package(rosidl_default_generators REQUIRED)

# Generate messages in the 'msg' folder
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Turtle.msg"
  "msg/TurtleArray.msg"
)

# Ensure all nodes in the package have access to the generated messages
ament_export_dependencies(rosidl_default_runtime)

# Declare a C++ executable
add_executable(turtle_controller src/turtle_controller.cpp)
ament_target_dependencies(turtle_controller rclcpp geometry_msgs turtlesim)

add_executable(turtle_spawner src/turtle_spawner.cpp)
ament_target_dependencies(turtle_spawner rclcpp geometry_msgs turtlesim)

# Install the executables
install(TARGETS
  turtle_controller
  turtle_spawner
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
