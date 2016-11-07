#include "tf_manage_listener.h"

/* ============================
      MainFunc Group
============================= */
void SubTopics_Init(void)
{

}

//-------------------------

//static TASK_THREAD *task_tf;
void Thread_Init(void)
{
    //task_tf = new TASK_THREAD;
}
void Thread_Release(void)
{
    //delete task_tf;
}

//-------------------------
void CordDtaInit(void)
{

}

void TMainRunning(void)
{

}

/* ============================
      Main Group
============================= */
int main(int argc, char **argv)
{
    ros::init(argc, argv, "mange_listener");
    ros::NodeHandle nstru;
    ros::Rate loop_rate(25);

    // init ----------------------------------------------------------------------------

    SubTopics_Init();

    CordDtaInit();

    Thread_Init();

    while(ros::ok())
    {
            TMainRunning();
            ros::spinOnce();

            loop_rate.sleep();
    }

    Thread_Release();

    return 0;
}
