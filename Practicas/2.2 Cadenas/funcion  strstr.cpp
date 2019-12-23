#include <iostream>
#include <string.h">
using namespace std;

int main()
{
	const char *cadena1 = "abcdefabcdef";
	const char *cadena2 = "def";

	cout<<"cadena1 = " << cadena1 
		<< "\ncadena2 = " << cadena2
		<<"\n\nEl resto de cadena1 que empieza con la\n"
		<<"primera ocurrencia de cadena2 es: "
		<<strstr(cadena1, cadena2) << endl;
		
	return 0;
}

/*salida:
	cadena1 = abcdefabcdef
	cadena2 = def
	El resto de cadena1 que empieza con la
	primera ocurrencia de cadena2 es: defabcdef
*/