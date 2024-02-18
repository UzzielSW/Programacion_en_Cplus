#ifndef HELP_H
#define HELP_H

struct Arbol
{
	int info;
	int fe; // factor de equilibrio
	Arbol *der;
	Arbol *izq;

	Arbol()
	{
		this->der = NULL;
		this->izq = NULL;
	};
};

// funciones de crea
void *crea_memoria(int n);
Arbol *crea_Arbol();
Arbol *crear_arbol();

// recorridos
void pre_orden(Arbol *p);
void pos_orden(Arbol *p);
void in_orden(Arbol *p);
void Graf(Arbol *p, int cont);

// busqueda
#include "busqueda.h"

// insercion
#include "insercion.h"

// eliminacion
#include "eliminacion.h"

// ----------------------------------------------------------------
void *crea_memoria(int n)
{
	void *p = (int *)malloc(n);
	if (p == NULL)
	{
		puts("LO siento no hay memoria disponible");
		getchar();
		exit(1);
	}

	return (p);
}

Arbol *crea_Arbol() { return (Arbol *)crea_memoria(sizeof(Arbol)); }

void pre_orden(Arbol *p)
{
	if (p != NULL)
	{
		printf("[%d] ", p->info);
		pre_orden(p->izq);
		pre_orden(p->der);
	}
	return;
}

void pos_orden(Arbol *p)
{
	if (p != NULL)
	{
		pos_orden(p->izq);
		pos_orden(p->der);
		printf("[%d] ", p->info);
	}
	return;
}

void in_orden(Arbol *p)
{
	if (p != NULL)
	{
		in_orden(p->izq);
		printf("[%d] ", p->info);
		in_orden(p->der);
	}
	return;
}

void Graf(Arbol *p, int cont)
{
	if (p != NULL)
	{
		Graf(p->der, cont + 1);

		for (int i = 0; i < cont; ++i)
			printf("   ");

		printf("%d\n", p->info);

		Graf(p->izq, cont + 1);
	}

	return;
}

Arbol *crear_arbol()
{
	int info;
	char resp;

	Arbol *p = new Arbol();

	printf(" Dato: ");
	scanf("%d", &p->info);
	fflush(stdin);

	printf(" Desea rama por la izquierda de %d [s/n]?\n =>> ", p->info);
	scanf("%c", &resp);
	fflush(stdin);

	if (resp == 's' || resp == 'S')
		p->izq = crear_arbol();

	printf(" Desea rama por la derecha de %d [s/n]?\n =>> ", p->info);
	scanf("%c", &resp);
	fflush(stdin);

	if (resp == 's' || resp == 'S')
		p->der = crear_arbol();

	return (p);
}

#endif