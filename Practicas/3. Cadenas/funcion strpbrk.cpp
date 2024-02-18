#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	const char *cadena1 = "Esta es una prueba";
	const char *cadena2 = "cuidado"; 

	cout<<"De los caracteres en \"" << cadena2 << "\"\n'" 
		<< *strpbrk(cadena1, cadena2) << "\' es el primer caracter "
		<<"que aparece en\n\"" << cadena1 << '\"' << endl;
	return 0;
}

/*salida:
	De los caracteres en "cuidado"
	'a' es el primer caracter que aparece en
	"Esta es una prueba"
*/