#include "tf_manage.h"

#include "manage_thread.h"

/* ============================
	  MainFunc Group
============================= */
static nav_msgs::Odometry DtaOdom;
void RobotOdomTopics_Call(const nav_msgs::Odometry& odomdta)
{
    DtaOdom = odomdta;
}

void RobotSimuLsrTopics_Call(const sensor_msgs::LaserScan& lsrdta)
{
    static ros::NodeHandle nstru;
    static sensor_msgs::LaserScan Lsrdta_new;
    Lsrdta_new.header = lsrdta.header;
    Lsrdta_new.header.stamp = ros::Time::now();
    Lsrdta_new.header.frame_id = "base_laser_link_r";

    Lsrdta_new.angle_increment = lsrdta.angle_increment;
    Lsrdta_new.angle_max = lsrdta.angle_max;
    Lsrdta_new.angle_min = lsrdta.angle_min;
    Lsrdta_new.time_increment = lsrdta.time_increment;
    Lsrdta_new.scan_time = lsrdta.scan_time;
    Lsrdta_new.range_max = lsrdta.range_max;
    Lsrdta_new.range_min = lsrdta.range_min;

    Lsrdta_new.ranges = lsrdta.ranges;
    Lsrdta_new.intensities = lsrdta.intensities;

    static ros::Publisher pub_lsr = nstru.advertise<sensor_msgs::LaserScan>("/RobotPort_FilterScan",1);
    pub_lsr.publish(Lsrdta_new);
}

void SubTopics_Init(void)
{
    static ros::NodeHandle nstru;
    static ros::Subscriber odom_sub = nstru.subscribe("/RobotPort_Odom",1, RobotOdomTopics_Call);

    static ros::Subscriber simuLsr_sub = nstru.subscribe("/scan_filtered",1, RobotSimuLsrTopics_Call);
}

//-------------------------

static TASK_THREAD *task_tf;
void ThreadTopics_Init(void)
{
    task_tf = new TASK_THREAD;
}
void ThreadTopics_Release(void)
{
    delete task_tf;
}

//-------------------------
void CordDtaInit(void)
{
    DtaOdom.pose.pose.position.x = 0;
    DtaOdom.pose.pose.position.y = 0;
    DtaOdom.pose.pose.position.z = 0;
    DtaOdom.pose.pose.orientation.w = 1.0f;
    DtaOdom.pose.pose.orientation.x = 0.0f;
    DtaOdom.pose.pose.orientation.y = 0.0f;
    DtaOdom.pose.pose.orientation.z = 0.0f;
}

void TMainRunning(void)
{	
    task_tf->DataFeed(DtaOdom);

    //ROS_INFO("ROS Thread ing");
}

/* ============================
	  Main Group
============================= */
int main(int argc, char **argv)
{
	ros::init(argc, argv, "tf_manage");
    ros::NodeHandle nstru("~");
    ros::Rate loop_rate(100);

    // init ----------------------------------------------------------------------------

	SubTopics_Init();

    CordDtaInit();

    ThreadTopics_Init();

    // param deal ----------------------------------------------------------------------
    bool param_sta = true;
    double lsr_location[3];
    param_sta &= nstru.getParam("lsr_x",lsr_location[0]);
    param_sta &= nstru.getParam("lsr_y",lsr_location[1]);
    param_sta &= nstru.getParam("lsr_z",lsr_location[2]);
    if(param_sta){
        task_tf->DataInit(lsr_location);
    }else{
        ROS_ERROR("need lsr x,y,z<double> as arguments");
        ThreadTopics_Release();
        return -1;
    };
    //----------------------------------------------------------------------------------

	while(ros::ok())
	{
            TMainRunning();

        	ros::spinOnce();

        	loop_rate.sleep();
    }

    ThreadTopics_Release();

	return 0;
}


