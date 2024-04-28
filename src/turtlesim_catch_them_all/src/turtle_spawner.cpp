#include "rclcpp/rclcpp.hpp"
#include "turtlesim/srv/spawn.hpp"
#include "my_robot_interfaces/srv/catched_turtle.hpp"
#include "my_robot_interfaces/msg/turtle.hpp"
#include "my_robot_interfaces/msg/turtle_array.hpp"

#include <random>

unsigned int seed = 1;
std::default_random_engine generator(seed);
std::uniform_real_distribution<double> dist(0.0, 11.0);



class TurtleSpawner : public rclcpp::Node // MODIFY NAME
{
public:
    TurtleSpawner() : Node("turtle_spawner") // MODIFY NAME
    {

        spawn_timer_ = this->create_wall_timer(std::chrono::seconds(1), std::bind(&TurtleSpawner::spawnTurtle, this));
        live_turtles_timer_ = this->create_wall_timer(std::chrono::seconds(1), std::bind(&TurtleSpawner::publishLiveTurtles, this));
        
        
        client_ = this->create_client<turtlesim::srv::Spawn>("spawn");
        catched_turtle_service_ = this->create_service<my_robot_interfaces::srv::CatchedTurtle>("catched_turtle", std::bind(&TurtleSpawner::catchedTurtle, this, std::placeholders::_1, std::placeholders::_2));

        live_turtles_publisher_ = this->create_publisher<my_robot_interfaces::msg::TurtleArray>("live_turtles", 10);
          
    }

private:

    


    std::map<std::string,my_robot_interfaces::msg::Turtle> turtles; // need to change into sorted map
    my_robot_interfaces::msg::Turtle turtle;

    rclcpp::TimerBase::SharedPtr spawn_timer_;
    rclcpp::TimerBase::SharedPtr live_turtles_timer_;

    rclcpp::Client<turtlesim::srv::Spawn>::SharedPtr client_;
    rclcpp::Publisher<my_robot_interfaces::msg::TurtleArray>::SharedPtr live_turtles_publisher_;
    rclcpp::Service<my_robot_interfaces::srv::CatchedTurtle>::SharedPtr catched_turtle_service_;

    turtlesim::srv::Spawn::Request request;
    
    unsigned int id = 2;

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
        
        turtle.name = name;
        turtle.x = request.x;
        turtle.y = request.y;

        turtles[name] = turtle;

        auto future = client_->async_send_request(std::make_shared<turtlesim::srv::Spawn::Request>(request));
        
        id++;
    }

    void publishLiveTurtles()
    {
        my_robot_interfaces::msg::TurtleArray msg;
        for (auto const& turtle : turtles)
        {
            msg.turtles.push_back(turtle.second);
        }
        live_turtles_publisher_->publish(msg);
    }

    void catchedTurtle(const std::shared_ptr<my_robot_interfaces::srv::CatchedTurtle::Request> request,
                        std::shared_ptr<my_robot_interfaces::srv::CatchedTurtle::Response> response)
    {
        if (turtles.find(request->name) != turtles.end())
        {
            turtles.erase(request->name);
            response->success = true;
        }
        else
        {
            response->success = false;
        }
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
