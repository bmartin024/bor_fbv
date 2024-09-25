cmake_minimum_required(VERSION 3.5)
project(bor_fbv)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(random_number_publisher src/random_number_publisher.cpp)
add_executable(sum_subscriber src/sum_subscriber.cpp)

ament_target_dependencies(random_number_publisher rclcpp std_msgs)
ament_target_dependencies(sum_subscriber rclcpp std_msgs)

install(TARGETS
  random_number_publisher
  sum_subscriber
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}/)

ament_package()
