#ifndef __map_s_datatype_H
#define __map_s_datatype_H

typedef class Map_S_DataType
{
public:
    const nav_msgs::OccupancyGrid *r_map;

    cv::Mat Map_MatDta;
    IplImage *Map_Image;

    cv::Mat Map_MatDta_Compared;
    IplImage *Map_Image_Compared;

    nav_msgs::OccupancyGrid guidemap;
    volatile bool guidemap_init;

    Map_S_DataType()
    {
        guidemap_init = false;
    }

    ~Map_S_DataType()
    {
        delete r_map;
        cvReleaseImage(&Map_Image);
        cvReleaseImage(&Map_Image_Compared);
    }

}Map_S_DataType;






















#endif
