#ifndef PILA_H
#define PILA_H
#include "nodo.h" 
using namespace std;

class PILA
{
private:
	nodo* last;
public:
	PILA();
	~PILA();
	void Push(Operacion*);
	nodo* Pop();
	nodo* Top();
	bool isEmpty();
	
};
#endif