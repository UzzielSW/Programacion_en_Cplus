#include <stdio.h> 
#include <stdlib.h> 

#include "help.h"
#include "algorithm.h"

void busqueda_x_doble(const NODO *, const NODO *, int x); // ejercicio 9
void recorreRecursivo_doble(const NODO *, const NODO *); // ejercicio 13
NODO *inserta_despues_x(NODO *, NODO **, int x, int dato); //ejercicio 14

int main()
{
	NODO *p = NULL, *f = NULL;


	for (int i = 0; i < 6; ++i)
		p = inserta_inicio(p, &f, getData());
	recorreRecursivo(p);

	// busqueda_x_doble(p, f, 3);
	// busqueda_x_doble(p, f, 5);
	// busqueda_x_doble(p, f, 10);
	busqueda_x_doble(p, f, 20);

	// recorreRecursivo_doble(p, f);

	// p = inserta_despues_x(p, &f, 6, 7);
	
	printf("\n");
	recorreRecursivo(p);
	// ----------------------------------
	p = liberaMemoria(p, &f);
	fflush(stdin);
	getchar();
	return 0;
}


void busqueda_x_doble(const NODO *p,const NODO *f, int x)
{
	if (p != NULL && f != NULL)
	{
		if (p->num == x || f->num == x)
			printf("\n Elemento [%d] encontrado", x);
		else if(p == f || p->der == f)
			printf("\n Elemento [%d] no se encontro en la lista",x);
		else
			busqueda_x_doble(p->der, f->izq, x);
	}

	return;
}

void recorreRecursivo_doble(const NODO *p, const NODO *f)
{
	if (p != NULL && f != NULL)
	{
		printf("\n [%d] [%d]", p->num, f->num);
		recorreRecursivo_doble(p->der, f->izq);
	}else
		printf("\n\t\tLa lista esta vacia");

	return;
}


NODO *inserta_despues_x(NODO *p, NODO **f, int x, int dato)
{
	static int band = 1;

	if (band == 1 && p != NULL && *f != NULL)
	{
		if (p->num == x || (*f)->num == x)
		{
			NODO *q = creaNodo();
			q->num = dato;

			if (p->num == x) // si lo encuentra p
			{
				NODO *t = p->der;

				q->der = t;
				q->izq = p;
				t->izq = q;
				p->der = q;
			}
			else // si lo encuentra f
			{
				if((*f)->der == NULL) // si es el ultimo nodo
				{
					q->der = NULL;
					q->izq = *f;
					(*f)->der = q;
					*f = q;
				}
			}
			
			band = 0;
		
		}else if (p == *f)
		{
			printf("\n NODO [%d] dado como referencia no se encontro en la lista\n", x);
			band = 0;
		}else
			p->der = inserta_despues_x(p->der, &(*f), x, dato);
	}else
		printf("\n\t\tLa lista esta vacia");

	return p;
}