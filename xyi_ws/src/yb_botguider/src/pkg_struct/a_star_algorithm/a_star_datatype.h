#ifndef __a_star_datatype_H
#define __a_star_datatype_H

enum{ PATH=0, OBSTACLE=255};
enum{ INOPENLIST=1, INCLOSELIST=2};

typedef class Astar_Node
{
public:
    unsigned char    sta;
    unsigned char    flag;

    float value_f;
    float value_g;
    float value_h;
    float value_s;  // value safe

    unsigned int Parent_Id;
    unsigned int Child_Id;

    Astar_Node()
    {
        sta = PATH;
        flag = 0;

        value_f = 0;
        value_g = 0;
        value_h = 0;
        value_s = 255;

        Parent_Id = 0;
        Child_Id = 0;
    }

    ~Astar_Node()
    {

    }

}Astar_Node;

typedef struct Astar_Route
{
    int P_Id;           // Point's Id in Map
    Int2Array P_XY;     // Point's X Y Location in Map

}ASTARROUTE;

typedef class A_STAR_DataType
{
public:

    volatile bool mutex_GRouteMessage;
    int StartP_Id, DesP_Id;
    int DesP_Id_SLimit;

    std::vector<Astar_Route> AStarRoute;
    std::vector<Astar_Route> AStarGRoute;

    volatile bool route_s_init;             // wait algorithm to get route. : out

    A_STAR_DataType()
    {
        route_s_init = false;
        AStarRoute.clear();

        mutex_GRouteMessage = true;
    }

    ~A_STAR_DataType()
    {
        AStarRoute.clear();
    }

}A_STAR_DataType;





#endif
