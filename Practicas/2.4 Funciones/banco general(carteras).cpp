/*
 - banco general tiene 5 sucursales con 4 carteras de prestamos(personales, autos, hipotecas, inversiones).
 - cargar la matriz con los datos  de las 5 sucursales.
 - en un menu calcular las siguientes opciones:
 	 1- totales por sucursales de las cuatro carteras
	 2- la cartera de mayor efectivo
	 3- la sucursal de menor efectivo
	 4- los totales de las 5 sucursales
	 5- salir.

matriz: 

     carteras  | suc1| suc2| suc3| suc4| suc5|total´s cart|
	personales | 100 | 200 | 300 | 300 | 200 |    1, 100   |
	autos      | 129 | 239 | 599 | 708 | 399 |    2, 074   |
	hipotecas  | 390 | 500 | 399 | 389 | 179 |    1, 857   |
	inversiones| 120 | 599 | 688 | 700 | 800 |    2, 907   |
	totales suc| 739 |1, 538|1, 986|2, 097|1, 578|    7, 938   |
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

// declaracion de funciones
int menu();
void imprimirDatos(int [][5]);
void case0(int [][5]);
void case1(int [][5], int []);
void case2(int [][5]);
void case3(int [][5], int []);
void case4(int [][5], int []);


int main()
{ 
	// declaracion de variables
	int matriz[4][5];
	int opc;
	int totalSucursales[5]; //total de sucursal#
	char imprma[10], mensucur[10];

	//===========================================================
	case0(matriz); //cargando los datos 

	do{
		system("cls");
		imprimirDatos(matriz);
		opc = menu();

		switch(opc)
		{
			case 0: case0(matriz); break;
			case 1: case1(matriz, totalSucursales); break;
			case 2: case2(matriz); break;
			case 3: case3(matriz, totalSucursales); break;
			case 4: case4(matriz, totalSucursales); break;
			case 5: cout<<"\n OK"; break;
			default: cout<<" opcion invalida"; break;
		}
		fflush(stdin);
		getchar();
	}while(opc != 5);	
	return 0;
}

//===========================================================
void imprimirDatos(int matriz[4][5])
{
	cout<<"\n Datos de 5 las sucursales del Banco General: \n"<<endl;
	for (int i = 0; i < 4; ++i)
	{ 
		for (int k = 0; k < 5; ++k)
			cout<<" "<<matriz[i][k]; 
		cout<<endl; 
	}
}

int menu()
{
	int opc = 0;
	cout<<"\n\n\n 0- ingresar nuevamente los datos de las 5 sucursales "
		<<"\n 1- totales por sucursales de las cuatro carteras"
		<<"\n 2- la cartera de mayor efectivo"
		<<"\n 3- la sucursal de menor efectivo"
		<<"\n 4- los totales de las 5 sucursales"
		<<"\n 5- salir"
		<<"\n  opcion: "; cin>>opc;
	return opc;
}

void case0(int matriz[4][5])
{
	cout<<"\n\n Ingresar datos de 5 las sucursales: "<<endl;
	for (int i = 0; i < 4; ++i)
		for (int k = 0; k < 5; ++k)
			cin>>matriz[i][k]; 
}

void case1(int matriz[4][5], int totalSucursales[5])
{
	for (int i = 0; i < 5; ++i) totalSucursales[i] = 0; //inicializando
	
	for (int k = 0; k < 5; ++k)
	{
		for (int i = 0; i < 4; ++i)
			totalSucursales[k] += matriz[i][k];

		cout <<"\n total de sucursal "<<(k+1)<<": "<<totalSucursales[k];
	}
}

void case2(int matriz[4][5])
{
	int carteras[4], mayor = 0, idmayor;
	char cart[][15] = {"personales","autos","hipotecas","inversiones"};

	for (int i = 0; i < 4; ++i) carteras[i] = 0; //inicializando;

	//calculando totales de cada cartera
	for (int i = 0; i < 4; ++i)
		for (int k = 0; k < 5; ++k)
			carteras[i] += matriz[i][k];

	//buscando el mayor
	for (int i = 0; i < 4; ++i)
	{	if (carteras[i] > mayor)
		{
			mayor = carteras[i];
			idmayor = i;
		} 
	}

	cout<<"\n la cartera de mayor numero es: "<<cart[idmayor];
}

void case3(int matriz[4][5], int totalSucursales[5])
{
	int menor, idmenor;

	case1(matriz, totalSucursales);
	cout<<"\n\n";

	//buscando la sucursal con menor efectivo
	menor = totalSucursales[0];
	idmenor = 0;

	for (int i = 1; i < 5; ++i)
	{
		if(totalSucursales[i] < menor)
		{
			idmenor = i;
			menor = totalSucursales[i];
		} 
	}

	cout<<"\n la sucursal de menor efectivo es: sucursal #"<<(idmenor + 1);
}

void case4(int matriz[4][5], int totalSucursales[5])
{
	case1(matriz, totalSucursales);
	cout<<"\n\n";
	int total=0;

	//calculando el total
	for (int i = 0; i < 5; ++i) total += totalSucursales[i];

	cout<<"\n El total de las 5 sucursales es: "<<total;
}