#include <IRremote.h>
#include <DCMotor.h>
#include "MultiplesProgramas.h"
#include "SPSeguidor.h"
#include "SPRemotoRobot.h"

MultiplesProgramas *programas = new MultiplesProgramas(A3); //El sensor de infrarrojo esta en el pin 3

void setup(){
	programas->agregar(new SPSeguidor(1));
	programas->agregar(new SPRemotoRobot(2));
	programas->iniciar();
}
void loop(){
	programas->actualizar();
}

