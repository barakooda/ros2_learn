from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()

    #remap_number_topic = ("number", "my_number")
    #remap_count_topic = ("number_count", "my_number_count")
    
    names =  ["glskard","bb8","daneel","jander","3cpo"]

    for name in names:
        
        robot_news_station_node = Node(
        package="my_cpp_pkg",
        executable="robot_news_station",
        name="robot_news_station_" + name,
        parameters=[
            {"robot_name": name}
            ]
        )

        ld.add_action(robot_news_station_node)


    smartphone_node = Node(
        package="my_cpp_pkg",
        executable="smartphone",
        name="smartphone"
        )

    
    ld.add_action(smartphone_node)

    return ld