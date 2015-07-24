/*
  SPSeguidor.h - Subprograma Seguidor 
  Copyright (c) 2015 Alf Sanzo.  All right reserved.
*/

// ensure this library description is only included once
#ifndef SPSeguidor_h
#define SPSeguidor_h

#include "MultiplesProgramas.h"
#include "DCMotor.h"

class SPSeguidor : public Subprograma{
  public:
    SPSeguidor(int);
	void iniciar(void);
	void actualizar(void);

  private:
	float sensorIzq, sensorDer;
	DCMotor motorIzq;
	DCMotor motorDer;
	int umbralLuz;
	int velocMotor;
};

#endif

