/*1. Escribe un programa que defina un vector de n�meros y calcule la suma de 
sus elementos.*/
#include<iostream>
using namespace std;

int main()
{
	int numeros[5] = {1, 2, 3, 4, 5};
	int suma=0;
	
	for(int i=0; i < 5; i++)
		suma += numeros[i]; //Utilizamos una suma iterativa
	
	cout<<"La suma de los elementos del arreglo es: "<< suma<<endl;	
	
	getchar();
	return 0;
}