#ifndef NODO_H
#define NODO_H
#include"Operacion.h"

using namespace std;

class nodo
{
private:
	Operacion* operacion;
	nodo* next;
public:
	nodo(Operacion*);
	void setNodo(nodo*);
	nodo* getNodo();
	Operacion* getOperacion();
};
#endif