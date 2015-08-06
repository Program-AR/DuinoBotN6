#include "MultiplePrograms.h"
#include "IRremote2.h"
#include "DCMotor2.h"
#define NOTE_A3  220

IRrecv irReceiver(A3); //El sensor de infrarrojo esta en el pin 3
float motorSpeed = 50.0;

Subprogram *currentSubprogram;
Subprogram *subprograms[MAXPROGRAMS];

void addSubprogram(Subprogram *sp, int pos){
        subprograms[pos] = sp;
}

void startPrograms(){
    pinMode(SPEAKER, OUTPUT);
    initiateSubprogram(1);
}

void initiateSubprogram(int code){ 
        currentSubprogram = subprograms[code];
        currentSubprogram->initiate();
}

bool isProgram(int code){
  return code > 0 && code < MAXPROGRAMS;
}

void beepProgramChange(int code){
    for (int i=0; i<code; i++){
        toneDelay(SPEAKER, NOTE_A3,100);
        delay(100);
    }
}

void readIRAndChangeProgram(){
	int code = irReceiver.getIRRemoteCode();
	if (isProgram(code)) {
                beepProgramChange(code);
		currentSubprogram->finalize();
		initiateSubprogram(code);
	}
	if (code == 8){
		motorSpeed -= 10.0;
	}
	if (code == 9){
		motorSpeed += 10.0;
	}
}

void updateCurrent(){
	readIRAndChangeProgram();
	currentSubprogram->update();
}

////////////////////////////////////////////////////////
DCMotor rightMotor(M0_EN, M0_D0, M0_D1);
DCMotor leftMotor(M1_EN, M1_D0, M1_D1);
float lightThreshold = 600;
float rightSensor;
float leftSensor;
Subprogram followR;

void initiateFollower(){
  rightMotor.setSpeed(motorSpeed);
  leftMotor.setSpeed(motorSpeed);
}

void updateFollower(){
  rightSensor = analogRead(0);
  leftSensor = analogRead(1);

  if ( (rightSensor<lightThreshold) && (leftSensor<lightThreshold) )  //00
  {
    rightMotor.setSpeed(motorSpeed);
    leftMotor.setSpeed(motorSpeed);
  }
  else if ( (rightSensor<lightThreshold) && (leftSensor>lightThreshold) ) //01
  {
    rightMotor.setSpeed(0.1*motorSpeed);
    leftMotor.setSpeed(motorSpeed);
  }
  else if( (rightSensor>lightThreshold) && (leftSensor<lightThreshold) ) //10
  {
    rightMotor.setSpeed(motorSpeed);
    leftMotor.setSpeed(0.1*motorSpeed);
  }
  //11: Keeps last state.
}

Subprogram *follower(){
  followR.initiate = &initiateFollower;
  followR.update = &updateFollower;
  followR.finalize = &initiateFollower;
  return &followR;
}

//////////////////////////////////////////////////////////////////////////////
Subprogram remotoR;

void motorsTo0(){
  rightMotor.setSpeed(0);
  leftMotor.setSpeed(0);
}

void updateRemoteControl(){
   int code = irReceiver.getIRRemoteCode();
   if (code == 820)
   {
      rightMotor.setSpeed(motorSpeed);
      leftMotor.setSpeed(motorSpeed);
   }
   else if (code == 821)
   {
      rightMotor.setSpeed(-motorSpeed);
      leftMotor.setSpeed(-motorSpeed);
   }
   else if (code == 810)
   {
      rightMotor.setSpeed(-motorSpeed);
      leftMotor.setSpeed(motorSpeed);
   }
   else if (code == 811)
   {
      rightMotor.setSpeed(motorSpeed);
      leftMotor.setSpeed(-motorSpeed);
   }
   else if (code == 1000)
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


