// Programa de prueba de la plantilla de clase list de la Biblioteca estandar.
// uso de las funciones: push_front && pop_front, push_back && pop_back, sort, insert,
// splice, merge, unique, swap, assign, remove.
#include <iostream>
#include <list>		 // definicion de la plantilla de clase list
#include <algorithm> // algoritmo de copia
#include <iterator>	 // ostream_iterator
using namespace std;

template <typename T>
void imprimirLista(const list<T> &Lista);

int main()
{
	const int TAMANIO = 4;
	int arreglo[TAMANIO] = {2, 6, 4, 8};
	list<int> valores; // crea una lista de valores int
	list<int> otrosValores;

	// inserta elementos en valores
	valores.push_front(1);
	valores.push_front(2);
	valores.push_back(4);
	valores.push_back(3);

	cout << "\n valores contiene: ";
	imprimirLista(valores);

	valores.sort(); // ordena los valores
	cout << "\n valores despues de ordenar contiene: ";
	imprimirLista(valores);

	// inserta elementos de arreglo en otrosValores
	otrosValores.insert(otrosValores.begin(), arreglo, arreglo + TAMANIO);
	cout << "\n Despues de insert, otrosValores contiene: ";
	imprimirLista(otrosValores);

	// elimina los elementos de otrosValores e inserta al final de valores
	valores.splice(valores.end(), otrosValores);
	cout << "\n Despues de splice, valores contiene: ";
	imprimirLista(valores);

	valores.sort(); // ordena valores
	cout << "\n Despues de sort, valores contiene: ";
	imprimirLista(valores);

	// inserta elementos de arreglo en otrosValores
	otrosValores.insert(otrosValores.begin(), arreglo, arreglo + TAMANIO);
	otrosValores.sort();
	cout << "\n Despues de insert y sort, otrosValores contiene: ";
	imprimirLista(otrosValores);

	// elimina los elementos de otrosValores y los inserta en valores por orden
	valores.merge(otrosValores);
	cout << "\n Despues de merge:\n valores contiene: ";
	imprimirLista(valores);
	cout << "\n otrosValores contiene: ";
	imprimirLista(otrosValores);

	valores.pop_front(); // elimina elemento de la parte inicial
	valores.pop_back();	 // elimina elemento de la parte final
	cout << "\n Despues de pop_front y pop_back:\n valores contiene: ";
	imprimirLista(valores);

	valores.unique(); // elimina elementos duplicados
	cout << "\n Despues de unique, valores contiene: ";
	imprimirLista(valores);

	// intercambia los elementos de valores y otrosValores
	valores.swap(otrosValores);
	cout << "\n Despues de swap:\n valores contiene: ";
	imprimirLista(valores);
	cout << "\n otrosValores contiene: ";
	imprimirLista(otrosValores);

	// reemplaza el contenido de valores con elementos de otrosValores
	valores.assign(otrosValores.begin(), otrosValores.end());
	cout << "\n Despues de assign, valores contiene: ";
	imprimirLista(valores);

	// elimina los elementos de otrosValores y los inserta en valores por orden
	valores.merge(otrosValores);
	cout << "\n Despues de merge, valores contiene: ";
	imprimirLista(valores);

	valores.remove(4); // elimina todos los 4s
	cout << "\n Despues de remove( 4 ), valores contiene: ";
	imprimirLista(valores);
	cout << endl;
	return 0;
}

// definicion de la plantilla de funcion imprimirLista;
// usa ostream_iterator y copy algorithm para mostrar los elementos de la lista
template <typename T>
void imprimirLista(const list<T> &Lista)
{
	if (Lista.empty()) // lista esta vacia
		cout << " Lista esta vacia";
	else
	{
		ostream_iterator<T> output(cout, " ");
		copy(Lista.begin(), Lista.end(), output);
	}
}
