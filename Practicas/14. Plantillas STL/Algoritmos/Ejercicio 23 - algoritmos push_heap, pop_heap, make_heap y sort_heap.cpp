// Los algoritmos push_heap, pop_heap, make_heap y sort_heap de la Biblioteca estandar.
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
	const int TAMANIO = 10;
	int a[TAMANIO] = {3, 100, 52, 77, 22, 31, 1, 98, 13, 40};
	vector<int> v(a, a + TAMANIO); // copia de a
	vector<int> v2;
	ostream_iterator<int> salida(cout, " ");

	cout << " El vector v: ";
	copy(v.begin(), v.end(), salida);

	make_heap(v.begin(), v.end()); // crea un monton en base al vector v
	cout << "\n El vector v despues de make_heap: ";
	copy(v.begin(), v.end(), salida);

	sort_heap(v.begin(), v.end()); // ordena los elementos con sort_heap
	cout << "\n El vector v despues de sort_heap: ";
	copy(v.begin(), v.end(), salida);

	// realiza el algoritmo heapsort con push_heap y pop_heap
	cout << "\n\n El arreglo a contiene: ";
	copy(a, a + TAMANIO, salida); // muestra el arreglo a
	cout << endl;

	// coloca los elementos del arreglo a en v2 y
	// mantiene los elementos de v2 en el monton
	for (int i = 0; i < TAMANIO; i++)
	{
		v2.push_back(a[i]);
		push_heap(v2.begin(), v2.end());
		cout << "\n v2 despues de push_heap(a[" << i << "]): ";
		copy(v2.begin(), v2.end(), salida);
	}
	cout << endl;

	// elimina los elementos del monton en orden
	for (unsigned int j = 0; j < v2.size(); j++)
	{
		cout << "\n v2 despues de sacar " << v2[0] << " del monton: ";
		pop_heap(v2.begin(), v2.end() - j);
		copy(v2.begin(), v2.end(), salida);
	}
	cout << endl;

	return 0;
}
