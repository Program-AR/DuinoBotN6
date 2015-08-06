#include "SPRemotoRobot.h"
#include <IRremote.h>
#include <DCMotor.h>


DCMotor rightMotor(M0_EN, M0_D0, M0_D1);
DCMotor leftMotor(M1_EN, M1_D0, M1_D1);
float motorSpeed = 50.0;
Subprogram remotoR;

void motorsTo0(){
  rightMotor.setSpeed(0);
  leftMotor.setSpeed(0);
}

void updateRemoteControl(){
   int code = irReceiver.getIRRemoteCode();
   if (code == 5)
   {
      rightMotor.setSpeed(motorSpeed);
      leftMotor.setSpeed(motorSpeed);
   }
   else if (code == 0)
   {
      rightMotor.setSpeed(-motorSpeed);
      leftMotor.setSpeed(-motorSpeed);
   }
   else if (code == 9)
   {
      rightMotor.setSpeed(-motorSpeed);
      leftMotor.setSpeed(motorSpeed);
   }
   else if (code == 7)
   {
      rightMotor.setSpeed(motorSpeed);
      leftMotor.setSpeed(-motorSpeed);
   }
   else if (code == 8)
   {
      rightMotor.setSpeed(0);
      leftMotor.setSpeed(0);
   }
};

Subprogram * remoteRobot(){
  remotoR.initiate = &motorsTo0;
  remotoR.update = &updateRemoteControl;
  remotoR.finalize = &motorsTo0;
  return &remotoR;
}


