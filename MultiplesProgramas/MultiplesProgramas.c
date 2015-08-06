#include "MultiplesProgramas.h"
#include <IRremote.h>

Subprogram *currentSubprogram;
Subprogram *subprograms[MAXPROGRAMS];

void addProgram(Subprogram *sp, int pos){
        subprograms[pos] = sp;
}

void initiateSubprogram(int code){ 
        currentSubprogram = subprograms[code];
        currentSubprogram->initiate();
}

void updateCurrent(){
	readIRAndChangeProgram();
	currentSubprogram->update();
}

void readIRAndChangeProgram(){
	int code = irReceiver.getIRRemoteCode();
	if (isProgram(code)) {
		currentSubprogram->finalize();
		initiateSubprogram(code);
	}
}

bool isProgram(int code){
  return code >= 0 && code < MAXPROGRAMS;
}
