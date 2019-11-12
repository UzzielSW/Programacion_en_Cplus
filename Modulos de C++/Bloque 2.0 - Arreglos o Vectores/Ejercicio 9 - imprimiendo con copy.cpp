// imprimiendo array con copy
#include <iostream>
#include <algorithm> // algoritmo de copia
#include <iterator> // ostream_iterator
using namespace std;

int main()
{
	const int TAMANIO = 10;
	int array[ TAMANIO ] = { 7, 22, 9, 1, 18, 30, 100, 22, 85, 13 };
	
	ostream_iterator< int > salida(cout, " ");
	copy( array, array + TAMANIO, salida );

	return 0;
}