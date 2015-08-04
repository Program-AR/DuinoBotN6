#include <IRremote.h>
#include <DCMotor.h>
#include "MultiplesProgramas.h"
#include "SPSeguidor.h"
#include "SPRemotoRobot.h"



void setup(){
	addSubprogram(seguidor,1);
	addSubprogram(remotoRobot,2);
        initiateCurrent();
}
void loop(){
	updateCurrent();
}

