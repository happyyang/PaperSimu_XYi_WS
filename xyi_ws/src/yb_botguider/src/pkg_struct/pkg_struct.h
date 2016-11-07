#ifndef __guide_struct_H
#define __guide_struct_H

    /* ********************************************************************************
     * Copyright (c) <Yingbing Chen>. All rights reserved.
     * FileName: pkg_struct.cpp
     * Contact:
     *
     * LICENSING TERMS:
     * This Code Have been contributed to The HandsFree team, And The Hands Free is
     * licensed generally under a permissive 3-clause BSD license.
     *                                   HadnsFree team Exchange Group -- 521037187
     *
     * Author: chenyingbing
     * Time: 20161025   11:04   in XIAMEN University
     * Illustration:
     *      This is a struct to manage Guider Pkg
     *      Including:
     *          Map(static/dynamic)
     *          A Star Algorithm
     *              KEY Point
     *          Dynmaic Windows Approach
     *          Fuzzy Control Method
     *
     * topics subscribe:
     *      map_s                   :   static map from mapserver
     *      map_d                   :   dynamic map (remain)
     *      RobotPort_FilterScan    :   laser data from laser filter
     *      move_base_simple/goal   :   Goal Pose from rivz
     *
     * topics pub:
     *
     * ********************************************************************************
    */

    // Pkg Include Part ****************************************/
    #include "pkg_include.h"

    #include "map_s_algorithm/map_s_algorithm.h"
    #include "a_star_algorithm/a_star_algorithm.h"
    #include "dw_approach/dw_approach.h"

    // Pkg Manage Type Part ************************************/
    typedef class GuiderPkgStruct
    {
    public:
        // sys **************************************/
        // common part
        ros::NodeHandle nh_;

        // suscribe part
        ros::Subscriber map_s_sub;
        ros::Subscriber map_d_sub;
        ros::Subscriber goalpose_sub;
        ros::Subscriber laser_sub;

        // thread part

        // data *************************************/
        // param:
        ParamData param;

        // data1: sensor data

        // data2: algorithm data
        Map_S_DataType gencostmap_data;
        A_STAR_DataType astar_data;
        DWA_DataType dwa_data;

        GuiderPkgStruct() : static_map_task(param, gencostmap_data),

                            astar_task(param, astar_data,
                                       gencostmap_data),

                            dwa_task(param, dwa_data,
                                     astar_data,
                                     gencostmap_data)
        {  
            Subscribe_init();
        }

        ~GuiderPkgStruct()
        {

        }

        // pkg_struct.cpp
        void Pkg_Init(double *pram);
        void Pkg_Release();
        void Pkg_MainRunning();

    private:
        // common part -----------------------------------------------------------
        // pkg_struct_subscribe.cpp
        void Subscribe_init(void);

        void Map_S_Topics_Call(const nav_msgs::OccupancyGrid &map);
        void Map_D_Topics_Call(const nav_msgs::OccupancyGrid &map);
        void GoalPose_Topics_Call(const geometry_msgs::PoseStamped &gpose);
        void LsrDta_Topics_Call(const sensor_msgs::LaserScan &lsrdta);

        // pkg_struct_thread.cpp
        void TfSubscribe_Task(void);
        void GoalPose_TopicsShow_Task(void);

        // algorithm part --------------------------------------------------------
        MAP_S_FUNC  static_map_task;
        A_STAR_FUNC astar_task;
        DWA_FUNC    dwa_task;

    }GuiderPkgStruct;

    /*
     *      // astar task && map_s task
            astar_data.r_map_s_init = gencostmap_data.guidemap_init;

    */
#endif

