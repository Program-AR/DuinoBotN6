/*
  MultiplesProgramas.h - Multiples Programas es una libreria
  cuyo objetivo es cargar varios programas en un RobotGroup N6
  para ser elegidos con el control remoto.
*/

#ifndef MultiplesProgramas_h
#define MultiplesProgramas_h

typedef struct {
    int id;
    static void (* const initiate)(void);
    static void (* const update)(void);
    static void (* const finalize)(void);
} Subprogram;

IRrecv irReceiver(A3); //El sensor de infrarrojo esta en el pin 3

void addSubprogram(Subprogram*);
void initiateCurrent(void);
void updateCurrent(void);

#endif

