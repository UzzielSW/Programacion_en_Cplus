// Uso de strtod.
//extraccion de un numero de una cadena
#include <iostream>
#include <stdlib.h> // prototipo de strtod
using namespace std;

int main()
{
	double d;
	const char *cadena1 = "51.2% se admite";
	char *cadenaPtr;

	d = strtod(cadena1, &cadenaPtr); // convierte caracteres a double

	cout << "La cadena \"" << cadena1 << "\" se convierte al\nvalor double " << d
	<< " y la cadena \"" << cadenaPtr << "\"" << endl;
	return 0;
} 

/*salida:
	La cadena "51.2% se admite" se convierte al
	valor double 51.2 y la cadena "% se admite"
*/