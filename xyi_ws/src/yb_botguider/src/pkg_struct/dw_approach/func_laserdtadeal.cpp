#include "dw_approach.h"

/* ********************************************************************************
 * author: chenyingbing
 * time: 20161019   10:53   in XIAMEN University
 * illustration:
 *      lsr deal function > dynamic window approach
 *
 *      Space Complexity:   ???
 *      Time  Complexity:   ???
 * ********************************************************************************
*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////

// Read the Lsr Dta then deal it
void DWA_FUNC::func_laserdtadeal(void)
{
    // Deal Dta Pack
    static bool FirstCopy = true;

    static float range;
    static float angle;
    static float x_dta, y_dta, x_dtaN, rangeN, angleN;
    static int j;

    static Float2Array dataIn_ra;
    static Float2Array dataIn_xy;
    static float MINDIS;

    MINDIS = dwa_param->Laser_Range_Max;
    j=0;

    for (int i=0; i<dwa_param->Laser_Dta_Len; i++){

        range = dwa_data->r_lsrdta->ranges[i];

        if ((i>(dwa_param->Laser_Dta_BDlen))and(i<(dwa_param->Laser_Dta_Len - dwa_param->Laser_Dta_EDlen))and(range == range)){

            // Data Prepared
            angle = (dwa_param->Laser_Angle_begin + i*dwa_param->Laserangle_increment);

            x_dta = cos(angle) * range;
            y_dta = sin(angle) * range;
            x_dtaN = x_dta + std::abs(dwa_param->TF_Robot2Lsr.position.x);

            rangeN = sqrt(x_dtaN*x_dtaN + y_dta*y_dta);
            angleN = atan2(y_dta, x_dtaN);

            // Get Laser Dta RA
            dataIn_ra.dta0 = rangeN;
            dataIn_ra.dta1 = angleN;
            if (FirstCopy){
                dwa_data->DLaserDtara.push_back(dataIn_ra);
            }else{
                dwa_data->DLaserDtara[j] = dataIn_ra;
            }

            // Get Laser Dta XY
            dataIn_xy.dta0 = x_dtaN;
            dataIn_xy.dta1 = y_dta;
            if (FirstCopy){
                dwa_data->DLaserDtaxy.push_back(dataIn_xy);
            }else{
                dwa_data->DLaserDtaxy[j] = dataIn_xy;
            }

            // Get PathDis Min
            if ((abs(y_dta) <= dwa_param->Robot_Physical_Radius) &&
                (x_dtaN <= MINDIS) &&
                (x_dtaN > 0)){
                MINDIS = x_dtaN;
            }

            j = j+1;
        }
    }
    FirstCopy = false;
    dwa_data->Lsr_PathMindis = MINDIS;

    //int ddd = dwa_data->DLaserDtaxy.size();
    //ROS_INFO("DLaserDtaxy Size: %d ", ddd);
}

static const int LaserDtaxy_Step = 5;

// Read the LaserDtaxy then deal it and get the AnglePathArray
void DWA_FUNC::func_anglepatharraydeal(void)
{
    // Deal Dta Pack
    static bool FirstCopy = true;
    static int readdtalen =0;
    readdtalen = dwa_data->DLaserDtaxy.size();
    static int i,j,k;
    static float DealAngle;
    static float xl,yl;
    static float cosd,sind;
    static float xn,yn;
    static float AngleDisMinC;
    static float Angle_Bgin,Angle_End;
    static vector<Float2Array>::iterator itxy;

    static Float2Array DtaInput;

    static bool disarray_show_flag = true;
    static sensor_msgs::LaserScan disarray_show;

    if(readdtalen > 0)
    {
        // init v
        if(disarray_show_flag){

            Angle_Bgin = dwa_param->Laser_Angle_begin;
            Angle_End = dwa_param->Laser_Angle_end;

            disarray_show.header.frame_id = "base_link_r";
            disarray_show.range_max = dwa_param->Laser_Range_Max;
            disarray_show.range_min = 0.02f;
            disarray_show.angle_min = dwa_param->Laser_Angle_begin;
            disarray_show.angle_max = dwa_param->Laser_Angle_end;;

            disarray_show.angle_increment = dwa_param->Laserangle_increment * AngleStep;

            disarray_show_flag = false;
        }

        i = 0, j = 0, k = 1;

        for(i=0; i<readdtalen; i++)
        {
            --k;
            if(k == 0){
                k = AngleStep;

                DealAngle = Angle_Bgin + i*dwa_param->Laserangle_increment;
                AngleDisMinC = dwa_param->Laser_Range_Max;

                for(itxy=dwa_data->DLaserDtaxy.begin(); itxy<dwa_data->DLaserDtaxy.end(); itxy+=LaserDtaxy_Step){

                    xl = (*itxy).dta0;
                    yl = (*itxy).dta1;

                    cosd = cos(DealAngle);
                    sind = sin(DealAngle);

                    xn = cosd*xl + sind*yl - dwa_param->Robot_Physical_Radius;
                    yn = -sind*xl + cosd*yl;

                    if ((abs(yn) <= dwa_param->MapSafe_Robot_Radius) &&
                        (xn <= AngleDisMinC) &&
                        (xn >= 0) ){
                        AngleDisMinC = xn;
                    }
                }

                DtaInput.dta0 = AngleDisMinC;
                DtaInput.dta1 = DealAngle;

                if (FirstCopy){
                    dwa_data->DAngleDisArray.push_back(DtaInput);
                    disarray_show.ranges.push_back(AngleDisMinC);
                }else{
                    dwa_data->DAngleDisArray[j] = DtaInput;
                    disarray_show.ranges[j] = AngleDisMinC;
                }

                j = j+1;
            }
        }
        FirstCopy = false;

        //show
        static ros::NodeHandle nstru;
        static ros::Publisher  pathdis_pub = nstru.advertise<sensor_msgs::LaserScan>("pathdis_array",1);
        disarray_show.header.stamp = ros::Time::now();
        pathdis_pub.publish(disarray_show);

    }

}

float DWA_FUNC::func_anglepathget(float Yaw_Rf)
{
    // Deal Dta Pack
    static int readdtalen =0;
    readdtalen = dwa_data->DLaserDtaxy.size();
    static float DealAngle;
    static float xl,yl;
    static float cosd,sind;
    static float xn,yn;
    static float AngleDisMinC;
    static vector<Float2Array>::iterator itxy;

    if(readdtalen > 0)
    {
        DealAngle = Yaw_Rf;
        AngleDisMinC = dwa_param->Laser_Range_Max;

        for(itxy=dwa_data->DLaserDtaxy.begin(); itxy<dwa_data->DLaserDtaxy.end(); itxy+=LaserDtaxy_Step){

            xl = (*itxy).dta0;
            yl = (*itxy).dta1;

            cosd = cos(DealAngle);
            sind = sin(DealAngle);

            xn = cosd*xl + sind*yl;
            yn = -sind*xl + cosd*yl;

            if ((abs(yn) <= dwa_param->MapSafe_Robot_Radius) &&
                (xn <= AngleDisMinC) &&
                (xn >= 0) ){
                AngleDisMinC = xn;
            }
        }
    }

    return AngleDisMinC;
}












