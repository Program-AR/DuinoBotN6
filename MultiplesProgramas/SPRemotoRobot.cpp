#include "SPRemotoRobot.h"

SPRemotoRobot::SPRemotoRobot(int id) : Subprograma::Subprograma(id){
  irReceiver = new IRrecv(3);
  motorDer = new DCMotor(M0_EN, M0_D0, M0_D1);
  motorIzq = new DCMotor(M1_EN, M1_D0, M1_D1);
  velocMotor = 50.0;
};

void SPRemotoRobot::actualizar()
{
   int code = irReceiver->getIRRemoteCode();
   if (code == 5)
   {
      motorDer->setSpeed(velocMotor);
      motorIzq->setSpeed(velocMotor);
   }
   else if (code == 0)
   {
      motorDer->setSpeed(-velocMotor);
      motorIzq->setSpeed(-velocMotor);
   }
   else if (code == 9)
   {
      motorDer->setSpeed(-velocMotor);
      motorIzq->setSpeed(velocMotor);
   }
   else if (code == 7)
   {
      motorDer->setSpeed(velocMotor);
      motorIzq->setSpeed(-velocMotor);
   }
   else if (code == 8)
   {
      motorDer->setSpeed(0);
      motorIzq->setSpeed(0);
   }
}
