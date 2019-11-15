/*Ejercicio 4: Escriba un programa en C++ que devuelva la parte fraccionaria de 
cualquier n�mero introducido por el usuario. Por ejemplo, si se introduce el n�mero
256.879, deber�a desplegarse el n�mero 0.879.*/
#include<iostream>
using namespace std;

void pedirDatos();
float devolucionFraccionaria(float n);

float numero;

int main()
{
	pedirDatos();
	
	cout<<"La parte fraccionaria del numero es: "<<devolucionFraccionaria(numero)<<endl;
	
	getchar();
	return 0;
}

void pedirDatos()
{
	cout<<"Digite un numero: ";
	cin>>numero;
}

float devolucionFraccionaria(float n)
{
	//por ejemplo si el numero es 45.567 en entero solo se guardaria 45
	int entero = n;
	//y por ultimo restamos el valor flotante menos el entero para tener la parte fraccionaria
	float resultado = n - entero;
	
	return resultado;	
}