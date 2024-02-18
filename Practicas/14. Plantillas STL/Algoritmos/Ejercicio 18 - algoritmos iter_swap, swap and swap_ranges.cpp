// Los algoritmos iter_swap, swap and swap_ranges de la Biblioteca estandar.
#include <iostream>
#include <algorithm> // definiciones de los algoritmos
#include <iterator>
using namespace std;

int main()
{
	const int TAMANIO = 10;
	int a[TAMANIO] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	ostream_iterator<int> salida(cout, " ");

	cout << " El arreglo a contiene: ";
	copy(a, a + TAMANIO, salida);
	// intercambia los elementos en las ubicaciones 0 y 1 del arreglo a
	swap(a[0], a[1]);

	cout << "\n El arreglo a despues de intercambiar a[0] y a[1] mediante swap: ";
	copy(a, a + TAMANIO, salida); // muestra el arreglo a

	// usa iteradores para intercambiar los elementos en las ubicaciones 0 y 1 del arreglo a
	iter_swap(&a[0], &a[1]); // intercambia con iteradores
	cout << "\n El arreglo a despues de intercambiar a[0] y a[1] mediante iter_swap: ";
	copy(a, a + TAMANIO, salida);

	// intercambia los primeros cinco elementos del arreglo a con los ultimos cinco elementos del arreglo a
	swap_ranges(a, a + 5, a + 5);

	cout << "\n El arreglo a despues de intercambiar los primeros cinco elementos con los ultimos cinco:\n ";
	copy(a, a + TAMANIO, salida);
	cout << endl;
	return 0;
}
