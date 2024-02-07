#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"

class AddTwoIntsClientNode : public rclcpp::Node // MODIFY NAME
{
public:
    AddTwoIntsClientNode() : Node("node_name") // MODIFY NAME
    {

        threads_.push_back(std::thread
                            (
                                std::bind(&AddTwoIntsClientNode::callbackAddTwoInts, this, 3, 2021)
                            )
            );
    }

private:

    std::vector<std::thread> threads_;

    void callbackAddTwoInts(int a,int b)
    {
        auto client = this->create_client<example_interfaces::srv::AddTwoInts>("add_two_ints");
        while (!client->wait_for_service(std::chrono::seconds(1)))
        {
            if (!rclcpp::ok())
            {
                RCLCPP_ERROR(this->get_logger(), "Interrupted while waiting for the service. Exiting.");
                return;
            }
            RCLCPP_INFO(this->get_logger(), "service not available, waiting again...");
        }
        auto request = std::make_shared<example_interfaces::srv::AddTwoInts::Request>();
        request->a = a;
        request->b = b;

        auto future = client->async_send_request(request);

        try
        {
            auto result = future.get();
            RCLCPP_INFO(this->get_logger(), "Result of %ld + %ld = %ld", request->a, request->b, result->sum);
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
    auto node = std::make_shared<AddTwoIntsClientNode>(); // MODIFY NAME
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
