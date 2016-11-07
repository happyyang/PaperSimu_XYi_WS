#ifndef __pkg_data_H
#define __pkg_data_H

    #include "geometry_msgs/Pose.h"
    #include "geometry_msgs/Twist.h"
    #include "geometry_msgs/Point.h"
    #include "nav_msgs/OccupancyGrid.h"
    #include "sensor_msgs/LaserScan.h"
    #include "visualization_msgs/Marker.h"
    #include "visualization_msgs/MarkerArray.h"

    typedef struct Int2Array
    {
        int dta0;
        int dta1;
    }Int2Array;

    typedef struct Int1Float2B1Array
    {
        int dta0;
        float dta1;
        float dta2;
        bool dta3;
    }Int1Float1Array;

    typedef struct Float2Array
    {
        float dta0;
        float dta1;
    }float2array;

    typedef struct Float3Array
    {
        float dta0;
        float dta1;
        float dta2;
    }float3array;

    typedef struct Float2B1Array
    {
        float dta0;
        float dta1;
        bool isSta;
    }float2b1array;

    typedef class ParamData
    {
    public:
        //-------------------------------------
        // launch file param
        volatile bool launchparam_init;
        double Robot_Physical_Radius;
        double MapSafe_Robot_Radius;
        int Laser_Dta_BDlen;
        int Laser_Dta_EDlen;

        //-------------------------------------
        // static map param
        volatile bool mapparam_init;
        unsigned int MAP_LEN;
        unsigned int MAP_WIDTH;
        unsigned int MAP_HEIGHT;
        geometry_msgs::Pose MAP_ORIN;
        float MAP_RESOLUTION;

        //-------------------------------------
        // laser sensors param
        volatile bool lsrparam_init;
        int Laser_Dta_Len;
        double Laser_Range_Max;
        double Laserangle_increment;
        double Laser_Angle_begin;
        double Laser_Angle_end;

        //-------------------------------------
        // tf subscribe data
        volatile bool tfparam_init;
        geometry_msgs::Pose TF_MAP2Odom;
        geometry_msgs::Pose TF_Odom2Robot;
        geometry_msgs::Pose TF_Robot2Lsr;

        geometry_msgs::Pose TF_MAP2Robot;

        //-------------------------------------
        volatile bool goalparam_init;
        geometry_msgs::Pose TF_Map2GoalPose;

        ParamData()
        {
            launchparam_init = false;
            mapparam_init = false;
            lsrparam_init = false;
            tfparam_init = false;
            goalparam_init = false;
        }

        ~ParamData()
        {

        }
    }ParamData;

#endif
