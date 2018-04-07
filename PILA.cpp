#include"PILA.h"
#include"nodo.h"
PILA::PILA(){
	last=NULL;
}

PILA::~PILA(){
	while(!isEmpty()){
		Pop();
	}
}
void PILA::Push(Operacion* i){
	nodo* nod=new nodo(i);
	nod->setNodo(last);
	last=nod;
}
nodo* PILA::Pop(){
	if(!isEmpty()){
		nodo* nod=last;
		last=last->getNodo();
		return nod;
	}else{
		return NULL; 
	}
}
nodo* PILA::Top(){
	return last;
}
bool PILA::isEmpty(){
	if(last==NULL){
		return true;
	}else{
		return false;
	}
}