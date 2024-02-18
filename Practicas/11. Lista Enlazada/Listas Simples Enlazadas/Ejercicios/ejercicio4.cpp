/*
	4. algoritmo para eliminar un nodo de una lista ordenada.
*/
#include <stdio.h> 
#include <stdlib.h> 
#include "help.h"

NODO *eliminar_ordenado_asc(NODO *, int);	// ejercicio 4

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
		
		printf("\n Eliminar: ");		
		printf("\n dato: "); scanf("%i",&dato);
			p = eliminar_ordenado_asc(p, dato);

		printf("\n Desea seguir: (y/n): ");
		fflush(stdin);
		scanf("%c",&resp);
		fflush(stdin);

	} while (resp == 'y' || resp == 'Y');
	p = liberaMemoria(p);
	return 0;
}

NODO *eliminar_ordenado_asc(NODO *p, int dato)
{
	NODO *q = p, *t;

	while(q->num < dato && q->liga != NULL)
	{
		t = q;
		q = q->liga;
	}

	if (q->num == dato)
	{
		if (q == p) // primer elemento
			p = p->liga;
		else
			t->liga = q->liga;

		free(q);
		printf("\nelemento %d a sido eliminado", dato);
	}
	else
		printf("\nno se encontro referencia x en la lista");

	return (p);
}