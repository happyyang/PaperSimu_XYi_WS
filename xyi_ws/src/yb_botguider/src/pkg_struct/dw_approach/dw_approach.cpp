#include "dw_approach.h"

//**************************************************************************
// Pkg MainRuning and Subscribe MainRunning is in the same thread circle
void DWA_FUNC::Pkg_MainRunning(void)
{
    //Main_Astar_Algorithm();
}

void DWA_FUNC::Subscribe_MainRunning(const sensor_msgs::LaserScan &laserdta)
{
    if (dwa_data->mutex_laserDtaAll)
    {
        dwa_data->mutex_laserDtaAll = false;

        dwa_data->r_lsrdta = &laserdta;

        func_laserdtadeal();

        dwa_data->mutex_laserDtaAll = true;
    }
}

// Thread_MainRunnnign is in the alone thread circle : data should add mutex.
void DWA_FUNC::Thread_MainRunning(void)
{
    if (dwa_data->mutex_laserDtaAll)
    {
        dwa_data->mutex_laserDtaAll = false;

        func_anglepatharraydeal();

        dwa_data->mutex_laserDtaAll = true;
    }

    if(dwa_param->goalparam_init)
    {
        if (otf_astar_data->mutex_GRouteMessage)
        {
            otf_astar_data->mutex_GRouteMessage = false;

            func_getguidepoint();

            otf_astar_data->mutex_GRouteMessage = true;
        }
    }

    if(otf_astar_data->route_s_init)
    {
        func_gudingrules();
    }

}

//**************************************************************************

void DWA_FUNC::task()
{
    static bool WhileFlag = true;
    const static bool isWhileThread = true;

    static int thread_delay = int(1000.0f * Control_Imu_T);

    while(WhileFlag)
    {
        try
        {
            boost::this_thread::interruption_point();

            static bool sta; sta = dwa_param->launchparam_init && dwa_param->lsrparam_init;
            if(sta)
            {
                // the part for dealing the laser's data
                Thread_MainRunning();

            }

            boost::this_thread::sleep(boost::posix_time::milliseconds(thread_delay));
        }
        catch(boost::thread_interrupted&)
        {

        }

        WhileFlag = isWhileThread;
    }
}









