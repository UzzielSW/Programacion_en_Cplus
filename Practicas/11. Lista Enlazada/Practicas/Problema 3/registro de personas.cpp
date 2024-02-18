/*  LAB 2 31/05/2018 Junior
	1. crear la estructura con los datos(nombre, edad, genero)
	2. crear lista
	3. crear funcion crea_lista_archivo(usar creaincio o creafinal)
		leer los datos de un archivo y guardarlo en una lista
		(recordar crear primero el archivo y colocar los datos)
		ejemplo:

		|  nombre1 edad1 genero1	|
		|  nombre2 edad2 genero2	|
		|  nombre3 edad3 genero3	|
		|  nombre4 edad4 genero4	|
		|  nombre5 edad5 genero5	|

	4. crear funcion recorre e imprime la lista
	5. elimina un Nodo por la edad
	6. mostrar la lista
*/

#include "helper.h"

int main()
{	
	int opc;
	string edad;
	Nodo *p = NULL;

	//funciones
	Nodo *leer_archivo();
	void imprimeInfo(Nodo *p);
	Nodo *eliminax(Nodo *p, string ref);
	void guardar_archivo(Nodo *p);
	Nodo *eliminarInventario(Nodo *p);

	do
	{	system("cls");
		cout<<"\n .:Inventario de Personas:.\t\t\t"<<char(174)<<"Junior"<<char(175);
		cout<<"\n 1.Crear lista";
		cout<<"\n 2.Mostrar inventario";
		cout<<"\n 3.Eliminar un nodo del inventario";
		cout<<"\n 4.Salir";
		cout<<"\n\n >> ";
		cin>>opc;
		fflush(stdin);
		
		switch(opc){
			case 1:
				if (p == NULL){
					p = leer_archivo();  //	leyendo el archivo
				}
				else
					cout<<"\n La lista existe [elimine inventario para habilitar esta opcion]";
			break;

			case 2:
				system("cls");
				imprimeInfo(p);	// imprimiendo
			break;

			case 3:
				if (p != NULL){
	  				printf("\n Introduzca la edad del Nodo a eliminar: ");
	  				cin>>edad;            	
					p = eliminax(p, edad); // eliminando nodo
				}else 
	     			printf("\n\t La lista esta vacia");
			break;

			default: 
				guardar_archivo(p); //guardando lista
				p = eliminarInventario(p);	opc = 4; 
		}getch();
	} while (opc != 4);
return 0;
}
