#include "MultiplePrograms.h"

void setup(){
    addSubprogram(follower(),1);
    addSubprogram(remoteRobot(),2);
    startPrograms();
}
void loop(){
	updateCurrent();
}

