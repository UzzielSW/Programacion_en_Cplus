#ifndef HELP_H
#define HELP_H

struct NODO
{
	int num;
	struct NODO *liga;
};

// CREAR NODO
void *creaMemoria(int n);
NODO *creaNodo();

// VACIAR LISTA
NODO *liberaMemoria(NODO *);

// RECORRER LISTA
void recorreRecursivo(NODO *);

int getData();
NODO *creaFinal();
NODO *insertar(NODO *, int n);

bool busqueda(NODO *, int);
NODO *enlazado(NODO *, NODO **, int);

// -----------------------------------------------------------------------
void *creaMemoria(int n)
{
	void *p = (int *)malloc(n);
	if (p == NULL)
	{
		puts("Lo siento no hay memoria disponible");
		getchar();
		exit(1);
	}

	return (p);
}

NODO *creaNodo() { return (NODO *)creaMemoria(sizeof(NODO)); }

NODO *creaFinal()
{
	int i, num;
	NODO *p, *t, *q;

	p = creaNodo();

	printf("\n Introduzca un valor entero: ");
	i = scanf("%d", &num);

	if (i == 1)
	{
		p->num = num;
		p->liga = NULL;

		t = p;

		do
		{
			q = creaNodo();

			printf("\n Introduzca un valor entero: ");
			i = scanf("%d", &num);
			fflush(stdin);

			if (i == 1)
			{
				q->num = num;
				q->liga = NULL;
				t->liga = q;
				t = q;
			}
			else
			{
				free(q);
				break;
			}

		} while (i == 1);
	}
	else
		return NULL;

	return p;
}

NODO *insertar(NODO *p, int num)
{
	NODO *q = creaNodo();

	q->num = num;
	q->liga = NULL;

	if (p == NULL)
		p = q;
	else
	{
		NODO *t = p;
		while (t->liga != NULL)
			t = t->liga;

		t->liga = q;
	}

	return p;
}

NODO *liberaMemoria(NODO *p)
{
	if (p != NULL)
	{
		NODO *q;

		while (p != NULL)
		{
			q = p;
			p = p->liga;
			free(q);
		}

		printf("\nLa memoria ha sido liberada");
	}

	return (p);
}

void recorreRecursivo(NODO *p)
{
	if (p != NULL)
	{
		printf("%2d-> ", p->num);

		if (p->liga != NULL)
			recorreRecursivo(p->liga);
		else
			printf("%s", p->liga);
	}
	else
		printf("\tLa lista esta vacia");
}

int getData()
{
	int num, i;
	do
	{
		printf("\n Introduzca un valor entero: ");
		i = scanf("%d", &num);
		fflush(stdin);
	} while (!i);

	return num;
}

bool busqueda(NODO *p, int dato)
{
	if (p != NULL)
	{
		NODO *q = p;

		while (q->liga != NULL && q->num != dato)
			q = q->liga;

		if (q->num == dato)
			return true;
	}

	return false;
}

NODO *enlazado(NODO *p, NODO **q, int dato)
{
	if (p == NULL)
	{
		p = creaNodo();
		p->liga = NULL;
		p->num = dato;
		*q = p;
	}
	else
	{
		NODO *nodo = creaNodo();
		nodo->liga = NULL;
		nodo->num = dato;
		(*q)->liga = nodo;
		*q = nodo;
	}

	return (p);
}

#endif