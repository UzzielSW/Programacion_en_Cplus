/*
 - banco general tiene 5 sucursales con 4 carteras de prestamos(personales,autos,hipotecas,inversiones).
 - cargar la matriz con los datos  de las 5 sucursales.
 - en un menu calcular las siguientes opciones:
 	 1- totales por sucursales de las cuatro carteras
	 2- la cartera de mayor numero
	 3- la sucursal de menor efectivo
	 4- los totales de las 5 sucursales
	 5- salir.

matriz: 

     carteras  | suc1| suc2| suc3| suc4| suc5|total´s cart|
	personales | 100 | 200 | 300 | 300 | 200 |    1,100   |
	autos      | 129 | 239 | 599 | 708 | 399 |    2,074   |
	hipotecas  | 390 | 500 | 399 | 389 | 179 |    1,857   |
	inversiones| 120 | 599 | 688 | 700 | 800 |    2,907   |
	totales suc| 739 |1,538|1,986|2,097|1,578|    7,938   |
 */


#include "iostream"
#include "stdlib.h"
#include "conio.h"
#include "string.h"
using namespace std;

int main(int argc, char const *argv[])
{ 
	// declaracion de variables
	int matriz[4][5],pers=0,aut=0,hipo=0,inver=0,mayor=0,menor=99999999;
	int opc,tsu1,tsu2,tsu3,tsu4,tsu5; //tsu# = total de sucursal#
	tsu1=tsu2=tsu3=tsu4=tsu5=0;
	char imprma[10],mensucur[10];

	// declaracion de funciones
	int menu(void);
	void case1(int [][5],int&,int&,int&,int&,int&);
	void case2(int [][5],int,int,int,int,int,char []);
	void case3(int,int,int,int,int,int,char []);

	cout<<" Ingresar datos de 5 las sucursales: "<<endl;

	// ingresando datos de sucursales
	for (int i = 0; i < 4; ++i){ for (int k = 0; k < 5; ++k){ cin>>matriz[i][k]; } }

	cout<<endl;

	// menu
	do{
		system("cls");
		cout<<"\n Datos de 5 las sucursales del Banco General: \n"<<endl;
		for (int i = 0; i < 4; ++i){ for (int k = 0; k < 5; ++k){ cout<<" "<<matriz[i][k]; } cout<<endl; }
		cout<<endl<<endl;
		opc = menu();
		switch(opc){
			case 1: case1(matriz,tsu1,tsu2,tsu3,tsu4,tsu5);         break;
			case 2: case2(matriz,pers,aut,hipo,inver,mayor,imprma); break;
			case 3: case3(tsu1,tsu2,tsu3,tsu4,tsu5,menor,mensucur); break;
			case 4: cout<<"\n total de totas las sucursales: "<<(tsu1+tsu2+tsu3+tsu4+tsu5); break;
			case 5: exit(0); break;
			default: cout<<" fail "; break;
		}
	getch();
	}while(opc!=5);	
return 0;
}


int menu(void){
	int opc=0;
		cout<<" 1- totales por sucursales de las cuatro carteras"<<endl
			<<" 2- la cartera de mayor numero"<<endl
			<<" 3- la sucursal de menor efectivo"<<endl
			<<" 4- los totales de las 5 sucursales"<<endl
			<<" 5- salir"<<endl
			<<"  opcion: ";cin>>opc;
return opc;
}


void case1(int matriz[4][5],int &tsu1,int &tsu2,int &tsu3,int &tsu4,int &tsu5)
{
	for (int i = 0; i < 4; ++i){ tsu1+=matriz[i][0]; } cout <<"\n total de sucursal 1: "<<tsu1;
	for (int i = 0; i < 4; ++i){ tsu2+=matriz[i][1]; } cout <<"\n total de sucursal 2: "<<tsu2;
	for (int i = 0; i < 4; ++i){ tsu3+=matriz[i][2]; } cout <<"\n total de sucursal 3: "<<tsu3;
	for (int i = 0; i < 4; ++i){ tsu4+=matriz[i][3]; } cout <<"\n total de sucursal 4: "<<tsu4;
	for (int i = 0; i < 4; ++i){ tsu5+=matriz[i][4]; } cout <<"\n total de sucursal 5: "<<tsu5;
}


void case2(int matriz[4][5],int pers,int aut,int hipo,int inver,int mayor,char imprma[10])
{
	for (int i = 0; i < 4; ++i)
	{
		for (int k = 0; k < 5; ++k)
		{
			     if (i==0) pers+=matriz[i][k];
			else if (i==1) aut+=matriz[i][k];
			else if (i==2) hipo+=matriz[i][k];
			else if (i==3) inver+=matriz[i][k];
		}
	}

	if(pers>mayor){ mayor=pers; strcpy(imprma,"personales"); }
	if(aut>mayor){ mayor=aut; strcpy(imprma,"autos"); }
	if(hipo>mayor){ mayor=hipo; strcpy(imprma,"hipotecas"); }
	if(inver>mayor){ mayor=inver; strcpy(imprma,"inversiones"); }

	cout<<"\n la cartera de mayor numero es: "<<imprma;
}


void case3(int tsu1,int tsu2,int tsu3,int tsu4,int tsu5,int menor,char mensucur[10])
{
	if(tsu1<menor){ menor=tsu1; strcpy(mensucur,"sucursal 1"); }
	if(tsu2<menor){ menor=tsu2; strcpy(mensucur,"sucursal 2"); }
	if(tsu3<menor){ menor=tsu3; strcpy(mensucur,"sucursal 3"); }
	if(tsu4<menor){ menor=tsu4; strcpy(mensucur,"sucursal 4"); }
	if(tsu5<menor){ menor=tsu5; strcpy(mensucur,"sucursal 5"); }

	cout<<"\n la sucursal de menor efectivo es: "<<mensucur;
}