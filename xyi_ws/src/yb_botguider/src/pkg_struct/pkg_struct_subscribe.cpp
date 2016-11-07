#include "pkg_struct.h"

// Subscribe Init ************************************************************************************************//

void GuiderPkgStruct::Subscribe_init(void)
{
    map_s_sub   = nh_.subscribe("/map_s", 1, &GuiderPkgStruct::Map_S_Topics_Call, this);
    map_d_sub   = nh_.subscribe("/map_d", 1, &GuiderPkgStruct::Map_D_Topics_Call, this);
    goalpose_sub = nh_.subscribe("move_base_simple/goal", 1, &GuiderPkgStruct::GoalPose_Topics_Call, this);
    laser_sub = nh_.subscribe("RobotPort_Scan", 1, &GuiderPkgStruct::LsrDta_Topics_Call, this);
}

// Subscribe Func ************************************************************************************************//
void GuiderPkgStruct::Map_S_Topics_Call(const nav_msgs::OccupancyGrid &map)
{
    if(!param.mapparam_init){
        param.MAP_WIDTH = map.info.width;
        param.MAP_HEIGHT = map.info.height;
        param.MAP_LEN = param.MAP_WIDTH * param.MAP_HEIGHT;
        param.MAP_ORIN = map.info.origin;
        param.MAP_RESOLUTION = map.info.resolution;

        param.mapparam_init = true;

        // This Topics Only Receive Once
        static_map_task.Subscribe_MainRunning(map);

        astar_task.Subscribe_MainRunning();
    }else{

    }
}

void GuiderPkgStruct::Map_D_Topics_Call(const nav_msgs::OccupancyGrid &map)
{

}

void GuiderPkgStruct::LsrDta_Topics_Call(const sensor_msgs::LaserScan &lsrdta)
{
    if(!param.lsrparam_init){
        param.Laser_Dta_Len = lsrdta.ranges.size();
        param.Laser_Range_Max = lsrdta.range_max;
        param.Laserangle_increment = lsrdta.angle_increment;
        param.Laser_Angle_begin = lsrdta.angle_min;
        param.Laser_Angle_end = lsrdta.angle_max;

        param.lsrparam_init = true;
    }else{
        dwa_task.Subscribe_MainRunning(lsrdta);
    }
}

void GuiderPkgStruct::GoalPose_Topics_Call(const geometry_msgs::PoseStamped &gpose)
{
    dwa_data.guiding_Exist = false;
    astar_data.route_s_init = false;

    param.TF_Map2GoalPose = gpose.pose;
    param.goalparam_init = true;

}



