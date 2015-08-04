/*
  SPSeguidor.h - Subprograma Seguidor 
  Copyright (c) 2015 Alf Sanzo.  All right reserved.
*/

// ensure this library description is only included once
#ifndef SPRemotoRobot_h
#define SPRemotoRobot_h

#include "MultiplesProgramas.h"
#include <DCMotor.h>

class SPRemotoRobot : public Subprograma::Subprograma{
  public:
    SPRemotoRobot(int id) : Subprograma::Subprograma(id){
  irReceiver = new IRrecv(A3);
  motorDer = new DCMotor(M0_EN, M0_D0, M0_D1);
  motorIzq = new DCMotor(M1_EN, M1_D0, M1_D1);
  velocMotor = 50.0;
};
	void actualizar(void);

  private:
	IRrecv* irReceiver;
	float sensorIzq, sensorDer;
	DCMotor* motorDer;
	DCMotor* motorIzq;
        int velocMotor;
};

#endif

