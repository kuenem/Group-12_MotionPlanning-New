## 1. Connect the robot
### Connecting with actual robot
Just connect pc with the ethernet cable from the robot
Most likely IP robot will be using is 192.168.1.102, so consider it as your robot IP

### Emulating robot connection, without the actual robot
If you want to work on emulation you can do all the same things, but instead of connecting robot and using actual Polyscope tablet you will have to emulate it.
You can launch polyscope emulator with the following command:

```console
ros2 run ur_client_library start_ursim.sh
```

By default emulator uses IP 192.168.56.101, so consider it as your IP, if you are using an emulator


## 2. Open Robot Polyscope And do all following steps:
(Polyscope is the robot's tablet)
* Settings -> System -> Network -> set:
    ```
    IP address: <robot_ip>
    Subnet mask: 255.255.255.0
    Default gateway: 192.168.1.1
    Preferred DNS server: 192.168.1.1
    Alternative DNS server: 0.0.0.0
    ```
    (Note that the IP address you are setting here will be used to refer to the robot later)
* Installation -> URCaps -> External Control -> specify pc ip and pc name. <br>
    You can get pc IP by running
    ```console
    ip a
    ```
    And pc name by running:
    ```console
    hostname
    ```
    
Computer's ip is most likely 192.168.1.101
Computer's ip is not really important: Important is that robot-ip != computer's-ip (Might be smart to use something besides 1;2;3 as end number e.g. 5) Furthermore Default gateway and preferred DNS server seem to should be the same as robots-ip

* Program -> Add External Control URCap to the robot program (And start the robot (Bottom left on off then turn it on and start it afterwards) and the program (right center play button))

## 3. Launch ur_robot_driver
This launches robot's driver and rviz vizualisation of your robot, note that it cannot be used to make any planning.
```console
ros2 launch ur_robot_driver ur_control.launch.py ur_type:=ur5e robot_ip:=<robot_ip>
```
Keep in mind that this ip is the same ip we set earlier

This node runs connection between computer and robot, so don't close it, unless you want your connection to be interrupted

## 4. Check communication
Ping robot. If pinging is successful then communication with the robot is set up.
```console
ping <robot_ip>
```

Also you can try moving robot manually in Polyscope. If it also changes location in the ur_robot_driver rviz - everything is working good.


## 5. Launching Moveit rviz
If you want to control your robot with Moveit rviz, run the following command:
```console
ros2 launch ur_moveit_config ur_moveit.launch.py ur_type:=ur5e launch_rviz:=true
```

Don't confuse it with the ur_robot_driver which is also running in rviz

## 6. Testing movement
For this section check that your robot in it's 'resting' state. For our robot it is
[0, -90, 0, -90, 0, 0]
(You can adjust it in move menu in the Polyscope)

After you launched and set up everything above - you can try launching following test script:
```
ros2 launch ur_robot_driver test_scaled_joint_trajectory_controller.launch.py
```

If everything is correct your robot arm should start moving 
## 7. Additional info
source files for demo from previous part: /opt/ros/jazzy/share/ur_robot_driver/launch <br>
description of ur5e robot properties: /opt/ros/jazzy/share/ur_description/config/ur5e <br>
UR config files for moveit: /opt/ros/jazzy/share/ur_moveit_config/config	

Scanner manual: https://docs.clearpathrobotics.com/assets/files/clearpath_robotics_023729-TDS2-2c7454cf9f317be53ce1938dca7ddcf4.pdf
