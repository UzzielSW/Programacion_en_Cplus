/*Ejercicio 1: Realice un programa que pida al usuario el nombre de un fichero 
de texto y, a continuacion permita almacenar al usuario tantas frases como el
usuario desee.*/
#include<iostream>
#include<fstream>
using namespace std;

void escribirFrases();

int main()
{
	escribirFrases();
	
	return 0;
} 

void escribirFrases()
{
	int edades[5];
	ofstream archivo;

	archivo.open("archivo.dat", ios::out); //Creamos el archivo
	
	if(archivo.fail())
	{ //Si a ocurrido algun error
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}

	cout<<"ingrese edades: ";
	for(int i=0; i < 5; i++)
		cin>>edades[i];

	for (int i = 0; i < 5; i++)
		archivo <<edades[i]<<" ";
	
	archivo.close();
}