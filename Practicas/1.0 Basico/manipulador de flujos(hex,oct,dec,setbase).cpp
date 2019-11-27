// Uso de los manipuladores de flujos hex, oct, dec y setbase.
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int numero;
 
 	cout << "Escriba un numero decimal: ";
 	cin >> numero;

	// usa el manipulador de flujo hex para mostrar un numero hexadecimal
	cout << numero << " en hexadecimal es: " << hex << numero << endl;
	// usa el manipulador de flujo oct para mostrar un numero octal
	cout << dec << numero << " en octal es: " << oct << numero << endl;
	// usa el manipulador de flujo setbase para mostrar un numero decimal
	cout << setbase( 10 ) << numero << " en decimal es: " << numero << endl;
	return 0;
}