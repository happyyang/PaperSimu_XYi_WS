#include "manage_thread.h"

#include "tf/transform_broadcaster.h"
#include "tf/transform_listener.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void tf_brocasterFun1(nav_msgs::Odometry odom, float *LsrLocation);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void TASK_THREAD::DataInit(double *LsrLInit)
{
    CONST_LsrLocation[0] = LsrLInit[0];
    CONST_LsrLocation[1] = LsrLInit[1];
    CONST_LsrLocation[2] = LsrLInit[2];

    taskInit = true;
}

void TASK_THREAD::DataFeed(nav_msgs::Odometry odom)
{
    if(mutex == true)
    {
        mutex = false;

        DtaOdom = odom;

        mutex = true;
    }
}

void TASK_THREAD::task()
{
	while(1)
	{
		try
		{
			boost::this_thread::interruption_point();
            //ROS_INFO(" test thread 200ms ");

            if (taskInit == true)
            {
                if(mutex == true)
                {
                    mutex = false;
                    tf_brocasterFun1(DtaOdom, CONST_LsrLocation);
                    mutex = true;
                }
            }

            boost::this_thread::sleep(boost::posix_time::milliseconds(100));
		}
		catch(boost::thread_interrupted&)
		{

		}

	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void tf_brocasterFun1(nav_msgs::Odometry odom, float *LsrLocation)
{
    //-----------------------------------------------------------------------
    static tf::TransformBroadcaster tfbr;
    static tf::Transform tftrans;

    //Parent: odom_r, Child: base_footprint_r
    tftrans.setOrigin(tf::Vector3(odom.pose.pose.position.x,
                                    odom.pose.pose.position.y,
                                     odom.pose.pose.position.z));
    tftrans.setRotation(tf::Quaternion(odom.pose.pose.orientation.x,
                                         odom.pose.pose.orientation.y,
                                          odom.pose.pose.orientation.z,
                                           odom.pose.pose.orientation.w));
    tfbr.sendTransform(tf::StampedTransform(tftrans, ros::Time::now(), "odom_r", "base_footprint_r"));

    //-----------------------------------------------------------------------
    const static float base_footprint2base_link[7] = {0,0,0, 0,0,0,1};
    static tf::TransformBroadcaster tfbr0;
    static tf::Transform tftrans0;

    //Parent: base_footprint_r, Child: base_link_r
    tftrans0.setOrigin(tf::Vector3(base_footprint2base_link[0],
                                    base_footprint2base_link[1],
                                     base_footprint2base_link[2]));
    tftrans0.setRotation(tf::Quaternion(base_footprint2base_link[3],
                                         base_footprint2base_link[4],
                                          base_footprint2base_link[5],
                                           base_footprint2base_link[6]));
    tfbr0.sendTransform(tf::StampedTransform(tftrans0, ros::Time::now(), "base_footprint_r", "base_link_r"));

    //-----------------------------------------------------------------------
    const static float base_link2base_laser_link[7] = {0,0,0, 0,0,0,1}; // just use [3-6]
    static tf::TransformBroadcaster tfbr1;
    static tf::Transform tftrans1;

    //Parent: base_link_r, Child: base_laser_link_r
    tftrans1.setOrigin(tf::Vector3(LsrLocation[0],
                                    LsrLocation[1],
                                     LsrLocation[2]));
    tftrans1.setRotation(tf::Quaternion(base_link2base_laser_link[3],
                                         base_link2base_laser_link[4],
                                          base_link2base_laser_link[5],
                                           base_link2base_laser_link[6]));
    tfbr1.sendTransform(tf::StampedTransform(tftrans1, ros::Time::now(), "base_link_r", "base_laser_link_r"));

    //-----------------------------------------------------------------------
    /*
    const static float base_link2base_link[7] = {0,0,0, 0,0,0,1};
    static tf::TransformBroadcaster tfbr2;
    static tf::Transform tftrans2;

    //Parent: base_laser_link_r, Child: base_laser_link
    tftrans2.setOrigin(tf::Vector3(base_link2base_link[0],
                                    base_link2base_link[1],
                                     base_link2base_link[2]));
    tftrans2.setRotation(tf::Quaternion(base_link2base_link[3],
                                         base_link2base_link[4],
                                          base_link2base_link[5],
                                           base_link2base_link[6]));
    tfbr2.sendTransform(tf::StampedTransform(tftrans2, ros::Time::now(), "base_laser_link_r", "base_laser_link"));
    */
    //-----------------------------------------------------------------------
}



