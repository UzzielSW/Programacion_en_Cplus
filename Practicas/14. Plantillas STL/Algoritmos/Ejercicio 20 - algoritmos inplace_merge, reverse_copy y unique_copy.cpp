// Los algoritmos inplace_merge, reverse_copy y unique_copy de la Biblioteca estandar.
#include <iostream>
#include <algorithm> // definiciones de los algoritmos
#include <vector>	 // definicion de la plantilla de clase vector
#include <iterator>	 // definicion de back_inserter
using namespace std;
int main()
{
	const int TAMANIO = 10;
	int a1[TAMANIO] = {1, 3, 5, 7, 9, 1, 3, 5, 7, 9};
	vector<int> v1(a1, a1 + TAMANIO); // copia de a
	ostream_iterator<int> salida(cout, " ");

	cout << " El vector v1 contiene: ";
	copy(v1.begin(), v1.end(), salida);

	// combina la primera mitad de v1 con la segunda mitad de v1, de tal forma
	// que v1 contiene un conjunto ordenado de elementos despues de la combinacion
	inplace_merge(v1.begin(), v1.begin() + 5, v1.end());
	cout << "\n Despues de inplace_merge, v1 contiene: ";
	copy(v1.begin(), v1.end(), salida);

	vector<int> resultados1;

	// copia solo los elementos unicos de v1 a resultados1
	unique_copy(v1.begin(), v1.end(), back_inserter(resultados1));
	cout << "\n Despues de unique_copy, resultados1 contiene: ";
	copy(resultados1.begin(), resultados1.end(), salida);

	vector<int> resultados2;

	// copia los elementos de v1 a resultados2 en orden inverso
	reverse_copy(v1.begin(), v1.end(), back_inserter(resultados2));
	cout << "\n Despues de reverse_copy, resultados2 contiene: ";
	copy(resultados2.begin(), resultados2.end(), salida);
	cout << endl;
	return 0;
}
