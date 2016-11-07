#ifndef __astar_H
#define __astar_H

#include "../pkg_include.h"

/* ********************************************************************************
 * Copyright (c) <Yingbing Chen>. All rights reserved.
 * FileName: a_star_algorithm.cpp
 * Contact:
 *
 * LICENSING TERMS:
 * This Code Have been contributed to The HandsFree team, And The Hands Free is
 * licensed generally under a permissive 3-clause BSD license.
 *                                   HadnsFree team Exchange Group -- 521037187
 *
 * Author: chenyingbing
 * Time: 20161027   09:27   in XIAMEN University
 * Illustration:
 *      A* Algorithm in Static Level Map (map_s)
 *                   in Dynamic Level Map (remain)
 *
 * ********************************************************************************/

enum MarkerArray_Action {FreshArray, AddData, ShowData};

typedef class A_STAR_FUNC
{
public:
    A_STAR_FUNC(ParamData &Pdata,
                A_STAR_DataType &Adata,
                Map_S_DataType  &OTF_MAP_S_DATA)
    {
        FLAG_Map_S_Init = false;

        astar_param = &Pdata;
        astar_data = &Adata;

        otf_map_s_data_r = &OTF_MAP_S_DATA;
    }

    ~A_STAR_FUNC()
    {
        delete nodemap;
    }

    // Public Data **************************************************
    ParamData       *astar_param;
    A_STAR_DataType *astar_data;

    Map_S_DataType  *otf_map_s_data_r;

    // MainRunging Func *********************************************
    // Pkg_MainRunning
    void Pkg_MainRunning(void);

    // Subscribe_MainRunning
    void Subscribe_MainRunning(void);

    // Thread_MainRunning
    void Thread_MainRunning(void);

private:
    #define K_Value_S   0.1f
    bool FLAG_Map_S_Init;

    int directionBuf8[8];
    int directionBuf4[4];
    int directionLen;
    float *directions;
    int *directionBuf;

    #define DIRECTIONLEN_8      8
    #define DIRECTIONLEN_4      4

    std::vector<unsigned int> Openlist;
    std::vector<unsigned int> Closelist;

    Astar_Node *nodemap;
    nav_msgs::OccupancyGrid debugmap;

    // Func Port ****************************************************
    void Main_Astar_Algorithm(void);

    void map_s_freshOnce(void);

    void func_add_pub_rtmakerarray(MarkerArray_Action PubFlag, Float2Array pointxy);

    // algorithm: Astar
    bool Normal_AStar(unsigned int startP, unsigned int desP);
    bool Modified_AStar1(unsigned int startP, unsigned int desP);
    bool Modified_AStar2(unsigned int startP, unsigned int desP);
    bool Modified_AStar3(unsigned int startP, unsigned int desP);
    bool Modified_AStar4(unsigned int startP, unsigned int desP); // fail!

    bool GetMapId_MapFrame(geometry_msgs::Pose data_in, int &Location_X, int &Location_Y, int &id_out);
    bool Func_Route_Fresh(void);
    void Func_GRoute_Fresh(void);
    void Func_Route_Show(void);

}A_STAR_FUNC;

#endif

