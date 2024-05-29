#include "socket.h"
#include "encoder.h"
#include "pwm.h"
#include "control.h"



void setup()
{
  //Serial.begin(115200);
  _soc.setCurrentSpeed(speedSettings::SLOW);
  _soc.connectWifi();
  _soc.initSPIFFS();
  _soc.initWebsocket();
  _encoder.initEncoderPin();
  _encoder.initInterruptEncoder();
  _pwm.initPwm();
  _ctrl.init_driver_uart();
  

  //_soc.readyCar();
}

void loop()
{
  _ctrl.processor(_ctrl.data);
}