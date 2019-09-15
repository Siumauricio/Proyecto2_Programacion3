#include "archivo.h"
#include <fstream>
#include <iostream>
#include <sstream> 
#include <string.h>
using namespace std;
#include <string>
#include "ListaEnlazada.h"
#include "nodo.h"
using std::istringstream;
void archivo::escribirArchivo(int fila, int columna,ListaEnlazada*ob,int n) {
	ofstream materiasOut("c.dat", ios::app);
	if (!materiasOut)
	{
		cout << "Error al intentar abrir archivo materias.dat";
		return;
	}

}
void archivo::leerArchivo() {
	string cadena;
	int Valor;
	ifstream datos("matriz1.txt");
	if (datos.fail()) {
		cout << "Texto entrada Estructura.txt no existe" << endl;
		return;
	}
	while (!datos.eof()) {
		getline(datos, cadena);
		istringstream in(cadena);
		while (in >> Valor) {
			cout << Valor << endl;
		}
	}
}
ListaEnlazada* archivo::matriz_1(string nombre) {
	ListaEnlazada* ob = new ListaEnlazada();
	string cadena;
	int n;
	ifstream datos(nombre);
	if (datos.fail()) {
		cout << "El Archivo no Existe! " << endl;
		return nullptr;

	}
	else {
	
		string line = "";
		int f = 0, c = 0;
		int filas = 0, columnas = 0;
		bool sumaColumnas = false;
		while (!datos.eof()) {
			filas++;
			getline(datos, cadena);
			istringstream in(cadena);
			while (in >> n) {
				//cout << n << endl;
				if (!sumaColumnas)columnas++;
				Nodo* nodo = nullptr;
				if (f == 0 && c == 0) {
					nodo = ob->raiz(n);
				}
				else {
					if ((c - 1) >= 0) {
						nodo = ob->agregarNodo(ob->obtenerNodo(f, (c - 1)), 1, n, f, c);
					}
					if ((f - 1) >= 0) {
						nodo = ob->agregarNodo(ob->obtenerNodo((f - 1), c), 2, n, f, c);
					}
				}
				c++;
			}
			sumaColumnas = true;
			f++;
			c = 0;
			asFila(filas);
			asColumna(columnas);
		}
	}
	
	return ob;
}
ListaEnlazada* archivo::matriz_2(string nombre) {
	ListaEnlazada* ob = new ListaEnlazada();

	string cadena;
	int n;
	ifstream datos(nombre);
	if (datos.fail()) {
		cout << "El Archivo no Existe! " << endl;
		return  nullptr;
	}
	else {
		string line = "";
		int f = 0, c = 0;
		int filas = 0, columnas = 0;

		bool sumaColumnas = false;
		while (!datos.eof()) {
			filas++;
			getline(datos, cadena);
			istringstream in(cadena);
			while (in >> n) {
				//cout << n << endl;
				if (!sumaColumnas)columnas++;
				Nodo* nodo = nullptr;
				if (f == 0 && c == 0) {
					nodo = ob->raiz(n);
				}
				else {
					if ((c - 1) >= 0) {
						nodo = ob->agregarNodo(ob->obtenerNodo(f, (c - 1)), 1, n, f, c);
					}
					if ((f - 1) >= 0) {
						nodo = ob->agregarNodo(ob->obtenerNodo((f - 1), c), 2, n, f, c);
					}
				}
				c++;
			}
			sumaColumnas = true;
			f++;
			c = 0;
			asFila(filas);
			asColumna(columnas);
		}
		cout << endl;
	}
	return ob;
}
void archivo::imprimir(string nombre) {
	ListaEnlazada* ob = new ListaEnlazada();

	string cadena;
	int n;
	ifstream datos(nombre);
	if (datos.fail()) {
		cout << "El Archivo no Existe! " << endl;
		return;
	}
	else {
		string line = "";
		int f = 0, c = 0;
		int filas = 0, columnas = 0;

		bool sumaColumnas = false;
		while (!datos.eof()) {
			filas++;
			getline(datos, cadena);
			istringstream in(cadena);
			while (in >> n) {
				//cout << n << endl;
				if (!sumaColumnas)columnas++;
				Nodo* nodo = nullptr;
				if (f == 0 && c == 0) {
					nodo = ob->raiz(n);
				}
				else {
					if ((c - 1) >= 0) {
						nodo = ob->agregarNodo(ob->obtenerNodo(f, (c - 1)), 1, n, f, c);
					}
					if ((f - 1) >= 0) {
						nodo = ob->agregarNodo(ob->obtenerNodo((f - 1), c), 2, n, f, c);
					}
				}
				c++;
			}
			sumaColumnas = true;
			f++;
			c = 0;
			asFila(filas);
			asColumna(columnas);
		}
		for (int i = 0; i < filas; i++)
		{
			for (int j = 0; j < columnas; j++) {
				cout << ob->obtenerNodo(i, j)->numero << " ";
			}
			cout << endl;;
		}
		cout << endl;
	}
}
void archivo::asFila(int valor) {
	this->fila = valor;
}
void archivo::asColumna(int valor) {
	this->columna = valor;
}
int archivo::obFila() {
	return this->fila;
}
int archivo::obColumna() {
	return this->columna;
}
