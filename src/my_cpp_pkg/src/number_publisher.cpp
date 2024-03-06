#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp"


class NumberPublisherNode : public rclcpp::Node // MODIFY NAME
{

    
public:
    NumberPublisherNode() : Node("number_publisher") // MODIFY NAME
    {

        this->declare_parameter("number_to_publish", 2);
        this->declare_parameter("publish_frequency", 1.0);

        int number_ = this->get_parameter("number_to_publish").as_int();
        double publish_frequency = this->get_parameter("publish_frequency").as_double();

        publisher_name_ = "number";
        publisher_ = this->create_publisher<example_interfaces::msg::Int64>(publisher_name_, 10);
        timer_ = this->create_wall_timer(std::chrono::milliseconds(int(1000/publish_frequency)), std::bind(&NumberPublisherNode::publishNumber, this));
        message_.data = number_;
        RCLCPP_INFO(this->get_logger(), "Number Publisher has been started");
    }


private:
    std::string publisher_name_;
    rclcpp::Publisher<example_interfaces::msg::Int64>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    example_interfaces::msg::Int64 message_ = example_interfaces::msg::Int64();


    void publishNumber()
    { 
        publisher_->publish(message_);
    }

};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<NumberPublisherNode>(); // MODIFY NAME
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
