/*
	1. Defina un algoritmo para insertar un elemento antes de otro nodo dado como referencia, en una lista ordenada.
*/

#include <stdio.h> 
#include <stdlib.h>
#include "help.h"

NODO *inserta_antes_x(NODO *, int, int);	// ejercicio 1

int main()
{
	NODO *p=NULL;
	int dato, x;
	char resp;

	printf("\ncreando lista: ");
	p = creaFinal();

	do
	{
		system("cls");
		printf("\n Lista: "); recorreRecursivo(p);
		
		printf("\n Insertar: ");		
		printf("\n dato: "); scanf("%i",&dato);
		printf(" antes de x: "); scanf("%i",&x);
			p = inserta_antes_x(p, dato, x);
		
		printf("\n Desea seguir: (y/n): ");
		fflush(stdin);
		scanf("%c",&resp);
		fflush(stdin);

	} while (resp == 'y' || resp == 'Y');
	p = liberaMemoria(p);
	return 0;
}

NODO *inserta_antes_x(NODO *p, int dato, int x)
{
	NODO *t;
	NODO *q = p;

	while(q->liga != NULL && q->num < x)
	{
		t = q;
		q = q->liga;
	}

	if (q->num == x)
	{
		NODO *nodo = creaNodo();
		nodo->num = dato;

		if (q == p) //primer nodo
		{
			nodo->liga = p;
			p = nodo;
		}
		else
		{
			t->liga = nodo;
			nodo->liga = q;
		}
	}
	else 
		printf("\n\tno se encontro referencia x en la lista");

	return (p);
}