/*
	inventario de mascotas
	precio
	nombre
	tipo
	codigo

	menu:
		1.carga 
		2.imprime
		3.buscar por tipo
		4.salir
 */
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

struct datosmascotas
{
	char codigo[20];
	string nombre, tipo;
	float precio;
}mascotas[50], *ptr_mascotas = mascotas;


int main()
{
	// declaracion de variables
	int opc,cant = 0;
	int carga(int);
	void imprimir(int);
	void buscarTipo(int);
	
	do
	{
		system("cls");
		cout<<" \n inventario de mascotas"<<endl
			<<" 1.cargar datos de mascotas"<<endl
			<<" 2.imprimir datos de mascotas"<<endl
			<<" 3.buscar por tipo"<<endl
			<<" 4.salir"<<endl
			<<" opcion: ";cin>>opc;
			
		switch(opc)
		{
			case 1:
				cant = carga(cant);break;
			case 2:
				imprimir(cant);break;
			case 3:
				buscarTipo(cant);break;
		}

		fflush(stdin);
		getchar();
	} while (opc != 4);
	return 0;
}

int carga(int cant)
{
	int N;
	cout<<"\n ingrese la cantidad de mascotas: "; cin>>N;
	for (int i = cant; i < (N + cant); ++i)
	{
		fflush(stdin);
		cout<<"\n mascota ["<<i+1<<"]:\n";
		cout<<" nombre de la mascota: "; getline(cin,(mascotas+i)->nombre);

		cout<<" precio de la mascota: "; cin>>(mascotas+i)->precio;
		fflush(stdin);

		cout<<" tipo de mascota: "; getline(cin,(mascotas+i)->tipo);

		cout<<" codigo de la mascota: "; cin.getline((mascotas+i)->codigo,20,'\n');
	}

	cant += N;
	return cant;
}


void imprimir(int cant)
{	
	for (int i = 0; i < cant; ++i)
	{
		cout<<"\n mascota ["<<i+1<<"]:\n";
		cout<<" nombre de la mascota: "<<(mascotas + i)->nombre<<endl;
		cout<<" precio de la mascota: "<<(mascotas + i)->precio<<endl;
		cout<<" tipo de mascota: "<<(mascotas + i)->tipo<<endl;
		cout<<" codigo de la mascota: "<<(mascotas + i)->codigo<<endl;
	}
}

void buscarTipo(int cant)
{
	string busca;
	cout<<"\n ingrese el tipo de la mascotas que desea buscar: "; cin>>busca;

	for (int i = 0; i <	cant; ++i)
	{
		if ((mascotas + i)->tipo == busca)
		{
		cout<<"\n mascota ["<<(i + 1)<<"]:\n";
		cout<<" nombre de la mascota: "<<(mascotas + i)->nombre<<endl;
		cout<<" precio de la mascota: "<<(mascotas + i)->precio<<endl;
		cout<<" codigo de la mascota: "<<(mascotas + i)->codigo<<endl;
		}
	}
}