#include "dw_approach.h"

//***********************************************************************************************************************
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//***********************************************************************************************************************
#define VELOCITY_MAX			0.3f
#define GYRO_MAX                0.52356f    // 30/57.3F

static float robot_yaw;

static float protected_speed = 0;
static float target_speed = 0.5f;
static float target_gyro = 0.0f;

static const float gyro_weaken_speed_K = 0.15f;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~>>>
void DWA_FUNC::func_control_loop(void)
{
    /************************************
    Robot_Action_Now.reach_x_mf;
    Robot_Action_Now.reach_y_mf;
    Robot_Action_Now.target_yaw_mf;
    Robot_Action_Now.wander_target_speed;
    Robot_Action_Now.wander_target_gyro;
    ************************************/

    static float aw,ax,ay,az;
    aw = dwa_param->TF_MAP2Robot.orientation.w;
    ax = dwa_param->TF_MAP2Robot.orientation.x;
    ay = dwa_param->TF_MAP2Robot.orientation.y;
    az = dwa_param->TF_MAP2Robot.orientation.z;
    robot_yaw = std::atan2(2*(aw*az+ax*ay),(1-2*(ay*ay+az*az)));

    protected_speed = dwa_data->Lsr_PathMindis - dwa_param->Robot_Physical_Radius;
    if(protected_speed < 0 )protected_speed = 0;


    switch(Robot_Action_Now.mode)
    {
    case ACTIONMODE_WANDER:
        target_speed = Robot_Action_Now.wander_guide_speed;
        target_gyro = Robot_Action_Now.wander_guide_gyro;
        break;

    case ACTIONMODE_REACH:
        target_speed = 0;
        target_gyro = 0;
        //Robot_Action_Now.reach_x_mf;
        //Robot_Action_Now.reach_y_mf;
        break;

    case ACTIONMODE_ROTATE:
        target_speed = Robot_Action_Now.wander_guide_speed;
        target_gyro = Robot_Action_Now.wander_guide_gyro;
        break;

    case ACTIONMODE_FINALROTATE:
        target_speed = 0;
        //target_gyro = Robot_Action_Now.target_yaw_mf;// - robot_yaw;
        action_busy = true;
        break;

    case ACTIONMODE_STOP:
        target_speed = 0;
        target_gyro = 0;
        break;

    }

    /*
    if(action_busy)
    {
        if( std::abs(target_gyro) <= dwa_approach_radius_reachguide)
        {
            Robot_Action_Now.mode = ACTIONMODE_STOP;
            action_busy = false;
        }
    }*/

    func_control_pid_speed();

    func_conrtol_pid_gyro();

    func_conrtol_pub();

    ROS_INFO(" HALD: MODE: %d, %f ", Robot_Action_Now.mode, dwa_fchose_add);
}



void DWA_FUNC::func_control_pid_speed(void)
{
    robot_speed = target_speed - dwa_param->Robot_Physical_Radius
                  - std::abs(robot_gyro) * gyro_weaken_speed_K;

    if(robot_speed >= VELOCITY_MAX) robot_speed = VELOCITY_MAX;
    if(robot_speed >= protected_speed) robot_speed = protected_speed;
    if(robot_speed < 0) robot_speed = 0;
}

void DWA_FUNC::func_conrtol_pid_gyro(void)
{
    /////////////////////////////////////////////////////////////////////
    const float pid_p = 0.15f;
    const float pid_i = 15.0f;
    const float pid_d = 0.0001f;

    static float Kp = pid_p;
    static float Ki = pid_p * pid_i * Control_Imu_T;
    static float Kd = pid_p * pid_d / Control_Imu_T;

    static float error[3] = {0, 0, 0};
    static float dPIDOut;

    /////////////////////////////////////////////////////////////////////
    error[2] = error[1];
    error[1] = error[0];
    error[0] = target_gyro - robot_gyro;

    dPIDOut = Kp*(error[0] - error[1]) +
              Ki*error[0] +
              Kd*(error[0] - 2*error[1] + error[2]);

    robot_gyro += dPIDOut;

    if(robot_gyro <= -GYRO_MAX) robot_gyro = -GYRO_MAX;
    if(robot_gyro >= GYRO_MAX)  robot_gyro = GYRO_MAX;

}

void DWA_FUNC::func_conrtol_pub(void)
{
    static ros::NodeHandle nstru;
    static ros::Publisher twist_pub = nstru.advertise<geometry_msgs::Twist>("/RobotPort_CmdVel",1);
    static geometry_msgs::Twist pubdta;

    if ((robot_speed != robot_speed)||(robot_gyro != robot_gyro))
    {
        ROS_ERROR("[botguider Node]: Speed/Gyro == NaN");
    }else{
        pubdta.linear.x = robot_speed;
        pubdta.linear.y = 0;
        pubdta.linear.z = 0;

        pubdta.angular.x = 0;
        pubdta.angular.y = 0;
        pubdta.angular.z = robot_gyro;

        twist_pub.publish(pubdta);
    }
}


