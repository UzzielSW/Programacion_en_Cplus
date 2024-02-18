/*  LAB 2 24/05/2018 Junior
	1. crear la estructura con los datos(nombre, posicion, pais)
	2. crear lista (Nodo *p)
	3. crear funcion crea_lista_archivo(usar creaincio o creafinal)
		leer los datos de un archivo y guardarlo en una lista
		(recordar crear primero el archivo y colocar los datos de los jugadores)
		ejemplo:

		|  nombre1 posicion1 pais1	|
		|  nombre2 posicion2 pais2	|
		|  nombre3 posicion3 pais3	|
		|  nombre4 posicion4 pais4	|
		|  nombre5 posicion5 pais5	|

	4. crear funcion recorre e imprime la lista
*/


#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;

struct DatosJugadores
{
	string nombre, posicion, pais;
	struct DatosJugadores *liga;
};

typedef struct DatosJugadores Nodo;

int main()
{
	Nodo *p = NULL;
	Nodo *leer_archivo();
	void imprimeInfo(Nodo *p);

	p = leer_archivo();
	imprimeInfo(p);

	system("pause");
	return 0;
}

Nodo *leer_archivo()
{
	fstream archivo;
	Nodo *p, *q;

	archivo.open("Datos_Jugadores.dat", ios::out | ios::in); 

	if (!archivo)
	{
		cout<<"\n Error al abrir el archivo";
		exit(1);
	}else{
		p = new Nodo();
		archivo >> p->nombre >> p->posicion >> p->pais;
		p->liga = NULL;

		while(!(archivo.eof()))
		{  // leer mientras no llegue al final del archivo
		 	q = new Nodo();
			archivo >> q->nombre >> q->posicion >> q->pais;
			q->liga = p;
			p = q;
		}
			
		archivo.close();
	}

	return p;
}


void imprimeInfo(Nodo *p)
{	
	Nodo *q = p;
	int i = 0;

	while(q != NULL){
		cout<<"\n Jugador "<<++i<<" : "<< q->nombre
			<<"\n Posicion: "<< q->posicion
			<<"\n Pais: "<< q->pais
			<<"\n__________________________"<< endl;
		q = q->liga;
	}
}
