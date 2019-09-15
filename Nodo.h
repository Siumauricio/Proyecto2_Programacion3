#pragma once
#include <iostream>
#ifndef NODO_H

#define NODO_H

using namespace std;
class Nodo {
public:
	int f, c;
	int numero;
	Nodo* abajo;
	Nodo* derecha;
	Nodo(int numero, int f, int c);
	int Fila();
	int Columna();
	void asignarD(Nodo* derecha);
	void asignarA(Nodo* abajo);
	Nodo* NodoD();
	Nodo* NodoA();
};
#endif // !NODO_H
