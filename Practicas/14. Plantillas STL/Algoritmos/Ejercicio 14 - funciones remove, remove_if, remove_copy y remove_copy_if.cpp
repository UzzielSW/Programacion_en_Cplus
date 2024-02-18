// Las funciones remove, remove_if, remove_copy y remove_copy_if de la Biblioteca estandar.
#include <iostream>
#include <algorithm> // definiciones de los algoritmos
#include <vector>	 // definicion de la plantilla de clase vector
#include <iterator>	 // ostream_iterator
using namespace std;

bool mayor9(int); // prototipo

int main()
{
	const int TAMANIO = 10;
	int a[TAMANIO] = {10, 2, 10, 4, 16, 6, 14, 8, 12, 10};
	ostream_iterator<int> salida(cout, " ");
	vector<int> v(a, a + TAMANIO); // copia de a
	vector<int>::iterator nuevoUltimoElemento;

	cout << " Vector v1:\n ";
	copy(v.begin(), v.end(), salida);

	// elimina todos los 10s de v
	nuevoUltimoElemento = remove(v.begin(), v.end(), 10);
	cout << "\n Vector v1 despues de eliminar todos los 10:\n ";
	copy(v.begin(), nuevoUltimoElemento, salida);

	vector<int> v2(a, a + TAMANIO); // copia de a
	vector<int> c(TAMANIO, 0);		// crea instancia del vector c
	cout << "\n\n Vector v2 antes de eliminar todos los 10 y copiar:\n ";
	copy(v2.begin(), v2.end(), salida);

	// copia de v2 a c, eliminando los 10s en el proceso
	nuevoUltimoElemento = remove_copy(v2.begin(), v2.end(), c.begin(), 10);
	cout << "\n Vector c1 despues de eliminar todos los 10 de v2:\n ";
	copy(c.begin(), nuevoUltimoElemento, salida);

	vector<int> v3(a, a + TAMANIO); // copia de a
	cout << "\n\n Vector v3:\n ";
	copy(v3.begin(), v3.end(), salida);

	// elimina los elementos mayores que 9 de v3
	nuevoUltimoElemento = remove_if(v3.begin(), v3.end(), mayor9);
	cout << "\n Vector v3 despues de eliminar todos los elementos mayores que 9:\n ";
	copy(v3.begin(), nuevoUltimoElemento, salida);

	vector<int> v4(a, a + TAMANIO); // copia de a
	vector<int> c2(TAMANIO, 0);		// crea instancia del vector c2
	cout << "\n\n Vector v4 antes de eliminar todos los elementos mayores que 9 y copiar:\n ";
	copy(v4.begin(), v4.end(), salida);

	// copia elementos de v4 a c2, eliminando los elementos
	// mayores que 9 en el proceso
	nuevoUltimoElemento = remove_copy_if(v4.begin(), v4.end(), c2.begin(), mayor9);
	cout << "\n Vector c2 despues de eliminar todos los elementos mayores que 9 de v4:\n ";
	copy(c2.begin(), nuevoUltimoElemento, salida);
	cout << endl;
	return 0;
}

// determina si el argumento es mayor que 9
bool mayor9(int x) { return x > 9; }
