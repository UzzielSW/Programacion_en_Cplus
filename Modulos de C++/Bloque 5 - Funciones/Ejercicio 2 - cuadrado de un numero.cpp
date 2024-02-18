/*Ejercicio 2: Escriba una funcion llamada al_cuadrado() que calcule el cuadrado del 
valor que se le transmite y despliegue el resultado. La funcion debera ser capaz de
elevar al cuadrado numeros flotantes*/
#include<iostream>
using namespace std;

void pedirDatos();
void al_cuadrado(float n);

float numero;

int main()
{
	pedirDatos();	
	al_cuadrado(numero);
	
	return 0;
}

void pedirDatos()
{
	cout<<"Digite un numero: ";
	cin>>numero;
}

void al_cuadrado(float n)
{
	cout<<"El cuadrado del numero es: "<<(numero * numero)<<endl;
}