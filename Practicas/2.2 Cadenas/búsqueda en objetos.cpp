// Demostración de las funciones miembro de búsqueda en objetos string.
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string cadena1("mediodia es 12 pm; medianoche no es.");
	int ubicacion;

	// encuentra "mediodia" en las ubicacion 0 y "medianoche" en la ubicacion 19
	cout<< "Cadena original:\n" << cadena1
		<< "\n\n(find) \"es\" se encontro en: " << cadena1.find( "mediodia" )
		<< "\n(rfind) \"es\" se encontro en: " << cadena1.rfind( "medianoche" );

	// encuentra 'e' en la ubicacion 1
	ubicacion = cadena1.find_first_of("liesop");
	cout<< "\n\n(find_first_of) encontro '" << cadena1[ ubicacion ]
		<< "' del grupo \"liesop\" en: " << ubicacion;

	// encuentra 's' en la ubicacion 34
	ubicacion = cadena1.find_last_of("misop");
	cout<< "\n\n(find_last_of) encontro '" << cadena1[ ubicacion ]
		<< "' del grupo \"misop\" en: " << ubicacion;

	// encuentra '1' en la ubicacion 12
	ubicacion = cadena1.find_first_not_of("medop ias");
	cout<< "\n\n(find_first_not_of) '" << cadena1[ ubicacion ]
		<< "' no esta contenido en \"medop ias\" y se encontro en: "
		<< ubicacion;

	// encuentra ';' en la ubicacion 17
	ubicacion = cadena1.find_first_not_of("12medop ias");
	cout<< "\n\n(find_first_not_of) '" << cadena1[ ubicacion ]
		<< "' no esta contenido en \"12medop ias\" y se "
		<< "encontro en: " << ubicacion << endl;

	// busca los caracteres que no estén en cadena1
	ubicacion = cadena1.find_first_not_of("mediodia es 12 pm; medianoche no es.");
	cout << "\nfind_first_not_of(\"mediodia es 12 pm; medianoche no es.\")"<< " devuelve: " << ubicacion << endl;

	getchar();
	return 0;
}