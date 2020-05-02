#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>

// Define a global client that can request services
ros::ServiceClient client;

// This function calls the command_robot service to drive the robot in the specified direction
void drive_robot(float lin_x, float ang_z)
{
    // Request a service and pass the velocities to it to drive the robot
    ROS_INFO_STREAM("Driving robot...");

    // Request velocities
    ball_chaser::DriveToTarget srv;
    srv.request.linear_x = lin_x;
    srv.request.angular_z = ang_z;

    // Call the safe_move service and pass the requested velocities
    if (!client.call(srv))
        ROS_ERROR("Failed to call service command_robot");

}

// This callback function continuously executes and reads the image data
void process_image_callback(const sensor_msgs::Image img)
{
    ROS_INFO_STREAM("Image callback...");
    ROS_INFO_STREAM("Width: " << img.width);
    ROS_INFO_STREAM("Height: " << img.height);
    ROS_INFO_STREAM("Step: " << img.step);
    ROS_INFO_STREAM("Data size: " << img.data.size());
    
    int white_pixel = 255;
    int image_size = img.height * img.step;
    bool white_detected = false;

    float x_val, z_val = 0.0;
    bool moving = false;

    for (int i = 0; i < image_size; i++){
      if (img.data[i] == 255){
	  white_detected = true;
	  if (i <= img.step*0.3){
	   // go left
	   x_val = 0.0;
	   z_val = 0.5;
	   moving = true;
	  }
	  else if (i <= img.step*0.6){
           // go forwards
	   x_val = 0.5;
	   z_val = 0.0;
	   moving = true;
	  }
          else {
	   // go right
	   x_val = 0.0;
	   z_val = -0.5;
	   moving = true;
	  }
	drive_robot(x_val, z_val);
	break;
	}
      else { if (moving) drive_robot(0.0, 0.0);}
    }
}

int main(int argc, char** argv)
{
    // Initialize the process_image node and create a handle to it
    ros::init(argc, argv, "process_image");
    ros::NodeHandle n;

    // Define a client service capable of requesting services from command_robot
    client = n.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");

    // Subscribe to /camera/rgb/image_raw topic to read the image data inside the process_image_callback function
    ros::Subscriber sub1 = n.subscribe("/camera/rgb/image_raw", 10, process_image_callback);
    ROS_INFO_STREAM("Camera subscriber created.");

    // Handle ROS communication events
    ros::spin();

    return 0;
}
