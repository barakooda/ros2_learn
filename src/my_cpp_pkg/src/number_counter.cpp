#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp"


class NumberCounterNode : public rclcpp::Node // MODIFY NAME
{

    
public:
    NumberCounterNode() : Node("number_publisher") // MODIFY NAME
    {
        publisher_name_ = "number_count";
        publisher_ = this->create_publisher<example_interfaces::msg::Int64>(publisher_name_, 10);
        subscriber_ = this->create_subscription<example_interfaces::msg::Int64>(
            "number", 
            10, 
            std::bind(&NumberCounterNode::publishNumber, this, std::placeholders::_1)
            );

        message_.data = 0;
        
        RCLCPP_INFO(this->get_logger(), "Number Counter has been started");
    }


private:
    std::string publisher_name_;
    rclcpp::Publisher<example_interfaces::msg::Int64>::SharedPtr publisher_;
    rclcpp::Subscription<example_interfaces::msg::Int64>::SharedPtr subscriber_;
    example_interfaces::msg::Int64 message_ = example_interfaces::msg::Int64();


    void publishNumber(const example_interfaces::msg::Int64::SharedPtr msg)
    {
        message_.data += msg->data;
        publisher_->publish(message_);
        
    }

};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<NumberCounterNode>(); // MODIFY NAME
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
