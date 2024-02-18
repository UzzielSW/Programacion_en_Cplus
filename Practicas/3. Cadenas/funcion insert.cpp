// Demostración de las funciones miembro insert de la clase string.
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string cadena1("principio fin");
	string cadena2("enmedio ");
	string cadena3("12345678");
	string cadena4("xx");

	cout<<"Cadenas iniciales:\ncadena1: " << cadena1
		<<"\ncadena2: " << cadena2 
		<<"\ncadena3: " << cadena3
		<<"\ncadena4: " << cadena4 << "\n\n";

	// inserta "enmedio" en la ubicación 10 en cadena1
	cadena1.insert(10, cadena2);

	// inserta "xx" en la ubicación 3 en cadena3
	cadena3.insert(3, cadena4, 0, string::npos );

	cout<<"Cadenas despues de insert:\ncadena1: " << cadena1
		<<"\ncadena2: " << cadena2 
		<<"\ncadena3: " << cadena3
		<<"\ncadena4: " << cadena4 << endl;
	return 0;
}