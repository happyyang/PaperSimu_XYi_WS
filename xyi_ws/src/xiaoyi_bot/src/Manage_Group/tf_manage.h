#ifndef __tf_manage_H
#define __tf_manage_H

    // Sys Part **********************************************/
    #include <ros/ros.h>
    #include <sstream>
    #include <iostream>
    #include <string>
    using namespace std;

    // C_Plus Standard Library *******************************/
    #include <algorithm>
    #include <signal.h>
    #include <c++/4.8/vector>

    // Math Part *********************************************/
    #include "eigen3/Eigen/Dense"
    #include "eigen3/Eigen/Geometry"
    using namespace Eigen;

    // This be done in particular code file...
    // Image Part ********************************************/
    //#include <cv_bridge/cv_bridge.h>
    //#include <image_transport/image_transport.h>
    //#include <opencv2/imgproc/imgproc.hpp>
    //#include <opencv2/highgui/highgui.hpp>

    // TF Part ****************************************************************/
    #include "tf/transform_broadcaster.h"
    #include "tf/transform_listener.h"

    // Topics Part ************************************************************/
    #include "std_msgs/String.h"
    #include "nav_msgs/Odometry.h"
    #include "nav_msgs/OccupancyGrid.h"
    #include "sensor_msgs/LaserScan.h"
    #include "sensor_msgs/PointCloud.h"
    #include "sensor_msgs/ChannelFloat32.h"
    #include "geometry_msgs/Twist.h"
    #include "geometry_msgs/Point.h"
    #include "geometry_msgs/Point32.h"
    #include "geometry_msgs/Quaternion.h"
    #include "geometry_msgs/Pose.h"
    #include "geometry_msgs/PoseStamped.h"
    #include "geometry_msgs/PoseArray.h"

#endif


