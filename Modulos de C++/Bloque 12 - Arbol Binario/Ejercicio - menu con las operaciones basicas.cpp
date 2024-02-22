/*
	Operaciones en Arboles binarios de busqueda:
	* Insertar nodo en el arbol
	* Mostrar el arbol completo
	* buscar un nodo especifico
	* Recorrer el arbol (recorridos: Pre-orden, In-orden, Post-orden)
	* Borrar un nodo del Arbol
	* Borrar el Arbol
 */
#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

struct Nodo
{
	int dato;
	Nodo *der;
	Nodo *izq;
	Nodo(int n = 0, Nodo *right = NULL, Nodo *left = NULL)
	{
		this->dato = n;
		this->der = right;
		this->izq = left;
	}
};

void InsertarNodo(Nodo *&, int);
void MostrarArbol(Nodo *, int);
bool BuscarNodo(Nodo *, int);
void RecorridosArbol(Nodo *, int);
bool EliminarNodo(Nodo *&, int);
void eliminar(Nodo *&);
void destruirArbol(Nodo *&);

enum
{
	PreOrden = 1,
	InOrden,
	PostOrden
};

int main()
{
	Nodo *Arbol = NULL;
	int opc = 0, dato = 0, cont = 0;
	do
	{
		system("cls");
		cout << "\n |_|_:menu:_|_|";
		cout << "\n 1. Insertar Nodos ";
		cout << "\n 2. Mostrar Arbol";
		cout << "\n 3. Buscar un Nodo";
		cout << "\n 4. Recorrido en PreOrden";
		cout << "\n 5. Recorrido en InOrden";
		cout << "\n 6. Recorrido en PostOrden";
		cout << "\n 7. Borrar un Nodo del Arbol";
		cout << "\n 8. Borrar el Arbol";
		cout << "\n 9. Salir";
		cout << "\n\n Opcion? ";
		cin >> opc;
		switch (opc)
		{
		case 1:
			cout << "\n ingrese un dato [0 para salir]: ";
			cin >> dato;
			while (dato != 0)
			{
				InsertarNodo(Arbol, dato);
				cout << " ingrese un dato [0 para salir]: ";
				cin >> dato;
			}
			break;

		case 2:
			if (Arbol != NULL)
			{
				cout << "\n Mostrando el arbol completo:\n\n";
				MostrarArbol(Arbol, cont);
			}
			else
				cout << "\n == Arbol vacio ==";
			break;

		case 3:
			if (Arbol != NULL)
			{
				cout << "\n ingrese el dato que desea buscar: ";
				cin >> dato;
				if (BuscarNodo(Arbol, dato))
					cout << "\n el dato " << dato << " fue encontrado";
				else
					cout << "\n el dato " << dato << " no se encontro";
			}
			else
				cout << "\n == Arbol vacio ==";
			break;

		case 4:
			if (Arbol != NULL)
			{
				cout << "\n Recorrido en Pre-orden: ";
				RecorridosArbol(Arbol, PreOrden);
			}
			else
				cout << "\n == Arbol vacio ==";
			break;

		case 5:
			if (Arbol != NULL)
			{
				cout << "\n Recorrido en In-orden: ";
				RecorridosArbol(Arbol, InOrden);
			}
			else
				cout << "\n == Arbol vacio ==";
			break;

		case 6:
			if (Arbol != NULL)
			{
				cout << "\n Recorrido en Post-orden: ";
				RecorridosArbol(Arbol, PostOrden);
			}
			else
				cout << "\n == Arbol vacio ==";
			break;

		case 7:
			if (Arbol != NULL)
			{
				cout << "\n Ingrese el Nodo que desea eliminar: ";
				cin >> dato;
				if (EliminarNodo(Arbol, dato))
					cout << "\n Nodo " << dato << " eliminado";
				else
					cout << "\n no se encontro el dato";
			}
			else
				cout << "\n == Arbol vacio ==";
			break;

		case 8:
			if (Arbol != NULL)
			{
				destruirArbol(Arbol);
			}
			else
				cout << "\n == Arbol vacio ==";
		}
		cout << "\n";
		getch();
	} while (opc != 9);
	return 0;
}

void InsertarNodo(Nodo *&Arbol, int n)
{
	if (Arbol == NULL)
	{
		Arbol = new Nodo(n);
		return;
	}

	if (Arbol->dato == n)
		return;

	if (n < Arbol->dato)
		InsertarNodo(Arbol->izq, n);
	else
		InsertarNodo(Arbol->der, n);
}

void MostrarArbol(Nodo *Arbol, int cont)
{
	if (Arbol == NULL) // caso base necesario para que no salga error cuando termine de mostrar todos
		return;
	else
	{
		MostrarArbol(Arbol->der, cont + 1);
		for (int i = 0; i < cont; ++i)
			cout << "   ";
		cout << Arbol->dato << endl;
		MostrarArbol(Arbol->izq, cont + 1);
	}
}

bool BuscarNodo(Nodo *Arbol, int n)
{
	Nodo *aux = Arbol;

	while (aux)
	{
		if (aux->dato == n)
			return true;
		else if (n < aux->dato)
			aux = aux->izq;
		else
			aux = aux->der;
	}

	return false;
}

void RecorridosArbol(Nodo *Arbol, int Orden)
{
	if (Arbol == NULL) // caso base necesario para que no salga error cuando termine de mostrar todos
		return;
	switch (Orden)
	{
	case PreOrden:
		cout << Arbol->dato << " - ";
		RecorridosArbol(Arbol->izq, Orden);
		RecorridosArbol(Arbol->der, Orden);
		break;

	case InOrden:
		RecorridosArbol(Arbol->izq, Orden);
		cout << Arbol->dato << " - ";
		RecorridosArbol(Arbol->der, Orden);
		break;

	case PostOrden:
		RecorridosArbol(Arbol->izq, Orden);
		RecorridosArbol(Arbol->der, Orden);
		cout << Arbol->dato << " - ";
		break;
	}
}

bool EliminarNodo(Nodo *&Arbol, int n)
{
	if (Arbol == NULL) // caso base necesario para que no salga error si no encuentra el nodo
		return false;
	if (n < Arbol->dato)
		EliminarNodo(Arbol->izq, n);
	else if (n > Arbol->dato)
		EliminarNodo(Arbol->der, n);
	else
	{
		eliminar(Arbol);
		return true;
	}
}

void eliminar(Nodo *&nodo)
{
	Nodo *borrarNodo = nodo;
	Nodo *aux;

	if (nodo->der == NULL)
		nodo = nodo->izq;

	else if (nodo->izq == NULL)
		nodo = nodo->der;

	else
	{
		aux = nodo->der;

		while (aux->izq != NULL)
			aux = aux->izq;

		aux->izq = nodo->izq;
		nodo = nodo->der;
	}

	delete borrarNodo;
}

void destruirArbol(Nodo *&Arbol)
{
	if (!Arbol)
		return;

	destruirArbol(Arbol->izq);
	destruirArbol(Arbol->der);
	cout << "\n delete Nodo " << Arbol->dato << "...";
	Arbol = NULL;
	delete Arbol;
}