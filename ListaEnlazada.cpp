#include "Nodo.h"
#include "ListaEnlazada.h"
#include "archivo.h"
#include <iostream>
using namespace std;

ListaEnlazada::ListaEnlazada() {
	cabeza = nullptr;
	ultimo = nullptr;
}
Nodo* ListaEnlazada::raiz(int valor) {
	Nodo* aux = new Nodo(valor, 0, 0);
	if (cabeza == nullptr) {
		cabeza = aux;
	}
	cantidad++;
	return cabeza;
}
Nodo* ListaEnlazada::agregarNodo(Nodo* nodo, int orientacion, int valor, int f, int c) {
	Nodo* aux = obtenerNodo(f, c);
	if (aux == nullptr) {
		aux = new Nodo(valor, f, c);
		cantidad++;
	}
	switch (orientacion) {
	case 1:
		nodo->asignarD(aux);
		break;
	case 2:
		nodo->asignarA(aux);
		break;
	}
	return aux;
}
Nodo* ListaEnlazada::obtenerNodo(int f, int c) {
	//        canal = false;
	if (cabeza == nullptr)return obtener;
	obtener = nullptr;
	Nodo* aux1 = cabeza;
	if (aux1->Fila() == f && aux1->Columna() == c) {
		obtener = aux1;
	}
	else {
		nOb(aux1, f, c);
	}
	return obtener;
}

void ListaEnlazada::nOb(Nodo* nodo, int f, int c) {
	if (nodo->derecha != nullptr) {
		if (nodo->derecha->Fila() == f && nodo->derecha->Columna() == c) {
			obtener = nodo->derecha;
		}
		else {
			nOb(nodo->derecha, f, c);
		}
	}
	if (nodo->abajo != nullptr) {
		if (nodo->abajo->Fila() == f && nodo->abajo->Columna() == c) {
			obtener = nodo->abajo;
		}
		else {
			nOb(nodo->abajo, f, c);
		}
	}
}
void ListaEnlazada::Menu() {
	bool cerrar = true;
	int opcion = 0;
	string nombre;
	string nombre2;
	archivo e;
	do
		{
			cout << "-----OPERACIONES CON MATRICES------" << endl;
			cout << "1. SUMA" << endl;
			cout << "2. RESTA" << endl;
			cout << "3. MULTIPLICACION" << endl;
			cout << "4. DETERMINANTE" << endl;
			cout << "5. IMPRIMIR MATRICES" << endl;
			cout << "6. SALIR" << endl;
			cout << "Ingrse Opcion:";
			cin >> opcion;
			switch (opcion)
			{
			case 1:
				cout << "-----SUMA------" << endl;
				cout << "Ingrese Nombre de Matriz 1:";
				cin >> nombre;
				cout << "\nIngrese Nombre de Matriz 2:";
				cin >> nombre2;
	           Suma(nombre, nombre2);
				break;
			case 2:
				cout << "-----RESTA------" << endl;
				cout << "Ingrese Nombre de Matriz 1:";
				cin >> nombre;
				cout << "\nIngrese Nombre de Matriz 2:";
				cin >> nombre2;
				Resta(nombre, nombre2);
				break;
			case 3:
				cout << "-----MULTIPLICACION------" << endl;
				cout << "Ingrese Nombre de Matriz 1:";
				cin >> nombre;
				cout << "\nIngrese Nombre de Matriz 2:";
				cin >> nombre2;
				Multiplicacion(nombre, nombre2);
				break;
			case 4:
				cout << "-----DETERMINANTE------" << endl;
				cout << "Ingrese Nombre de Matriz 1:";
				cin >> nombre;
				Determinante(nombre);
				break;
			case 5:
				cout<< "-----IMPRIMIR MATRICES------" << endl;
				cout << "Ingrese Nombre de Matriz 1:";
				cin >> nombre;
				cout << "-------MATRIZ--------\n";
				e.imprimir(nombre);
				break;
			case 6:
				cerrar = false;
				break;
			default:
				cout << "Ingrese Una Opcion Valida" << endl;
				break;
			}
		} while (cerrar);

}
void ListaEnlazada::Suma(string nombre, string nombre2) {
	archivo arch2;
	archivo archivo;
	if (archivo.matriz_1(nombre)==nullptr||archivo.matriz_2(nombre2)==nullptr)
	{
		cout << "\nNo Existen los archivos" << endl;
		return;
	}
	ListaEnlazada* lista = archivo.matriz_1(nombre);
	ListaEnlazada* lista2 = arch2.matriz_2(nombre2);
	ListaEnlazada* resultado = new ListaEnlazada();
	if (archivo.obColumna()==arch2.obColumna()&&archivo.obFila()==arch2.obFila())
	{
		cout << "-----MATRIZ A--------" << endl;

		archivo.imprimir(nombre);
		cout << "-----MATRIZ B--------" << endl;

		arch2.imprimir(nombre2);
		cout << "-----RESULTADO--------" << endl;
		for (int i = 0; i < archivo.obFila(); i++)
		{
			for (int j = 0; j < archivo.obColumna(); j++)
			{
				int valor = lista->obtenerNodo(i, j)->numero + lista2->obtenerNodo(i, j)->numero;
				Nodo* nodo = nullptr;
				if (i == 0 && j == 0) {
					nodo = resultado->raiz(valor);
				}
				else {
					if ((j - 1) >= 0) {
						nodo = resultado->agregarNodo(resultado->obtenerNodo(i, (j - 1)), 1, valor, i, j);
					}
					if ((i - 1) >= 0) {
						nodo = resultado->agregarNodo(resultado->obtenerNodo((i - 1), j), 2, valor, i, j);
					}
				}
			}
		}
		resultado->mostrarLista();
		string direccion;
		cout << "Ingrese el nombre de el archivo a crear:";
		cin >> direccion;
		archivo.escribirArchivo(archivo.obFila(), archivo.obColumna(), resultado, direccion);

		cout << endl;
	
	}
	else {
		cout << "Lo Siento no son compatibles" << endl;
		return;
	}

}
void ListaEnlazada::Resta(string nombre,string nombre2) {
	archivo arch2;
	archivo archivo;
	if (archivo.matriz_1(nombre) == nullptr || archivo.matriz_2(nombre2) == nullptr)
	{
		cout << "\nNo Existen los archivos" << endl;
		return;
	}
	ListaEnlazada* lista = archivo.matriz_1(nombre);
	ListaEnlazada* lista2 = arch2.matriz_2(nombre2);
	ListaEnlazada* resultado = new ListaEnlazada();
	if (archivo.obColumna() == arch2.obColumna() && archivo.obFila() == arch2.obFila())
	
	{
		cout << "-----MATRIZ A--------" << endl;

		archivo.imprimir(nombre);
		cout << "-----MATRIZ B--------" << endl;

		arch2.imprimir(nombre2);
		cout << "-----RESULTADO--------" << endl;
	for (int i = 0; i < archivo.obFila(); i++)
	{
		for (int j = 0; j < archivo.obColumna(); j++)
		{
			int valor = lista->obtenerNodo(i, j)->numero - lista2->obtenerNodo(i, j)->numero;
			Nodo* nodo = nullptr;
			if (i == 0 && j == 0) {
				nodo = resultado->raiz(valor);
			} else {
				if ((j - 1) >= 0) {
					nodo = resultado->agregarNodo(resultado->obtenerNodo(i, (j - 1)), 1, valor, i, j);
				}
				if ((i - 1) >= 0) {
					nodo = resultado->agregarNodo(resultado->obtenerNodo((i - 1), j), 2, valor, i, j);
				}
			}
		}
	}
	resultado->mostrarLista();
	string direccion;
	cout << "Ingrese el nombre de el archivo a crear:";
	cin >> direccion;
	archivo.escribirArchivo(archivo.obFila(), archivo.obColumna(), resultado, direccion);
		cout << endl;
	}
	else {
		cout << "Lo Siento no son compatibles" << endl;
		return;
	}

}
void ListaEnlazada::Multiplicacion(string nombre, string nombre2) {
	archivo archivo2;
	archivo archivo;
	ListaEnlazada* lista = archivo.matriz_1(nombre);
	ListaEnlazada* resultado = new ListaEnlazada();
	ListaEnlazada* lista2 = archivo2.matriz_2(nombre2);
	//bool bosa = archivo.obColumna() == archivo2.obFila();
	//cout<< archivo.obColumna() <<" "<< archivo2.obFila();
	if (archivo.matriz_1(nombre) == nullptr || archivo.matriz_2(nombre2) == nullptr)
	{
		cout << "\nNo Existen los archivos" << endl;
		return;
	}
	else if (bosa) {
		int temporal = 0;
		lista = archivo.matriz_1(nombre);
		 resultado = new ListaEnlazada();
		lista2 = archivo2.matriz_2(nombre2);
		cout << "-----MATRIZ A--------" << endl;
		lista->mostrarLista();
		cout << "-----MATRIZ B--------" << endl;
		lista2->mostrarLista();
		for (int i = 0; i < archivo.obFila(); i++) //i para las filas de la matriz resultante
		{
			for (int k = 0; k < archivo2.obColumna(); k++) // k para las columnas de la matriz resultante
			{
				for (int j = 0; j < archivo.obColumna(); j++) //j para realizar la multiplicacion de 
				{                                   //los elementos   de la matriz
					temporal = temporal + (lista->obtenerNodo(i, j)->numero * lista2->obtenerNodo(j, k)->numero);
				}
				Nodo* nodo = nullptr;
				if (i == 0 && k == 0) {
					nodo = resultado->raiz(temporal);
				}
				else {
					if ((k - 1) >= 0) {
						nodo = resultado->agregarNodo(resultado->obtenerNodo(i, (k - 1)), 1, temporal, i, k);
					}
					if ((i - 1) >= 0) {
						nodo = resultado->agregarNodo(resultado->obtenerNodo((i - 1), k), 2, temporal, i, k);
					}
				}
				temporal = 0;

			}
		}
		cout << "-----MULTIPLICACION--------" << endl;
		resultado->mostrarLista();
		string direccion;
		cout << "Ingrese el nombre de el archivo a crear:";
		cin >> direccion;
		archivo.escribirArchivo(archivo.obFila(), archivo.obColumna(), resultado, direccion);
		cout << endl;
	}
	

}



void ListaEnlazada::Determinante(string nombre) {
	archivo archivo;
	int temporal = 0;
	if (archivo.matriz_1(nombre) == nullptr)
	{
		cout << "\nNo Existen los archivos" << endl;
		return;
	}
	if (archivo.obFila()==1&&archivo.obColumna()==1)
	{
		ListaEnlazada* lista = archivo.matriz_1(nombre);
		ListaEnlazada* resultado = new ListaEnlazada();
		cout << "-----MATRIZ A--------" << endl;
		archivo.imprimir(nombre);
		cout << "-----DETERMINANTE ES--------" << endl;
		Nodo* nodo = nullptr;
		if (0 == 0 && 0 == 0) {
			nodo = resultado->raiz(lista->obtenerNodo(0, 0)->numero);
		}
		resultado->mostrarLista();
		string direccion;
		cout << "Ingrese el nombre de el archivo a crear:";
		cin >> direccion;
		archivo.escribirDet(archivo.obFila(), archivo.obColumna(), resultado, direccion);
		cout << endl;


	}
	else if (archivo.obFila() == 2 && archivo.obColumna() == 2) {
		ListaEnlazada* lista = archivo.matriz_1(nombre);
		ListaEnlazada* resultado = new ListaEnlazada();
		int valor = lista->obtenerNodo(0, 0)->numero*lista->obtenerNodo(1, 1)->numero;
		int valor2 = lista->obtenerNodo(0, 1)->numero * lista->obtenerNodo(1, 0)->numero;
		Nodo* nodo = nullptr;
		if (0 == 0 && 0 == 0) {
			nodo = resultado->raiz(valor-valor2);
		}
		cout << "-----DETERMINANTE ES --------" << endl;
		resultado->mostrarLista();
		string direccion;
		cout << "Ingrese el nombre de el archivo a crear:";
		cin >> direccion;
		archivo.escribirDet(archivo.obFila(), archivo.obColumna(), resultado, direccion);
		cout << endl;
		
	}else if (archivo.obFila() == 3 && archivo.obColumna() == 3) {
		ListaEnlazada* lista = archivo.matriz_1(nombre);
		int det, pos, neg;
		pos = lista->obtenerNodo(0, 0)->numero * lista->obtenerNodo(1, 1)->numero * lista->obtenerNodo(2, 2)->numero + lista->obtenerNodo(1, 0)->numero * lista->obtenerNodo(2, 1)->numero * lista->obtenerNodo(0, 2)->numero + lista->obtenerNodo(0, 1)->numero * lista->obtenerNodo(1, 2)->numero * lista->obtenerNodo(2, 0)->numero;
		neg = lista->obtenerNodo(0, 2)->numero * lista->obtenerNodo(1, 1)->numero * lista->obtenerNodo(2, 0)->numero + lista->obtenerNodo(1, 2)->numero * lista->obtenerNodo(2, 1)->numero * lista->obtenerNodo(0, 0)->numero + lista->obtenerNodo(0, 1)->numero * lista->obtenerNodo(1, 0)->numero * lista->obtenerNodo(2, 2)->numero;
		det = pos - neg;
		Nodo* nodo = nullptr;
		ListaEnlazada* resultado = new ListaEnlazada();
		if (0 == 0 && 0 == 0) {
			nodo = resultado->raiz(det);
		}
		cout << "-----DETERMINANTE ES--------" << endl;
		resultado->mostrarLista();
		string direccion;
		cout << "Ingrese el nombre de el archivo a crear:";
		cin >> direccion;
		archivo.escribirDet(archivo.obFila(), archivo.obColumna(), resultado, direccion);
		cout << endl;
	}
	else if (archivo.obFila() >= 4 && archivo.obColumna() >=4)
	{
		cout << "-----MATRIZ A--------" << endl;
		archivo.imprimir(nombre);
		ListaEnlazada* lista = archivo.matriz_1(nombre);
		Nodo* nodo = nullptr;
		ListaEnlazada* resultado = new ListaEnlazada();
		if (0 == 0 && 0 == 0) {
			nodo = resultado->raiz(Det(lista, archivo.obFila(), nombre));
		}
		cout << "-----DETERMINANTE ES--------" << endl;
		resultado->mostrarLista();
		string direccion;
		cout << "Ingrese el nombre de el archivo a crear:";
		cin >> direccion;
		archivo.escribirDet(archivo.obFila(), archivo.obColumna(), resultado, direccion);
		cout << endl;
	}


	cout << endl;
}
int ListaEnlazada::Det(ListaEnlazada* lista2, int n, string nombre) {
	archivo archivo;
	ListaEnlazada* lista = archivo.matriz_1(nombre);
	int det = 0;
	if (n == 2)
		return ((lista2->obtenerNodo(0, 0)->numero * lista2->obtenerNodo(1, 1)->numero) - (lista2->obtenerNodo(1, 0)->numero * lista2->obtenerNodo(0, 1)->numero));
	else {
		for (int x = 0; x < n; x++) {
			int subi = 0;
			for (int i = 1; i < n; i++) {
				int subj = 0;
				for (int j = 0; j < n; j++) {
					if (j == x)
						continue;
					lista->obtenerNodo(subi, subj)->numero = lista2->obtenerNodo(i, j)->numero;
					subj++;
				}
				subi++;
			}
			det = det + (pow(-1, x) * lista2->obtenerNodo(0, x)->numero * Det(lista, n - 1, nombre));
		}
	}
	return det;
}
void ListaEnlazada::mostrarLista() {
	Nodo* aux1 = cabeza;
	cout << aux1->numero << " ";
	Nodo* nod = aux1->derecha;
	do {
		if (nod == nullptr)break;
		cout<<nod->numero<<" ";
		nod = nod->derecha;
	} while (true);
	cout << endl;
	while ((aux1 = aux1->abajo) != nullptr) {
		cout << aux1->numero << " ";
		nod = aux1->derecha;
		do {
			if (nod == nullptr)break;
			cout << nod->numero << " ";
			nod = nod->derecha;
		} while (true);
		//            break;
		cout << endl;
	}
}
