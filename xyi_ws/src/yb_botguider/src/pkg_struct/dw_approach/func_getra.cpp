#include "dw_approach.h"

//***********************************************************************************************************************
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//***********************************************************************************************************************

extern Float2Array Mid_chooseRA;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~>>>
void DWA_FUNC::func_getra_show(void)
{
    static ros::NodeHandle nstru;
    static ros::Publisher rtpose_pub = nstru.advertise<geometry_msgs::PoseStamped>("rtpose",1);
    static geometry_msgs::PoseStamped pubdata;

    Quaternion<float> dta1( AngleAxisf(Mid_chooseRA.dta1, Vector3f(0.0f,0.0f,1.0f)) );
    pubdata.header.frame_id = "base_link_r";
    pubdata.header.stamp = ros::Time::now();
    pubdata.pose.orientation.w = dta1.w();
    pubdata.pose.orientation.x = dta1.x();
    pubdata.pose.orientation.y = dta1.y();
    pubdata.pose.orientation.z = dta1.z();

    rtpose_pub.publish(pubdata);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~>>>
void DWA_FUNC::func_getra_chosen_dwa(float GuideYaw_Rf)
{
    static const float VKRange  = 2.0f/dwa_param->Laser_Range_Max;
    static const float VKRaidus = 1.0f/dwa_approach_radius_max;

    static float f_r_chosen;
    static vector<Float2Array>::iterator AdisArray;

    static float Akrange;
    static float Aktarget;
    static float Aksmooth;

    static float norm,d1,d2,d3,d4,d5;

    Akrange  = 0.3f;
    Aktarget = 1.0f;
    Aksmooth = 0.05f;

    norm = 1.0f/sqrt(Akrange*Akrange + Aktarget*Aktarget + Aksmooth*Aksmooth);
    Akrange *= norm;
    Aktarget *= norm;
    Aksmooth *= norm;

    static bool dwa_flag; dwa_flag = false;

    if(robot_speed < 0.05f) dwa_fchose_add += 0.1f;
    if(dwa_fchose_add >= dwa_param->MapSafe_Robot_Radius) dwa_fchose_add = dwa_param->MapSafe_Robot_Radius;
    f_r_chosen = 0.0f + dwa_fchose_add;

    // Choose the best Direction
    static float value_C; value_C = -1000000;
    for(AdisArray = dwa_data->DAngleDisArray.begin();
        AdisArray != dwa_data->DAngleDisArray.end(); AdisArray++){

        d1 = (*AdisArray).dta0; //range
        d2 = (*AdisArray).dta1; //angle

        if (d1 >= f_r_chosen){

            d3 = Akrange * d1 * VKRange;                        //value_range
            d4 = -Aktarget * abs(d2 - GuideYaw_Rf) * VKRaidus;  //value_guide
            d5 = -Aksmooth * abs(d2) * VKRaidus;                //value_smooth

            float value_sum = d3 + d4 + d5;
            if (value_sum > value_C){
                value_C = value_sum;

                dwa_flag = true;
                Mid_chooseRA.dta0 = dwa_data->Lsr_PathMindis;
                Mid_chooseRA.dta1 = d2;
            }
        }
    }

    if(!dwa_flag)
    {
        Mid_chooseRA.dta0 = dwa_data->Lsr_PathMindis;

        if(robot_gyro > 0)
            Mid_chooseRA.dta1 = M_PI_2;
        else
            Mid_chooseRA.dta1 = -M_PI_2;
    }

}






