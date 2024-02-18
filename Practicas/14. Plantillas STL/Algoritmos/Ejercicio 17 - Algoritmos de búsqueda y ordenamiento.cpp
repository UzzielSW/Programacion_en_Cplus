// Algoritmos de busqueda y ordenamiento de la Biblioteca estandar.
#include <iostream>
#include <algorithm> // definiciones de los algoritmos
#include <vector>	 // definicion de la plantilla de clase vector
#include <iterator>
using namespace std;

bool mayor10(int valor); // prototipo de la funcion predicado

int main()
{
	const int TAMANIO = 10;
	int a[TAMANIO] = {10, 2, 17, 5, 16, 8, 13, 11, 20, 7};
	vector<int> v(a, a + TAMANIO); // copia de a
	ostream_iterator<int> salida(cout, " ");

	cout << " El vector v contiene: ";
	copy(v.begin(), v.end(), salida); // muestra el vector de salida

	// localiza la primera ocurrencia de 16 en v
	vector<int>::iterator ubicacion;
	ubicacion = find(v.begin(), v.end(), 16);
	if (ubicacion != v.end()) // found 16
		cout << "\n\n Se encontro el 16 en la ubicacion " << (ubicacion - v.begin());
	else // no se encontro el 16
		cout << "\n\n No se encontro el 16";

	// localiza la primera ocurrencia de 100 en v
	ubicacion = find(v.begin(), v.end(), 100);

	if (ubicacion != v.end()) // encontro el 100
		cout << "\n Se encontro el 100 en la ubicacion " << (ubicacion - v.begin());
	else // no se encontro el 100
		cout << "\n No se encontro el 100";

	// localiza la primera ocurrencia del valor que sea mayor que 10 en v
	ubicacion = find_if(v.begin(), v.end(), mayor10);

	if (ubicacion != v.end()) // encontro un valor mayor que 10
		cout << "\n\n El primer valor mayor que 10 es " << *ubicacion
			 << "\n se encontro en la ubicacion " << (ubicacion - v.begin());
	else // no se encontro un valor mayor que 10
		cout << "\n\n No se encontraron valores mayores que 10";

	// ordena los elementos de v
	sort(v.begin(), v.end());
	cout << "\n\n Vector v despues de sort: ";
	copy(v.begin(), v.end(), salida);

	// usa binary_search para localizar el 13 en v
	if (binary_search(v.begin(), v.end(), 13))
		cout << "\n\n Se encontro el 13 en v";
	else
		cout << "\n\n No se encontro el 13 en v";

	// usa binary_search para localizar el 100 en v
	if (binary_search(v.begin(), v.end(), 100))
		cout << "\n Se encontro el 100 en v";
	else
		cout << "\n No se encontro el 100 en v";

	cout << endl;
	return 0;
}

// determina si el argumento es mayor que 10
bool mayor10(int valor) { return valor > 10; }