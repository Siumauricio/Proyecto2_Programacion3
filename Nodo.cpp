#pragma once
#include "Nodo.h"

Nodo::Nodo(int numero, int f, int c) {
	this->numero = numero;
	this->c = c;
	this->f = f;
}
int  Nodo::Fila() {
	return this->f;
}
int Nodo::Columna() {
	return this->c;
}
void Nodo::asignarD(Nodo* derecha) {
	this->derecha = derecha;
}
void Nodo::asignarA(Nodo* abajo) {
	this->abajo = abajo;
}
Nodo* Nodo::NodoD() {
	return derecha;
}
Nodo* Nodo::NodoA() {
	return abajo;
}
