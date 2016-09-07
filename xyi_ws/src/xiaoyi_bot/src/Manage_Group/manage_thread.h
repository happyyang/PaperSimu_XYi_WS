#ifndef __manage_thread_H
#define __manage_thread_H
	#include <ros/ros.h>
    #include <boost/thread.hpp>
    #include "eigen3/Eigen/Dense"
    #include "eigen3/Eigen/Geometry"

    #include "nav_msgs/Odometry.h"
    #include "geometry_msgs/Twist.h"

	typedef class TASK_THREAD
	{

	public:
	    TASK_THREAD()
	    {
            Trun = boost::bind(&TASK_THREAD::task,this);
            ThisThread = new boost::thread(Trun);
            //ThisThread->join(); //Run until quit!!!

            mutex = true;

            DtaOdom.pose.pose.position.x = 0;
            DtaOdom.pose.pose.position.y = 0;
            DtaOdom.pose.pose.position.z = 0;
            DtaOdom.pose.pose.orientation.w = 1.0f;
            DtaOdom.pose.pose.orientation.x = 0.0f;
            DtaOdom.pose.pose.orientation.y = 0.0f;
            DtaOdom.pose.pose.orientation.z = 0.0f;

            taskInit = false;

            CONST_LsrLocation[0] = 0.0f;
            CONST_LsrLocation[1] = 0.0f;
            CONST_LsrLocation[2] = 0.0f;
	    }

	    ~TASK_THREAD()
	    {
            ThisThread->interrupt();
            delete ThisThread;
	    }

        void DataInit(double *LsrLInit);
        void DataFeed(nav_msgs::Odometry odom);

	private:

	    boost::thread *ThisThread;

	    boost::function0<void> Trun;
	    void task();
	    
        volatile bool mutex;
        nav_msgs::Odometry DtaOdom;

        volatile bool taskInit;
        float CONST_LsrLocation[3];


	}TASK_THREAD;

#endif

