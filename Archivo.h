#pragma once
#pragma once
#include "ListaEnlazada.h"
class archivo {

public:
	int fila;
	int columna;
	ListaEnlazada* matriz_1(string);
	ListaEnlazada*  matriz_2(string);
	void leerArchivo();
	void asFila(int);
	int obFila();
	void asColumna(int);
	int obColumna();
	void imprimir(string nombre);
	void escribirArchivo(int fila, int columna, ListaEnlazada* lista,int );
};
