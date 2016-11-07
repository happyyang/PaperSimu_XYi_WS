#include "pkg_struct.h"

void GuiderPkgStruct::Pkg_Init(double *pram)
{
    if(!param.launchparam_init)
    {
        param.Robot_Physical_Radius = pram[0];
        param.Laser_Dta_BDlen = int(pram[1]);
        param.Laser_Dta_EDlen = int(pram[2]);
        param.MapSafe_Robot_Radius = pram[3];
        param.launchparam_init = true;

    }
}
void GuiderPkgStruct::Pkg_Release(void)
{

}

void GuiderPkgStruct::Pkg_MainRunning(void)
{
    // common part
    TfSubscribe_Task();
    GoalPose_TopicsShow_Task();

    // task part
    static_map_task.Pkg_MainRunning();
    astar_task.Pkg_MainRunning();

    /*
    ROS_INFO(" Init Sta: %d, %d, %d, %d; ", param.launchparam_init,
                                            param.mapparam_init,
                                            param.lsrparam_init,
                                            param.tfparam_init);
    */
}

// TfSubscribe_Task ****************************************************************/
void GuiderPkgStruct::TfSubscribe_Task(void)
{
    static tf::TransformListener listener1;
    static tf::StampedTransform transform1;

    static tf::TransformListener listener2;
    static tf::StampedTransform transform2;

    static tf::TransformListener listener3;
    static tf::StampedTransform transform3;

    static tf::TransformListener listener4;
    static tf::StampedTransform transform4;

    try{
        //------------------------------------------------------------
        listener1.lookupTransform("/map_r", "/base_link_r", ros::Time(0), transform1);
        param.TF_MAP2Robot.position.x = transform1.getOrigin().x();
        param.TF_MAP2Robot.position.y = transform1.getOrigin().y();
        param.TF_MAP2Robot.position.z = transform1.getOrigin().z();
        param.TF_MAP2Robot.orientation.w = transform1.getRotation().w();
        param.TF_MAP2Robot.orientation.x = transform1.getRotation().x();
        param.TF_MAP2Robot.orientation.y = transform1.getRotation().y();
        param.TF_MAP2Robot.orientation.z = transform1.getRotation().z();

        listener2.lookupTransform("/map_r", "/odom_r", ros::Time(0), transform2);
        param.TF_MAP2Odom.position.x = transform2.getOrigin().x();
        param.TF_MAP2Odom.position.y = transform2.getOrigin().y();
        param.TF_MAP2Odom.position.z = transform2.getOrigin().z();
        param.TF_MAP2Odom.orientation.w = transform2.getRotation().w();
        param.TF_MAP2Odom.orientation.x = transform2.getRotation().x();
        param.TF_MAP2Odom.orientation.y = transform2.getRotation().y();
        param.TF_MAP2Odom.orientation.z = transform2.getRotation().z();

        listener3.lookupTransform("/odom_r", "/base_link_r", ros::Time(0), transform3);
        param.TF_Odom2Robot.position.x = transform3.getOrigin().x();
        param.TF_Odom2Robot.position.y = transform3.getOrigin().y();
        param.TF_Odom2Robot.position.z = transform3.getOrigin().z();
        param.TF_Odom2Robot.orientation.w = transform3.getRotation().w();
        param.TF_Odom2Robot.orientation.x = transform3.getRotation().x();
        param.TF_Odom2Robot.orientation.y = transform3.getRotation().y();
        param.TF_Odom2Robot.orientation.z = transform3.getRotation().z();

        listener4.lookupTransform("/base_link_r", "/base_laser_link_r", ros::Time(0), transform4);
        param.TF_Robot2Lsr.position.x = transform4.getOrigin().x();
        param.TF_Robot2Lsr.position.y = transform4.getOrigin().y();
        param.TF_Robot2Lsr.position.z = transform4.getOrigin().z();
        param.TF_Robot2Lsr.orientation.w = transform4.getRotation().w();
        param.TF_Robot2Lsr.orientation.x = transform4.getRotation().x();
        param.TF_Robot2Lsr.orientation.y = transform4.getRotation().y();
        param.TF_Robot2Lsr.orientation.z = transform4.getRotation().z();

        param.tfparam_init = true;
    }catch (tf::TransformException &ex) {
        ROS_ERROR("%s",ex.what());
        ros::Duration(1.0).sleep();

    }
}

void GuiderPkgStruct::GoalPose_TopicsShow_Task(void)
{
    static ros::NodeHandle nstru;
    static ros::Publisher gpose_pub = nstru.advertise<geometry_msgs::PoseStamped>("goalpose",1);
    geometry_msgs::PoseStamped gpose;

    if (param.goalparam_init)
    {
        gpose.header.frame_id = "map_r";
        gpose.header.stamp = ros::Time::now();
        gpose.pose = param.TF_Map2GoalPose;
        gpose_pub.publish(gpose);
    }
}




