#include "map_s_algorithm.h"

//**************************************************************************
// Pkg MainRuning and Subscribe MainRunning is in the same thread circle
void MAP_S_FUNC::Pkg_MainRunning(void)
{
    Main_ImgShow();

    Func_PubMap();
}

void MAP_S_FUNC::Subscribe_MainRunning(const nav_msgs::OccupancyGrid &map_dta)
{
    map_s_data->r_map = &map_dta;

    SubMain_StaticMap_Algorithm();
}

// Thread_MainRunnnign is in the alone thread circle : data should add mutex.
void MAP_S_FUNC::Thread_MainRunning(void)
{

}

//**************************************************************************

void MAP_S_FUNC::Main_ImgShow(void)
{
    if(FLAG_taskInit && map_param->mapparam_init)
    {
        if(FLAG_ifShowIMAGE){
            cv::imshow(WINDOWS_NAME1, map_s_data->Map_MatDta);
            cv::imshow(WINDOWS_NAME2, map_s_data->Map_MatDta_Compared);

            cv::waitKey(3);
        }
    }
}

void MAP_S_FUNC::SubMain_StaticMap_Algorithm(void)
{
    if(map_param->mapparam_init)
    {
        Func_GetCostMap();

        FLAG_taskInit = true;
    }
}





