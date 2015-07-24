/*
  MultiplesProgramas.h - Multiples Programas es una libreria
  cuyo objetivo es cargar varios programas en un RobotGroup N6
  para ser elegidos con el control remoto.
*/

#include "MultiplesProgramas.h"
#include <algorithm>

Subprograma::Subprograma(int idPrograma){
	id = idPrograma;
	virtual void iniciar(void){};
	virtual void actualizar(void) = 0;
	virtual void terminar(void){};
}

int Subprograma::id(){
	return id;
}

MultiplesProgramas::MultiplesProgramas(int pinIRReceiver){
	 irReceiver = new IRrecv(pinIRReceiver);
}

void MultiplesProgramas::agregar(Subprograma *sp){
	subprogramas.push_back(*sp);
	subProgramaActual = sp;
}

void MultiplesProgramas::iniciar(){
	subProgramaActual->iniciar();
}

void MultiplesProgramas::actualizar(){
	cambiarProgramaSiNecesario();
	subProgramaActual->actualizar();
}

void MultiplesProgramas::cambiarProgramaSiNecesario(){
	int code = irReceiver->getIRRemoteCode();
	if (esPrograma(code)) {
		subProgramaActual->terminar();
		subProgramaActual = subProgramaConId(code);
		subProgramaActual->iniciar();
	}
}

bool MultiplesProgramas::esPrograma(int code){
	return std::any_of(subprogramas.begin(),subprogramas.end(),
		[](Subprograma sp){return sp.id == code;})
}

Subprograma* MultiplesProgramas::subProgramaConId(int code){
	return std::find_if(subprogramas.begin(),subprogramas.end(),
		[](Subprograma sp){return sp.id == code;})
}
