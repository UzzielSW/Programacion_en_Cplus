#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

#include "Arbol.h"

int main()
{
  Arbol< int > intArbol; // Crea un Arbol de valores del tipo int
  int intValue;
 
  cout << " Escriba 10 values enteros:\n";
 
  // insertar 10 enteros a intArbol
  for ( int i = 0; i < 10; i++ ){
    cin >> intValue;
    intArbol.insertarNodo( intValue );
  }
 
  cout << "\nRecorrido Preorden\n";
  intArbol.recorridoPreOrden();
  cout << "\nRecorrido inOrden\n";
  intArbol.recorridoInOrden();
  cout << "\nRecorrido Postorden\n";
  intArbol.recorridoPostOrden();
 
  Arbol< double > doubleArbol; // crea Arbol con valores tipo double
  double doubleValue;
 
  cout << fixed << setprecision( 1 )
       << "\n\n\nEscriba 10 valores del tipo double:\n";
 
  // insertar 10 valores del tipo double en doubleArbol
  for ( int j = 0; j < 10; j++ ){
    cin >> doubleValue;
    doubleArbol.insertarNodo( doubleValue );
  }
 
  cout << "\nRecorrido Preorden\n";
  doubleArbol.recorridoPreOrden();
  cout << "\nRecorrido inOrden\n";
  doubleArbol.recorridoInOrden();
  cout << "\nRecorrido Postorden\n";
  doubleArbol.recorridoPostOrden();
 
  cout << endl;
  return 0;
}
