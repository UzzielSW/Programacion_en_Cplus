// Programa de prueba de la clase multimap de la Biblioteca estandar.
#include <iostream>
#include <map> // definicion de la plantilla de clase map
using namespace std;

// define un nombre corto para el tipo multimap utilizado en este programa
typedef multimap<int, double, less<int>> multi;
int main()
{
	multi pares; // declara los pares de multimap

	cout << " Hay actualmente " << pares.count(15) << " pares con la clave 15 en el multimap\n";

	// inserta dos objetos value_type en pares
	pares.insert(multi::value_type(15, 2.7));
	pares.insert(multi::value_type(15, 99.3));

	cout << " Despues de las inserciones, hay " << pares.count(15) << " pares con la clave 15\n\n";

	// inserta cinco objetos value_type en pares
	pares.insert(multi::value_type(30, 111.11));
	pares.insert(multi::value_type(10, 22.22));
	pares.insert(multi::value_type(25, 33.333));
	pares.insert(multi::value_type(20, 9.345));
	pares.insert(multi::value_type(5, 77.54));

	cout << " Los pares de multimap contienen:\nClave\tValor\n";

	// usa const_iterator para recorrer los elementos de pares
	for (multi::const_iterator iter = pares.begin(); iter != pares.end(); ++iter)
		cout << iter->first << '\t' << iter->second << '\n';
	cout << endl;

	return 0;
}
