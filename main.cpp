#include "PILA.h"
#include "nodo.h"
#include "iostream"
#include "string"
#include "Operacion.h"
#include <fstream>
using namespace std;

void Crear(PILA*&);
void Eliminar(PILA*&);
bool ValidarOp(string);
void Resolver(PILA*&,vector<int>,vector<char>);
void GuardarPila(PILA*&);
void CargarPila(PILA*&);
void Asignar(PILA*&,vector<int>&,vector<char>&);
int main(){
	vector<int> valores;
	vector<char> nombres;
	int op=0;
	PILA* pila=new PILA();
	while(op!=7){	
		cout<<"menu"<<endl;
		cout<<"1-Crear y Agregar Operacion a la pila"<<endl;
		cout<<"2-Eliminar Operacion de la pila"<<endl;
		cout<<"3-Resolver Operacion"<<endl;
		cout<<"4-Asignar Operacion a una Variable"<<endl;
		cout<<"5-Guardar y limpiar pila de Operaciones"<<endl;
		cout<<"6-Cargar pila de Operaciones"<<endl;
		cout<<"7-Salir"<<endl;
		cin>>op;
		switch(op){
			case 1:
				Crear(pila);
				break;
			case 2:
				Eliminar(pila);
				break;
			case 3:
				Resolver(pila,valores,nombres);
				break;
			case 4:
				Asignar(pila,valores,nombres);
			case 5:
				GuardarPila(pila);
				break;
			case 6:
				CargarPila(pila);
				break;
		}
	}
}
void Asignar(PILA*& pila,vector<int>& valores,vector<char>& nombres){
	char nombre;
	cout<<"Ingrese el nombre de la Variable"<<endl;
	cin>>nombre;
	nombres.push_back(nombre);
	nodo* nod=pila->Pop();
	int A=nod->getOperacion()->Resolve(nod->getOperacion()->getOperacion(),valores,nombres);
	cout<<"El resultado de la operacion es: "<<A<<endl;
	valores.push_back(A);
}
void GuardarPila(PILA*& pila){
	ofstream archivo("Operaciones.txt",ios::app);
	while(!pila->isEmpty()){
		archivo<<pila->Pop()->getOperacion()->getOperacion()<<endl;
	}

}
void CargarPila(PILA*& pila){

}
void Resolver(PILA*& pila,vector<int> valores,vector<char> nombres){
	nodo* nod=pila->Pop();
	int A=nod->getOperacion()->Resolve(nod->getOperacion()->getOperacion(),valores,nombres);
	cout<<"El resultado de la operacion es: "<<A<<endl;
}
void Crear(PILA*& pila){
	string operacion;
	cout<<"Ingrese una operacion valida"<<endl;
	cin>>operacion;
	//if(ValidarOp(operacion)){
		Operacion* op=new Operacion(operacion);
		pila->Push(op);
	//}
}
bool ValidarOp(string cad){
	if(cad.size()%2==0){
		return false;
	}
	for(int i=0;cad.size();i++){
		if(i%2==0){
			if(isdigit(cad[i])){
			}else{
				if(cad[i]=='('){
					string sub="";
					bool val=false;
					for (int j = i+1; j < cad.size(); j++)
					{
						if(cad[j]==')'){
							if(!ValidarOp(sub)){
								return false;
							}
							val=true;
							i=j+1;
							break;
						}else{
							sub+=cad[j];
						}
					}
					if(val==false){
						return false;
					}
				}else{
					return false;
				}
			}
		}else{
			if(cad[i]!='+'&&cad[i]!='-'&&cad[i]!='*'&&cad[i]!='/'){
				return false;
			}
		}
	}
	return true;
}
void Eliminar(PILA*& pila){
	nodo* nod=pila->Pop();
	delete nod;
}