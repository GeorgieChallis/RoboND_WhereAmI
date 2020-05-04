# RoboND_GoChaseIt
Submission for Project 2 of Udacity Robotics Nanodegree: robot design to locate and follow a white ball around a Gazebo world using ROS.

### Directory Structure
```
    .src                              # src folder within Catkin Workspace            
    ├── ball_chaser                   # ball_chaser package         
    │   ├── launch
    │   │   ├── ball_chaser.launch    # Launch 2 nodes in this package
    │   ├── src             	  
    │   │   ├── drive_bot.cpp         # Node for controlling robot movement
    │   │   ├── process_image.cpp		  # Node for processing camera feed to detect object
    │   ├── srv            	  
    │   │   ├── DriveToTarget.srv     # Service for driving the robot model
    │   ├── CMakeLists.txt      		  
    │   ├── package.xml     		  
    ├── my_robot                      # Robot package files    
    │   ├── launch
    │   │   ├── robot_description.launch    
    │   │   ├── world.launch
    │   ├── meshes             	  
    │   │   ├── hokuyo.dae            # Lidar mesh
    │   ├── urdf
    │   │   ├── my_robot.gazebo
    │   │   ├── my_robot.xacro
    │   ├── worlds
    │   │   ├── simple-building.world  # From Project 1
    │   ├── CMakeLists.txt      		  
    │   ├── package.xml     		  
    ├── CMakeLists.txt                 # Link libraries 
                             
```
