#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
import example_interfaces.msg as MsgI

class RobotNewsStatioNode(Node): # MODIFY NAME
    def __init__(self):
        super().__init__("robot_news_station") # MODIFY NAME

        self.robot_name_ = "Barakooda"

        self.publisher_ = self.create_publisher(MsgI.String, "robot_news", 10)
        self.timer_ = self.create_timer(0.5, self.publish_news)
        self.get_logger().info("Robot News Station has been started.")
    
    def publish_news(self):
        message = MsgI.String()
        message.data = f"Hi, this is robot {self.robot_name_} from the robot news station."
        self.publisher_.publish(message)
        self.get_logger().info(message.data)

def main(args=None):
    rclpy.init(args=args)
    node = RobotNewsStatioNode() # MODIFY NAME
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
