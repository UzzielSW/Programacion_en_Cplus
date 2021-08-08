/*Ejercicio 8: Escriba una funcion nombrada cambio() que tenga un parametro en numero
entero y seis parametros de referencia en numero entero nombrados cien, cincuenta,
veinte, diez, cinco y uno, respectivamente. La funcion tiene que considerar el
valor entero transmitido como una cantidad en dolares y convertir el valor en el numero
menor de billetes equivalentes. */
#include<iostream>
using namespace std;

void cambio(int, int&, int&, int&, int&, int&, int&);

int main()
{
	int valor, cien = 0, cincuenta = 0, veinte = 0, diez = 0, cinco = 0, uno = 0;
	
	cout<<"Digite un valor: ";
	cin>>valor;
	//Llamos a la funcion
	cambio(valor, cien, cincuenta, veinte, diez, cinco, uno);
	
	cout<<"Cantidad de billetes a entregar como cambio:"
		<<"\nCien: "<<cien
		<<"\nCincuenta: "<<cincuenta
		<<"\nVeinte: "<<veinte
		<<"\nDiez: "<<diez
		<<"\nCinco: "<<cinco
		<<"\nUno: "<<uno<<endl;
	
	return 0;
}

void cambio(int valor, int& cien, int& cincuenta, int& veinte, int& diez, int& cinco, int& uno)
{
	cien = valor / 100;
	valor %= 100;

	cincuenta = valor / 50;
	valor %= 50;

	veinte = valor / 20;
	valor %= 20;

	diez = valor / 10;
	valor %= 10;

	cinco = valor / 5;
	uno = valor % 5;
}