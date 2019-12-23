#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	unsigned long x;
	const char *cadena1 = "1234567abc";
	char *restoPtr;

	// convierte una secuencia de caracteres a unsigned long 
	x = strtoul(cadena1, &restoPtr, 0);

	cout<<"La cadena original es \"" << cadena1 
		<<"\"\nEl valor convertido es " << x
		<<"\nEl resto de la cadena original es \"" << restoPtr
		<<"\"\nEl valor convertido menos 567 es " << x - 567 << endl;

	return 0;
}

/*salida:
	La cadena original es "1234567abc"
	El valor convertido es 1234567
	El resto de la cadena original es "abc"
	El valor convertido menos 567 es 1234000
*/