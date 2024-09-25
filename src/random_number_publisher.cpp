#include <chrono>
#include <cstdlib>
#include <ctime>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32_multi_array.hpp"

using namespace std::chrono_literals;

class RandomNumberPublisher : public rclcpp::Node
{
public:
  RandomNumberPublisher() : Node("random_number_publisher")
  {
    publisher_ = this->create_publisher<std_msgs::msg::Int32MultiArray>("random_numbers", 10);
    timer_ = this->create_wall_timer(1000ms, std::bind(&RandomNumberPublisher::publishNumbers, this));
    std::srand(std::time(0));
  }

private:
  void publishNumbers()
  {
    auto message = std_msgs::msg::Int32MultiArray();
    message.data = {std::rand() % 100 + 1, std::rand() % 100 + 1};
    RCLCPP_INFO(this->get_logger(), "Publishing: [%d, %d]", message.data[0], message.data[1]);
    publisher_->publish(message);
  }

  rclcpp::Publisher<std_msgs::msg::Int32MultiArray>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<RandomNumberPublisher>());
  rclcpp::shutdown();
  return 0;
}
