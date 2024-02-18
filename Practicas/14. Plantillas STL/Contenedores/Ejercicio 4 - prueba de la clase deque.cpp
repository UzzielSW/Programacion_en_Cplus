// Programa de prueba de la clase deque de la Biblioteca estandar.
#include <iostream>
#include <deque>	 // definicion de la plantilla de clase deque
#include <algorithm> // algoritmo de copia
#include <iterator>	 // ostream_iterator
using namespace std;

int main()
{
	deque<double> valores; // crea deque de valores double
	ostream_iterator<double> output(cout, ", ");

	// inserta elementos en valores
	valores.push_front(2.2);
	valores.push_front(3.5);
	valores.push_back(1.1);

	cout << "\n valores contiene: ";
	// usa el operador subindice para obtener elementos de valores
	for (unsigned int i = 0; i < valores.size(); i++)
		cout << valores[i] << ", ";

	valores.pop_front(); // elimina el primer elemento
	cout << "\n Despues de pop_front, valores contiene: ";
	copy(valores.begin(), valores.end(), output);

	// usa el operador subindice para modificar el elemento en la ubicacion 1
	valores[1] = 5.4;
	cout << "\n Despues de valores[ 1 ] = 5.4, valores contiene: ";
	copy(valores.begin(), valores.end(), output);
	cout << endl;
	return 0;
}
