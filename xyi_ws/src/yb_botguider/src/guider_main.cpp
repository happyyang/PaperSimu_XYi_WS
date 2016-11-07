#include "guider_main.h"

static GuiderPkgStruct *Task_Pkg;


/* ============================
	  MainFunc Group
============================= */


/* ============================
	  Main Group
============================= */
int main(int argc, char **argv)
{
    ros::init(argc, argv, "guider_main");
    ros::NodeHandle nstru("~");
    ros::Rate loop_rate(100);

    // task init -----------------------------------------------------------------------//
    Task_Pkg = new GuiderPkgStruct;

    // param init ----------------------------------------------------------------------//
    bool param_sta = true;
    double param[4];
    param_sta &= nstru.getParam("Robot_Radius",param[0]);
    param_sta &= nstru.getParam("LsrDta_Blen",param[1]);
    param_sta &= nstru.getParam("LsrDta_Elen",param[2]);
    param_sta &= nstru.getParam("MapSafe_Robot_Radius",param[3]);

    if(param_sta){
        Task_Pkg->Pkg_Init(param);

    }else{
        ROS_ERROR("[Guider Node]: Arguments is not enough!!!");
        Task_Pkg->Pkg_Release();
        return -1;
    };

    //---------------------------------------------------------------------------------//
	while(ros::ok())
	{
        Task_Pkg->Pkg_MainRunning();

        ros::spinOnce();

        loop_rate.sleep();
    }

    Task_Pkg->Pkg_Release();
    //delete Task_Pkg;

	return 0;
}
