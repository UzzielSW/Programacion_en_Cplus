// Las funciones replace, replace_if, replace_copy y replace_copy_if de la Biblioteca estandar.
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator> // ostream_iterator
using namespace std;

bool mayor9(int); // prototipo de la funcion predicado

int main()
{
	const int TAMANIO = 10;
	int a[TAMANIO] = {10, 2, 10, 4, 16, 6, 14, 8, 12, 10};
	ostream_iterator<int> salida(cout, " ");

	vector<int> v1(a, a + TAMANIO); // copia de a
	cout << " Vector v1:\n ";
	copy(v1.begin(), v1.end(), salida);

	// reemplaza todos los 10s en v1 con 100
	replace(v1.begin(), v1.end(), 10, 100);
	cout << "\n Vector v1 despues de reemplazar los 10 con 100:\n ";
	copy(v1.begin(), v1.end(), salida);

	vector<int> v2(a, a + TAMANIO); // copia de a
	vector<int> c1(TAMANIO);		// crea una instancia del vector c1
	cout << "\n\n Vector v2 antes de reemplazar todos los 10 y copiar:\n ";
	copy(v2.begin(), v2.end(), salida);

	// copia de v2 a c1, reemplazando los 10s con 100s
	replace_copy(v2.begin(), v2.end(), c1.begin(), 10, 100);
	cout << "\n Vector c1 despues de reemplazar todos los 10 en v2:\n ";
	copy(c1.begin(), c1.end(), salida);

	vector<int> v3(a, a + TAMANIO); // copia de a
	cout << "\n\n Vector v3:\n ";
	copy(v3.begin(), v3.end(), salida);

	// reemplaza los valores mayores que 9 en v3 con 100
	replace_if(v3.begin(), v3.end(), mayor9, 100);
	cout << "\n Vector v3 despues de reemplazar todos los valores mayores que 9 con 100:\n ";
	copy(v3.begin(), v3.end(), salida);

	vector<int> v4(a, a + TAMANIO); // copia de a
	vector<int> c2(TAMANIO);		// crea instancia del vector c2
	cout << "\n\n Vector v4 antes de reemplazar todos los valores mayores que 9 y copiar:\n ";
	copy(v4.begin(), v4.end(), salida);

	// copia v4 a c2, reemplazando los elementos mayores que 9 con 100
	replace_copy_if(v4.begin(), v4.end(), c2.begin(), mayor9, 100);
	cout << "\n Vector c2 despues de reemplazar todos los valores mayores que 9 en v4:\n ";
	copy(c2.begin(), c2.end(), salida);
	cout << endl;
	return 0;
}

// determina si el argumento es mayor que 9
bool mayor9(int x) { return x > 9; }
