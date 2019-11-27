// Uso de listas de argumentos de longitud variable.
#include <iostream>
#include <iomanip>
#include <cstdarg>
using namespace std;

double promedio(int, ...);

int main()
{
	double double1 = 37.5;
	double double2 = 22.5;
	double double3 = 1.7;
	double double4 = 10.2;
	
	cout<< fixed << setprecision(1) 
		<< "double1 = "<< double1 
		<< "\ndouble2 = "<< double2 
		<< "\ndouble3 = "<< double3 
		<< "\ndouble4 = "<< double4 << endl

		<< setprecision(3)
		<< "\nEl promedio de double1 y double2 es "<< promedio(2, double1, double2 ) 
		<< "\nEl promedio de double1, double2 y double3 es "<< promedio(3, double1, double2, double3 )
		<< "\nEl promedio de double1, double2, double3 y double4 es "<< promedio(4, double1, double2, double3, double4)
		<< endl;

	return 0;
}

// calcula el promedio
double promedio(int cuenta, ...)
{
	double total = 0;
	va_list lista; // para almacenar la informacion que necesita va_start
	
	va_start(lista, cuenta);
	
	// procesa la lista de argumentos de longitud variable
	for (int i = 1; i <= cuenta; i++)
	 	total += va_arg(lista, double);
	
 	va_end(lista); // termina va_start

	return total / cuenta;
}