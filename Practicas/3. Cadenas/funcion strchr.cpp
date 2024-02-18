#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	const char *cadena1 = "Esta es una prueba";
	char caracter1 = 'a';
	char caracter2 = 'z';

	// busca el caracter1 en cadena1
	if (strchr(cadena1, caracter1) != NULL)
		cout << '\'' << caracter1 << "' se encontro en \"" << cadena1 << "\".\n";
	else
		cout << '\'' << caracter1 << "' no se encontro en \"" << cadena1 << "\".\n";

	// busca el caracter2 en cadena1
	if (strchr(cadena1, caracter2 ) != NULL)
		cout << '\'' << caracter2 << "' se encontro en \"" << cadena1 << "\".\n";
	else
		cout << '\'' << caracter2 << "' no se encontro en \""<< cadena1 << "\"." << endl;

	return 0;
}

/*salida:
	'a' se encontro en "Esta es una prueba".
	'z' no se encontro en "Esta es una prueba".
*/