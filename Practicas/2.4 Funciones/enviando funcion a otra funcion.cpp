#include <iostream>
#include <iomanip>
using namespace std;

void ordenamientoSeleccion(int [], const int, bool (*)(int, int));
void intercambiar(int *const, int *const);
bool ascendente(int, int ); // implementa el orden ascendente
bool descendente(int, int ); // implementa el orden descendente
 
int main()
{
	int orden; // 1 = ascendente, 2 = descendente
	int arreglo[10] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };
 
	cout<< " Escriba 1 para orden ascendente,\n"
		<< " Escriba 2 para orden descendente: "; 
	cin >> orden;

	cout << "\n Elementos del arreglo en el orden original: \n";
	for (int i = 0; i < 10; i++)  cout << setw( 4 ) << arreglo[ i ];
 
	if (orden == 1)
	{
		ordenamientoSeleccion(arreglo, 10, ascendente);
		cout << "\n Elementos de datos en orden ascendente: \n";
	}
	else
	{
		ordenamientoSeleccion(arreglo, 10, descendente);
		cout << "\n Elementos de datos en orden descendente: \n";
	}
  
  	// imprime el arreglo ordenado
	for ( int i = 0; i < 10; i++ ) cout << setw( 4 ) << arreglo[ i ];
	cout << endl;

	return 0;
} 
 
void ordenamientoSeleccion(int arreglo[], const int tamanio, bool (*compara)(int, int))
{	
	int minOmax; 
 
	for ( int i = 0; i < (tamanio - 1); i++ )
	{
  		minOmax = i; 
 
  		for ( int k = i + 1; k < tamanio; k++ )
  			if (!(*compara)(arreglo[minOmax], arreglo[ k ])) //llamando la funcion compara
  				minOmax = k;
		
		intercambiar(&arreglo[ minOmax ], &arreglo[ i ]);
	}
} 
 
void intercambiar(int *const elemento1Ptr, int *const elemento2Ptr)
{
	int contenido = *elemento1Ptr;
	*elemento1Ptr = *elemento2Ptr;
	*elemento2Ptr = contenido;
}
 
// determina si el elemento a es menor que el elemento b para un orden ascendente
bool ascendente(int a, int b){ return a < b; }// devuelve true si a es menor que b

// determina si el elemento a es mayor que el elemento b para un orden descendente
bool descendente(int a, int b){ return a > b; }// devuelve true si a es mayor que b