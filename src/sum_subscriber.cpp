#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32_multi_array.hpp"

class SumSubscriber : public rclcpp::Node
{
public:
  SumSubscriber() : Node("sum_subscriber")
  {
    subscription_ = this->create_subscription<std_msgs::msg::Int32MultiArray>(
      "random_numbers", 10, std::bind(&SumSubscriber::handleNumbers, this, std::placeholders::_1));
  }

private:
  void handleNumbers(const std_msgs::msg::Int32MultiArray::SharedPtr msg)
  {
    int sum = msg->data[0] + msg->data[1];
    RCLCPP_INFO(this->get_logger(), "Received: [%d, %d], Sum: %d", msg->data[0], msg->data[1], sum);
  }

  rclcpp::Subscription<std_msgs::msg::Int32MultiArray>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SumSubscriber>());
  rclcpp::shutdown();
  return 0;
}
