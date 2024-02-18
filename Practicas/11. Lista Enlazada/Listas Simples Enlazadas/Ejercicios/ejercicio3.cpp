/*
	3. algoritmo para insertar un elemento en una lista ordenada de tal manera que no se altere el orden de la misma.
 */
#include <stdio.h> 
#include <stdlib.h> 
#include "help.h"

NODO *insertar_ordenado_asc(NODO *, int);	// ejercicio 3

int main()
{
	NODO *p=NULL;
	int dato;
	char resp;

	printf("\ncreando lista: ");
	p = creaFinal();

	do
	{
		system("cls");
		printf("\n Lista: "); recorreRecursivo(p);
		
		printf("\n Insertar: ");		
		printf("\n dato: "); scanf("%i",&dato);
			p = insertar_ordenado_asc(p, dato);

		printf("\n Desea seguir: (y/n): ");
		fflush(stdin);
		scanf("%c",&resp);
		fflush(stdin);

	} while (resp == 'y' || resp == 'Y');
	p = liberaMemoria(p);
	return 0;
}


NODO *insertar_ordenado_asc(NODO *p, int dato)
{
	NODO *nodo = creaNodo();
	nodo->num = dato;

	if (dato <= p->num) // insertar al inicio
	{
		nodo->liga = p;
		p = nodo;
	}
	else
	{
		NODO *q = p;
		bool band = false;

		while(q->liga != NULL && band == false)
		{
			NODO *r = q->liga;

			if (q->num < dato && dato <= r->num)
			{
				q->liga = nodo;
				nodo->liga = r;
				band = true;
			}
			else 
				q = q->liga;
		}

		if (band == false) // insertar al final
		{
			q->liga = nodo;
			nodo->liga = NULL;
		}	
	}

	return (p);
}