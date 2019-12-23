// Uso de strtok para dividir una cadena en tokens.
#include <iostream>
#include <string.h> // prototipo para strtok
using namespace std; 

int main()
{
	char enunciado[] = "julio carlos marisol lucas aaron";
	char *tokenPtr;

	cout<<"\n La cadena a dividir en tokens es: " << enunciado 
		<<"\n\n Los tokens son:\n";

	// empieza la division de enunciado en tokens
	tokenPtr = strtok(enunciado, " ");

	// continúa dividiendo enunciado en tokens hasta que tokenPtr se vuelve NULL
	while (tokenPtr != NULL)
	{
		cout << ' ' << tokenPtr << '\n';
		tokenPtr = strtok(NULL, " "); // obtiene el siguiente token
	}

	cout << "\n Despues de strtok, enunciado = " << enunciado << endl;
	return 0;
}