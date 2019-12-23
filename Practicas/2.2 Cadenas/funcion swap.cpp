//Uso de la función swap para intercambiar dos objetos string.
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string primero("uno");
	string segundo("dos");

	// imprime los objetos string
	cout << "Antes de swap:\nprimero: " << primero << "\nsegundo: " << segundo;

	primero.swap(segundo); // intercambia los objetos string

	cout << "\n\nDespues de swap:\nprimero: " << primero << "\nsegundo: " << segundo << endl;
	return 0;
}