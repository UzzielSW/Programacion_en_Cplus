/*
	18. programa que elimine los elementos repetidos de una lista ordenada ascendentemente.
 */
#include <stdio.h> 
#include <stdlib.h> 
#include "help.h"

// ejercicio 18
	NODO *unique(NODO *); //desordenado
	NODO *unique_or(NODO *); //ordenado
int main()
{
	NODO *p=NULL;
	int opc;

	printf("\ncreando lista:");
	p = creaFinal();

	system("cls");
	printf("\nLista: "); recorreRecursivo(p);
	printf("\n1.lista ordenada");
	printf("\n2.lista desordenada");
	printf("\nopc? ");
	scanf("%d",&opc);

	if (opc == 1)
		p = unique_or(p); 
	else
		p = unique(p); 

	printf("\n Lista: "); recorreRecursivo(p);

	fflush(stdin);
	getchar();
	p = liberaMemoria(p);
	return 0;
}

NODO *unique(NODO *p)
{
	NODO *q, *t = NULL, *r = NULL;
	
	for(q = p; q != NULL; q = q->liga)
	{
		if (busqueda(r, q->num))
			continue;
		else
			r = enlazado(r, &t, q->num);
	}
	
	p = liberaMemoria(p); // eliminando la otra lista (opcional)
	
	return (r); 
}


NODO *unique_or(NODO *p)
{
	NODO *q = p;
	NODO *t;

	while(q->liga != NULL)
	{
		t = q->liga;
		if (q->num == t->num)
		{
			q->liga = t->liga;
			t->liga = NULL;
			free(t);
		}else
			q = q->liga;
	}

	return p;
}