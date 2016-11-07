/* ********************************************************************************
* Copyright (c) <Yingbing Chen>. All rights reserved.
* FileName: dw_approach.cpp
* Contact:
*
* LICENSING TERMS:
* This Code Have been contributed to The HandsFree team, And The Hands Free is
* licensed generally under a permissive 3-clause BSD license.
*                                   HadnsFree team Exchange Group -- 521037187
*
* Author: chenyingbing
* Time: 20161107   10:49   in XIAMEN University
* Illustration:
*      A*Route + Static Map(+ Safe Area) + DynamicWindowsApproach(DWA) + gmapping/hectormapping
* 
* ********************************************************************************/

# PaperSimu_XYi_WS
simulation environment:	 stage_ros
handsfree robot:	 handsfree team's robot
xiaoyi_robot: 		 private robot(chenyingbing)

>> tf_tree	
		map_r		

		odom_r				

		base_footprint_r		

		base_link_r			

		base_laser_link_r		
	
>> rostopics list
	/RobotPort_CmdVel	<geometry_msgs::Twist>
	/RobotPort_FilterScan	<sensor_msgs::LaserScan>	Out
	/RobotPort_Scan		<sensor_msgs::LaserScan>	Orin Out

	/RobotPort_Odom 	<nav_msgs::Odometry>	: unaccomplished
		: the final odom dta

more details see the xyi_ws/src/ReadMe
