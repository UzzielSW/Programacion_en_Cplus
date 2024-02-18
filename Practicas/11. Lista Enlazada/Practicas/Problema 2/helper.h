#ifndef HELPER_H
#define HELPER_H 

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
using namespace std;

struct DatosPartes
{
	string codigo, nombre;
	float precio;
	int cantidad;
};

struct DatosNodo
{
	struct DatosPartes Dato;
	struct DatosNodo *liga;
};

typedef struct DatosNodo Nodo;

Nodo *creafinal(Nodo *p);
Nodo *eliminarInventario(Nodo *p);
void MostrarInventario(Nodo *p);



Nodo *creafinal(Nodo *p)
{
	Nodo *t, *q;
	char resp;
	DatosPartes cargarDatos(); // funcion local

	p = new Nodo();
	p->Dato = cargarDatos();
	p->liga = NULL;
	t = p;

	cout<<"\n desea ingresar mas partes: (y/n)\n >> ";
	cin>>resp;

	while((resp == 'y') || (resp == 'Y'))
	{
	 	q = new Nodo();
	    q->Dato = cargarDatos();
		q->liga = NULL;
		t->liga = q;
		t = q;
		
		fflush(stdin);
		cout<<"\n desea ingresar mas partes: (y/n)\n >> ";
		cin>>resp;	
	}

   return p;  
}


DatosPartes cargarDatos()
{
	DatosPartes Dato;
	
	system("cls");
	fflush(stdin);
	cout<<"\n ingrese nombre de la parte: ";
	getline(cin, Dato.nombre);	
	
	fflush(stdin);
	cout<<" Codigo: ";
	getline(cin, Dato.codigo);	

	cout<<" Precio: ";
	cin>>Dato.precio;

	cout<<" Cantidad: ";
	cin>>Dato.cantidad;

	return Dato;
}


void MostrarInventario(Nodo *p)
{
	if(p != NULL)
	{
		int i=0; //contador
		for(Nodo *q = p; q != NULL; q = q->liga){
			cout<<"\n Parte "<< ++i <<" : "<< q->Dato.nombre
				<<"\n Codigo: "<< q->Dato.codigo
				<<"\n Precio: "<< q->Dato.precio
				<<"\n Cantidad: "<< q->Dato.cantidad
				<<"\n__________________________"<< endl;
		}		
	}
	else
		cout<<"\n\tLa lista esta vacia";
}


Nodo *eliminarInventario(Nodo *p)
{
	if (p != NULL)
	{
		Nodo *q;
		while(p != NULL)
		{
			q = p;
			p = p->liga;
			delete q;	
		}
		cout<<"\n\tInventario eliminado";	
	
	}else
		cout<<"\n\tLa lista esta vacia";

	return p;
}



#endif