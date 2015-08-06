#include "MultiplesProgramas.h"
#include "SPSeguidor.h"
#include "SPRemotoRobot.h"

void setup(){
	addSubprogram(seguidor,0);
	addSubprogram(remoteRobot,1);
    initiateSubprogram(0);
}
void loop(){
	updateCurrent();
}

