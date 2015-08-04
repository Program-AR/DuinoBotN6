/*
  MultiplesProgramas.h - Multiples Programas es una libreria
  cuyo objetivo es cargar varios programas en un RobotGroup N6
  para ser elegidos con el control remoto.
*/

#ifndef MultiplesProgramas_h
#define MultiplesProgramas_h

#include <iterator>
#include <vector>
#include <IRremote.h>

class Subprograma
{
  public:
    Subprograma(int);
    int getId();
    virtual void iniciar(void){};
    virtual void actualizar(void){};
    virtual void terminar(void){};

  private:
    int id;
};

class MultiplesProgramas
{
  public:
    MultiplesProgramas(int);
    void agregar(Subprograma*);
    void iniciar();
    void actualizar();

  private:
	std::vector<Subprograma*> subprogramas;
	Subprograma* subProgramaActual;
	IRrecv *irReceiver;
	void cambiarProgramaSiNecesario();
	bool esPrograma(int);
	Subprograma* subProgramaConId(int);
};
#endif

