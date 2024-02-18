/*
  Este programa demuestra una funcion recursiva que 2 realiza una busqueda binaria
  en una matriz de enteros.
*/

#include <iostream>
using namespace std;

const int SIZE = 20;

int main()
{
	int tests[SIZE] = { 101, 142, 147, 189, 199, 207, 222, 234, 289, 296, 310, 319, 388, 394, 417, 429, 447, 521, 536, 600};
	int result; // resultado de busqueda
	int ID; // dato a buscar
	int binarySearch(int [], int, int, int);
	 
	cout << " Ingrese el ID del empleado que desea buscar: ";
	cin >> ID;

	result = binarySearch(tests, 0, SIZE - 1, ID);

	if (result == -1)
	 	cout << " Ese numero no existe en la matriz.\n";
	else
	{
		cout << " Esa ID se encuentra en el elemento " << result;
		cout << " en el arreglo\n";
	}

 return 0;
}

 /*********************************************************************************
  La funcion binarySearch realiza una busqueda binaria recursiva en un rango de 
  elementos de una matriz entera. El parametro primero contiene el subindice del 
  elemento inicial del rango, y el ultimo contiene el subindice del ultimo elemento 
  del rango. El valor del parametro contiene el valor de busqueda. Si se encuentra 
  el valor de busqueda, se devuelve su subindice de matriz. De lo contrario, 
  se devuelve -1 indicando que el valor no estaba en la matriz.
 **********************************************************************************/

 int binarySearch(int array[], int primer, int ultimo, int value)
 {
	int medio; // punto medio de busqueda

	if (primer > ultimo) // caso base
	 	return -1;
	 
	medio = (primer + ultimo)/2;
	 
	if (array[medio] == value)
	 	return medio;
	if (array[medio] < value)
	 	return binarySearch(array, medio+1, ultimo, value);
	else
		return binarySearch(array, primer, medio-1, value);
 }
