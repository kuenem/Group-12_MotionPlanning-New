#include <memory>
#include <tf2/LinearMath/Quaternion.h>
// #include <tf2_geometry_msgs/tf2_geometry_msgs.h>

#include <rclcpp/rclcpp.hpp>
#include <moveit/move_group_interface/move_group_interface.hpp>
#include <moveit_msgs/msg/display_robot_state.hpp>
#include "controller_manager_msgs/srv/switch_controller.hpp"

int main(int argc, char *argv[])
{

    std::cout << "Starting============================================================================================1" << std::endl;
    // Initialize ROS and create the Node
    rclcpp::init(argc, argv);

    // Create node and executor
    auto const node = std::make_shared<rclcpp::Node>(
        "hello_moveit",
        rclcpp::NodeOptions().automatically_declare_parameters_from_overrides(true));

    // Spin up a SingleThreadedExecutor for MoveItVisualTools to interact with ROS
    rclcpp::executors::SingleThreadedExecutor executor;
    executor.add_node(node);
    auto spinner = std::thread([&executor]()
                               { executor.spin(); });

    std::cout << "ROSinitialised============================================================================================1" << std::endl;

    // Create a ROS logger
    auto const logger = rclcpp::get_logger("test_node");
    RCLCPP_INFO(logger, "Node initialized");


    moveit::planning_interface::MoveGroupInterface move_group_interface(node, "ur_manipulator");
    RCLCPP_INFO(logger, "MoveGroup interface created for group: %s", move_group_interface.getName().c_str());
    

    // Configure planner parameters
    move_group_interface.startStateMonitor();
    RCLCPP_INFO(logger, "Started state monitor");

    // Wait for joint states with timeout
    RCLCPP_INFO(logger, "Waiting for joint states...");
    auto start_time = std::chrono::steady_clock::now();
    bool state_received = false;

    while (rclcpp::ok() && 
           std::chrono::steady_clock::now() - start_time < std::chrono::seconds(10)) 
    {
        if (move_group_interface.getCurrentState(1.0)) {
            state_received = true;
            break;
        }
        rclcpp::sleep_for(std::chrono::milliseconds(100));
    }

    if (!state_received) {
        RCLCPP_ERROR(logger, "Failed to receive joint states after 10 seconds!");
        rclcpp::shutdown();
        return 1;
    }

    move_group_interface.setPoseReferenceFrame("base");
    move_group_interface.setPlanningTime(10.0);
    std::cout << "setPlanningTime++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    move_group_interface.setNumPlanningAttempts(100);
    std::cout << "setNumPlanningAttemps++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    move_group_interface.setPlannerId("PTP");
    std::cout << "setPlannerId++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;

    move_group_interface.setMaxVelocityScalingFactor(0.2);
    move_group_interface.setMaxAccelerationScalingFactor(0.5);

    std::cout << "Activating the Conroller============================================================================================1" << std::endl;
    
    
    
    // Activate the controller
    auto controller_manager = node->create_client<controller_manager_msgs::srv::SwitchController>(
        "/controller_manager/switch_controller");

    auto request = std::make_shared<controller_manager_msgs::srv::SwitchController::Request>();
    request->activate_controllers = {"scaled_joint_trajectory_controller"};
    request->strictness = request->STRICT;

    if (!controller_manager->wait_for_service(std::chrono::seconds(2)))
    {
        RCLCPP_ERROR(logger, "Controller manager service not available");
    }
    else
    {
        auto result = controller_manager->async_send_request(request);
        if (rclcpp::spin_until_future_complete(node, result, std::chrono::seconds(2)) != 
            rclcpp::FutureReturnCode::SUCCESS) {
            RCLCPP_ERROR(logger, "Failed to activate controller");
        }
        // if (rclcpp::spin_until_future_complete(node, result) != rclcpp::FutureReturnCode::SUCCESS)
        // {
        //     RCLCPP_ERROR(logger, "Failed to activate controller");
        // }
    }

    rclcpp::sleep_for(std::chrono::seconds(1));



    geometry_msgs::msg::Pose target_pose1;
    
    // Convert mm to meters for position
    target_pose1.position.x = -0.460;  // -460 mm
    target_pose1.position.y = -0.265;  // -265 mm
    target_pose1.position.z = -0.131;  // -131 mm

    // Convert Euler angles to quaternion (roll, pitch, yaw)
    // tf2::Quaternion q;
    // q.setRPY(0, 2.2, -2.189);  // RX=0, RY=2.2, RZ=-2.189
    // target_pose1.orientation = tf2::toMsg(q);

    // Set and execute first target
    move_group_interface.setPoseTarget(target_pose1);
    auto const [success1, plan1] = [&move_group_interface]{
        moveit::planning_interface::MoveGroupInterface::Plan msg;
        auto const ok = static_cast<bool>(move_group_interface.plan(msg));
        return std::make_pair(ok, msg);
    }();

    if (!success1) {
        RCLCPP_ERROR(logger, "First planning failed!");
        rclcpp::shutdown();
        return 1;
    }
    move_group_interface.execute(plan1);
    RCLCPP_INFO(logger, "Reached first target position");

    // ========================================================================
    // SECOND MOTION (50 cm upward movement)
    // ========================================================================
    std::vector<geometry_msgs::msg::Pose> waypoints;
    
    // Start from current position
    geometry_msgs::msg::Pose start_pose = move_group_interface.getCurrentPose().pose;
    waypoints.push_back(start_pose);
    
    // Move 50 cm up in base frame (Z direction)
    geometry_msgs::msg::Pose end_pose = start_pose;
    end_pose.position.z += 0.50;  // 50 cm = 0.5 m
    waypoints.push_back(end_pose);

    // Generate Cartesian path
    moveit_msgs::msg::RobotTrajectory trajectory;
    const double jump_threshold = 0.0;  // Disable jump checking
    const double eef_step = 0.01;       // 1 cm resolution
    double fraction = move_group_interface.computeCartesianPath(
        waypoints, eef_step, jump_threshold, trajectory);
    
    RCLCPP_INFO(logger, "Cartesian path: %.2f%% achieved", fraction * 100.0);
    
    if (fraction < 0.9) {
        RCLCPP_ERROR(logger, "Cartesian path planning failed");
        rclcpp::shutdown();
        return 1;
    }

    move_group_interface.execute(trajectory);
    RCLCPP_INFO(logger, "Reached second target position (50 cm upward movement)");

    // Shutdown ROS
    std::cout << "Im============================================================================================1" << std::endl;

    rclcpp::shutdown();
    return 0;
}
