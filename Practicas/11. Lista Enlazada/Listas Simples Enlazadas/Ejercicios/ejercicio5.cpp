/*
	5. con dos listas ordenadas, formar una tercera con la mezcla de los elementos de ambas listas, en forma ordenada.
 */
#include <stdio.h> 
#include <stdlib.h> 
#include "help.h"
 
NODO *merge_list(NODO *, NODO *); // ejercicio 5

int main()
{
	NODO *p=NULL, *s=NULL, *n=NULL;

	printf("\ncreando lista: [P]");
	p = creaFinal();

	printf("\ncreando lista: [S]");
	s = creaFinal();

	system("cls");
	printf("\n Lista P: "); recorreRecursivo(p);
	printf("\n Lista S: "); recorreRecursivo(s);				
	
	n = merge_list(p, s);
	
	printf("\n Mezcla: "); recorreRecursivo(n);

	fflush(stdin);
	getchar();

	p = liberaMemoria(p);
	s = liberaMemoria(s);
	n = liberaMemoria(n);
	return 0;
}


NODO *merge_list(NODO *p, NODO *s)
{
	NODO *q = p, *t = s;
	NODO *n = NULL, *r = NULL;

	while((q != NULL) || (t != NULL))
	{
		if (t == NULL)
		{
			n = enlazado(n, &r, q->num);
			q = q->liga;
		}
		else if(q == NULL)
		{
			n = enlazado(n, &r, t->num);
			t = t->liga;
		}
		else if (q->num <= t->num)
		{
			n = enlazado(n, &r, q->num);
			q = q->liga;
		}
		else if ((t->num < q->num))
		{
			n = enlazado(n, &r, t->num);
			t = t->liga;
		}
	}

	return (n);
}