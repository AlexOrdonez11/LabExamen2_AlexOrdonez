temp:	main.o PILA.o Operacion.o nodo.o
	g++ main.o PILA.o Operacion.o nodo.o -o temp
main.o:	nodo.h Operacion.h PILA.h main.cpp
	g++ -c main.cpp
PILA.o:	nodo.h PILA.h PILA.cpp
	g++ -c PILA.cpp
Operacion.o:	Operacion.h Operacion.cpp
	g++ -c Operacion.cpp
nodo.o:	nodo.h Operacion.cpp nodo.cpp
	g++ -c nodo.cpp
