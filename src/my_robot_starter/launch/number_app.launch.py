from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()

    remap_number_topic = ("number", "my_number")
    remap_count_topic = ("number_count", "my_number_count")
    

    number_publisher_node = Node(
        package="my_cpp_pkg",
        executable="number_publisher",
        name="my_number_publisher",
        remappings=[remap_number_topic],
        parameters=[
            {"number_to_publish": 5},
            {"publish_frequency": 5.0},
            ]
    )

    counter_node = Node(
        package="my_cpp_pkg",
        executable="number_counter",
        name="my_number_counter",
        remappings=[
            remap_number_topic,
            remap_count_topic]
    )

    ld.add_action(number_publisher_node)
    ld.add_action(counter_node)

    return ld