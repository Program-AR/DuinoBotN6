#include "MultiplesProgramas.h"
#include "SPSeguidor.h"
#include "SPRemotoRobot.h"
#include "IRremote.h"

MultiplesProgramas *programas = new MultiplesProgramas(A3); //El sensor de infrarrojo esta en el pin 3
SPSeguidor seguidor(1);
SPRemotoRobot remoto(2);

void setup(){
	programas->agregar(&seguidor);
	programas->agregar(&remoto);
	programas->iniciar();
}
void loop(){
	programas->actualizar();
}

