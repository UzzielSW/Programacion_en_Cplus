// Algoritmos matematicos de la Biblioteca estandar.
#include <iostream>
#include <algorithm> // definiciones de algoritmos
#include <numeric>	 // aqui se define accumulate
#include <vector>
#include <iterator>
using namespace std;

bool mayor9(int);			// prototipo de la funcion predicado
void imprimirCuadrado(int); // imprime el cuadrado de un valor
int calcularCubo(int);		// calcula el cubo de un valor

int main()
{
	const int TAMANIO = 10;
	int a1[TAMANIO] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<int> v(a1, a1 + TAMANIO); // copia de a1
	ostream_iterator<int> salida(cout, " ");

	cout << " Vector v: ";
	copy(v.begin(), v.end(), salida);

	random_shuffle(v.begin(), v.end()); // revuelve los elementos de v
	cout << "\n Vector v despues de random_shuffle: ";
	copy(v.begin(), v.end(), salida);

	int a2[TAMANIO] = {100, 2, 8, 1, 50, 3, 8, 8, 9, 10};
	vector<int> v2(a2, a2 + TAMANIO); // copia de a2
	cout << "\n\n Vector v2: ";
	copy(v2.begin(), v2.end(), salida);

	// cuenta el numero de elementos en v2 con el valor 8
	int resultado = count(v2.begin(), v2.end(), 8);
	cout << "\n Numero de elementos que concuerdan con 8: " << resultado;

	// cuenta el numero de elementos en v2 mayores que 9
	resultado = count_if(v2.begin(), v2.end(), mayor9);
	cout << "\n Numero de elementos mayores que 9: " << resultado;

	// localiza el elemento minimo en v2
	cout << "\n\n El elemento minimo en el vector v2 es: " << *(min_element(v2.begin(), v2.end()));

	// localiza el elemento maximo en v2
	cout << "\n El elemento maximo en vector v2 es: " << *(max_element(v2.begin(), v2.end()));

	// calcula la suma de los elementos en v
	cout << "\n\n El total de la suma de los elementos en el vector v es: " << accumulate(v.begin(), v.end(), 0);

	// imprime el cuadrado de cada elemento en v
	cout << "\n\n El cuadrado de cada entero en el vector v es: ";
	for_each(v.begin(), v.end(), imprimirCuadrado);
	vector<int> cubos(TAMANIO); // crea instancia del vector cubos

	// calcula el cubo de cada elemento en v; coloca los resultados en cubos
	transform(v.begin(), v.end(), cubos.begin(), calcularCubo);
	cout << "\n\n El cubo de cada entero en el vector v es: ";
	copy(cubos.begin(), cubos.end(), salida);
	cout << endl;
	return 0;
}

// determina si el argumento es mayor que 9
bool mayor9(int valor) { return valor > 9; }

// imprime el cuadrado del argumento
void imprimirCuadrado(int valor) { cout << valor * valor << ' '; }

// devuelve el cubo del argumento
int calcularCubo(int valor) { return valor * valor * valor; }
