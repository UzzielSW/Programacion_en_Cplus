/*  LAB 2 9/05/2018 Junior
	problema: Inventario de partes de computadora.
	Datos: codigo, nombre de la parte, precio y cantidad.

	opciones:
	1. Crear lista (usar algoritmo crea final) (inhabilitar una ves creada)
	2. imprimir inventario
	3.Eliminar inventario
	4.Salir

 */

#include "helper.h"
	
int main()
{
	Nodo *p = NULL;
	int opc;

	do
	{	system("cls");
		cout<<"\n .:Inventario Info_Computo:.\t\t\t"<<char(174)<<"Junior"<<char(175);
		cout<<"\n 1.Crear lista";
		cout<<"\n 2.Mostrar inventario";
		cout<<"\n 3.Eliminar inventario";
		cout<<"\n 4.Salir";
		cout<<"\n\n >> ";
		cin>>opc;
		fflush(stdin);
		
		switch(opc){
			case 1:
				if (p == NULL)
					p = creafinal(p);
				else
					cout<<"\n La lista existe [elimine inventario para habilitar esta opcion]";
			break;

			case 2:
				MostrarInventario(p);
			break;

			case 3:
				p = eliminarInventario(p);
			break;

			default: p = eliminarInventario(p);	opc = 4; 
		}getch();
	} while (opc != 4);
	return 0;
}