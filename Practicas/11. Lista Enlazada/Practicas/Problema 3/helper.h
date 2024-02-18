#ifndef HELPER_H
#define HELPER_H 


#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;

struct Datos
{
	string nombre, edad, genero;
	struct Datos *liga;
};

typedef struct Datos Nodo;

Nodo *leer_archivo()
{
	fstream archivo;
	Nodo *p, *q;

	archivo.open("Datos_personas.dat", ios::out | ios::in); 

	if (!archivo)
	{
		cout<<"\n Error al abrir el archivo";
		exit(1);
	}else{
		p = new Nodo();
		archivo >> p->nombre >> p->edad >> p->genero;
		p->liga = NULL;

		while(!(archivo.eof()))
		{  // leer mientras no llegue al final del archivo
		 	q = new Nodo();
			archivo >> q->nombre >> q->edad >> q->genero;
			q->liga = p;
			p = q;
		}
		cout<<"\n Archivo leido correctamente";	
		archivo.close();
	}

	return p;
}


void imprimeInfo(Nodo *p)
{	
	if (p != NULL)
	{
		Nodo *q = p;

		while(q != NULL){
			cout<<"\n Nombre: "<< q->nombre
				<<"\n Edad: "<< q->edad
				<<"\n Genero: "<< q->genero
				<<"\n__________________________"<< endl;
			q = q->liga;
		}
	}else
		printf("\n\t La lista esta vacia");
}


Nodo *eliminax(Nodo *p, string ref)
{
	Nodo *q, *t;
	int BAND = 1;
	
	q = p;
	
	while ((q->edad != ref) && (BAND == 1))
    {
		if(q->liga != NULL) // recorrer mientras no llegue al final
		{
		  	t = q;
		  	q = q->liga;
		}
		else // si no se encontro
		    BAND = 0;   
	}
      
    if (BAND == 0)
    	printf("\n\n El elemento no fue encontrado");
    else{
    	cout<<"\n Nodo eliminado";
		if (p == q) // si es el primer nodo
	 		p = q->liga;
		else
	   		t->liga = q->liga;
		
		delete q;
	}

	return p;
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
		cout<<"\n Inventario eliminado";	
	
	}else
		cout<<"\n\tLa lista esta vacia";

	return p;
}


void guardar_archivo(Nodo *p)
{
	Nodo *q;
	fstream archivo;
	string nombreArchivo;

	cout<<"\n Digite el nombre o la ubicacion del archivo: ";
	getline(cin,nombreArchivo);

	nombreArchivo.insert(nombreArchivo.length(), ".dat");

	archivo.open(nombreArchivo.c_str(), ios::out | ios::app); 

	if (archivo.fail())
	{
		cout<<"\n Error al abrir el archivo";
		exit(1);
	}else{
		
		q = p;

		while(q != NULL)
		{
			archivo << q->nombre <<" "<< q->edad <<" "<< q->genero<<endl;
			q = q->liga;
		}

		cout<<"\n Lista guardada correctamente";	
		archivo.close();
	}
}


#endif


