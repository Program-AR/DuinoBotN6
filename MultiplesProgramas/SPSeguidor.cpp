#include "SPSeguidor.h"

SPSeguidor::SPSeguidor(int id) : Subprograma::Subprograma(id){
  motorIzq = new DCMotor(M0_EN, M0_D0, M0_D1);
  motorDer = new DCMotor(M1_EN, M1_D0, M1_D1);
  umbralLuz = 600;
  velocMotor = 50.0;
};
 
void SPSeguidor::iniciar(){
  // Serial.begin(115200);
  motorIzq->setSpeed(velocMotor);
  motorDer->setSpeed(velocMotor);
}

void SPSeguidor::actualizar(){
  //Read sensors:
  sensorIzq = analogRead(0);
  sensorDer = analogRead(1);
  
  /*
  //Debug:
  Serial.print("sensorIzq = ");
  Serial.print(sensorIzq);
  Serial.print("/ sensorDer = ");
  Serial.println(sensorDer);
  */

  if ( (sensorIzq<umbralLuz) && (sensorDer<umbralLuz) )  //00
  {
    motorIzq->setSpeed(velocMotor);
    motorDer->setSpeed(velocMotor);
  }
  else if ( (sensorIzq<umbralLuz) && (sensorDer>umbralLuz) ) //01
  {
    motorIzq->setSpeed(0.1*velocMotor);
    motorDer->setSpeed(velocMotor);
  }
  else if( (sensorIzq>umbralLuz) && (sensorDer<umbralLuz) ) //10
  {
    motorIzq->setSpeed(velocMotor);
    motorDer->setSpeed(0.1*velocMotor);
  }
  //11: Keeps last state.
}
