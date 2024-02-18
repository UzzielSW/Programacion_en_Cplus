// Programa de prueba del adaptador stack de la Biblioteca estandar.
#include <iostream>
#include <stack>  // definicion del adaptador stack
#include <vector> // definicion de la plantilla de clase vector
#include <list>	  // definicion de la plantilla de clase list
using namespace std;

// prototipo de la plantilla de funcion meterElementos
template <typename T>
void meterElementos(T &refStack);
// prototipo de la plantilla de funcion sacarElementos
template <typename T>
void sacarElementos(T &refStack);

int main()
{
	// pila con el contenedor deque subyacente predeterminado
	stack<int> pilaDequeInt;

	// pila con el contenedor vector subyacente
	stack<int, vector<int>> pilaVectorInt;

	// pila con el contenedor list subyacente
	stack<int, list<int>> pilaListInt;

	// mete los valores 0 a 9 en cada pila
	cout << " Metiendo datos en pilaDequeInt: ";
	meterElementos(pilaDequeInt);
	cout << "\n Metiendo datos en pilaVectorInt: ";
	meterElementos(pilaVectorInt);
	cout << "\n Metiendo datos en pilaListInt: ";
	meterElementos(pilaListInt);
	cout << endl
		 << endl;

	// muestra y elimina los elementos de cada pila
	cout << " Sacando datos de pilaDequeInt: ";
	sacarElementos(pilaDequeInt);
	cout << "\n Sacando datos de pilaVectorInt: ";
	sacarElementos(pilaVectorInt);
	cout << "\n Sacando datos de pilaListInt: ";
	sacarElementos(pilaListInt);
	cout << endl;
	return 0;
}

// mete elementos al objeto pila al que refStack hace referencia
template <typename T>
void meterElementos(T &refStack)
{
	for (int i = 0; i < 10; i++)
	{
		refStack.push(i);			   // mete elemento en la pila
		cout << refStack.top() << ' '; // ve (y muestra) el elemento superior
	}
}

// saca elementos del objeto pila al que refStack hace referencia
template <typename T>
void sacarElementos(T &refStack)
{
	while (!refStack.empty())
	{
		cout << refStack.top() << ' '; // ve (y muestra) el elemento superior
		refStack.pop();				   // elimina el elemento superior
	}
}
