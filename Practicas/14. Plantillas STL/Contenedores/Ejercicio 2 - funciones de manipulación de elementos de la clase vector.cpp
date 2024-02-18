// Prueba de las funciones de manipulacion de elementos de la
// plantilla de clase vector de la Biblioteca estandar.
#include <iostream>
#include <vector>	 // definicion de la plantilla de clase vector
#include <algorithm> // algoritmo de copia
#include <iterator>	 // iterador ostream_iterator
#include <stdexcept> // excepcion out_of_range
using namespace std;

int main()
{
	const int TAMANIO = 6;
	int arreglo[TAMANIO] = {1, 2, 3, 4, 5, 6};
	vector<int> enteros(arreglo, arreglo + TAMANIO);
	ostream_iterator<int> salida(cout, " ");

	cout << "El vector enteros contiene: ";
	// algoritmo copy  para mostrar todo el contenido completo del vector enteros en la salida
	copy(enteros.begin(), enteros.end(), salida);

	cout << "\nPrimer elemento de enteros: " << enteros.front()
		 << "\nUltimo elemento de enteros: " << enteros.back();

	enteros[0] = 7;		// establece el primer elemento a 7
	enteros.at(2) = 10; // establece el elemento en la posicion 2 a 10

	// inserta 22 como 2do elemento
	enteros.insert(enteros.begin() + 1, 22);

	cout << "\n\nContenido del vector enteros despues de los cambios: ";
	copy(enteros.begin(), enteros.end(), salida);
	// acceso a un elemento fuera de rango
	try
	{
		enteros.at(100) = 777;
	}
	catch (out_of_range &fueraDeRango)
	{ // excepcion out_of_range
		cout << "\n\nExcepcion: " << fueraDeRango.what();
	}

	// borra el primer elemento
	enteros.erase(enteros.begin());
	cout << "\n\nVector enteros despues de borrar el primer elemento: ";
	copy(enteros.begin(), enteros.end(), salida);

	// borra los elementos restantes
	enteros.erase(enteros.begin(), enteros.end());
	cout << "\nDespues de borrar todos los elementos, el vector enteros "
		 << (enteros.empty() ? "esta" : "no esta") << " vacio";

	// inserta los elementos del arreglo
	enteros.insert(enteros.begin(), arreglo, arreglo + TAMANIO);
	cout << "\n\nContenido del vector enteros antes de clear: ";
	copy(enteros.begin(), enteros.end(), salida);

	// vacia enteros; clear llama a erase para vaciar una coleccion
	enteros.clear();
	cout << "\nDespues de clear, el vector enteros "
		 << (enteros.empty() ? "esta" : "no esta") << " vacio" << endl;
	return 0;
} // fin de main
