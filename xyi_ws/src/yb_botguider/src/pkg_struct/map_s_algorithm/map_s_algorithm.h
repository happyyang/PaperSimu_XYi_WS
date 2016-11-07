#ifndef __map_s_algorithm_H
#define __map_s_algorithm_H

#include "../pkg_include.h"

/* ********************************************************************************
 * Copyright (c) <Yingbing Chen>. All rights reserved.
 * FileName: map_s_algorithm.cpp
 * Contact:
 *
 * LICENSING TERMS:
 * This Code Have been contributed to The HandsFree team, And The Hands Free is
 * licensed generally under a permissive 3-clause BSD license.
 *                                   HadnsFree team Exchange Group -- 521037187
 *
 * Author: chenyingbing
 * Time: 20161026   09:36   in XIAMEN University
 * Illustration:
 *      Static Level Map
 *
 * ********************************************************************************/

#define WINDOWS_NAME1   "Map_Windows"
#define WINDOWS_NAME2   "Map_CWindows"

typedef class MAP_S_FUNC
{
private:
    ros::NodeHandle nh_;

    image_transport::ImageTransport it_;
    image_transport::Publisher image_pub_;

    bool taskInit;

public:
    MAP_S_FUNC(ParamData &Pdata, Map_S_DataType &Adata) : it_(nh_)
    {
        FLAG_taskInit = false;
        FLAG_ifShowIMAGE = false;

        map_param = &Pdata;
        map_s_data = &Adata;

        if(FLAG_ifShowIMAGE)
        {
            cv::namedWindow(WINDOWS_NAME1);
            cv::namedWindow(WINDOWS_NAME2);
        }
    }

    ~MAP_S_FUNC()
    {
        cv::destroyWindow(WINDOWS_NAME1);
        cv::destroyWindow(WINDOWS_NAME2);
    }

    // Public Data **************************************************
    ParamData       *map_param;
    Map_S_DataType  *map_s_data;

    // MainRunging Func *********************************************
    // Pkg_MainRunning
    void Pkg_MainRunning(void);

    // Subscribe_MainRunning
    void Subscribe_MainRunning(const nav_msgs::OccupancyGrid &map_dta);

    // Thread_MainRunning
    void Thread_MainRunning(void);

private:
    bool FLAG_ifShowIMAGE;
    bool FLAG_taskInit;

    // Func Port ****************************************************
    void Main_ImgShow(void);
    void SubMain_StaticMap_Algorithm(void);

    void Func_GetCostMap(void);
    void Func_PubMap(void);

}MAP_S_FUNC;



#endif


