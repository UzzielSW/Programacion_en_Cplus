// Programa de prueba de la clase set de la Biblioteca estandar.
#include <iostream>
#include <set>
#include <algorithm>
#include <iterator> // ostream_iterator
using namespace std;

// define un nombre corto para el tipo set utilizado en este programa
typedef set<double, less<double>> SetDouble;
int main()
{
	const int TAMANIO = 5;
	double a[TAMANIO] = {2.1, 4.2, 9.5, 2.1, 3.7};
	SetDouble setDouble(a, a + TAMANIO);
	ostream_iterator<double> salida(cout, " ");

	cout << " setDouble contiene: ";
	copy(setDouble.begin(), setDouble.end(), salida);

	// p representa un par que contiene elementos const_iterator y bool
	pair<SetDouble::const_iterator, bool> p;

	// insert< 13.8 en setDouble; insert devuelve un par en el cual
	// p.first representa la ubicacion de 13.8 en setDouble y
	// p.second representa si se inserto o no el valor 13.8
	p = setDouble.insert(13.8); // el valor no esta en el conjunto
	cout << "\n\n " << *(p.first) << (p.second ? " se" : " no se") << " inserto";
	cout << "\n doubleSet contiene: ";
	copy(setDouble.begin(), setDouble.end(), salida);

	// inserta 9.5 en setDouble
	p = setDouble.insert(9.5); // el valor ya esta en el conjunto
	cout << "\n\n " << *(p.first) << (p.second ? " se" : " no se") << " inserto";
	cout << "\n doubleSet contiene: ";
	copy(setDouble.begin(), setDouble.end(), salida);
	cout << endl;
	return 0;
}