#include "nodo.h"
#include "Operacion.h"

nodo::nodo(Operacion* oper){
	operacion=oper;
	next=NULL;
}
void nodo::setNodo(nodo* nod){
	next=nod;
}
nodo* nodo::getNodo(){
	return next;
}
Operacion* nodo::getOperacion(){
	return operacion;
}