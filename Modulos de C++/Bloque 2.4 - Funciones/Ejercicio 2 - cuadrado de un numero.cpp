/*Ejercicio 2: Escriba una funci�n llamada al_cuadrado() que calcule el cuadrado del 
valor que se le transmite y despliegue el resultado. La funci�n deber� ser capaz de
elevar al cuadrado n�meros flotantes*/
#include<iostream>
using namespace std;

void pedirDatos();
void al_cuadrado(float n);

float numero;

int main()
{
	pedirDatos();	
	al_cuadrado(numero);
	
	getchar();
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