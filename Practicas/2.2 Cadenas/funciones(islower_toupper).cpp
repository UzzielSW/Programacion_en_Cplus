#include <iostream>
#include <ctype.h> // prototipos para islower y toupper
using namespace std;
 
void convertirAMayusculas(char *);
 
int main()
{
	char frase[] = "caracteres y $32.98";

	cout << "La frase antes de la conversion es: " << frase;
	convertirAMayusculas(frase);
	cout << "\nLa frase despues de la conversion es: " << frase << endl;
    return 0; 
} // fin de main
 
  // convierte la cadena a letras mayúsculas
 void convertirAMayusculas(char *sPtr)
 {
  	while (*sPtr != '\0') // itera mientras el caracter actual no sea '\0'
  	{
  		if (islower(*sPtr)) // si el caracter es minúscula,
  		    *sPtr = toupper(*sPtr); // lo convierte a mayúscula
 
	    sPtr++; // mueve sPtr al siguiente carácter en la cadena
	}
}