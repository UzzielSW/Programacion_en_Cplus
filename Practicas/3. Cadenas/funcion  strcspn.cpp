#include <iostream>
#include <string.h>
using namespace std;

int main()
{
  const char *cadena1 = "El valor es 3.14159";
  const char *cadena2 = "1234567890";
 
	cout<<"cadena1 = " << cadena1 
		<<"\ncadena2 = " << cadena2

  		<<"\n\nLa longitud del segmento inicial de cadena1"
		<<"\nque no contiene caracteres de cadena2 = "
 		<<strcspn(cadena1, cadena2) <<endl;
	return 0;
} 

/*salida:
	cadena1 = El valor es 3.14159
	cadena2 = 1234567890
	La longitud del segmento inicial de cadena1
	que no contiene caracteres de cadena2 = 12
*/