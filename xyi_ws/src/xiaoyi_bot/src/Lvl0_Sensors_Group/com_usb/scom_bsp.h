#ifndef __scom_bsp_H
#define __scom_bsp_H

  #include <sstream>
  #include <boost/asio.hpp>
  #include <boost/bind.hpp>
  #include <c++/4.8/iostream>
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  #define CommandLenth 40
  #define RS_DEVICE   "/dev/ttyUSB0"

  #define BAUDRATE    921600
  #define PARITY      serial_port::parity(serial_port::parity::odd)
  #define STOPBITS    serial_port::stop_bits::one
  #define CharSize    8

  // bsp
  bool Scom_Init();
  void Scom_Flush();
  void Scom_Close();

  void SCom_WriteChar(char *dta);

  void SCom_ReadChar(char *dta);











#endif




