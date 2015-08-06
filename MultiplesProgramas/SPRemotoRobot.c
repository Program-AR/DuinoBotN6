#include "SPRemotoRobot.h"

DCMotor rightMotor(M0_EN, M0_D0, M0_D1);
DCMotor leftMotor(M1_EN, M1_D0, M1_D1);
motorSpeed = 50.0;

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
}

seguidor.initiate = motorsTo0;
seguidor.update = updateRemoteControl;
seguidor.finalize = motorsTo0;
