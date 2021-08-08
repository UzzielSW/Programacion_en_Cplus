#include <stdexcept> // el archivo de encabezado stdexcept contiene runtime_error
#include <iostream>
using namespace std;

//std::runtime_error - La clase runtime_error de la biblioteca estándar de C++
// los objetos ExcepcionDivisionEntreCero deben lanzarse por las funciones

class ExcepcionDivisionEntreCero : public runtime_error
{
	public:
 		ExcepcionDivisionEntreCero(): runtime_error("intento de dividir entre cero"){}
}; 

double Cociente(int numerador, int denominador)
{
 	if (denominador == 0)
 		throw ExcepcionDivisionEntreCero();
 
	return static_cast < double > numerador  / denominador;
}

int main()
{
	int numero1;
	int numero2;
	double resultado;

	cout << "\n Escriba dos enteros: ";
	while (cin >> numero1 >> numero2)
	{
 		try
 		{
			resultado = Cociente(numero1, numero2 );
	 		cout << " El Cociente es: " << resultado << endl;
  		}catch (ExcepcionDivisionEntreCero &divideByZeroException)
  		{
			cout << " Ocurrio una excepcion: "<< divideByZeroException.what() << endl;
 		}

		cout << "\n Escriba dos enteros o (ctrl+z) para terminar: ";
	}

	return 0; 
}