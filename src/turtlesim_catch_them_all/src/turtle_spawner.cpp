#include "rclcpp/rclcpp.hpp"
#include "turtlesim/srv/spawn.hpp"
#include <random>

unsigned int seed = 1;
std::default_random_engine generator(seed);
std::uniform_real_distribution<double> dist(0.0, 11.0);



class TurtleSpawner : public rclcpp::Node // MODIFY NAME
{
public:
    TurtleSpawner() : Node("turtle_spawner") // MODIFY NAME
    {
        turtles["turtle1"] = "turtle1";

        timer_ = this->create_wall_timer(std::chrono::seconds(1), std::bind(&TurtleSpawner::spawnTurtle, this));
        
        client_ = this->create_client<turtlesim::srv::Spawn>("spawn");
        
     
    }

private:

    


    std::unordered_map<std::string, std::string> turtles;
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Client<turtlesim::srv::Spawn>::SharedPtr client_;
    turtlesim::srv::Spawn::Request request;
    unsigned int id = 0;

    void spawnTurtle()
    {

        //check how many turtles are spawned
        if (turtles.size() >= 10)
        {
            RCLCPP_INFO(this->get_logger(), "Maximum number of turtles reached");
            return;
        }
        
           
        request.x = dist(generator);
        request.y = dist(generator);
        request.theta = 0.0;
        
        std::string name = "turtle" + std::to_string(id);
        request.name = name;
        
        turtles[name] = name;

        auto future = client_->async_send_request(std::make_shared<turtlesim::srv::Spawn::Request>(request));
        
        id++;
    }


};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<TurtleSpawner>(); // MODIFY NAME
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
