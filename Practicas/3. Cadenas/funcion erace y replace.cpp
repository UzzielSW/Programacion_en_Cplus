// Demostracion de las funciones miembro erase y replace de string.
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string cadena1("Los valores en cualquier subarbol izquierdo"
					"\nson menos que el valor en el"
					"\nnodo padre y los valores en"
					"\ncualquier subarbol derecho son mayores"
					"\nque el valor en el nodo padre");

	cout << "Cadena original:\n" << cadena1 << "\n\n";
	
	// elimina todos los caracteres de (e incluyendo a) la ubicacin 72 hasta el final de cadena1
	cadena1.erase(72);

	// imprime una nueva cadena
	cout << "Cadena original despues de erase:\n" << cadena1 << "\n\nDespues del primer reemplazo:\n";

	 // busca el primer espacio
	int posicion = cadena1.find( " " );
	// reemplaza todos los espacios con un punto
	while (posicion != string::npos)
	{
		cadena1.replace(posicion, 1, ".");
		posicion = cadena1.find(" ", posicion + 1 );//buscame desde (posicion + 1) en adelante la siguiente coincidencia
	}

	// imprime una nueva cadena
	cout << cadena1 << "\n\nDespues del segundo reemplazo:\n";
	 // busca el primer periodo
	posicion = cadena1.find( "." );
 	// reemplaza todos los puntos con dos signos de punto y coma
	// NOTA: esto sobrescribira los caracteres
	while (posicion != string::npos) 
	{
		cadena1.replace(posicion, 2, "xxxxx;;yyy", 5, 2);
		posicion = cadena1.find( ".", posicion + 1 );
	} // fin de while
	// imprime una nueva cadena
	cout << cadena1 << endl;
	return 0;
}