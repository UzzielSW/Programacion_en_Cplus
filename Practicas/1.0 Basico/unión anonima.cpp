// Uso de una union anonima.
#include <iostream>
#include <stdlib.h>
#include <conio.h">
using namespace std;

int main()
{
	// declara una union anonima los miembros entero1, double1 y charPtr comparten el mismo espacio
	union{
		int entero1;
		double double1;
		char *charPtr;
	}; // fin de la union anonima

	// declara las variables locales
	int entero2 = 1;
	double double2 = 3.3;
	char *char2Ptr = "Union";

	// asigna un valor a cada miembro de la union
	// en forma sucesiva, e imprime cada uno
	
	cout << entero2 << ' ';

	entero1 = 2;
	cout << entero1 << endl << double2 << ' ';
	
	double1 = 4.4;
	cout << double1 << endl << char2Ptr << ' ';
	
	charPtr = "anonima";
	cout << charPtr << endl;

	return 0;
}
