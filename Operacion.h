#ifndef OPERACION_H
#define OPERACION_H
#include<string>
#include <vector>
using namespace std;

class Operacion
{
public:
	Operacion(string);
	int Resolve(string,vector<int>,vector<char>);
	string getOperacion();
private:
	string operacion;
};
#endif