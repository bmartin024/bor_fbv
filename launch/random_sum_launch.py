from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='bor_fbv',
            executable='random_number_publisher',
            output="screen",
        ),
        Node(
            package='bor_fbv',
            executable='sum_subscriber',
            output="screen",
        )
    ])
