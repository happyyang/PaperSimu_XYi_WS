# PaperSimu_XYi_WS
simulation environment 

launch file:
	simu_bot.launch: 	stage_ros
	xiaoyi_bot.launch:	yingbing's robot
	
pkg or include files require:
	1: pkg		laser_filters	stage_ros  tf and so on
	2: include 	/usr/include/eigen3

>> tf_tree	<bot part>			<simuation remained>
		map_r(unaccomplished)		

		odom_r				odom

		base_footprint_r		base_footprint

		base_link_r			base_link

		base_laser_link_r		base_laser_link
	
>> rostopics list
	/RobotPort_CmdVel	<geometry_msgs::Twist>
	/RobotPort_FilterScan	<sensor_msgs::LaserScan>	Out
	/RobotPort_Scan		<sensor_msgs::LaserScan>	Orin Out

	/RobotPort_TmpOdom 	<nav_msgs::Odometry>
		: the tempalate odom dta
			the integral of the robot odom + robot twist(simulation can't offer twist data)
			you use it to caculate the final odom dta: "/RobotPort_Odom"

	/RobotPort_Odom 	<nav_msgs::Odometry>	: unaccomplished
		: the final odom dta

>> node list
	pkg="xiaoyi_bot" name="Node_Tfmanage" type="tfmanage_node" output="screen">
												                 羽
	1：	offer the basic tf of the tf_tree above, and can be use in simuation and xiaoyi(yingbing's bot 小立)  
	2：	change the frame_id of "/scan_filtered" in simuation. and republish it as "/RobotPort_FilterScan"
