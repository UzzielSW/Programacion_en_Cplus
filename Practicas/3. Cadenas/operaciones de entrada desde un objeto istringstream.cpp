// Demostración de las operaciones de entrada desde un objeto istringstream.
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
 	string entrada("Entrada prueba 123 4.7 A");
 	istringstream cadenaEntrada(entrada);

 	string cadena1;
 	string cadena2;
 	int entero;
 	double doble1;
 	char caracter;
 	long valor=0;

	cadenaEntrada >> cadena1 >> cadena2 >> entero >> doble1 >> caracter;

	cout<<"\nSe extrajeron los siguientes elementos del objeto istringstream:" 
		<<"\n string 1: " << cadena1
		<<"\n string 2: "	<< cadena2 
		<<"\n int: " 		<< entero
		<<"\n double: " 	<< doble1 
		<<"\n char: " 	<< caracter;

	// intento de leer de un flujo vacío
	cadenaEntrada >> valor;
	// prueba los resultados del flujo
 	if (valor != 0)
 		cout<<"\n\n el valor long es: " << valor << endl;
 	else
 		cout<<"\n\n cadenaEntrada esta vacia" << endl;

	return 0;
}