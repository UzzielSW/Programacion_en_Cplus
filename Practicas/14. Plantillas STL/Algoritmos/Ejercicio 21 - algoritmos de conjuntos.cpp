// Los algoritmos includes, set_difference, set_intersection, set_symmetric_difference y set_union.
#include <iostream>
#include <algorithm> // definiciones de los algoritmos
#include <iterator>	 // ostream_iterator
using namespace std;

int main()
{
	const int TAMANIO1 = 10, TAMANIO2 = 5, TAMANIO3 = 20;
	int a1[TAMANIO1] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int a2[TAMANIO2] = {4, 5, 6, 7, 8};
	int a3[TAMANIO2] = {4, 5, 6, 11, 15};
	ostream_iterator<int> salida(cout, " ");

	cout << " a1 contiene: ";
	copy(a1, a1 + TAMANIO1, salida); // muestra el arreglo a1
	cout << "\n a2 contiene: ";
	copy(a2, a2 + TAMANIO2, salida); // muestra el arreglo a2
	cout << "\n a3 contiene: ";
	copy(a3, a3 + TAMANIO2, salida); // muestra el arreglo a3

	// determina si el conjunto a2 esta completamente contenido en a1
	if (includes(a1, a1 + TAMANIO1, a2, a2 + TAMANIO2))
		cout << "\n\n a1 incluye a a2";
	else
		cout << "\n\n a1 no incluye a a2";

	// determina si el conjunto a3 esta completamente contenido en a1
	if (includes(a1, a1 + TAMANIO1, a3, a3 + TAMANIO2))
		cout << "\n a1 incluye a a3";
	else
		cout << "\n a1 no incluye a a3";

	int diferencia[TAMANIO1];

	// determina los elementos de a1 que no estan en a2
	int *ptr = set_difference(a1, a1 + TAMANIO1, a2, a2 + TAMANIO2, diferencia);
	cout << "\n\n set_difference de a1 y a2 es: ";
	copy(diferencia, ptr, salida);

	int interseccion[TAMANIO1];

	// determina los elementos que estan tanto en a1 como en a2
	ptr = set_intersection(a1, a1 + TAMANIO1, a2, a2 + TAMANIO2, interseccion);
	cout << "\n\n set_intersection de a1 y a2 es: ";
	copy(interseccion, ptr, salida);

	int symmetric_difference[TAMANIO1 + TAMANIO2];

	// determina los elementos de a1 que no estan en a2 y los elementos de a2 que no estan en a1
	ptr = set_symmetric_difference(a1, a1 + TAMANIO1, a3, a3 + TAMANIO2, symmetric_difference);
	cout << "\n\n set_symmetric_difference de a1 y a3 es: ";
	copy(symmetric_difference, ptr, salida);

	int conjuntoUnion[TAMANIO3];

	// determina los elementos que estan en uno o ambos conjuntos
	ptr = set_union(a1, a1 + TAMANIO1, a3, a3 + TAMANIO2, conjuntoUnion);
	cout << "\n\n set_union de a1 y a3 es: ";
	copy(conjuntoUnion, ptr, salida);
	cout << endl;
	return 0;
}
