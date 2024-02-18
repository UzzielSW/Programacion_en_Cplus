// Las funciones lower_bound, upper_bound y equal_range
// de la Biblioteca estandar para una secuencia ordenada de valores.
#include <iostream>
#include <algorithm> // definiciones de los algoritmos
#include <vector>	 // definicion de la plantilla de clase vector
#include <iterator>	 // ostream_iterator
using namespace std;

int main()
{
	const int TAMANIO = 10;
	int a1[TAMANIO] = {2, 2, 4, 4, 4, 6, 6, 6, 6, 8};
	vector<int> v(a1, a1 + TAMANIO); // copia de a1
	ostream_iterator<int> salida(cout, " ");

	cout << " El vector v contiene: ";
	copy(v.begin(), v.end(), salida);

	vector<int>::iterator inferior; // determina el punto de insercion del limite inferior para 6 en v
	vector<int>::iterator superior; // determina el punto de insercion del limite superior para 6 en v
	inferior = lower_bound(v.begin(), v.end(), 6);
	superior = upper_bound(v.begin(), v.end(), 6);
	cout << "\n\n El limite inferior de 6 es el elemento " << (inferior - v.begin()) << " del vector v";
	cout << "\n El limite superior de 6 es el elemento " << (superior - v.begin()) << " del vector v";

	inferior = lower_bound(v.begin(), v.end(), 5); // determina el punto de insercion del limite inferior para 5 en v
	cout << "\n\n Usa lower_bound para localizar el primer punto en el que se puede insertar el 5 en orden";
	cout << "\n El limite inferior de 5 es el elemento " << (inferior - v.begin()) << " del vector v";

	superior = upper_bound(v.begin(), v.end(), 7); // determina el punto de insercion del limite superior para 7 en v
	cout << "\n\n Usa upper_bound para localizar el ultimo punto en el que se puede insertar el 7 en orden";
	cout << "\n El limite superior de 7 es el elemento " << (superior - v.begin()) << " del vector v";

	pair<vector<int>::iterator,
		 vector<int>::iterator>
		eq;
	eq = equal_range(v.begin(), v.end(), 6); // usa equal_range para determinar los puntos de insercion inferior y superior para 6
	cout << "\n\n Usando equal_range:\n\n El limite inferior de 6 es el elemento " << (eq.first - v.begin()) << " del vector v";
	cout << "\n El limite superior de 6 es el elemento " << (eq.second - v.begin()) << " del vector v";

	eq = equal_range(v.begin(), v.end(), 5); // usa equal_range para determinar los puntos de insercion inferior y superior para el 5
	cout << "\n\n Usa equal_range para localizar el primer y ultimo punto en el que se puede insertar el 5 en orden";
	cout << "\n El limite inferior de 5 es el elemento " << (eq.first - v.begin()) << " del vector v";
	cout << "\n El limite superior de 5 es el elemento " << (eq.second - v.begin()) << " del vector v" << endl;
	return 0;
}
