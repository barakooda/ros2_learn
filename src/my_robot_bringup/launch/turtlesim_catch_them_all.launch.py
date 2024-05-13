from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()

    # Launch the turtlesim_node
    turtlesim_node = Node(
        package="turtlesim",
        executable="turtlesim_node",
        name="turtlesim_node"
    )

    turtle_controller_node = Node(
        package="turtlesim_catch_them_all",
        executable="turtle_controller",
        name="turtle_controller",
        parameters=[{"is_by_distance:True"}]
                    
    )

    turtle_spawner_node = Node(
        package="turtlesim_catch_them_all",
        executable="turtle_spawner",
        name="turtle_spawner"
    )




    ld.add_action(turtlesim_node)
    ld.add_action(turtle_controller_node)
    ld.add_action(turtle_spawner_node)

    return ld