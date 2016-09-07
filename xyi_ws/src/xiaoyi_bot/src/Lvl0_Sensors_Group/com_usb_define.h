#ifndef __usb_com_define_H
#define __usb_com_define_H

	#include "../ROBOT_DFINE.h"

	// const , can't not be modify!!!
	#define Simulation_En		0
	#define Turtlesim_KeyEn		0

	// define the k to modify the speed
	#define velocity_k		1.0f	//0.05f
	#define gyro_k			1.0f	//0.2f

	// In:	
    #define Topics_Cmd          "/RobotPort_CmdVel"             // geometry_msgs::Twist
	#define Topics_PosiCmd		"/RobotPort_PosiCmd"			// geometry_msgs::Point32
	
	// Out:
    #define Topics_Ack          "/RobotPort_Ack"                // std_msgs::Int8
    #define Topics_RTOSOdom     "/RobotPort_TmpOdom"            // nav_msgs::Odometry

    // unused but remained
    #define Topics_RTOSPoint	"/RobotPort_TmpPoint"			// geometry_msgs::Point32
    #define Topics_RTOSTwist	"/RobotPort_Twist"              // geometry_msgs::Twist


#endif


