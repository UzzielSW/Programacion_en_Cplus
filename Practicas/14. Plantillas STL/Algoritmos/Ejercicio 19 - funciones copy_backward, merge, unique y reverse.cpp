// Las funciones copy_backward, merge, unique y reverse de la Biblioteca estandar.
#include <iostream>
#include <algorithm> // definiciones de los algoritmos
#include <vector>	 // definicion de la plantilla de clase vector
#include <iterator>	 // ostream_iterator
using namespace std;

int main()
{
	const int TAMANIO = 5;
	int a1[TAMANIO] = {1, 3, 5, 7, 9};
	int a2[TAMANIO] = {2, 4, 5, 7, 9};
	vector<int> v1(a1, a1 + TAMANIO); // copia de a1
	vector<int> v2(a2, a2 + TAMANIO); // copia de a2
	ostream_iterator<int> salida(cout, " ");

	cout << " El vector v1 contiene: ";
	copy(v1.begin(), v1.end(), salida); // muestra la salida del vector
	cout << "\n El vector v2 contiene: ";
	copy(v2.begin(), v2.end(), salida); // muestra la salida del vector

	vector<int> resultados(v1.size());

	// coloca los elementos de v1 en resultados, en orden inverso
	copy_backward(v1.begin(), v1.end(), resultados.end());
	cout << "\n\n Despues de copy_backward, resultados contiene: ";
	copy(resultados.begin(), resultados.end(), salida);

	vector<int> resultados2(v1.size() + v1.size());

	// combina los elementos de v1 y v2 en resultados2, en orden
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), resultados2.begin());

	cout << "\n\n Despues de combinar v1 y v2, resultados2 contiene: ";
	copy(resultados2.begin(), resultados2.end(), salida);

	// elimina valores duplicados de resultados2
	vector<int>::iterator ubicacionFinal;
	ubicacionFinal = unique(resultados2.begin(), resultados2.end());

	cout << "\n\n Despues de unique, resultados2 contiene: ";
	copy(resultados2.begin(), ubicacionFinal, salida);

	cout << "\n\n Vector v1 despues de reverse: ";
	reverse(v1.begin(), v1.end()); // invierte los elementos de v1
	copy(v1.begin(), v1.end(), salida);
	cout << endl;
	return 0;
}
