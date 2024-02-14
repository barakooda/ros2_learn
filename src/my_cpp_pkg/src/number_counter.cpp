#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp"
#include "example_interfaces/srv/set_bool.hpp"


class NumberCounterNode : public rclcpp::Node // MODIFY NAME
{

    
public:
    NumberCounterNode() : Node("number_publisher") // MODIFY NAME
    {


        server_ = this->create_service<example_interfaces::srv::SetBool>(
        "reset_counter", 
        std::bind(&NumberCounterNode::resetCounter, this, std::placeholders::_1, std::placeholders::_2)
        );


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
    rclcpp::Service<example_interfaces::srv::SetBool>::SharedPtr server_;
    
    void resetCounter(
        const example_interfaces::srv::SetBool::Request::SharedPtr request,
        example_interfaces::srv::SetBool::Response::SharedPtr response)
    {

        if(request->data)
        {
            message_.data = 0;
            RCLCPP_INFO(this->get_logger(), "Counter has been reset");
            response->success = true;
            response->message = "Counter has been reset";
        }
        else
        {
            RCLCPP_INFO(this->get_logger(), "Counter has not been reset");
            response->success = false;
            response->message = "Counter has not been reset";
        }
    }

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
