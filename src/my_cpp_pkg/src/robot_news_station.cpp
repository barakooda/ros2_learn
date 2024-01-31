#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

class RobotNewsStatioNode : public rclcpp::Node 
{
public:
    RobotNewsStatioNode() : Node("robot_news_station") 
    {
        publisher_ = this->create_publisher<example_interfaces::msg::String>("robot_news", 10);
        timer_ = this->create_wall_timer(std::chrono::milliseconds(500), std::bind(&RobotNewsStatioNode::publishNews, this));
        robot_name = "R2D2";
        RCLCPP_INFO(this->get_logger(), "Robot News Station has been started");
    }

private:
    std::string robot_name;
    rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;

    void publishNews()
    {
        auto message = example_interfaces::msg::String();
        std::ostringstream oss;
        oss << "Hi, this is " << robot_name << " from the Robot News Station";
        message.data = oss.str();
        publisher_->publish(message);
    }

};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<RobotNewsStatioNode>(); 
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
