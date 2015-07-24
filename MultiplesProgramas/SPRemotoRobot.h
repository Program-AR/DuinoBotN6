/*
  SPSeguidor.h - Subprograma Seguidor 
  Copyright (c) 2015 Alf Sanzo.  All right reserved.
*/

// ensure this library description is only included once
#ifndef SPRemotoRobot_h
#define SPRemotoRobot_h

#include "MultiplesProgramas.h"
#include "DCMotor.h"
#include "IRremote.h"

class SPRemotoRobot : public Subprograma{
  public:
    SPRemotoRobot(int);
	void iniciar(void);
	void actualizar(void);

  private:
	IRrecv irReceiver;
	float sensorIzq, sensorDer;
	DCMotor motorDer;
	DCMotor motorIzq;
        int velocMotor;
};

#endif

