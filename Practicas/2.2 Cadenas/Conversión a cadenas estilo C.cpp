// Conversion a cadenas estilo C.
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string cadena1("CADENAS"); 
	int longitud = cadena1.length();
	char *ptr2 = new char[longitud + 1]; // incluyendo el carácter nulo

	// copia caracteres de cadena1 a la memoria asignada
	cadena1.copy(ptr2, longitud, 0); // copia cadena1 a ptr2 char*
	ptr2[longitud] = '\0'; // agrega el terminador nulo

	cout << "\n el objeto string cadena1 es: " << cadena1 << "\n cadena1 convertida a una cadena estilo C es: "<< cadena1.c_str();

	cout << "\n ptr2 es: " << ptr2 << endl;
	delete [] ptr2; // reclama la memoria asignada en forma dinámica
	return 0;
}