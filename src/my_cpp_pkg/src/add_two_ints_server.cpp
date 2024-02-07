#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"

class AddTwoIntsServerNode : public rclcpp::Node // MODIFY NAME
{
public:
    AddTwoIntsServerNode() : Node("add_two_ints_server") // MODIFY NAME
    {
        server_ = this->create_service<example_interfaces::srv::AddTwoInts>
        (
            "add_two_ints", 
            std::bind(&AddTwoIntsServerNode::callback, this, std::placeholders::_1, std::placeholders::_2)
        );
    }

private:
    void callback(
        const example_interfaces::srv::AddTwoInts::Request::SharedPtr request,
        example_interfaces::srv::AddTwoInts::Response::SharedPtr response
    )
    {
        response->sum = request->a + request->b;
        RCLCPP_INFO(this->get_logger(), "Incoming request\na: %ld" " b: %ld", request->a, request->b);
        RCLCPP_INFO(this->get_logger(), "Sending back response: %ld", response->sum);
    }
    rclcpp::Service<example_interfaces::srv::AddTwoInts>::SharedPtr server_;


};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<AddTwoIntsServerNode>(); // MODIFY NAME
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
