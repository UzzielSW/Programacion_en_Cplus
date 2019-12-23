#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	const char *cadena1 = "El valor es 3.14159";
	const char *cadena2 = "aerls Eov";

	cout<<"cadena1 = " << cadena1 << "\ncadena2 = " << cadena2
		<<"\n\nLa longitud del segmento inicial de cadena1\n" 
		<<"que solo contiene caracteres de cadena 2 cadena2 = " << strspn(cadena1, cadena2) << endl;
	return 0;
}

/*salida:
	cadena1 = El valor es 3.14159
	cadena2 = aerls Eov
	La longitud del segmento inicial de cadena1
	que solo contiene caracteres de cadena 2 = 12
*/