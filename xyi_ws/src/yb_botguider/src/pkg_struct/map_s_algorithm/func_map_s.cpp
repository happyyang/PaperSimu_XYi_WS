#include "map_s_algorithm.h"

void MAP_S_FUNC::Func_GetCostMap(void)
{
    if(map_param->mapparam_init)
    {
        // create space
        map_s_data->Map_MatDta.create(map_param->MAP_WIDTH, map_param->MAP_HEIGHT, CV_8UC1);
        map_s_data->Map_MatDta_Compared.create(map_param->MAP_WIDTH, map_param->MAP_HEIGHT, CV_8UC1);

        // copy data to map_s_data->Map_MatDta
        uchar* p; int i,j;
        for( i = 0; i < map_param->MAP_WIDTH; ++i)
        {
            p = map_s_data->Map_MatDta.ptr<uchar>(i);

            for (j = 0; j < map_param->MAP_HEIGHT; ++j)
            {
                p[j] = map_s_data->r_map->data[ (i*map_param->MAP_WIDTH + j) ];
            }
        }

        // generate IplImage
        map_s_data->Map_Image           = new IplImage(map_s_data->Map_MatDta);
        map_s_data->Map_Image_Compared  = new IplImage(map_s_data->Map_MatDta_Compared);

        // image deal...
        int RoundDiameter = int(map_param->Robot_Physical_Radius * 2.0 / map_param->MAP_RESOLUTION);
        int values = RoundDiameter*RoundDiameter;
        int CenterRound = int(RoundDiameter/2)-1;

        cvThreshold(map_s_data->Map_Image,map_s_data->Map_Image, 0, 255, CV_THRESH_BINARY);
        cvDilate(map_s_data->Map_Image, map_s_data->Map_Image,
                 cvCreateStructuringElementEx(RoundDiameter, RoundDiameter,
                                              CenterRound, CenterRound,
                                              CV_SHAPE_ELLIPSE,
                                              &values),
                 1
                 );

        RoundDiameter = int(map_param->Robot_Physical_Radius * 2.0f / map_param->MAP_RESOLUTION);
        cv::Mat filter_kernel(RoundDiameter,RoundDiameter,CV_32F);
        float *fp;
        float fp_value = 1.0f/(float(RoundDiameter*RoundDiameter));
        for( i = 0; i < RoundDiameter; ++i)
        {
            fp = filter_kernel.ptr<float>(i);

            for (j = 0; j < RoundDiameter; ++j)
            {
                fp[j] = fp_value;
            }
        }

        cv::filter2D(map_s_data->Map_MatDta, map_s_data->Map_MatDta_Compared, -1, filter_kernel);

        // reset obstacle and copy to pubmap show
        uchar* q;
        map_s_data->guidemap.header.frame_id = map_s_data->r_map->header.frame_id;
        map_s_data->guidemap.info = map_s_data->r_map->info;

        map_s_data->guidemap.data.resize(map_param->MAP_LEN,-1);
        for( i = 0; i < map_param->MAP_WIDTH; ++i)
        {
            q = map_s_data->Map_MatDta.ptr<uchar>(i);
            p = map_s_data->Map_MatDta_Compared.ptr<uchar>(i);

            for (j = 0; j < map_param->MAP_HEIGHT; ++j)
            {
                //q[j], p[j] is read only!!!
                if(q[j] == 255){
                    map_s_data->guidemap.data[ (i*map_param->MAP_WIDTH + j) ] = 255;
                }else{
                    map_s_data->guidemap.data[ (i*map_param->MAP_WIDTH + j) ] = p[j];
                }
                // 255 is black, 0 is white
            }
        }

        map_s_data->guidemap_init = true;
    }
}

void MAP_S_FUNC::Func_PubMap(void)
{
    static ros::NodeHandle nstru;
    static ros::Publisher gmap_pub = nstru.advertise<nav_msgs::OccupancyGrid>("guidemap",1);

    if(FLAG_taskInit)
    {
        map_s_data->guidemap.header.stamp = ros::Time::now();
        gmap_pub.publish(map_s_data->guidemap);
    }
}









