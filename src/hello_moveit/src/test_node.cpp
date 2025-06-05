#include <memory>

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



    auto const target_pose = []{
      geometry_msgs::msg::Pose msg;
      msg.orientation.w = 1.0;
      msg.position.x = -0.515;
      msg.position.y = -0.265;
      msg.position.z = 0.256;
      return msg;
    }();


    std::cout << "SetTargetPose============================================================================================1" << std::endl;

    move_group_interface.setPoseTarget(target_pose);

    std::cout << "SetPoseTarget============================================================================================1" << std::endl;

    // Create a plan to that target pose
    auto const [success, plan] = [&move_group_interface]
    {
        moveit::planning_interface::MoveGroupInterface::Plan msg;
        auto const ok = static_cast<bool>(move_group_interface.plan(msg));
        return std::make_pair(ok, msg);
    }();

    // Print the planning result
    if (success)
    {
        RCLCPP_INFO(logger, "Planning succeeded!");
        std::cout << "Planning succeeded!============================================================================================1" << std::endl;
    }
    else
    {
        RCLCPP_ERROR(logger, "Planning failed!");
        std::cout << "Planning failed!============================================================================================1" << std::endl;
        rclcpp::shutdown();
        return 1;
    }
    // Print the plan details
    std::cout << "Plan details:" << std::endl;
    std::cout << "Start state: " << plan.start_state.joint_state.name.size() << " joints" << std::endl;
    std::cout << "Trajectory: " << plan.trajectory.joint_trajectory.points.size() << " points" << std::endl;
    std::cout << "Planning time: " << plan.planning_time << " seconds" << std::endl;
    // Print the trajectory
    std::cout << "Trajectory points:" << std::endl;
    for (const auto &point : plan.trajectory.joint_trajectory.points)
    {
        std::cout << "  Time: " << point.time_from_start.sec << " seconds, Positions: ";
        for (const auto &position : point.positions)
        {
            std::cout << position << " ";
        }
        std::cout << std::endl;
    }
    // Print the plan as a string

    std::cout << "CreatedPlan============================================================================================1" << std::endl;

    // Execute the plan
    if (success)
    {
        move_group_interface.execute(plan);
        std::cout << "Success============================================================================================1" << std::endl;
    }
    else
    {
        RCLCPP_ERROR(logger, "Planning failed!");
    }

    // Shutdown ROS
    std::cout << "Im============================================================================================1" << std::endl;

    rclcpp::shutdown();
    return 0;
}
