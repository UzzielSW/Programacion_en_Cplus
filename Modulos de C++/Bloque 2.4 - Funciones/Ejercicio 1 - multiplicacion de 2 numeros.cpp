/*Ejercicio 1: Escriba una funcion llamada mult() que acepte dos numeros en punto 
flotante como parametros, multiplique estos dos numeros y despliegue el resultado.*/
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