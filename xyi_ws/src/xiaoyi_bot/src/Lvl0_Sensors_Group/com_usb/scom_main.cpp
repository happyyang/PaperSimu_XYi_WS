#include "scom_main.h"


// Varible
class ScomThread_Manage *Scom_Thread;

// thread class
void thread_wait_time(char mode, unsigned t)
{
  switch(mode)
  {
    case 0:
      boost::this_thread::sleep(boost::posix_time::seconds(t));
    break;
    case 1:
      boost::this_thread::sleep(boost::posix_time::milliseconds(t));
    break;
  }
}

ScomThread_Manage::ScomThread_Manage()
{
  Tdog = 25;
  ProtectDog = 10;
  ScomGetOnceDta = false;
  ScomSendOnceDta = false;

  Trunf0 = boost::bind(&ScomThread_Manage::TRrun, this);
  ReceiveThread = new boost::thread(Trunf0);

  Trunf1= boost::bind(&ScomThread_Manage::TSrun, this);
  SendThread = new boost::thread(Trunf1);
}

ScomThread_Manage::~ScomThread_Manage()
{
  delete ReceiveThread;
  delete SendThread;
}

// thread Feed
void ScomThread_Manage::Feeddog(void)
{
  Tdog = 200;
}


// thread Receive
void ScomThread_Manage::TRrun(void)
{
  try{
    while(Tdog--)
    {
      boost::this_thread::interruption_point();

      SCom_ReadChar(ScomRdta);

      if(!ScomGetOnceDta){
        ScomGetOnceDta = true;
      }

      thread_wait_time(1, 10);
    } 
    Scom_Close();
  }
  catch(boost::thread_interrupted&)
  {
    Scom_Close();
  }


}

// thread Send
void ScomThread_Manage::TSrun(void)
{
  try{
    while(Tdog--)
    {
      boost::this_thread::interruption_point();

      if(ScomSendOnceDta){
        SCom_WriteChar(ScomSdta);
	ScomSendOnceDta = false;
      }

      thread_wait_time(1, 10);
    } 
    Scom_Close();
  }
  catch(boost::thread_interrupted&)
  {
    Scom_Close();
  }

  
}

// Subscribe Manage
void TopicSub_Cmdvel_Callback(const geometry_msgs::Twist& cmd_vel)
{
  Scom_Thread->ProtectDog = 25;

  PackCmd_VelocityCmand(cmd_vel, Scom_Thread->ScomSdta);

  #if Simulation_En == 0  
    if(!Scom_Thread->ScomSendOnceDta){
      Scom_Thread->ScomSendOnceDta = true;
    }
  #endif
}

void TopicSub_PosiCmd_Callback(const geometry_msgs::Point32& posi_cmd)
{
  #if Simulation_En == 0
    PackCmd_PosiCmand(posi_cmd, Scom_Thread->ScomSdta);
    if(!Scom_Thread->ScomSendOnceDta){
      Scom_Thread->ScomSendOnceDta = true;
    }
  #endif
}

void Topics_Subscribe_Init(void)
{
  static ros::NodeHandle nstru;

  static ros::Subscriber CmdVel_Sub = nstru.subscribe(Topics_Cmd, 1, TopicSub_Cmdvel_Callback); 
  
  #if Simulation_En == 0
    static ros::Subscriber PosiCmd_Sub = nstru.subscribe(Topics_PosiCmd, 2, TopicSub_PosiCmd_Callback); 
  #endif
}

// DealFunction Receive
void RDta_Dealwith(class ScomThread_Manage *Scom_Thread)
{
  CMAND_Robot2TK1_ID deal_Id;
  char deal_Content[CommandLenth];
  unsigned int deal_ContentLen;

  if(F_PackCommand_ExtractMes(Scom_Thread->ScomRdta, &deal_Id, deal_Content, &deal_ContentLen))
  {
    // [Id] -------------------------------------------------
    if(deal_Id == Ack_Cmand){
      ROS_INFO("Receive Ack");
      std_msgs::Int8 AckContent;
      AckContent.data = deal_Content[0]; 

      TopicsPublish_AckCmand(AckContent);
    }

    // [Id] -------------------------------------------------
    if(deal_Id == ReturnDta_Cmand_FrameDta){
 
      static float Frame_Dta[5];
      Pointer_Char2Float(deal_Content, 20, Frame_Dta);

      static nav_msgs::Odometry RTOSOdom;
      static geometry_msgs::Point32 RTOSPosi;
      static geometry_msgs::Twist RTOSTwist;
	
      RTOSPosi.x = Frame_Dta[0];
      RTOSPosi.y = Frame_Dta[1];
      RTOSPosi.z = Frame_Dta[2];
      RTOSTwist.linear.x = Frame_Dta[3];
      RTOSTwist.angular.z = Frame_Dta[4];


      RTOSOdom.pose.pose.position.x = RTOSPosi.x; RTOSOdom.pose.pose.position.y = RTOSPosi.y; RTOSOdom.pose.pose.position.z = 0;
      Quaternion<float> yawAng(AngleAxisf(RTOSPosi.z, Vector3f(0.0f,0.0f,1.0f)));
      RTOSOdom.pose.pose.orientation.w = yawAng.w();
      RTOSOdom.pose.pose.orientation.x = yawAng.x();
      RTOSOdom.pose.pose.orientation.y = yawAng.y();
      RTOSOdom.pose.pose.orientation.z = yawAng.z();

      RTOSOdom.twist.twist = RTOSTwist;

      TopicsPublish_ReturnDtaCmandOdomDta(RTOSOdom);            //Pub Odom
      //TopicsPublish_ReturnDtaCmandFrameDta(RTOSPosi);         //Pub Posi
      //TopicsPublish_ReturnDtaCmandFrameDtaTwist(RTOSTwist);	//Pub Velocity,Gyro_Rotate
    }
  }
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "scom_node");
  ros::NodeHandle nstru;
  ros::Rate loop_rate(100);

  Topics_Subscribe_Init();

  if(Scom_Init()){
    ROS_INFO("Scom Start Success");
  }else{
    ROS_INFO("Scom Start Fail");
  }

  Scom_Thread = new class ScomThread_Manage;

  while(ros::ok())
  {
    
    //ROS_INFO("hello_world");
    Scom_Thread->Feeddog();

    if(Scom_Thread->ScomGetOnceDta){
      // Receive dta and deal
      RDta_Dealwith(Scom_Thread);

      Scom_Thread->ScomGetOnceDta = false;
    }

    /* Protect to Robot >> Have done in the MCU
    if(Scom_Thread->ProtectDog <= 0){
      geometry_msgs::Twist Tcmd_vel; 
      Tcmd_vel.linear.x = 0; Tcmd_vel.linear.y = 0; Tcmd_vel.angular.z = 0;
      #if Simulation_En == 0
        if(!Scom_Thread->ScomSendOnceDta){
          PackCmd_VelocityCmand(Tcmd_vel, Scom_Thread->ScomSdta);
          Scom_Thread->ScomSendOnceDta = true;
        }
      #endif
    }else{
      Scom_Thread->ProtectDog--;
    }*/

    ros::spinOnce(); // to deal with the SubScribe~!!!!
    loop_rate.sleep();
  }


}















