#include "scom_function.h"

void F_Memcpy(char *CharDes, unsigned int DesBegin, char *CharOrin, unsigned int Len)
{
  unsigned int i,j;
  for(i = DesBegin, j =0; i< (DesBegin+Len); i++, j++){
    CharDes[i] = CharOrin[j];
  }
}

void F_FillCommand(char *CharDes, unsigned int Len)
{
  unsigned int i;
  for(i = Len; i< CommandLenth; i++){
    CharDes[i] = 0x00;
  }
}

// PS: float dta[1] > sizeof(dta) = 4!!! so this input should be sizeof(dta),no sizeof(dta)/4
void Pointer_Float2Char(float *FloatDta_in, unsigned int Len, char *CharDta_out)
{	
  char *CharDeal;
  unsigned int i;
	
  CharDeal = (char *)FloatDta_in;
	
  for(i = 0;i < Len; i++){
    CharDta_out[i] = CharDeal[i];
  }
}

void Pointer_Char2Float(char *CharDta_in, unsigned int Len, float *FloatDta_out)
{
  float *FloatDeal;
  unsigned int i;
	
  if((Len%4) == 0)
  {
    FloatDeal = (float *)CharDta_in;
		
    for(i = 0;i < (Len/4); i++){
      FloatDta_out[i] = FloatDeal[i];
    }
  }
}

void F_PackCommand2Robot_PackMes(enum CMAND_TK12Robot_ID IdType, char *Content, unsigned int ContentLen, char *DtaPack)
{
  //Pack Head
  DtaPack[0] = 0xaa;
  DtaPack[1] = 0xaa;
  //Pack Id
  DtaPack[2] = IdType;
  //Pack Lenth
  DtaPack[3] = ContentLen;
  //Pack Content
  F_Memcpy(DtaPack, 4, Content, ContentLen);
  //Pack Tails
  DtaPack[4+ContentLen] = 0x77;
  DtaPack[5+ContentLen] = 0x77;
  //Pack Replenish
  F_FillCommand(DtaPack, 6+ContentLen);
}

bool F_PackCommand_ExtractMes(char *DtaPack, CMAND_Robot2TK1_ID *CMandID, char *Content, unsigned int *ContentLen)
{
  bool sta = false;
  bool sta2 = false;
  char DtaCord[2] = {0,0};
  char DtaBuf[CommandLenth];
  unsigned int i,j,k;

  // repack > dtabuf
  for(i = 0; i < CommandLenth; i++){
    DtaCord[1] = DtaCord[0];
    DtaCord[0] = DtaPack[i];

    if((DtaCord[0] == (char)0xaa)&&(DtaCord[1] == (char)0xaa)){
      sta = true;
        j = 1;
        DtaBuf[0] = (char)0xaa;
        DtaBuf[1] = (char)0xaa;
    }

    if(sta){
      DtaBuf[j] = DtaCord[0];
      j++;
      if((DtaCord[0] == (char)0x77)&&(DtaCord[1] == (char)0x77)){
        for(k = j; k < CommandLenth; k++){
          DtaBuf[k] = 0x00;
        }
        sta = false;
        sta2 = true;
      }
    }
  }

  
  // deal dtabuf 
  sta = true; 
  sta &= ( (DtaBuf[0] == (char)0xaa)
		&& (DtaBuf[1] == (char)0xaa)
		&& (DtaBuf[4+DtaBuf[3]] == (char)0x77)
		&& (DtaBuf[5+DtaBuf[3]] == (char)0x77) );

  if(sta&&sta2){
    (*CMandID) = (enum CMAND_Robot2TK1_ID)DtaBuf[2];
    (*ContentLen) = DtaBuf[3];

    for(i=0,j=4; i<DtaBuf[3];  i++,j++){
      Content[i] = DtaBuf[j];
    }
    return true;
  }else{
    return false;
  }
}

// Typical Command Pack
void PackCmd_VelocityCmand(geometry_msgs::Twist cmd_vel, char *DtaBuf)
{
  #if Turtlesim_KeyEn == 1
  #if Simulation_En == 1
    cmd_vel.linear.x *=0.25f;
    cmd_vel.angular.z *=0.1f;
  #else
    cmd_vel.linear.x *=0.05f;
    cmd_vel.angular.z *=0.2f;
  #endif
  #endif

  cmd_vel.linear.x *=	velocity_k;
  cmd_vel.angular.z *=	gyro_k;

  #if Simulation_En
    static ros::NodeHandle nstru;
    static ros::Publisher msgPublish = nstru.advertise<geometry_msgs::Twist>(Topics_Cmd_Simulation2Robot, 1);

    msgPublish.publish(cmd_vel);

  #else
    static float CmdFloat[3];
    static char CmdChar[12];
    if(cmd_vel.linear.x <= 0){
      CmdFloat[0] = 0;
      CmdFloat[1] = 0;
    }else{
      CmdFloat[0] = cmd_vel.linear.x;
      CmdFloat[1] = CmdFloat[0];
    }
    CmdFloat[2] = cmd_vel.angular.z*57.3f;
 
    Pointer_Float2Char(CmdFloat, 12, CmdChar);

    F_PackCommand2Robot_PackMes(Velocity_Cmand, CmdChar, 12, DtaBuf);


  #endif
  
}

void PackCmd_PosiCmand(geometry_msgs::Point32 posi_cmd, char *DtaBuf)
{
  #if Simulation_En == 0
    static float CmdFloat[3];
    static char CmdChar[12];
 
    CmdFloat[0] = posi_cmd.x;
    CmdFloat[1] = posi_cmd.y;
    CmdFloat[2] = posi_cmd.z;

    Pointer_Float2Char(CmdFloat, 12, CmdChar);

    F_PackCommand2Robot_PackMes(Posi_Cmand, CmdChar, 12, DtaBuf);
  #endif
}

// Typical Command Pub
void TopicsPublish_AckCmand(std_msgs::Int8 Ack)
{
  #if Simulation_En == 0
    static ros::NodeHandle nstru;
    static ros::Publisher msgPublish = nstru.advertise<std_msgs::Int8>(Topics_Ack, 10);

    msgPublish.publish(Ack);
  #endif
}

void TopicsPublish_ReturnDtaCmandOdomDta(nav_msgs::Odometry OdomDta)
{
    #if Simulation_En == 0
    static ros::NodeHandle nstru;
    static ros::Publisher msgPublish = nstru.advertise<nav_msgs::Odometry>(Topics_RTOSOdom, 1);

    msgPublish.publish(OdomDta);
    #endif
}

void TopicsPublish_ReturnDtaCmandFrameDta(geometry_msgs::Point32 PointDta)
{
  #if Simulation_En == 0
    static ros::NodeHandle nstru;
    static ros::Publisher msgPublish = nstru.advertise<geometry_msgs::Point32>(Topics_RTOSPoint, 1);

    msgPublish.publish(PointDta);
  #endif
}

void TopicsPublish_ReturnDtaCmandFrameDtaTwist(geometry_msgs::Twist TwistDta)
{
  #if Simulation_En == 0
    static ros::NodeHandle nstru;
    static ros::Publisher msgPublish = nstru.advertise<geometry_msgs::Twist>(Topics_RTOSTwist, 1);

    msgPublish.publish(TwistDta);
  #endif
}


