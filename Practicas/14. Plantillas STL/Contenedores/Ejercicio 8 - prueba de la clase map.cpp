// Programa de prueba de la clase map de la Biblioteca estandar.
#include <iostream>
#include <map> // definicion de la plantilla de clase map
using namespace std;

// define un nombre corto para el tipo map utilizado en este programa
typedef map<int, double, less<int>> Map;
int main()
{
	Map pares;

	// inserta ocho objetos value_type en pares
	pares.insert(Map::value_type(15, 2.7));
	pares.insert(Map::value_type(30, 111.11));
	pares.insert(Map::value_type(5, 1010.1));
	pares.insert(Map::value_type(10, 22.22));
	pares.insert(Map::value_type(25, 33.333));
	pares.insert(Map::value_type(5, 77.54)); // se ignora el valor duplicado
	pares.insert(Map::value_type(20, 9.345));
	pares.insert(Map::value_type(15, 99.3)); // se ignora el valor duplicado

	cout << " pares contiene:\nClave\tValor\n";

	// usa const_iterator para recorrer los elementos de pares
	for (Map::const_iterator iter = pares.begin(); iter != pares.end(); ++iter)
		cout << iter->first << '\t' << iter->second << '\n';

	pares[25] = 9999.99; // usa subindices para modificar el valor de la clave 25
	pares[40] = 8765.43; // usa subindices para modificar el valor de la clave 40

	cout << "\n Despues de las operaciones de subindices, pares 37 contiene:\nClave\tValor\n";

	// usa const_iterator para recorrer los elementos de pares
	for (Map::const_iterator iter2 = pares.begin(); iter2 != pares.end(); ++iter2)
		cout << iter2->first << '\t' << iter2->second << '\n';
	cout << endl;

	return 0;
}
