/*
	2. Defina un algoritmo para insertar un elemento siguiendo a otro nodo dado como referencia, en una lista ordenada.
 */
#include <stdio.h> 
#include <stdlib.h> 
#include "help.h"

NODO *inserta_despues_x(NODO *, int, int);	// ejercicio 2

int main()
{
	NODO *p=NULL;
	int opc, dato, x;
	char resp;

	printf("\ncreando lista: ");
	p = creaFinal();

	do
	{
		system("cls");
		printf("\n Lista: "); recorreRecursivo(p);
		
		printf("\n Insertar: ");		
		printf("\n dato: "); scanf("%i",&dato);
		printf(" despues de x: "); scanf("%i",&x);
			p = inserta_despues_x(p, dato, x);
		
		printf("\n Desea seguir: (y/n): ");
		fflush(stdin);
		scanf("%c",&resp);
		fflush(stdin);

	} while (resp == 'y' || resp == 'Y');
	p = liberaMemoria(p);
	return 0;
}


NODO *inserta_despues_x(NODO *p, int dato, int x)
{
	NODO *q = p;

	while(q->liga != NULL && q->num < x)
		q = q->liga;

	if (q->num == x)
	{
		NODO *nodo = creaNodo();
		nodo->num = dato;
		nodo->liga = q->liga;
		q->liga = nodo;
	}
	else
		printf("\n\tno se encontro referencia x en la lista");
		
	return (p);
}