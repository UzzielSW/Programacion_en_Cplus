/*Ejercicio 1: Escriba una funci�n llamada mult() que acepte dos n�meros en punto 
flotante como par�metros, multiplique estos dos n�meros y despliegue el resultado.*/
#include<iostream>
using namespace std;

//Prototipo de Funcion
void mult(float x, float y);
void pedirDatos();

float n1, n2;

int main()
{
	pedirDatos();
	mult(n1, n2);
	
	getchar();
	return 0;
}

void pedirDatos()
{	
	cout<<"Digite 2 numeros: ";
	cin>>n1>>n2;
}

void mult(float x, float y)
{
	cout<<"La multiplicacion es: "<<(x * y)<<endl;
}