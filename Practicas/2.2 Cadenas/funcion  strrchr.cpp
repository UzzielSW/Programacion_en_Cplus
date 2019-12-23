#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	const char *cadena1 = "Un zoologico tiene muchos animales incluyendo zopilotes";
	char c = 'z';

  	cout<<"cadena1 = " << cadena1
 		<<"\n\nEl resto de cadena1 empezando con la\n"
		<<"ultima ocurrencia del caracter '"
		<< c << "' es: \"" << strrchr(cadena1, c) << '\"' << endl;
 return 0;
}

/*salida:
	cadena1 = Un zoologico tiene muchos animales incluyendo zopilotes
	El resto de cadena1 empezando con la
	ultima ocurrencia del caracter 'z' es: "zopilotes"
*/