# hello_moveit/launch/full_system.launch.py
import os
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    # Get paths to config files
    hello_moveit_dir = get_package_share_directory('hello_moveit')
    ur_moveit_config_dir = get_package_share_directory('ur_moveit_config')
    
    # Kinematics config (with proper structure)
    kinematics_config = os.path.join(hello_moveit_dir, 'config', 'kinematics.yaml')
    
    # UR Driver launch
    ur_driver_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(get_package_share_directory('ur_robot_driver'), 'launch', 'ur_control.launch.py')
        ),
        launch_arguments={
            'ur_type': 'ur5e',
            'robot_ip': '192.168.1.5',
            'launch_rviz': 'false',
            'calibration_controller': '/home/new_ws/src/hello_moveit/config/my_robot_calibration.yaml'
        }.items()
    )
    
    # MoveIt launch with custom kinematics config
    moveit_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(ur_moveit_config_dir, 'launch', 'ur_moveit.launch.py')
        ),
        launch_arguments={
            'ur_type': 'ur5e',
            'launch_rviz': 'true',
            'kinematics_config': kinematics_config  # Inject kinematics config
        }.items()
    )
    
    # Your node
    hello_node = Node(
        package='hello_moveit',
        executable='hello_moveit',
        name='hello_moveit',
        output='screen',
        parameters=[kinematics_config]
    )
    
    return LaunchDescription([
        ur_driver_launch,
        moveit_launch,
        hello_node
    ])