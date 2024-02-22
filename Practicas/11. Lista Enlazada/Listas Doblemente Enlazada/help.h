#ifndef HELP_H
#define HELP_H

// ESTRUCTURA
struct NODO
{
	int num;
	struct NODO *izq;
	struct NODO *der;
};

// CREAR NODO
void *creaMemoria(int n);
NODO *creaNodo();
int getData();

// RECORRIDO
void recorreIterativo(NODO *, NODO *);
void recorreIterativo(NODO *);
void recorreRecursivo(NODO *);

// VACIAR LISTA
NODO *liberaMemoria(NODO *, NODO **);

// CREAR NODO
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

// RECORRIDOS

void recorreIterativo(NODO *p, NODO *f)
{
	if (p != NULL && f != NULL)
	{
		// ADELANTE
		NODO *q = p;
		printf("\n [%s,", q->izq);

		for (; q != NULL; q = q->der)
			printf("%2d,", q->num);

		printf("%s]", q);

		// INVERSO
		q = f;
		printf("\n [%s,", q->der);

		for (; q != NULL; q = q->izq)
			printf("%2d,", q->num);

		printf("%s]", q);
	}
	else
		printf("\n\tLa lista esta vacia");
}

void recorreIterativo(NODO *p)
{
	if (p != NULL)
	{
		NODO *q = p;
		printf("\n [");

		for (; q != NULL; q = q->der)
			printf("%2d,", q->num);

		printf("]");
	}
	else
		printf("\n\tLa lista esta vacia");
}

void recorreRecursivo(NODO *p)
{
	if (p != NULL)
	{
		if (p->izq == NULL)
			printf(" %s", p->izq);

		printf("%2d <=> ", p->num);

		if (p->der != NULL)
			recorreRecursivo(p->der);
		else
			printf("%s \n", p->der);
	}
	else
		printf("\n\t\tLa lista esta vacia");

	return;
}

// VACIAR LISTA
NODO *liberaMemoria(NODO *p, NODO **f)
{
	if (p == NULL)
		return p; // VALIDANDO

	*f = NULL;

	NODO *q;

	while (p != NULL)
	{
		q = p;
		p = p->der;
		free(q);
	}

	printf("\n\n\tLa memoria ha sido liberada");

	return (p);
}

#endif