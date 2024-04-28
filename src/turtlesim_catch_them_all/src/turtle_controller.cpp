#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "turtlesim/msg/pose.hpp"

#include "my_robot_interfaces/msg/turtle_array.hpp"

class TurtleController : public rclcpp::Node // MODIFY NAME
{
public:
    TurtleController() : Node("turtle_controller") // MODIFY NAME
    {

    turtle_hero_sub_ = this->create_subscription<turtlesim::msg::Pose>(
        "turtle1/pose", 10, std::bind(&TurtleController::poseCallback, this, std::placeholders::_1));
    
    live_turtles_sub_ = this->create_subscription<my_robot_interfaces::msg::TurtleArray>(
        "live_turtles", 10, std::bind(&TurtleController::liveTurtlesCallback, this, std::placeholders::_1));
    
    publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("turtle1/cmd_vel", 10);

    timer_ = this->create_wall_timer(std::chrono::milliseconds(100), std::bind(&TurtleController::moveTurtle, this));

    }

private:

    void liveTurtlesCallback(const my_robot_interfaces::msg::TurtleArray::SharedPtr msg)
    {
        target_x = msg->turtles[0].x;
        target_y = msg->turtles[0].y;

    }

    void poseCallback(const turtlesim::msg::Pose::SharedPtr msg)
    {
        
        pose_ = msg;
        
    }

    void moveTurtle()
    {
        
        if (!pose_)
        {
            return;
        }
        

        RCLCPP_INFO(this->get_logger(), "Turtle pose: x=%f, y=%f",  pose_->x,  pose_->y);

        float vel_x = target_x - pose_->x;
        float vel_y = target_y - pose_->y;
        
        float distance = sqrt(vel_x*vel_x + vel_y*vel_y);

        if (distance < 0.5)
        {
            twist.linear.x = 0.0;
            twist.angular.z = 0.0;
            return;
        }

        twist.angular.z = atan2(vel_y, vel_x);

        twist.angular.z -= pose_->theta;

        if (twist.angular.z > 3.14)
        {
            twist.angular.z -=  5*3.14;
        }
        else if (twist.angular.z < -3.14)
        {
            twist.angular.z += 5*3.14;
        }

        

        twist.linear.x = distance*0.5;

        publisher_->publish(twist);
    
    }

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr turtle_hero_sub_;
    rclcpp::Subscription<my_robot_interfaces::msg::TurtleArray>::SharedPtr live_turtles_sub_;

    float target_x = 5.5;
    float target_y = 5.5;


    my_robot_interfaces::msg::TurtleArray::SharedPtr live_turtles_;

    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
    turtlesim::msg::Pose::SharedPtr pose_;
    geometry_msgs::msg::Twist twist;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<TurtleController>(); // MODIFY NAME
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
