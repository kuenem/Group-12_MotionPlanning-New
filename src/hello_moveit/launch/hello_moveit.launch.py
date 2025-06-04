import os
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    # Get path to kinematics.yaml
    hello_moveit_dir = get_package_share_directory('hello_moveit')
    kinematics_config = os.path.join(hello_moveit_dir, 'config', 'kinematics.yaml')
    
    # Ensure the file exists
    if not os.path.exists(kinematics_config):
        raise RuntimeError(f"kinematics.yaml not found at {kinematics_config}")
    
    return LaunchDescription([
        Node(
            package='hello_moveit',
            executable='hello_moveit',
            name='hello_moveit',
            output='screen',
            parameters=[
                kinematics_config,  # Load kinematics config
                # Add other parameters if needed
            ]
        )
    ])