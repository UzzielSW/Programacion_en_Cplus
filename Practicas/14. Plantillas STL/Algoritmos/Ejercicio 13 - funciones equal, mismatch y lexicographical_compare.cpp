// Las funciones equal, mismatch y lexicographical_compare de la Biblioteca estandar.
#include <iostream>
#include <algorithm> // definiciones de los algoritmos
#include <vector>	 // definicion de la plantilla de clase vector
#include <iterator>	 // ostream_iterator
using namespace std;

int main()
{
	const int TAMANIO = 10;
	int a1[TAMANIO] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int a2[TAMANIO] = {1, 2, 3, 4, 1000, 6, 7, 8, 9, 10};
	vector<int> v1(a1, a1 + TAMANIO); // copia de a1
	vector<int> v2(a1, a1 + TAMANIO); // copia de a1
	vector<int> v3(a2, a2 + TAMANIO); // copia de a2
	ostream_iterator<int> salida(cout, " ");

	cout << " El vector v1 contiene: ";
	copy(v1.begin(), v1.end(), salida);
	cout << "\n El vector v2 contiene: ";
	copy(v2.begin(), v2.end(), salida);
	cout << "\n El vector v3 contiene: ";
	copy(v3.begin(), v3.end(), salida);

	// compara los vectores v1 y v2 para ver si son iguales
	bool resultado = equal(v1.begin(), v1.end(), v2.begin());
	cout << "\n\n El vector v1 " << (resultado ? "es" : "no es") << " igual al vector v2.\n";

	// compara los vectores v1 y v3 para ver si son iguales
	resultado = equal(v1.begin(), v1.end(), v3.begin());
	cout << " El vector v1 " << (resultado ? "es" : "no es") << " igual al vector v3.\n";

	// ubicacion representa el par de iteradores del vector
	pair<vector<int>::iterator, vector<int>::iterator> ubicacion;

	// comprueba que no haya inconsistencia entre v1 y v3
	ubicacion = mismatch(v1.begin(), v1.end(), v3.begin());
	cout << "\n Hay una inconsistencia entre v1 y v3 en la ubicacion "
		 << (ubicacion.first - v1.begin()) << " en donde v1 contiene "
		 << *ubicacion.first << " y v3 contiene " << *ubicacion.second << "\n\n";

	char c1[TAMANIO] = "HOLA";
	char c2[TAMANIO] = "BYE BYE";

	// realiza una comparacion lexicografica de c1 y c2
	resultado = lexicographical_compare(c1, c1 + TAMANIO, c2, c2 + TAMANIO);
	cout << c1 << (resultado ? " es menor que " : " es mayor o igual a ") << c2 << endl;
	return 0;
}
