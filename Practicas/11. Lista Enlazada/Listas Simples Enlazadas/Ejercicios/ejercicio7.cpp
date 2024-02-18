/*
	7. dada una lista con numeros, dividala en dos listas independientes. una con numeros positivos y otra con los numeros negativos.
 */
#include <stdio.h> 
#include <stdlib.h> 
#include "help.h"

void divide_lista(NODO *); // ejercicio 7

int main()
{
	NODO *p=NULL;
	printf("\ncreando lista: (incluir numeros negativos y positivos");
	p = creaFinal();

	divide_lista(p);

	fflush(stdin);
	getchar();
	p = liberaMemoria(p);
	return 0;
}


void divide_lista(NODO *p)
{
	NODO *pos=NULL, *neg=NULL;
	NODO *t=NULL, *r=NULL;
	NODO *q;

	for (q = p; q != NULL ; q = q->liga)
	{
		if (q->num < 0)
			neg = enlazado(neg, &r, q->num);
		else
			pos = enlazado(pos, &t, q->num);		
	}

	printf("\nLista positivos: "); recorreRecursivo(pos);
	printf("\nLista negativos: "); recorreRecursivo(neg);
}