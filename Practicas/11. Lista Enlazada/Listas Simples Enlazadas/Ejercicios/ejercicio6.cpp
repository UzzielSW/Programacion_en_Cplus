/*
	6. programa recursivo que dadas dos listas ordenadas ascendentemente las mezcle y genere una nueva lista de forma descendente.
 */

#include <stdio.h> 
#include <stdlib.h> 
#include "help.h"

// FUNCIONES COMPLEMENTOS
	void recorre_ascen_descen(NODO *p, NODO *s);


NODO *mezcla_descendente(NODO *, NODO *, NODO *, NODO **); // ejercicio 6

int main()
{
	NODO *p=NULL, *s=NULL, *n=NULL;
	NODO *q;

	printf("\ncreando lista: [P]");
	p = creaFinal();

	printf("\ncreando lista: [S]");
	s = creaFinal();

	system("cls");
	printf("\n Lista P: "); recorreRecursivo(p);
	printf("\n Lista S: "); recorreRecursivo(s);

	// recorre_ascen_descen(p, s);
	n = mezcla_descendente(p, s, n, &q);
	printf("\n mezcla recursiva descendente: "); recorreRecursivo(n);	

	fflush(stdin);
	getchar();

	p = liberaMemoria(p);
	s = liberaMemoria(s);
	n = liberaMemoria(n);
	return 0;
}

void recorre_ascen_descen(NODO *p, NODO *s)
{
	if ((p != NULL) || (s != NULL))
	{
		if (p == NULL)
		{
			printf("\n [%i] ", s->num);
			recorre_ascen_descen(p, s->liga);
			printf("\n [%i] ", s->num);	
		}
		else if (s == NULL)
		{
			printf("\n [%i] ", p->num);
			recorre_ascen_descen(p->liga, s);
			printf("\n [%i] ", p->num);
		}
		else if (p->num <= s->num)
		{
			printf("\n [%i] ", p->num);
			recorre_ascen_descen(p->liga, s);
			printf("\n [%i] ", p->num);
		}

		else if (s->num < p->num)
		{
			printf("\n [%i] ", s->num);
			recorre_ascen_descen(p, s->liga);
			printf("\n [%i] ", s->num);
		}
	}else
		printf("\n------------------------------");

	return;
}


NODO *mezcla_descendente(NODO *p, NODO *s, NODO *n, NODO **q)
{
	int dato;

	if ((p != NULL) || (s != NULL))
	{
		if (p == NULL)
		{
			n = mezcla_descendente(p, s->liga, n, &(*q));
			// printf("\n [%i] ", s->num);	

			dato = s->num;
		}
		else if (s == NULL)
		{
			n = mezcla_descendente(p->liga, s, n, &(*q));
			// printf("\n [%i] ", p->num);

			dato = p->num;
		}
		else if (p->num <= s->num)
		{
			n = mezcla_descendente(p->liga, s, n, &(*q));
			// printf("\n [%i] ", p->num);

			dato = p->num;
		}

		else if (s->num < p->num)
		{
			n = mezcla_descendente(p, s->liga, n, &(*q));
			// printf("\n [%i] ", s->num);

			dato = s->num;
		}

		// ------------------------------------
		n = enlazado(n, &(*q), dato);

	}else
		printf("\n------------------------------------------------");

	return n;
}