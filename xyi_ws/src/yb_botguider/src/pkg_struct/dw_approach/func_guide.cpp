#include "dw_approach.h"

//***********************************************************************************************************************
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//***********************************************************************************************************************
// variables
static const float Double_M_PI = M_PI * 2.0f;

static float G2Des_Dis;
static int Robot_Locate_Id;
static int Robot_Locate_x, Robot_Locate_y;    // map_id x,y

static Int1Float2B1Array GuidePoint;
static std::vector<Int1Float2B1Array> GuidePointArray;

Float2Array Mid_chooseRA = {0, 0};

void DWA_FUNC::func_getguidepoint(void)
{
    bool sta;
    static std::vector<Astar_Route>::iterator it;
    static float aw,ax,ay,az;

    GuidePointArray.clear();

    sta = GetMapId_MapFrame(dwa_param->TF_MAP2Robot, Robot_Locate_x, Robot_Locate_y, Robot_Locate_Id);

    static bool firstGetDesFlag; firstGetDesFlag = true;

    static float R2Des_Yaw_Rf;
    static float R2GP_Dis;
    static Int1Float2B1Array ThisPoint, ChosePoint;

    static float R2GP_DisMin;
    static int id, R2GP_DisMinPointId;

    R2GP_DisMin = 1000000;

    for(it = (otf_astar_data->AStarGRoute.begin()), id = 0;
        (it < otf_astar_data->AStarGRoute.end()) && sta;
        it++)
    {
        ++id;

        ThisPoint.dta0 = (*it).P_Id;

        aw = dwa_param->TF_MAP2Robot.orientation.w;
        ax = dwa_param->TF_MAP2Robot.orientation.x;
        ay = dwa_param->TF_MAP2Robot.orientation.y;
        az = dwa_param->TF_MAP2Robot.orientation.z;
        ThisPoint.dta1 = std::atan2(2*(aw*az+ax*ay),(1-2*(ay*ay+az*az)));
        ThisPoint.dta1 = -ThisPoint.dta1 + std::atan2((*it).P_XY.dta1 - Robot_Locate_y, (*it).P_XY.dta0 - Robot_Locate_x);
        if(ThisPoint.dta1 >= M_PI)   ThisPoint.dta1 -= Double_M_PI;
        if(ThisPoint.dta1 <=- M_PI)  ThisPoint.dta1 += Double_M_PI;

        ThisPoint.dta2 = func_anglepathget(ThisPoint.dta1);

        R2GP_Dis = std::sqrt( std::pow((*it).P_XY.dta1 - Robot_Locate_y, 2) +
                              std::pow((*it).P_XY.dta0 - Robot_Locate_x, 2) ) * dwa_param->MAP_RESOLUTION;
        ThisPoint.dta3 = (ThisPoint.dta2 >= R2GP_Dis);

        if(firstGetDesFlag){
            G2Des_Dis = R2GP_Dis;
            ChosePoint = ThisPoint;
            R2Des_Yaw_Rf = ThisPoint.dta1;

            firstGetDesFlag = false;
        }

        if(R2GP_Dis < R2GP_DisMin){
            R2GP_DisMinPointId = id;
            R2GP_DisMin = R2GP_Dis;
        }

        GuidePointArray.push_back(ThisPoint);
    }
    ///////////////////////////////////////////////////////////////////////////////////

    if(R2GP_DisMinPointId >= 4){
        ChosePoint = GuidePointArray[R2GP_DisMinPointId - 4];
    }

    GuidePoint = ChosePoint;
    dwa_data->guiding_Exist = true;

}

//***********************************************************************************************************************
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//***********************************************************************************************************************

void DWA_FUNC::func_gudingrules(void)
{
    /*  #define ACTIONMODE_INTERRUPTED_LIMIT    10
     *  ACTIONMODE_WANDER, ACTIONMODE_REACH, ACTIONMODE_STOP, ACTIONMODE_ROTATE, ACTIONMODE_FINALROTATE
     *
     *  [DWA_ActionType]:
     *  ACTIONMODE mode;
     *  float reach_x_mf;       //[reach mode]: target's x location in map_r frame
     *  float reach_y_mf;       //[reach mode]:
     *  float target_yaw_mf;    //[rotate mode]: target's yaw in map_r frame
    */

    /*  [GuidePoint]:
     *  dta0<int>       GuidePoint Id
     *  dta1<float>     R2P_Yaw_Rf: Robot to Point 's Yaw in Robot's Frame
     *  dta2<float>     R2P_Yaw_Rf's Path Distance
     *  dta3<bool>      can reach = dta2 > R2P_Dis ? true : false       */

    static float frotate_yaw, aw,ax,ay,az;
    static ACTIONMODE actionmode_chosen = ACTIONMODE_STOP;

    Mid_chooseRA.dta0 = 0;
    Mid_chooseRA.dta1 = 0;

    // show guide point
    func_pubrtmaker(GuidePoint.dta0);

    if(dwa_data->guiding_Exist)
    {
        if ((G2Des_Dis <= dwa_approach_reachrangelimit1) &&
            (GuidePoint.dta0 == otf_astar_data->AStarGRoute[0].P_Id) )
        {
            aw = dwa_param->TF_Map2GoalPose.orientation.w;
            ax = dwa_param->TF_Map2GoalPose.orientation.x;
            ay = dwa_param->TF_Map2GoalPose.orientation.y;
            az = dwa_param->TF_Map2GoalPose.orientation.z;
            frotate_yaw = std::atan2(2*(aw*az+ax*ay),(1-2*(ay*ay+az*az)));

            aw = dwa_param->TF_MAP2Robot.orientation.w;
            ax = dwa_param->TF_MAP2Robot.orientation.x;
            ay = dwa_param->TF_MAP2Robot.orientation.y;
            az = dwa_param->TF_MAP2Robot.orientation.z;
            frotate_yaw -= std::atan2(2*(aw*az+ax*ay),(1-2*(ay*ay+az*az)));

            if(frotate_yaw >= M_PI)   frotate_yaw -= Double_M_PI;
            if(frotate_yaw <=- M_PI)  frotate_yaw += Double_M_PI;

            if( frotate_yaw > dwa_approach_radius_reachtarget)
            {
                actionmode_chosen = ACTIONMODE_STOP;
            }else{
                actionmode_chosen = ACTIONMODE_FINALROTATE;
            }

        }else{

            if ((GuidePoint.dta3 == true) &&
                (G2Des_Dis <= dwa_approach_reachrangelimit0) &&
                (std::abs(GuidePoint.dta1) <= dwa_approach_radius_max) &&
                (GuidePoint.dta0 == otf_astar_data->AStarGRoute[0].P_Id))
            {   // face the target and near!
                actionmode_chosen = ACTIONMODE_REACH;
            }else{
                if(std::abs(GuidePoint.dta1) > dwa_approach_radius_max){
                actionmode_chosen = ACTIONMODE_ROTATE;
                }else{
                actionmode_chosen = ACTIONMODE_WANDER;
                }
            }
        }

        if ((Robot_Action_Now.mode != ACTIONMODE_WANDER))
        {
            dwa_fchose_add = 0;
        }

        // busy action require!!!
        if( Robot_Action_Now.mode < ACTIONMODE_INTERRUPTED_LIMIT )
        {
            Robot_Action_Now.mode = actionmode_chosen;
        }

        switch(Robot_Action_Now.mode)
        {
        case ACTIONMODE_WANDER:
            func_getra_chosen_dwa(GuidePoint.dta1);
            Robot_Action_Now.wander_guide_speed = Mid_chooseRA.dta0;
            Robot_Action_Now.wander_guide_gyro = Mid_chooseRA.dta1;
            break;

        case ACTIONMODE_REACH:
            Robot_Action_Now.reach_x_mf;
            Robot_Action_Now.reach_y_mf;

            Robot_Action_Now.wander_guide_speed = 0;
            Robot_Action_Now.wander_guide_gyro = 0;
            break;

        case ACTIONMODE_ROTATE:

            Robot_Action_Now.wander_guide_speed = 0.1f + dwa_param->Robot_Physical_Radius;

            Mid_chooseRA.dta1 = GuidePoint.dta1;
            Robot_Action_Now.wander_guide_gyro = Mid_chooseRA.dta1;
            break;

        case ACTIONMODE_FINALROTATE:
            //Robot_Action_Now.target_yaw_mf = frotate_yaw;
            break;

        case ACTIONMODE_STOP:
            Robot_Action_Now.wander_guide_speed = 0;
            Robot_Action_Now.wander_guide_gyro = 0;
            break;
        }

    }else{
        // map is updating, dwa_data->guiding_Exist = false;
        actionmode_chosen = ACTIONMODE_STOP;
        Robot_Action_Now.wander_guide_speed = 0;
        Robot_Action_Now.wander_guide_gyro = 0;
    }


    func_control_loop();

    func_getra_show();
}

//***********************************************************************************************************************
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//***********************************************************************************************************************

void DWA_FUNC::func_pubrtmaker(int pointid)
{
    static bool intmaker = true;
    static float deal1,deal2;
    static ros::NodeHandle nstru;
    static ros::Publisher rtmarker_pub = nstru.advertise<visualization_msgs::Marker>("rtmarker",1);
    static visualization_msgs::Marker pubdata;

    deal1 = pointid % dwa_param->MAP_WIDTH;
    deal2 = (pointid-deal1)/dwa_param->MAP_WIDTH;

    deal1*= dwa_param->MAP_RESOLUTION;
    deal2*= dwa_param->MAP_RESOLUTION;

    deal1 += dwa_param->MAP_ORIN.position.x;
    deal2 += dwa_param->MAP_ORIN.position.y;

    pubdata.header.stamp = ros::Time::now();

    if(intmaker)
    {
        pubdata.header.frame_id = "map_r";
        pubdata.ns = "Target Guide Point";
        pubdata.id = 0;
        pubdata.type = visualization_msgs::Marker::CUBE;

        pubdata.scale.x = 0.1;
        pubdata.scale.y = 0.1;
        pubdata.scale.z = 0.1;

        pubdata.color.a = 1.0;
        pubdata.color.r = 1.0;
        pubdata.color.g = 1.0;
        pubdata.color.b = 0.0;

        intmaker = false;
    }
    pubdata.pose.position.x = deal1;
    pubdata.pose.position.y = deal2;
    pubdata.pose.position.z = 0;
    pubdata.pose.orientation = dwa_param->TF_MAP2Robot.orientation;

    rtmarker_pub.publish(pubdata);
}

//***********************************************************************************************************************
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//***********************************************************************************************************************

bool DWA_FUNC::GetMapId_MapFrame(geometry_msgs::Pose data_in, int &Location_X, int &Location_Y, int &id_out)
{
    static int Location_Id;

    id_out = 0;
    if(dwa_param->mapparam_init)
    {
        Location_X = dwa_param->MAP_WIDTH + int((data_in.position.x + (dwa_param->MAP_ORIN.position.x))/dwa_param->MAP_RESOLUTION);
        Location_Y = dwa_param->MAP_HEIGHT + int((data_in.position.y + (dwa_param->MAP_ORIN.position.y))/dwa_param->MAP_RESOLUTION);
        Location_Id = dwa_param->MAP_WIDTH * Location_Y + Location_X;

        if((Location_Id >= 0)and(Location_Id < dwa_param->MAP_LEN))
        {
            id_out = Location_Id;
            return true;
        }
    }

    return false;
}



