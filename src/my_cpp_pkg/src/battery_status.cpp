#include "rclcpp/rclcpp.hpp"
#include "my_robot_interfaces/srv/set_led.hpp"

class BatteryClientNode : public rclcpp::Node // MODIFY NAME
{
public:
    BatteryClientNode() : Node("battery_status") // MODIFY NAME
    {

        threads_.push_back(std::thread
                            (
                                std::bind(&BatteryClientNode::callbackBatteryStatus, this)
                            )
            );
    }

private:

    std::vector<std::thread> threads_;

    void callbackBatteryStatus()
    {
        auto client = this->create_client<my_robot_interfaces::srv::SetLed>("set_led");
        

        while (1)
        {
            //battery full status
            batteryStatus(client, 3, false);
            RCLCPP_INFO(this->get_logger(), "Battery full status");
            //runs 4 seconds
            std::this_thread::sleep_for(std::chrono::seconds(4));

            //battery empty status
            batteryStatus(client, 3, true);
            RCLCPP_INFO(this->get_logger(), "Battery empty status");
            //wait 6 seconds
            std::this_thread::sleep_for(std::chrono::seconds(6));
        }
        
   
    }

    void batteryStatus(std::shared_ptr<rclcpp::Client<my_robot_interfaces::srv::SetLed>> &client, u_int8_t led_number, bool state)
    {
  
        while (!client->wait_for_service(std::chrono::seconds(1)))
        {
            if (!rclcpp::ok())
            {
                RCLCPP_ERROR(this->get_logger(), "Interrupted while waiting for the service. Exiting.");
                return;
            }
            RCLCPP_INFO(this->get_logger(), "service not available, waiting again...");
        }
        auto request = std::make_shared<my_robot_interfaces::srv::SetLed::Request>();
        request->led_number = led_number;
        request->state = state;

        auto future = client->async_send_request(request);

        try
        {
            auto result = future.get();
            RCLCPP_INFO(this->get_logger(), "Result of service call: %d", result->success);
        }
        catch (const std::exception &e)
        {
            RCLCPP_ERROR(this->get_logger(), "Service call failed");
        }

    }


};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<BatteryClientNode>(); // MODIFY NAME
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
