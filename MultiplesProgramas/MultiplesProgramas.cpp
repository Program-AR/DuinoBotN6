/*
  MultiplesProgramas.h - Multiples Programas es una libreria
  cuyo objetivo es cargar varios programas en un RobotGroup N6
  para ser elegidos con el control remoto.
*/

#include "MultiplesProgramas.h"
#include <algorithm>

Subprograma::Subprograma(int idPrograma){
	id = idPrograma;
}

int Subprograma::getId(){
	return id;
}

MultiplesProgramas::MultiplesProgramas(int pinIRReceiver){
	 irReceiver = new IRrecv(pinIRReceiver);
}

void MultiplesProgramas::agregar(Subprograma *sp){
	subprogramas.push_back(sp);
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

int elCode;
bool hasTheCode(Subprograma *sp){
  return sp->getId() == elCode;
}
bool MultiplesProgramas::esPrograma(int code){
  elCode = code;
  return std::count_if(subprogramas.begin(),subprogramas.end(), hasTheCode) > 0;
}

Subprograma* MultiplesProgramas::subProgramaConId(int code){
    elCode = code;
    return * std::find_if(subprogramas.begin(),subprogramas.end(),hasTheCode);
}
