#include "a_star_algorithm.h"

float directions8[DIRECTIONLEN_8][2] = { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 1, -1 }, { 0, 1 }, { 1, 1 }, { 1, 0 } };
float directions4[DIRECTIONLEN_4][2] = { { -1, 0 }, { 0, -1 }, { 0, 1 }, { 1, 0 } };

Matrix4d GeoPose2Matrix4dArray(geometry_msgs::Pose posedta);
void Matrix4dGetGeoPose(Matrix4d MatrixDta, geometry_msgs::Pose *posedta);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* ********************************************************************************
 * author: chenyingbing
 * time: 20161019   09:38   in XIAMEN University
 * illustration:
 *      basic matrix function using eigen library
 *
 * ********************************************************************************
*/
Matrix4d GeoPose2Matrix4dArray(geometry_msgs::Pose posedta)
{
    static double ArrayGet[16];
    static double px; px = posedta.position.x;
    static double py; py = posedta.position.y;
    static double pz; pz = posedta.position.z;

    static double qw; qw = posedta.orientation.w;
    static double qx; qx = posedta.orientation.x;
    static double qy; qy = posedta.orientation.y;
    static double qz; qz = posedta.orientation.z;

    ArrayGet[0] = qw*qw + qx*qx - qy*qy - qz*qz;
    ArrayGet[1] = 2*qx*qy + 2*qw*qz;
    ArrayGet[2] = 2*qx*qz - 2*qw*qy;
    ArrayGet[3] = 0;

    ArrayGet[4] = 2*qx*qy - 2*qw*qz;
    ArrayGet[5] = qw*qw - qx*qx + qy*qy - qz*qz;
    ArrayGet[6] = 2*qy*qz + 2*qw*qx;
    ArrayGet[7] = 0;

    ArrayGet[8] = 2*qx*qz + 2*qw*qy;
    ArrayGet[9] = 2*qy*qz - 2*qw*qx;
    ArrayGet[10] = qw*qw - qx*qx - qy*qy + qz*qz;
    ArrayGet[11] = 0;

    ArrayGet[12] = px;
    ArrayGet[13] = py;
    ArrayGet[14] = pz;
    ArrayGet[15] = 1.0;

    Map<Matrix4d> MatrixReturn(ArrayGet);

    return MatrixReturn;
}

void Matrix4dGetGeoPose(Matrix4d MatrixDta, geometry_msgs::Pose *posedta)
{
    static double PRY[3];
    PRY[1] = atan2(MatrixDta.data()[6],MatrixDta.data()[10]);	// A6/A10
    PRY[0] = asin(-MatrixDta.data()[2]);                        // A2
    PRY[2] = atan2(MatrixDta.data()[1],MatrixDta.data()[0]);	// A1/A0

    posedta->position.x = MatrixDta.data()[12];
    posedta->position.y = MatrixDta.data()[13];
    posedta->position.z = MatrixDta.data()[14];

    static double p; p = PRY[0]*0.5;
    static double r; r = PRY[1]*0.5;
    static double y; y = PRY[2]*0.5;
    posedta->orientation.w = cos(r)*cos(p)*cos(y) + sin(r)*sin(p)*sin(y);	//When yaw: 	cos(yaw*0.5f)
    posedta->orientation.x = sin(r)*cos(p)*cos(y) - cos(r)*sin(p)*sin(y);	//		0
    posedta->orientation.y = cos(r)*sin(p)*cos(y) + sin(r)*cos(p)*sin(y);	//		0
    posedta->orientation.z = cos(r)*cos(p)*sin(y) - sin(r)*sin(p)*cos(y);	//		sin(yaw*0.5f)
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool A_STAR_FUNC::GetMapId_MapFrame(geometry_msgs::Pose data_in, int &Location_X, int &Location_Y, int &id_out)
{
    static int Location_Id;

    id_out = 0;
    if(astar_param->mapparam_init)
    {
        Location_X = astar_param->MAP_WIDTH + int((data_in.position.x + (astar_param->MAP_ORIN.position.x))/astar_param->MAP_RESOLUTION);
        Location_Y = astar_param->MAP_HEIGHT + int((data_in.position.y + (astar_param->MAP_ORIN.position.y))/astar_param->MAP_RESOLUTION);
        Location_Id = astar_param->MAP_WIDTH * Location_Y + Location_X;

        if((Location_Id >= 0)and(Location_Id < astar_param->MAP_LEN))
        {
            id_out = Location_Id;
            return true;
        }
    }

    return false;
}

static bool Route_HavingFresh = false;

bool A_STAR_FUNC::Func_Route_Fresh(void)
{
    static bool sta; sta = false;
    static float deal1, deal2;
    static Astar_Route RoutePoint;

    if(FLAG_Map_S_Init)
    {
        // sign the path in map
        static unsigned int ThisPointId;
        static int ProtectT;   ProtectT = 10000;
        ThisPointId = astar_data->DesP_Id;

        //ROS_INFO("aaaaaaaaaaaaaaaaaaaaaaaa");
        astar_data->AStarRoute.clear();
        while(ProtectT--)
        {
            debugmap.data[ThisPointId] = 0; // set white to show

            // fill RoutePoint Message!
            RoutePoint.P_Id = ThisPointId;

            deal1 = ThisPointId % astar_param->MAP_WIDTH;
            deal2 = (ThisPointId-deal1)/astar_param->MAP_WIDTH;
            RoutePoint.P_XY.dta0 = int(deal1);
            RoutePoint.P_XY.dta1 = int(deal2);

            astar_data->AStarRoute.push_back(RoutePoint);

            if(ThisPointId == astar_data->StartP_Id) break;
            ThisPointId = nodemap[ThisPointId].Parent_Id;
        }

        if(ProtectT == -1){
            sta = false;
            ROS_ERROR("ERROR: path's parent id is wrong! ");
        }else{
            sta = true;
        }

        Route_HavingFresh = true;
    }

    return sta;
}

static const int SearchGuidePoint_Step = 10;

void A_STAR_FUNC::Func_GRoute_Fresh(void)
{
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    /* Astar_Route Old Param
     * int P_Id;           // Point's Id in Map
     * Int2Array P_XY;     // Point's X Y Location in Map
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

    static std::vector<Astar_Route>::iterator it;
    astar_data->AStarGRoute.clear();

    ///////////////////////////////////////////////////////////////////////////////////
    static Astar_Route CordPoint[3];
    it=astar_data->AStarRoute.begin();
    CordPoint[2] = (*it);
    CordPoint[1] = (*it);
    CordPoint[0] = (*it);

    debugmap.data[CordPoint[0].P_Id] = 99;
    astar_data->AStarGRoute.push_back(CordPoint[0]);

    ///////////////////////////////////////////////////////////////////////////////////
    static const float dYaw_Linear = 0.0872f;   // 5/57.3
    static float dYaw[2];
    static bool extend2threeFlag; extend2threeFlag = false;

    for(it = (astar_data->AStarRoute.begin() +1); it < astar_data->AStarRoute.end(); it+=SearchGuidePoint_Step)
    {
        if(extend2threeFlag){
            CordPoint[0] = (*it);
            //dYaw[0] = std::atan2(CordPoint[0].P_XY.dta1 - CordPoint[2].P_XY.dta1, CordPoint[0].P_XY.dta0 - CordPoint[2].P_XY.dta0);
            //dYaw[1] = std::atan2(CordPoint[1].P_XY.dta1 - CordPoint[2].P_XY.dta1, CordPoint[1].P_XY.dta0 - CordPoint[2].P_XY.dta0);

            if( true )//std::abs(dYaw[0] - dYaw[1]) > dYaw_Linear
            {
                CordPoint[2] = (*it);
                CordPoint[1] = (*it);
                extend2threeFlag = false;

                astar_data->AStarGRoute.push_back(CordPoint[0]);
                debugmap.data[CordPoint[0].P_Id] = 99; // set black to show
            }
        }else{
            extend2threeFlag = true;
            CordPoint[1] = (*it);
        }
    }
}

void A_STAR_FUNC::Func_Route_Show(void)
{
    static ros::NodeHandle nstru;
    static ros::Publisher debugmap_pub = nstru.advertise<nav_msgs::OccupancyGrid>("debugmap",1);
    if(Route_HavingFresh)
    {
        debugmap.header.stamp = ros::Time::now();
        debugmap_pub.publish(debugmap);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#define STEP_MAX                    1000000
#define STEP_LIMIT                  2400
#define AStar_Compare_DebugShow     false

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* ********************************************************************************
 * author: chenyingbing
 * time: 20161012   20:13   in XIAMEN University
 * illustration:
 *      most normal A* Algorithm
 *
 *      Space Complexity:
 *      Time  Complexity:
 * ********************************************************************************
*/

bool A_STAR_FUNC::Normal_AStar(unsigned int startP, unsigned int desP)
{
    if(FLAG_Map_S_Init)
    {
        static std::vector<unsigned int>::iterator it;
        static std::vector<unsigned int>::reverse_iterator r_it;
        static float deal1,deal2;

        //init nodemap, debugmap----------------------------------------
        directionLen = DIRECTIONLEN_4;
        directions = (float *)directions4;
        directionBuf = directionBuf4;

        for(it=Openlist.begin();it!=Openlist.end();it++)
        {
            nodemap[(*it)].flag = 0;

            nodemap[(*it)].value_f = 0;
            nodemap[(*it)].value_g = 0;
            nodemap[(*it)].value_h = 0;

            nodemap[(*it)].Parent_Id = 0;

            debugmap.data[(*it)] = -1;
        }
        for(it=Closelist.begin();it!=Closelist.end();it++)
        {
            nodemap[(*it)].flag = 0;

            nodemap[(*it)].value_f = 0;
            nodemap[(*it)].value_g = 0;
            nodemap[(*it)].value_h = 0;

            nodemap[(*it)].Parent_Id = 0;

            debugmap.data[(*it)] = -1;
        }
        Openlist.clear();
        Closelist.clear();

        //a star algorithm-----------------------
        static unsigned int step;   step = STEP_MAX;

        static unsigned int thisP;
        static int nextP;

        thisP = startP;                             // step 0: init thisP = startP
        Openlist.push_back(startP);                 // step 1: add to openlist
        nodemap[startP].flag = INOPENLIST;

        deal1 = desP % astar_param->MAP_WIDTH;
        deal2 = (desP-deal1)/astar_param->MAP_WIDTH;
        static unsigned int desP_X; desP_X = (unsigned int)(deal1);
        static unsigned int desP_Y; desP_Y = (unsigned int)(deal2);

        static bool toDes; toDes = false;
        if(nodemap[desP].sta != PATH)
        {
            return false;
        }

        while(step--)
        {
            #define f_NaN   1000000
            static float f_mincord;
            static unsigned int f_minid;

            f_mincord = f_NaN;
            f_minid = 0;

            // find minest in openlist and see if des in openlist
            for(r_it=Openlist.rbegin();r_it!=Openlist.rend();r_it++)
            {
                if((*r_it)==desP) toDes = true;

                if( nodemap[(*r_it)].flag == INOPENLIST)
                {   // Openlist Vector's data may be put in CloseList
                    if( nodemap[(*r_it)].value_f < f_mincord )
                    {
                        f_minid = (*r_it);
                        f_mincord = nodemap[(*r_it)].value_f;
                    }
                }
            }
            if(f_minid != 0)
            {
                nodemap[thisP].flag = INCLOSELIST;      // set thisP to CloseList
                Closelist.push_back(thisP);

                thisP = f_minid;    // to nextP
            }
            if(toDes)                                   //step final: finish algorithm;
            {
                break;
            }

            // search the neighborhood
            for(char i=0; i<directionLen; i++)
            {
                static float addgV;
                addgV = std::sqrt(directions[i*2]*directions[i*2] + directions[i*2+1]*directions[i*2+1]);

                nextP = thisP + directionBuf[i];

                if( (nextP > 0)&&(nextP<astar_param->MAP_LEN)&&(nodemap[nextP].sta == PATH) )  // is in maplen: available
                {
                    if(nodemap[nextP].flag == INOPENLIST)     // step 6: in openlist
                    {
                        deal1 = nodemap[nextP].value_g + addgV;
                        deal2 = nodemap[thisP].value_g;
                        if(deal1 < deal2)
                        {
                            nodemap[thisP].Parent_Id = nextP;

                            // recaculate the value_g
                            nodemap[thisP].value_g = deal1;

                            // have been calculated
                            //nodemap[thisP].value_h = abs(deal1 - desP_X) + abs(deal2 - desP_Y);

                            nodemap[thisP].value_f = nodemap[thisP].value_g + nodemap[thisP].value_h;
                        }
                    }else if (nodemap[nextP].flag == 0){    // step 2: add to openlist
                        nodemap[nextP].flag = INOPENLIST;
                        Openlist.push_back(nextP);

                        nodemap[nextP].Parent_Id = thisP;

                        nodemap[nextP].value_g = nodemap[thisP].value_g + addgV;                    //value_g

                        deal1 = nextP % astar_param->MAP_WIDTH;                     // x
                        deal2 = (nextP-deal1)/astar_param->MAP_WIDTH;               // y
                        nodemap[nextP].value_h = std::sqrt( std::pow(deal1 - desP_X, 2) +
                                                            std::pow(deal2 - desP_Y, 2) );          //value_h

                        nodemap[nextP].value_f = nodemap[nextP].value_g + nodemap[nextP].value_h;   //value_f

                    }else{
                        // do nothing if in closelist
                    }
                }
            }

        }//while(1)

        if(toDes){
            if(AStar_Compare_DebugShow) ROS_INFO("Normal AStar Step: %d ",STEP_MAX-step);
            return true;
        }else{
            ROS_ERROR("ERROR: Destination can't be reach! ");
            return false;
        }
    }
}

/* ********************************************************************************
 * author: chenyingbing
 * time: 20161019   19:37   in XIAMEN University
 * illustration:
 *      modified A* Algorithm 1
 *          + SafeSpace
 *      Space Complexity:
 *      Time  Complexity:
 * ********************************************************************************
*/

bool A_STAR_FUNC::Modified_AStar1(unsigned int startP, unsigned int desP)
{
    if(FLAG_Map_S_Init)
    {
        static std::vector<unsigned int>::iterator it;
        static std::vector<unsigned int>::reverse_iterator r_it;
        static float deal1,deal2;

        //init nodemap, debugmap----------------------------------------
        directionLen = DIRECTIONLEN_4;
        directions = (float *)directions4;
        directionBuf = directionBuf4;

        for(it=Openlist.begin();it!=Openlist.end();it++)
        {
            nodemap[(*it)].flag = 0;

            nodemap[(*it)].value_f = 0;
            nodemap[(*it)].value_g = 0;
            nodemap[(*it)].value_h = 0;

            nodemap[(*it)].Parent_Id = 0;

            debugmap.data[(*it)] = -1;
        }
        for(it=Closelist.begin();it!=Closelist.end();it++)
        {
            nodemap[(*it)].flag = 0;

            nodemap[(*it)].value_f = 0;
            nodemap[(*it)].value_g = 0;
            nodemap[(*it)].value_h = 0;

            nodemap[(*it)].Parent_Id = 0;

            debugmap.data[(*it)] = -1;
        }
        Openlist.clear();
        Closelist.clear();

        //a star algorithm-----------------------
        static unsigned int step;   step = STEP_MAX;

        static unsigned int thisP;
        static int nextP;

        thisP = startP;                             // step 0: init thisP = startP
        Openlist.push_back(startP);                 // step 1: add to openlist
        nodemap[startP].flag = INOPENLIST;

        deal1 = desP % astar_param->MAP_WIDTH;
        deal2 = (desP-deal1)/astar_param->MAP_WIDTH;
        static unsigned int desP_X; desP_X = (unsigned int)(deal1);
        static unsigned int desP_Y; desP_Y = (unsigned int)(deal2);

        static bool toDes; toDes = false;
        if(nodemap[desP].sta != PATH)
        {
            return false;
        }

        while(step--)
        {
            #define f_NaN   1000000
            static float f_mincord;
            static unsigned int f_minid;

            f_mincord = f_NaN;
            f_minid = 0;

            // find minest in openlist and see if des in openlist
            for(r_it=Openlist.rbegin();r_it!=Openlist.rend();r_it++)
            {
                if((*r_it)==desP) toDes = true;

                if( nodemap[(*r_it)].flag == INOPENLIST)
                {   // Openlist Vector's data may be put in CloseList
                    if( nodemap[(*r_it)].value_f < f_mincord )
                    {
                        f_minid = (*r_it);
                        f_mincord = nodemap[(*r_it)].value_f;
                    }
                }
            }

            if(f_minid != 0)
            {
                nodemap[thisP].flag = INCLOSELIST;      // set thisP to CloseList
                Closelist.push_back(thisP);

                thisP = f_minid;    // to nextP
            }
            if(toDes)                                   //step final: finish algorithm;
            {
                break;
            }

            // search the neighborhood
            for(char i=0; i<directionLen; i++)
            {
                static float addgV;
                addgV = std::sqrt(directions[i*2]*directions[i*2] + directions[i*2+1]*directions[i*2+1]);

                nextP = thisP + directionBuf[i];

                if( (nextP > 0)&&(nextP<astar_param->MAP_LEN)&&(nodemap[nextP].sta < OBSTACLE) )  // is in maplen: available
                {
                    if(nodemap[nextP].flag == INOPENLIST)     // step 6: in openlist
                    {
                        deal1 = nodemap[nextP].value_g + addgV;
                        deal2 = nodemap[thisP].value_g;
                        if(deal1 < deal2)
                        {
                            nodemap[thisP].Parent_Id = nextP;

                            // recaculate the value_g
                            nodemap[thisP].value_g = deal1;

                            // have been calculated
                            //nodemap[thisP].value_h = abs(deal1 - desP_X) + abs(deal2 - desP_Y);

                            nodemap[thisP].value_f = nodemap[thisP].value_g + nodemap[thisP].value_h
                                                     + nodemap[thisP].value_s;
                        }

                    }else if (nodemap[nextP].flag == 0){    // step 2: add to openlist
                        nodemap[nextP].flag = INOPENLIST;
                        Openlist.push_back(nextP);

                        nodemap[nextP].Parent_Id = thisP;

                        nodemap[nextP].value_g = nodemap[thisP].value_g + addgV;                    //value_g

                        deal1 = nextP % astar_param->MAP_WIDTH;                     // x
                        deal2 = (nextP-deal1)/astar_param->MAP_WIDTH;               // y
                        nodemap[nextP].value_h = std::sqrt( std::pow(deal1 - desP_X, 2) +
                                                            std::pow(deal2 - desP_Y, 2) );          //value_h

                        nodemap[nextP].value_f = nodemap[nextP].value_g + nodemap[nextP].value_h
                                                 + nodemap[nextP].value_s;                          //value_f

                    }else{
                        // do nothing if in closelist
                    }
                }
            }

        }//while(1)

        if(toDes){
            if(AStar_Compare_DebugShow) ROS_INFO("Modified AStar1 Step: %d ",STEP_MAX-step);
            return true;
        }else{
            ROS_ERROR("ERROR: Destination can't be reach! ");
            return false;
        }
    }
}

/* ********************************************************************************
 * author: chenyingbing
 * time: 20161027   ????   in XIAMEN University
 * illustration:
 *      modified A* Algorithm 2
 *          + SafeSpace
 *          + Openlist Sorting
 *          + Manhattan distance
 *      Space Complexity:
 *      Time  Complexity:
 * ********************************************************************************
*/

bool A_STAR_FUNC::Modified_AStar2(unsigned int startP, unsigned int desP)
{
    if(FLAG_Map_S_Init)
    {
        static std::vector<unsigned int>::iterator it;
        static float deal1,deal2;

        //init nodemap, debugmap----------------------------------------
        directionLen = DIRECTIONLEN_4;
        directions = (float *)directions4;
        directionBuf = directionBuf4;

        for(it=Openlist.begin();it!=Openlist.end();it++)
        {
            nodemap[(*it)].flag = 0;

            nodemap[(*it)].value_f = 0;
            nodemap[(*it)].value_g = 0;
            nodemap[(*it)].value_h = 0;

            nodemap[(*it)].Parent_Id = 0;

            debugmap.data[(*it)] = -1;
        }
        for(it=Closelist.begin();it!=Closelist.end();it++)
        {
            nodemap[(*it)].flag = 0;

            nodemap[(*it)].value_f = 0;
            nodemap[(*it)].value_g = 0;
            nodemap[(*it)].value_h = 0;

            nodemap[(*it)].Parent_Id = 0;

            debugmap.data[(*it)] = -1;
        }
        Openlist.clear();
        Closelist.clear();

        //a star algorithm-----------------------
        static unsigned int step;   step = STEP_MAX;

        static unsigned int thisP;
        static int nextP;

        thisP = startP;                             // step 0: init thisP = startP
        Openlist.push_back(startP);                 // step 1: add to openlist
        nodemap[startP].flag = INOPENLIST;

        deal1 = desP % astar_param->MAP_WIDTH;
        deal2 = (desP-deal1)/astar_param->MAP_WIDTH;
        static unsigned int desP_X; desP_X = (unsigned int)(deal1);
        static unsigned int desP_Y; desP_Y = (unsigned int)(deal2);

        static bool toDes; toDes = false;
        if(nodemap[desP].sta != PATH)
        {
            return false;
        }

        while(step--)
        {
            #define f_NaN   1000000
            static float f_mincord;
            static unsigned int f_minid;

            f_mincord = f_NaN;
            f_minid = 0;

            // find minest in openlist and see if desP is in Openlist
            for(it=Openlist.begin();it!=Openlist.end();it++)
            {
                if( nodemap[(*it)].flag == INOPENLIST)
                {   // Openlist Vector's data may be put in CloseList
                    if((*it)==desP) toDes = true;

                    f_minid = (*it);
                    f_mincord = nodemap[(*it)].value_f;

                    break;
                }
            }

            if(f_minid != 0)
            {
                nodemap[thisP].flag = INCLOSELIST;      // set thisP to CloseList
                Closelist.push_back(thisP);

                thisP = f_minid;    // to nextP
            }
            if(toDes)                                   //step final: finish algorithm;
            {
                break;
            }

            // search the neighborhood
            for(char i=0; i<directionLen; i++)
            {
                static float addgV;
                static float direction4_cost = 1.0f/astar_param->MAP_WIDTH;
                //addgV = (std::abs(directions[i*2]) + std::abs(directions[i*2+1]));
                addgV = direction4_cost;

                nextP = thisP + directionBuf[i];

                if( (nextP > 0)&&(nextP<astar_param->MAP_LEN)&&(nodemap[nextP].sta < OBSTACLE) )  // is in maplen: available
                {
                    if(nodemap[nextP].flag == INOPENLIST)     // step 6: in openlist
                    {
                        deal1 = nodemap[nextP].value_g + addgV;
                        deal2 = nodemap[thisP].value_g;
                        if(deal1 < deal2)
                        {
                            nodemap[thisP].Parent_Id = nextP;

                            // recaculate the value_g
                            nodemap[thisP].value_g = deal1;

                            // have been calculated
                            //nodemap[thisP].value_h

                            nodemap[thisP].value_f = nodemap[thisP].value_g + nodemap[thisP].value_h
                                                     + nodemap[thisP].value_s;
                        }

                    }else if (nodemap[nextP].flag == 0){    // step 2: add to openlist
                        nodemap[nextP].Parent_Id = thisP;

                        nodemap[nextP].value_g = nodemap[thisP].value_g + addgV;                    //value_g

                        deal1 = nextP % astar_param->MAP_WIDTH;                     // x
                        deal2 = (nextP-deal1)/astar_param->MAP_WIDTH;               // y
                        nodemap[nextP].value_h = (abs(deal1 - desP_X) + abs(deal2 - desP_Y));       //value_h

                        nodemap[nextP].value_f = nodemap[nextP].value_g + nodemap[nextP].value_h
                                                 + nodemap[nextP].value_s;                          //value_f

                        // insert to openlist in the order from minest to largest
                        nodemap[nextP].flag = INOPENLIST;

                        static bool IsInsert;   IsInsert = false;
                        static int OpenlistId;
                        for(it=Openlist.begin(), OpenlistId = 0;
                            it!=Openlist.end();
                            it++, OpenlistId++)
                        {
                            if ((nodemap[nextP].value_f <= nodemap[(*it)].value_f) &&
                               ( nodemap[nextP].flag == INOPENLIST)){

                                Openlist.insert(Openlist.begin()+OpenlistId, nextP);

                                IsInsert = true;
                                break;
                            }
                        }
                        if(!IsInsert){
                            Openlist.push_back(nextP);
                        }

                    }else{
                        // do nothing if in closelist
                    }
                }
            }

        }//while(1)

        if(toDes){
            if(AStar_Compare_DebugShow) ROS_INFO("Modified AStar2 Step: %d ",STEP_MAX-step);
            return true;
        }else{
            int ddd = Openlist.size();
            ROS_ERROR("ERROR: Destination can't be reach! %d ",ddd);
            return false;
        }
    }
}

/* ********************************************************************************
 * author: chenyingbing
 * time: 20161029   17:04   in XIAMEN University
 * illustration:
 *      modified A* Algorithm 3
 *          + SafeSpace
 *          + Openlist Sorting
 *          + Chebyshev Distance
 *      Space Complexity:
 *      Time  Complexity:
 * ********************************************************************************
*/

bool A_STAR_FUNC::Modified_AStar3(unsigned int startP, unsigned int desP)
{
    if(FLAG_Map_S_Init)
    {
        static std::vector<unsigned int>::iterator it;
        static float deal1,deal2;

        //init nodemap, debugmap----------------------------------------
        directionLen = DIRECTIONLEN_4;
        directions = (float *)directions4;
        directionBuf = directionBuf4;

        for(it=Openlist.begin();it!=Openlist.end();it++)
        {
            nodemap[(*it)].flag = 0;

            nodemap[(*it)].value_f = 0;
            nodemap[(*it)].value_g = 0;
            nodemap[(*it)].value_h = 0;

            nodemap[(*it)].Parent_Id = 0;

            debugmap.data[(*it)] = -1;
        }
        for(it=Closelist.begin();it!=Closelist.end();it++)
        {
            nodemap[(*it)].flag = 0;

            nodemap[(*it)].value_f = 0;
            nodemap[(*it)].value_g = 0;
            nodemap[(*it)].value_h = 0;

            nodemap[(*it)].Parent_Id = 0;

            debugmap.data[(*it)] = -1;
        }
        Openlist.clear();
        Closelist.clear();

        //a star algorithm-----------------------
        static unsigned int step;   step = STEP_MAX;

        static unsigned int thisP;
        static int nextP;

        thisP = startP;                             // step 0: init thisP = startP
        Openlist.push_back(startP);                 // step 1: add to openlist
        nodemap[startP].flag = INOPENLIST;

        deal1 = desP % astar_param->MAP_WIDTH;
        deal2 = (desP-deal1)/astar_param->MAP_WIDTH;
        static unsigned int desP_X; desP_X = (unsigned int)(deal1);
        static unsigned int desP_Y; desP_Y = (unsigned int)(deal2);

        static bool toDes; toDes = false;
        if(nodemap[desP].sta != PATH)
        {
            return false;
        }

        while(step--)
        {
            #define f_NaN   1000000
            static float f_mincord;
            static unsigned int f_minid;

            f_mincord = f_NaN;
            f_minid = 0;

            // find minest in openlist and see if desP is in Openlist
            for(it=Openlist.begin();it!=Openlist.end();it++)
            {
                if((*it)==desP) toDes = true;

                if( nodemap[(*it)].flag == INOPENLIST)
                {   // Openlist Vector's data may be put in CloseList
                    f_minid = (*it);
                    f_mincord = nodemap[(*it)].value_f;
                    break;
                }
            }

            if(f_minid != 0)
            {
                nodemap[thisP].flag = INCLOSELIST;      // set thisP to CloseList
                Closelist.push_back(thisP);

                thisP = f_minid;    // to nextP
            }
            if(toDes)                                   //step final: finish algorithm;
            {
                break;
            }

            // search the neighborhood
            for(char i=0; i<directionLen; i++)
            {
                static float addgV;
                addgV = std::max(abs(directions[i*2]),std::abs(directions[i*2+1]));

                nextP = thisP + directionBuf[i];

                if( (nextP > 0)&&(nextP<astar_param->MAP_LEN)&&(nodemap[nextP].sta < OBSTACLE) )  // is in maplen: available
                {
                    if(nodemap[nextP].flag == INOPENLIST)     // step 6: in openlist
                    {
                        deal1 = nodemap[nextP].value_g + addgV;
                        deal2 = nodemap[thisP].value_g;
                        if(deal1 < deal2)
                        {
                            nodemap[thisP].Parent_Id = nextP;

                            // recaculate the value_g
                            nodemap[thisP].value_g = deal1;

                            // have been calculated
                            //nodemap[thisP].value_h = abs(deal1 - desP_X) + abs(deal2 - desP_Y);

                            nodemap[thisP].value_f = nodemap[thisP].value_g + nodemap[thisP].value_h
                                                     + nodemap[thisP].value_s;
                        }

                    }else if (nodemap[nextP].flag == 0){    // step 2: add to openlist
                        nodemap[nextP].Parent_Id = thisP;

                        nodemap[nextP].value_g = nodemap[thisP].value_g + addgV;                    //value_g

                        deal1 = nextP % astar_param->MAP_WIDTH;                     // x
                        deal2 = (nextP-deal1)/astar_param->MAP_WIDTH;               // y
                        nodemap[nextP].value_h = std::max(abs(deal1 - desP_X), abs(deal2 - desP_Y));         //value_h

                        nodemap[nextP].value_f = nodemap[nextP].value_g + nodemap[nextP].value_h
                                                 + nodemap[nextP].value_s;                          //value_f

                        // insert to openlist in the order from minest to largest
                        nodemap[nextP].flag = INOPENLIST;

                        static bool IsInsert;   IsInsert = false;
                        static int OpenlistId;
                        for(it=Openlist.begin(), OpenlistId = 0;
                            it!=Openlist.end();
                            it++, OpenlistId++)
                        {
                            if ((nodemap[nextP].value_f <= nodemap[(*it)].value_f) &&
                               ( nodemap[nextP].flag == INOPENLIST)){
                                Openlist.insert(Openlist.begin()+OpenlistId, nextP);
                                IsInsert = true;
                                break;
                            }
                        }
                        if(!IsInsert){
                            Openlist.push_back(nextP);
                        }

                    }else{
                        // do nothing if in closelist
                    }
                }
            }

        }//while(1)

        if(toDes){
            if(AStar_Compare_DebugShow) ROS_INFO("Modified AStar3 Step: %d ",STEP_MAX-step);
            return true;
        }else{
            ROS_ERROR("ERROR: Destination can't be reach! ");
            return false;
        }
    }
}

/* ********************************************************************************
 * author: chenyingbing
 * time: 20161029   17:04   in XIAMEN University
 * illustration:
 *      modified A* Algorithm 4
 *          + SafeSpace
 *          + Openlist Sorting
 *          + Chebyshev Distance
 *          + Child_Id, Step_Limit
 *      Space Complexity:
 *      Time  Complexity:
 *
 * ********************************************************************************
*/

bool A_STAR_FUNC::Modified_AStar4(unsigned int startP, unsigned int desP)
{
    if(FLAG_Map_S_Init)
    {
        static std::vector<unsigned int>::iterator it;
        static float deal1,deal2;

        //init nodemap, debugmap----------------------------------------
        directionLen = DIRECTIONLEN_4;
        directions = (float *)directions4;
        directionBuf = directionBuf4;

        for(it=Openlist.begin();it!=Openlist.end();it++)
        {
            nodemap[(*it)].flag = 0;

            nodemap[(*it)].value_f = 0;
            nodemap[(*it)].value_g = 0;
            nodemap[(*it)].value_h = 0;

            nodemap[(*it)].Parent_Id = 0;
            nodemap[(*it)].Child_Id = 0;

            debugmap.data[(*it)] = -1;
        }
        for(it=Closelist.begin();it!=Closelist.end();it++)
        {
            nodemap[(*it)].flag = 0;

            nodemap[(*it)].value_f = 0;
            nodemap[(*it)].value_g = 0;
            nodemap[(*it)].value_h = 0;

            nodemap[(*it)].Parent_Id = 0;
            nodemap[(*it)].Child_Id = 0;

            debugmap.data[(*it)] = -1;
        }
        Openlist.clear();
        Closelist.clear();

        //a star algorithm-----------------------
        static unsigned int step;   step = STEP_LIMIT;

        static unsigned int thisP;
        static int nextP;

        thisP = startP;                             // step 0: init thisP = startP
        Openlist.push_back(startP);                 // step 1: add to openlist
        nodemap[startP].flag = INOPENLIST;

        deal1 = desP % astar_param->MAP_WIDTH;
        deal2 = (desP-deal1)/astar_param->MAP_WIDTH;
        static unsigned int desP_X; desP_X = (unsigned int)(deal1);
        static unsigned int desP_Y; desP_Y = (unsigned int)(deal2);

        static bool toDes; toDes = false;
        if(nodemap[desP].sta != PATH)
        {
            return false;
        }

        while(step--)
        {
            #define f_NaN   1000000
            static float f_mincord;
            static unsigned int f_minid;

            f_mincord = f_NaN;
            f_minid = 0;

            // find minest in openlist and see if desP is in Openlist
            for(it=Openlist.begin();it!=Openlist.end();it++)
            {
                if( nodemap[(*it)].flag == INOPENLIST)
                {   // Openlist Vector's data may be put in CloseList
                    if((*it)==desP) toDes = true;

                    f_minid = (*it);
                    f_mincord = nodemap[(*it)].value_f;

                    break;
                }
            }

            if(f_minid != 0)
            {
                nodemap[thisP].flag = INCLOSELIST;      // set thisP to CloseList
                Closelist.push_back(thisP);

                nodemap[thisP].Child_Id = nodemap[f_minid].Parent_Id;
                nodemap[(nodemap[f_minid].Parent_Id)].Child_Id = f_minid;

                thisP = f_minid;    // to nextP
            }
            if(toDes)                                   //step final: finish algorithm;
            {
                break;
            }

            // search the neighborhood
            for(char i=0; i<directionLen; i++)
            {
                static float addgV;
                addgV = std::abs(directions[i*2]) + std::abs(directions[i*2+1]);

                nextP = thisP + directionBuf[i];

                if( (nextP > 0)&&(nextP<astar_param->MAP_LEN)&&(nodemap[nextP].sta < OBSTACLE) )  // is in maplen: available
                {
                    if(nodemap[nextP].flag == INOPENLIST)     // step 6: in openlist
                    {
                        deal1 = nodemap[nextP].value_g + addgV;
                        deal2 = nodemap[thisP].value_g;
                        if(deal1 < deal2)
                        {
                            nodemap[thisP].Parent_Id = nextP;

                            nodemap[(nodemap[nextP].Parent_Id)].Child_Id = nextP;
                            nodemap[nextP].Child_Id = thisP;

                            // recaculate the value_g
                            nodemap[thisP].value_g = deal1;

                            // have been calculated
                            //nodemap[thisP].value_h = abs(deal1 - desP_X) + abs(deal2 - desP_Y);

                            nodemap[thisP].value_f = nodemap[thisP].value_g + nodemap[thisP].value_h
                                                     + nodemap[thisP].value_s;
                        }

                    }else if (nodemap[nextP].flag == 0){    // step 2: add to openlist
                        nodemap[nextP].Parent_Id = thisP;

                        nodemap[nextP].value_g = nodemap[thisP].value_g + addgV;                    //value_g

                        deal1 = nextP % astar_param->MAP_WIDTH;                     // x
                        deal2 = (nextP-deal1)/astar_param->MAP_WIDTH;               // y
                        nodemap[nextP].value_h = abs(deal1 - desP_X) + abs(deal2 - desP_Y);         //value_h

                        nodemap[nextP].value_f = nodemap[nextP].value_g + nodemap[nextP].value_h
                                                 + nodemap[nextP].value_s;                          //value_f

                        // insert to openlist in the order from minest to largest
                        nodemap[nextP].flag = INOPENLIST;

                        static bool IsInsert;   IsInsert = false;
                        static int OpenlistId;
                        for(it=Openlist.begin(), OpenlistId = 0;
                            it!=Openlist.end();
                            it++, OpenlistId++)
                        {
                            if ((nodemap[nextP].value_f <= nodemap[(*it)].value_f) &&
                               ( nodemap[nextP].flag == INOPENLIST)){

                                Openlist.insert(Openlist.begin()+OpenlistId, nextP);

                                IsInsert = true;
                                break;
                            }
                        }
                        if(!IsInsert){
                            Openlist.push_back(nextP);
                        }

                    }else{
                        // do nothing if in closelist
                    }
                }
            }

        }//while(1)

        if(toDes)
        {
            astar_data->DesP_Id_SLimit = astar_data->DesP_Id;;
        }else{
            astar_data->DesP_Id_SLimit = thisP;
        }

        return true;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

















