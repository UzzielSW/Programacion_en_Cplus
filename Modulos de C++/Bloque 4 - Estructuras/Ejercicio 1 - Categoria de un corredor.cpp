/*1. Hacer una estructura llamada corredor, en la cual se tendran los siguientes 
campos: Nombre, edad, sexo, club, pedir datos al usuario para un corredor, y asignarle
una categoria de competicion:
- Juvenil <= 18 year
- Senior <= 40 year
- Veterano > 40 year
Posteriormente imprimir todos los datos del corredor, incluida su categoria de 
competicion.*/
#include<iostream>
#include<string.h>
using namespace std;

struct Corredor
{
	char nombre[20];
	int edad;
	char sexo[10];
	char club[20];
	char categoria[20];
};

int main()
{
	Corredor c1;
	
	cout<<"Nombre: "; cin.getline(c1.nombre, 20, '\n');
	cout<<"Edad: "; cin>> c1.edad;
	fflush(stdin);
	cout<<"Sexo: "; cin.getline(c1.sexo, 10, '\n');
	cout<<"Club: "; cin.getline(c1.club, 20, '\n');
	
	if(c1.edad <= 18)
		strcpy(c1.categoria,"Juvenil");
	else if(c1.edad <= 40)
		strcpy(c1.categoria,"Senior");
	else
		strcpy(c1.categoria,"Veterano");
	
	cout<<"\n\nMostrando Datos"
		<<"\nNombre: "<< c1.nombre
		<<"\nEdad: "<< c1.edad
		<<"\nSexo: "<< c1.sexo
		<<"\nClub: "<< c1.club
		<<"\nCategoria: "<<c1.categoria<<endl;
	
	return 0;
}