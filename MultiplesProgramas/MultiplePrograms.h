/*
  MultiplePrograms.h - Multiples Programas es una libreria
  cuyo objetivo es cargar varios programas en un RobotGroup N6
  para ser elegidos con el control remoto.
*/

#ifndef MultiplePrograms_h
#define MultiplePrograms_h

#include <Arduino.h>

#define MAXPROGRAMS 5 // Should never be more than 10

typedef struct {
    void (* initiate)(void);
    void (* update)(void);
    void (* finalize)(void);
} Subprogram;

void startPrograms(void);
void addSubprogram(Subprogram*,int);
void initiateSubprogram(int);
void updateCurrent(void);

//////////////// UGLY
Subprogram *follower();
Subprogram* remoteRobot(void);

#endif

