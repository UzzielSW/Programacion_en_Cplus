// Prueba de la clase multiset de la Biblioteca estandar
#include <iostream>
#include <set>		 // definicion de la plantilla de clase multiset
#include <algorithm> // algoritmo de copia
#include <iterator>	 // ostream_iterator
using namespace std;

// define un nombre corto para el tipo multiset utilizado en este programa
typedef multiset<int, less<int>> Ims;
int main()
{
	const int TAMANIO = 10;
	int array[TAMANIO] = {7, 22, 9, 1, 18, 30, 100, 22, 85, 13};
	Ims multisetInt; // Ims es el typedef para "multiset entero"
	ostream_iterator<int> salida(cout, " ");

	cout << " Hay actualmente " << multisetInt.count(15) << " valores de 15 en el multiset\n";

	multisetInt.insert(15); // inserta 15 en multisetInt
	multisetInt.insert(15); // inserta 15 en multisetInt
	cout << " Despues de insert, hay " << multisetInt.count(15) << " valores de 15 en el multiset\n\n";

	// iterador const
	Ims::const_iterator resultado;

	resultado = multisetInt.find(15); // busca 15 en multisetInt; find devuelve el iterador

	if (resultado != multisetInt.end())		  // si el iterador no esta al final
		cout << " Se encontro el valor 15\n"; // encontro el valor de busqueda 15

	resultado = multisetInt.find(20); // busca 20 en multisetInt; find devuelve el iterador

	if (resultado == multisetInt.end()) // sera verdadero, ya que no encontro el 20
		cout << " No se encontro el valor 20\n";

	multisetInt.insert(array, array + TAMANIO); // inserta los elementos del arreglo a en multisetInt

	cout << "\n Despues de insert, multisetInt contiene:\n";
	copy(multisetInt.begin(), multisetInt.end(), salida);

	// determina los limites inferior y superior de 22 en multisetInt
	cout << "\n\n Limite inferior de 22: " << *(multisetInt.lower_bound(22));
	cout << "\n Limite superior de 22: " << *(multisetInt.upper_bound(22));

	pair<Ims::const_iterator, Ims::const_iterator> p; // p representa un par de iteradores const_iterator

	// usa equal_range para determinar los limites inferior y superior de 22 en multisetInt
	p = multisetInt.equal_range(22);

	cout << "\n\n equal_range de 22:"
		 << "\n Limite inferior: " << *(p.first)
		 << "\n Limite superior: " << *(p.second) << endl;

	return 0;
}
