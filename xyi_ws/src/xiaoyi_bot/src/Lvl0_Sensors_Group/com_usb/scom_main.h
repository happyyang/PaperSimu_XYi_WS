#ifndef __scom_main_H
#define __scom_main_H

  #include "ros/ros.h"
  #include <sstream>
  #include "boost/thread.hpp"

  #include <boost/asio.hpp>
  #include <boost/bind.hpp>
  #include <c++/4.8/iostream>

  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  #include "scom_bsp.h"
  #include "scom_function.h"

  #include "eigen3/Eigen/Dense"
  #include "eigen3/Eigen/Geometry"
  using namespace Eigen;

  #define CommandLenth 40
  #define RS_DEVICE   "/dev/ttyUSB0"

  #define BAUDRATE    921600
  #define PARITY      serial_port::parity(serial_port::parity::odd)
  #define STOPBITS    serial_port::stop_bits::one
  #define CharSize    8

  void thread_wait_time(char mode, unsigned t);

  class ScomThread_Manage
  {
  public:
    ScomThread_Manage();
    ~ScomThread_Manage();

    unsigned int Tdog;
    void Feeddog(void);

    volatile int ProtectDog;

    char ScomRdta[CommandLenth];
    char ScomSdta[CommandLenth];

    volatile bool ScomGetOnceDta;
    volatile bool ScomSendOnceDta;
    
  private:
    void TRrun(void);
    void TSrun(void);

    boost::function0<void> Trunf0,Trunf1;
    boost::thread *ReceiveThread, *SendThread;


  };

 














#endif




