/*
std::vector<int> vi; variable vector vacia
std::vector<int> vit(10); un vector de 10 elementos
std::vector<int> vit(10, 2); un vector de 10 elementos y todos los elementos son inicializados con el valor de 2
std::vector<int> vites(vit); creando un vector en donde todos los elementos pasan al nuevo vector
de copia
*/
#include "iostream"
#include "vector"
using namespace std;

template <typename T>
void imprimirVector(const vector<T> &enteros, char);

int main()
{
	const int TAMANIO = 6; // define el tamanio del arreglo
	int arreglo[TAMANIO] = {1, 2, 3, 4, 5, 6};
	vector<int> enteros; // crea un vector de valores int

	cout << " El tamanio inicial de enteros es: " << enteros.size()
		 << "\n La capacidad inicial de enteros es: " << enteros.capacity();

	// la funcion push_back se encuentra en toda coleccion de secuencia
	enteros.push_back(2);
	enteros.push_back(3);
	enteros.push_back(4);

	cout << "\n se agregaron 3 elementos al vector (enteros)"
		 << "\n El tamanio de enteros es: " << enteros.size()
		 << "\n La capacidad de enteros es: " << enteros.capacity();
	cout << "\n\n Impresion de un arreglo normal usando notacion de apuntador: ";

	// muestra el arreglo usando notacion de apuntador
	for (int *ptr = arreglo; ptr != arreglo + TAMANIO; ptr++)
		cout << *ptr << ' ';

	cout << "\n Impresion de vector usando notacion de iterador: ";
	imprimirVector(enteros, 'n');
	cout << "\n Contenido invertido del vector enteros: ";
	imprimirVector(enteros, 'i');

	cout << endl;
	return 0;
}

// plantilla de funcion para mostar los elementos de un vector
template <typename T>
void imprimirVector(const vector<T> &enteros, char orden)
{
	if (orden == 'n')
	{
		typename vector<T>::const_iterator iteradorConst; // iterador const_iterator

		// muestra los elementos del vector usando const_iterator
		for (iteradorConst = enteros.begin(); iteradorConst != enteros.end(); ++iteradorConst)
			cout << *iteradorConst << ' ';
	}
	else
	{
		typename vector<T>::const_reverse_iterator iteradorInverso; // iterador const_reverse

		// muestra el vector en orden inverso usando reverse_iterator
		for (iteradorInverso = enteros.rbegin(); iteradorInverso != enteros.rend(); ++iteradorInverso)
			cout << *iteradorInverso << ' ';
	}
}