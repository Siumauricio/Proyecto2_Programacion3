#pragma once
#include "Nodo.h"
#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H
class ListaEnlazada{
private:
	Nodo* obtener;
	Nodo* cabeza;
	Nodo* ultimo;
	int contador = 0;
	int contador2 = 0;
	int cantidad = 0;
public:
	ListaEnlazada(void);
	Nodo* raiz(int valor);
	Nodo* agregarNodo(Nodo* nodo, int orientacion, int valor, int f, int c);
	Nodo* obtenerNodo(int f, int c);
	void nOb(Nodo* nodo, int f, int c);
	void Suma(string,string);
	void Resta(string,string);
	void Multiplicacion(string,string);
	void Determinante(string);
	int Det(ListaEnlazada*,int , string);
	void Menu();
	void mostrarLista();
};
#endif // !LISTAENLAZADA_H
