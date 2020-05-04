# RoboND_GoChaseIt
Submission for Project 2 of Udacity Robotics Nanodegree: robot design to locate and follow a white ball around a Gazebo world using ROS.

### Directory Structure
This project is intended to be built within a [catkin workspace](http://wiki.ros.org/catkin/workspaces#Catkin_Workspaces). To build, clone this repo into the `catkin_ws/src` folder and run `catkin_make`.

```
    .src                        
    ├── ball_chaser                  
    │   ├── launch
    │   │   ├── ball_chaser.launch   
    │   ├── src             	  
    │   │   ├── drive_bot.cpp         
    │   │   ├── process_image.cpp	
    │   ├── srv            	  
    │   │   ├── DriveToTarget.srv     
    │   ├── CMakeLists.txt      		  
    │   ├── package.xml     		  
    ├── my_robot                       
    │   ├── launch
    │   │   ├── robot_description.launch    
    │   │   ├── world.launch
    │   ├── meshes             	  
    │   │   ├── hokuyo.dae           
    │   ├── urdf
    │   │   ├── my_robot.gazebo
    │   │   ├── my_robot.xacro
    │   ├── worlds
    │   │   ├── simple-building.world 
    │   ├── CMakeLists.txt      		  
    │   ├── package.xml     		  
    ├── CMakeLists.txt                 
                             
```
