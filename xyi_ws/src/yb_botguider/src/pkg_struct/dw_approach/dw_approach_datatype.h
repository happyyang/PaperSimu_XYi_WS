#ifndef __dw_approach_datatype_H
#define __dw_approach_datatype_H

//can be interrupted?   <10:true, >=10: false
#define ACTIONMODE_INTERRUPTED_LIMIT    10
enum ACTIONMODE {ACTIONMODE_WANDER = 0,
                 ACTIONMODE_REACH = 1,
                 ACTIONMODE_STOP = 2,
                 ACTIONMODE_ROTATE = 3,

                 ACTIONMODE_FINALROTATE = 11};

typedef class DWA_ActionType
{
public:
    ACTIONMODE mode;

    float reach_x_mf;           //[reach mode]: target's x location in map_r frame
    float reach_y_mf;           //[reach mode]:

    float wander_guide_speed;   //[wander/stop mode]
    float wander_guide_gyro;    //[wander/stop mode]

    DWA_ActionType()
    {
        wander_guide_speed = 0;
        wander_guide_gyro = 0;
    }

}DWA_ActionType;

typedef class DWA_DataType
{
public:
    const sensor_msgs::LaserScan *r_lsrdta;

    float Lsr_PathMindis;

    volatile bool mutex_laserDtaAll;
    vector<Float2Array> DLaserDtara;
    vector<Float2Array> DLaserDtaxy;
    vector<Float2Array> DAngleDisArray; //dta0 = PathDis; dta1 = Angle;

    volatile bool guiding_Exist;

    DWA_DataType()
    {
        DLaserDtara.clear();
        DLaserDtaxy.clear();
        DAngleDisArray.clear();

        mutex_laserDtaAll = true;
        guiding_Exist = false;
    }

    ~DWA_DataType()
    {
        DLaserDtara.clear();
        DLaserDtaxy.clear();
        DAngleDisArray.clear();
    }

}DWA_DataType;

#endif






