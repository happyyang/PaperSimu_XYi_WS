#ifndef __dw_approach_H
#define __dw_approach_H

#include "../pkg_include.h"

    /* ********************************************************************************
     * Copyright (c) <Yingbing Chen>. All rights reserved.
     * FileName: dw_approach.cpp
     * Contact:
     *
     * LICENSING TERMS:
     * This Code Have been contributed to The HandsFree team, And The Hands Free is
     * licensed generally under a permissive 3-clause BSD license.
     *                                   HadnsFree team Exchange Group -- 521037187
     *
     * Author: chenyingbing
     * Time: 20161028   10:21   in XIAMEN University
     * Illustration:
     *      Dynamic Windows Approach accoring to the A* Route
     *
     * ********************************************************************************/

    typedef class DWA_FUNC
    {
    public:
        DWA_FUNC(ParamData &Pdata, DWA_DataType &Adata,
                 A_STAR_DataType &OTF_A_STAR_DATA,
                 Map_S_DataType  &OTF_MAP_S_DATA) : AngleStep(5),
                                                    Control_Imu_T(0.08),
                                                    dwa_approach_radius_max(M_PI_2),
                                                    dwa_approach_radius_reachtarget(0.0175f),
                                                    dwa_approach_radius_reachguide(0.05f),
                                                    dwa_approach_reachguidelimit(2.0f),
                                                    dwa_approach_reachrangelimit0(0.25f),
                                                    dwa_approach_reachrangelimit1(0.05f)
        {
            dwa_param = &Pdata;
            dwa_data = &Adata;

            otf_astar_data = &OTF_A_STAR_DATA;
            otf_map_s_data = &OTF_MAP_S_DATA;

            dwa_fchose_add = 0;

            Robot_Action_Now.mode = ACTIONMODE_STOP;
            action_busy = false;
            robot_speed = 0;
            robot_gyro = 0;

            Trun = boost::bind(&DWA_FUNC::task,this);
            ThisThread = new boost::thread(Trun);
        }

        ~DWA_FUNC()
        {
            ThisThread->interrupt();
            delete ThisThread;
        }

        // Public Data **************************************************
        ParamData       *dwa_param;
        DWA_DataType    *dwa_data;

        A_STAR_DataType *otf_astar_data;
        Map_S_DataType  *otf_map_s_data;

        // MainRunging Func *********************************************
        // Pkg_MainRunning
        void Pkg_MainRunning(void);

        // Subscribe_MainRunning
        void Subscribe_MainRunning(const sensor_msgs::LaserScan &laserdta);

        // Thread_MainRunning
        void Thread_MainRunning(void);

    private:
        // Privatate Algrotihm Dta
        const float Control_Imu_T;
        const int AngleStep;

        float dwa_fchose_add;

        const float dwa_approach_radius_max;
        const float dwa_approach_radius_reachtarget;
        const float dwa_approach_radius_reachguide;
        const float dwa_approach_reachguidelimit;
        const float dwa_approach_reachrangelimit0;  // far dis
        const float dwa_approach_reachrangelimit1;  // arrive dis

        // Thread Part **************************************************
        boost::thread *ThisThread;
        boost::function0<void> Trun;
        void task();

        volatile bool action_busy;
        DWA_ActionType Robot_Action_Now;
        float robot_speed;
        float robot_gyro;

        // Algorithm:
        void  func_laserdtadeal(void);
        void  func_anglepatharraydeal(void);
        float func_anglepathget(float Yaw_Rf);

        void  func_getguidepoint(void);
        void  func_gudingrules(void);
        void  func_pubrtmaker(int pointid);

        void  func_getra_show(void);
        void  func_getra_chosen_dwa(float GuideYaw_Rf);

        void  func_control_loop(void);
        void  func_control_pid_speed(void);
        void  func_conrtol_pid_gyro(void);
        void  func_conrtol_pub(void);

        // Math
        bool GetMapId_MapFrame(geometry_msgs::Pose data_in, int &Location_X, int &Location_Y, int &id_out);

    }DWA_FUNC;

#endif




