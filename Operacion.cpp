#include "Operacion.h"
#include<string>
#include <iostream>
#include <vector>

Operacion::Operacion(string oper){
	operacion=oper;
}
int Operacion::Resolve(string cad,vector<int> valores,vector<char> nombres){
	cout<<"Resolviendo"<<endl;
	if(isdigit(cad[0])){
		int x=(int)cad[0]-48;
		cout<<x<<endl;
		if(cad.size()>2){
			switch(cad[1]){
				case '+':
					return x+Resolve(cad.substr(2),valores,nombres);
					break;
				case '-':
					return x-Resolve(cad.substr(2),valores,nombres);
					break;
				case '*':
					return x*Resolve(cad.substr(2),valores,nombres);
					break;
				case '/':		
					return x/Resolve(cad.substr(2),valores,nombres);
			}
		}else{
			return x;
		}
	}else{
		if(cad[0]=='('){
			string scad="";
			for (int i = 1; i < cad.size(); ++i)
			{
				if(cad[i]==')'){
					if(i+1<cad.size()){
						switch(cad[i+1]){
							case '+':
								return Resolve(scad,valores,nombres)+Resolve(cad.substr(i+1),valores,nombres);
								break;
							case '-':
								return Resolve(scad,valores,nombres)-Resolve(cad.substr(i+1),valores,nombres);
								break;
							case '*':
								return Resolve(scad,valores,nombres)*Resolve(cad.substr(i+1),valores,nombres);
								break;
							case '/':		
								return Resolve(scad,valores,nombres)/Resolve(cad.substr(i+1),valores,nombres);
						}
						 
					}else{
						return Resolve(scad,valores,nombres);
					}
				}else{
					scad+=cad[i];
				}
			}
		}else{
			for (int j=0;j<nombres.size();j++){
				if(cad[0]==nombres[j]){
					int x=valores[j];
					switch(cad[1]){
						case '+':
							return x+Resolve(cad.substr(2),valores,nombres);
							break;
						case '-':
							return x-Resolve(cad.substr(2),valores,nombres);
							break;
						case '*':
							return x*Resolve(cad.substr(2),valores,nombres);
							break;
						case '/':		
							return x/Resolve(cad.substr(2),valores,nombres);
					}
				}
			}
		}
	}
}
string Operacion::getOperacion(){
	return operacion;
}