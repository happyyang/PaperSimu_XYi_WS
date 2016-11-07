#ifndef __pkg_include_H
#define __pkg_include_H

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

    // Image Part ********************************************/
    #include <cv.h>
    #include <cv_bridge/cv_bridge.h>
    #include <image_transport/image_transport.h>
    #include <opencv2/imgproc/imgproc.hpp>
    #include <opencv2/highgui/highgui.hpp>
    #include <sensor_msgs/image_encodings.h>
    #include <image_transport/image_transport.h>

    // TF Part ***********************************************/
    #include "tf/transform_broadcaster.h"
    #include "tf/transform_listener.h"

    // Self-Define Data Type Part ****************************/
    #include "pkg_data.h"

    #include "map_s_algorithm/map_s_datatype.h"
    #include "a_star_algorithm/a_star_datatype.h"
    #include "dw_approach/dw_approach_datatype.h"


#endif
