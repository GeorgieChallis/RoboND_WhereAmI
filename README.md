# RoboND _ Where Am I?
[WIP] Submission for Project 3 of Udacity Robotics Nanodegree: Implement Adaptive Monte Carlo Localisation (AMCL) algorithm to localise a robot in a pre-generated map. Particle position and orientation are shown as blue arrows in RViz - as the robot localises in the environment, the number of particles will reduce to a single arrow indicating the localised pose.

### Build
This project is intended to be built within a [catkin workspace](http://wiki.ros.org/catkin/workspaces#Catkin_Workspaces). To build, clone this repo into the `catkin_ws/src` folder and run `catkin_make`.

## Run
After sourcing `setup.bash`, if not already in `.bashrc`:
```
$ roslaunch my_robot world.launch
$ roslaunch my_robot amcl.launch
```
<img src="https://github.com/GeorgieChallis/RoboND_WhereAmI/blob/master/my_robot/img/AMCL.jpg" width="640">
