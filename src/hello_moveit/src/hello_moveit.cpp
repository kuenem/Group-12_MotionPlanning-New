#include <memory>

#include <rclcpp/rclcpp.hpp>
#include <moveit/move_group_interface/move_group_interface.hpp>
#include "controller_manager_msgs/srv/switch_controller.hpp"

int main(int argc, char * argv[])
{

    std::cout << "Starting============================================================================================1" << std::endl;
  // Initialize ROS and create the Node
  rclcpp::init(argc, argv);

  // Spin up a SingleThreadedExecutor for MoveItVisualTools to interact with ROS
  rclcpp::executors::SingleThreadedExecutor executor;
  auto spinner = std::thread([&executor]()
                             { executor.spin(); });


    std::cout << "ROSinitialised============================================================================================1" << std::endl;

  auto const node = std::make_shared<rclcpp::Node>(
    "hello_moveit",
    rclcpp::NodeOptions().automatically_declare_parameters_from_overrides(true)
  );

  // Create a ROS logger
  auto const logger = rclcpp::get_logger("hello_moveit");
  RCLCPP_INFO(logger, "Node initialized");

// Create the MoveIt MoveGroup Interface
// using moveit::planning_interface::MoveGroupInterface;
// auto move_group_interface = MoveGroupInterface(node, "ur_manipulator");

//     RCLCPP_INFO(logger, "MoveGroup interface created for group: %s", 
//                 move_group_interface.getName().c_str());

//     // Start state monitor
//     move_group_interface.startStateMonitor();
//     RCLCPP_INFO(logger, "Started state monitor");

    moveit::planning_interface::MoveGroupInterface move_group_interface(node, "ur_manipulator");
    if (!move_group_interface.getRobotModel()) {
        RCLCPP_ERROR(logger, "Failed to get robot model!");
        rclcpp::shutdown();
        return 1;
    }
    RCLCPP_INFO(logger, "MoveGroup interface created for group: %s", 
                move_group_interface.getName().c_str());
    RCLCPP_INFO(logger, "Robot model: %s",
                move_group_interface.getRobotModel()->getName().c_str());


    std::cout << "MoveGroupInterfaceCreated============================================================================================1" << std::endl;

    // // Diagnostic: Check for joint_states topic
    // bool has_joint_states = false;
    // for (const auto& [name, types] : topic) {
    //     if (name == "/joint_states") {
    //         has_joint_states = true;
    //         break;
    //     }
    // }
    // RCLCPP_INFO(logger, has_joint_states ? 
    //             "Found /joint_states topic" : "MISSING /joint_states topic");


    // // Wait for current state with timeout
    // RCLCPP_INFO(logger, "Waiting for current robot state...");
    // auto start_time = std::chrono::steady_clock::now();
    // bool state_received = false;
    
    // while (rclcpp::ok() && 
    //        std::chrono::steady_clock::now() - start_time < std::chrono::seconds(20)) {
    //     auto current_state = move_group_interface.getCurrentState(1.0);
    //     if (current_state) {
    //         state_received = true;
    //         RCLCPP_INFO(logger, "Current state received after %.1f seconds", 
    //             std::chrono::duration<double>(std::chrono::steady_clock::now() - start_time).count());
            
    //         // Print current joint values
    //         const auto& joint_names = current_state->getJointModelGroup("ur_manipulator")->getJointModelNames();
    //         std::cout << "\nCurrent Joint Positions:" << std::endl;
    //         for (const auto& name : joint_names) {
    //             std::cout << "  " << name << ": " 
    //                       << (*current_state->getJointPositions(name))[0] << " rad" << std::endl;
    //         }
    //         break;
    //     }
    //     rclcpp::sleep_for(std::chrono::milliseconds(100));
    //  }

    // if (!state_received) {
    //     RCLCPP_ERROR(logger, "Failed to get current state after 20 seconds!");
        
    //     // Additional diagnostics
    //     RCLCPP_ERROR(logger, "Check if robot driver is publishing joint states");
    //     RCLCPP_ERROR(logger, "Run: ros2 topic echo /joint_states");
    //     RCLCPP_ERROR(logger, "Ensure controller_manager is running");
        
    //     rclcpp::shutdown();
    //     return 1;
    // }



rclcpp::sleep_for(std::chrono::seconds(5));  // Wait for state initialization

    std::cout << "Waited10Sec============================================================================================1" << std::endl;

// Verify current state is available
// auto current_state = move_group_interface.getCurrentState(10.0);
// if (!current_state) {
//     RCLCPP_ERROR(logger, "Failed to get current state!");
//     rclcpp::shutdown();
//     return 1;
// }
// Print the current state
// std::cout << "Current state: " << current_state->getRobotModel()->getName() << std::endl;

    std::cout << "CreatedMoveItInterface============================================================================================1" << std::endl;

      // Configure planner parameters
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

if (!controller_manager->wait_for_service(std::chrono::seconds(2))) {
    RCLCPP_ERROR(logger, "Controller manager service not available");
} else {
    auto result = controller_manager->async_send_request(request);
    if (rclcpp::spin_until_future_complete(node, result) != rclcpp::FutureReturnCode::SUCCESS) {
        RCLCPP_ERROR(logger, "Failed to activate controller");
    }
}

// Add this after activating the controller
rclcpp::sleep_for(std::chrono::seconds(1));  // Allow time for activation
// if (!move_group_interface.getControllerName().empty()) {
//     RCLCPP_INFO(logger, "Controller is active: %s", 
//                 move_group_interface.getControllerName().c_str());
// } else {
//     RCLCPP_ERROR(logger, "No active controller found!");
//     rclcpp::shutdown();
//     return 1;
// }

    std::cout << "ControllerActivated============================================================================================1" << std::endl;

auto const target_pose = []{     // Home pose
  geometry_msgs::msg::Pose msg;
  msg.orientation.w = 1.0;
  msg.position.x = -0.001;
  msg.position.y = -0.265;
  msg.position.z = 1.079;
  return msg;
}();

// auto const target_pose = []{
//   geometry_msgs::msg::Pose msg;
//   msg.orientation.w = 1.0;
//   msg.position.x = -0.515;
//   msg.position.y = -0.265;
//   msg.position.z = 0.256;
//   return msg;
// }();

// auto const target_pose = []{
//   geometry_msgs::msg::Pose msg;
//   msg.orientation.w = 1.0;
//   msg.position.x = 0.5;
//   msg.position.y = 0.3;
//   msg.position.z = 0.3;
//   return msg;
// }();
move_group_interface.setPoseTarget(target_pose);

    std::cout << "SetPoseTarget============================================================================================1" << std::endl;


// Create a plan to that target pose
auto const [success, plan] = [&move_group_interface]{
  moveit::planning_interface::MoveGroupInterface::Plan msg;
  auto const ok = static_cast<bool>(move_group_interface.plan(msg));
  return std::make_pair(ok, msg);
}();

// Print the planning result
if (success) {
  RCLCPP_INFO(logger, "Planning succeeded!");
  std::cout << "Planning succeeded!============================================================================================1" << std::endl;
} else {
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
for (const auto& point : plan.trajectory.joint_trajectory.points) {
  std::cout << "  Time: " << point.time_from_start.sec << " seconds, Positions: ";
  for (const auto& position : point.positions) {
    std::cout << position << " ";
  }
  std::cout << std::endl;
}
// Print the plan as a string

    std::cout << "CreatedPlan============================================================================================1" << std::endl;


// Execute the plan
if(success) {
  move_group_interface.execute(plan);
  std::cout << "Success============================================================================================1" << std::endl;

} else {
  RCLCPP_ERROR(logger, "Planning failed!");
}

  // Shutdown ROS
  std::cout << "Im============================================================================================1" << std::endl;

  rclcpp::shutdown();
  return 0;
}
