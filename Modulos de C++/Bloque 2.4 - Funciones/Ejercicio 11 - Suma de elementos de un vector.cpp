/*Ejercicio 11: Realice una funcion que tome como parametros un vector de numeros enteros
y devuelva la suma de sus elementos.*/
#include<iostream>
using namespace std;

void pedirDatos();
int calcularSuma(int vec[], int);

int vec[100], tam;

int main()
{
	pedirDatos();
	
	cout<<"\nLa suma es: "<<calcularSuma(vec, tam)<<endl;
	
	return 0;
}

void pedirDatos()
{
	cout<<"Digite el numero de elementos del arreglo: ";
	cin>>tam;
	
	for(int i=0; i < tam; i++)
	{
		cout<<(i + 1)<<". Digite un numero: ";
		cin>>vec[i];
	}
}

int calcularSuma(int vec[], int tam)
{
	int suma = 0;
	
	for(int i=0; i < tam; i++)
		suma += vec[i];

	return suma;
}