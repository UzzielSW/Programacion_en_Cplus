/* Uso de goto.
con la etiqueta inicio: se marca el inicio del bucle que se ejecuta hasta la linea 17
Luego que cuenta toma el valor de 11 se ejecuta goto fin donde se ejecuta lo que esta despues de la
etiqueta fin: */
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int cuenta = 1;

	inicio: // etiqueta

	// va hasta fin cuando cuenta excede a 10
	if ( cuenta > 10 )
		goto fin;

	cout << setw( 2 ) << left << cuenta;
	++cuenta;

	goto inicio;

	fin: // etiqueta
	cout << endl;

	return 0;
}