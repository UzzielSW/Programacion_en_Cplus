// Uso de goto.
#include <iostream>
#include <iomanip>

int main()
{
	int cuenta = 1;

	inicio: // etiqueta

	// va hasta fin cuando cuenta excede a 10
	if ( cuenta > 10 )
		goto fin;

	cout << setw( 2 ) << left << cuenta;
	++cuenta;

	// va hasta inicio en la línea 17
	goto inicio;

	fin: // etiqueta
	cout << endl;

	return 0;
}