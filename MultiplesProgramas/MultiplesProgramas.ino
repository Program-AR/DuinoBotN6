#include <IRremote.h>
#include <DCMotor.h>
#include "MultiplesProgramas.h"
#include "SPSeguidor.h"
#include "SPRemotoRobot.h"

void setup(){
	addSubprogram(seguidor,0);
	addSubprogram(remotoRobot,1);
        initiateSubprogram(0);
}
void loop(){
	updateCurrent();
}

