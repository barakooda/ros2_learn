#include "rclcpp/rclcpp.hpp"

class MyNode : public rclcpp::Node
{
private:
    int counter_ ;
    rclcpp::TimerBase::SharedPtr timer_;

    void timer_callback()
    {
        
        RCLCPP_INFO(this->get_logger(),"Hello from barak node! %d !!!",counter_);
        counter_++;
    }

public:
    MyNode() : Node("cpp_test"),counter_(0)
    {
    //RCLCPP_INFO(this->get_logger(),"Hello %d !",counter_);
    
    timer_ = this->create_wall_timer(std::chrono::seconds(1),std::bind(&MyNode::timer_callback,this));
    }
};


int main(int argc,char **argv)
{
    rclcpp::init(argc,argv);
    auto node = std::make_shared<MyNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}