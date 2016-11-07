#include "a_star_algorithm.h"

#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

extern float directions8[DIRECTIONLEN_8][2];
extern float directions4[DIRECTIONLEN_4][2];

//**************************************************************************
// Pkg MainRuning and Subscribe MainRunning is in the same thread circle
void A_STAR_FUNC::Pkg_MainRunning(void)
{
    Main_Astar_Algorithm();
}

void A_STAR_FUNC::Subscribe_MainRunning(void)
{
    map_s_freshOnce();
}

// Thread_MainRunnnign is in the alone thread circle : data should add mutex.
void A_STAR_FUNC::Thread_MainRunning(void)
{

}

//**************************************************************************

void A_STAR_FUNC::map_s_freshOnce(void)
{
    static bool FLAG_FreshOnce = true;

    if(FLAG_FreshOnce)
    {
        delete nodemap;
        nodemap = new Astar_Node[astar_param->MAP_LEN];

        for(unsigned int i=0; i<astar_param->MAP_LEN; i++)
        {
            nodemap[i].sta = otf_map_s_data_r->guidemap.data[i];
            nodemap[i].value_s = otf_map_s_data_r->guidemap.data[i] * K_Value_S;
        }

        for(char j=0; j<DIRECTIONLEN_8; j++)
        {
            directionBuf8[j] = astar_param->MAP_WIDTH * directions8[j][1] + directions8[j][0];
        }
        for(char j=0; j<DIRECTIONLEN_4; j++)
        {
            directionBuf4[j] = astar_param->MAP_WIDTH * directions4[j][1] + directions4[j][0];
        }

        //-----------------------------------------
        debugmap.header.frame_id = otf_map_s_data_r->guidemap.header.frame_id;
        debugmap.info = otf_map_s_data_r->guidemap.info;
        debugmap.data.resize(astar_param->MAP_LEN,-1);   // -1 == 255: is black

        FLAG_FreshOnce = false;
        FLAG_Map_S_Init = true;
    }
}

void A_STAR_FUNC::Main_Astar_Algorithm(void)
{
    static bool sta;

    if(astar_param->mapparam_init && FLAG_Map_S_Init && otf_map_s_data_r->guidemap_init)
    { // mapparam,                   map_s guide data   map_s data

        //astar_param->TF_Map2GoalPose;
        //astar_param->TF_MAP2Robot;
        //astar_data->TF_Map2GuidePose;

        if(!astar_data->route_s_init &&
            astar_param->goalparam_init && astar_param->tfparam_init)
        {
            static int locate_x, locate_y;
            sta = true;

            if(sta) sta &= GetMapId_MapFrame(astar_param->TF_MAP2Robot, locate_x, locate_y, astar_data->StartP_Id);

            if(sta) sta &= GetMapId_MapFrame(astar_param->TF_Map2GoalPose, locate_x, locate_y, astar_data->DesP_Id);

            if(sta) sta &= Modified_AStar2(astar_data->StartP_Id, astar_data->DesP_Id);

            if(sta) sta = Func_Route_Fresh();

            if(sta)
            {
                if (astar_data->mutex_GRouteMessage)
                {
                    astar_data->mutex_GRouteMessage = false;

                    Func_GRoute_Fresh();

                    astar_data->mutex_GRouteMessage = true;
                }

                astar_data->route_s_init = true;
            }
        }

        Func_Route_Show();
    }
}

//**************************************************************************
void A_STAR_FUNC::func_add_pub_rtmakerarray(MarkerArray_Action PubFlag, Float2Array pointxy)
{
    static bool intmaker = true;
    static ros::NodeHandle nstru;
    static ros::Publisher rtmarkerarray_pub = nstru.advertise<visualization_msgs::MarkerArray>("rtmarkerarray",1);
    static visualization_msgs::Marker pubdata;
    static visualization_msgs::MarkerArray pubarraydata;
    static int id = 0;

    switch(PubFlag)
    {
    case FreshArray:
        id = 0;
        pubarraydata.markers.clear();
        break;

    case AddData:
        pubdata.id = id;   ++id;
        pubdata.header.stamp = ros::Time::now();
        if(intmaker)
        {
            pubdata.header.frame_id = "map_r";
            pubdata.ns = "Local Guide Point";

            pubdata.type = visualization_msgs::Marker::CUBE;

            pubdata.scale.x = 0.1;
            pubdata.scale.y = 0.1;
            pubdata.scale.z = 0.1;

            pubdata.color.a = 1.0;
            pubdata.color.r = 0.0;
            pubdata.color.g = 1.0;
            pubdata.color.b = 0.0;

            intmaker = false;
        }

        pubdata.pose.position.x = (pointxy.dta0 * astar_param->MAP_RESOLUTION) + astar_param->MAP_ORIN.position.x;
        pubdata.pose.position.y = (pointxy.dta1 * astar_param->MAP_RESOLUTION) + astar_param->MAP_ORIN.position.y;
        pubdata.pose.position.z = 0;
        pubdata.pose.orientation = astar_param->TF_MAP2Robot.orientation;

        pubarraydata.markers.push_back(pubdata);
        break;

    case ShowData:
        rtmarkerarray_pub.publish(pubarraydata);
        break;
    }
}










