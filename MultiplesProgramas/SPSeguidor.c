#include "SPSeguidor.h"

//DCMotor rightMotor(M0_EN, M0_D0, M0_D1);
//DCMotor leftMotor(M1_EN, M1_D0, M1_D1);
float lightThreshold = 600;
//float motorSpeed = 50.0;
float rightSensor;
float leftSensor;

void initiateFollower(){
  rightMotor->setSpeed(motorSpeed);
  leftMotor->setSpeed(motorSpeed);
}

void updateFollower(){
  rightSensor = analogRead(0);
  leftSensor = analogRead(1);

  if ( (rightSensor<lightThreshold) && (leftSensor<lightThreshold) )  //00
  {
    rightMotor->setSpeed(motorSpeed);
    leftMotor->setSpeed(motorSpeed);
  }
  else if ( (rightSensor<lightThreshold) && (leftSensor>lightThreshold) ) //01
  {
    rightMotor->setSpeed(0.1*motorSpeed);
    leftMotor->setSpeed(motorSpeed);
  }
  else if( (rightSensor>lightThreshold) && (leftSensor<lightThreshold) ) //10
  {
    rightMotor->setSpeed(motorSpeed);
    leftMotor->setSpeed(0.1*motorSpeed);
  }
  //11: Keeps last state.
}

follower.initiate = initiateFollower;
follower.update = updateFollower;
follower.finalize = initiateFollower;