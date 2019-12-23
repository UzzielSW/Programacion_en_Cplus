// Uso de un objeto ostringstream asignado en forma dinámica.
#include <iostream>
#include <string>
#include <sstream> // archivo de encabezado para el procesamiento de flujos de cadena
using namespace std;

int main()
{
	ostringstream cadenaSalida; // crea una instancia de ostringstream

	string cadena1("\nEnvio de varios tipos de datos " );
	string cadena2("a un objeto ostringstream:" );
	string cadena3("\n double: " );
	string cadena4("\n int: " );
	string cadena5("\n direccion de int: " );

	double doble1 = 123.4567;
	int entero = 22;

	// envia objetos string, double e int al objeto ostringstream cadenaSalida
	cadenaSalida << cadena1 << cadena2 << cadena3 << doble1 << cadena4 << entero << cadena5 << &entero;

	// llama a str para obtener el contenido string del objeto ostringstream
	cout << "\n cadenaSalida contiene:\n" << cadenaSalida.str();

	// agrega caracteres adicionales y llama a str para enviar el objeto string
	cadenaSalida << "\n se agregaron mas caracteres";

	cout<<"\n\n despues de las inserciones de flujo adicionales," 
		<<" cadenaSalida contiene:\n" << cadenaSalida.str() << endl;
		
	return 0;
}