#include "rclcpp/rclcpp.hpp"
#include "my_robot_interfaces/srv/set_led.hpp"
#include "my_robot_interfaces/msg/led_status.hpp"

class LedPanelServerNode : public rclcpp::Node // MODIFY NAME
{
public:
    LedPanelServerNode() : Node("led_panel") // MODIFY NAME
    {

        this->declare_parameter("led_status", std::vector<bool>{false, false, false});
        
        for(int i = 0;i<3;i++) {
            led_status.led_status[i] =
            this->get_parameter("led_status").as_bool_array()[i];
        }
        
        publisher_ = this->create_publisher<my_robot_interfaces::msg::LedStatus>("led_status", 10);

        server_ = this->create_service<my_robot_interfaces::srv::SetLed>
        (
            "set_led", 
            std::bind(&LedPanelServerNode::callback, this, std::placeholders::_1, std::placeholders::_2)
        );
    }

private:


    void callback(
        const my_robot_interfaces::srv::SetLed_Request::SharedPtr request,
        my_robot_interfaces::srv::SetLed_Response::SharedPtr response
    )
    {
        
        led_status.led_status[request->led_number-1] = request->state;
        response->success = true;
        publisher_->publish(led_status);

        RCLCPP_INFO(this->get_logger(), "sending response: %d", response->success);
        for (int i = 0; i < 3; i++)
        {
            RCLCPP_INFO(this->get_logger(), "led_status[%d]: %d", i, led_status.led_status[i]);
        }
    }
    
    rclcpp::Publisher <my_robot_interfaces::msg::LedStatus>::SharedPtr publisher_ = this->create_publisher<my_robot_interfaces::msg::LedStatus>("led_status", 10);
    rclcpp::Service<my_robot_interfaces::srv::SetLed>::SharedPtr server_;
    my_robot_interfaces::msg::LedStatus led_status;


};

int main(int argc, char **argv)
{
    
    rclcpp::init(argc, argv);
    auto node = std::make_shared<LedPanelServerNode>(); // MODIFY NAME
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
