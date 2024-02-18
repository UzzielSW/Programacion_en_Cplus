/* Arboles */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define V 1
#define F 0

struct datos
{

	int info;
	int fe;
	struct datos *der;
	struct datos *izq;
};

typedef struct datos arbol;

void *crea_memoria(int infor);
arbol *crea_arbol();
arbol *carga(arbol *p);
void pre_orden(arbol *p);
void in_orden(arbol *p);
void pos_orden(arbol *p);
void busqueda(arbol *p, int infor);
void busqueda1(arbol *p, int infor);
void insercio(arbol *p, int infor);
int buscarmenor(arbol *p, int menor);
int buscarmayor(arbol *p, int mayor);
void hojas(arbol *p);
arbol *inser_bal(arbol *p, int bo, int infor);
arbol *elim_bal(arbol *p, int bo, int infor);

int main(void)
{
	arbol *p = NULL;
	int bol, inf, sel, val, menor, mayor;
	char op;

	// while ( op != NULL)
	do
	{
		system("cls");
		printf("\n\t\t*_*_*_*_*_*_Menu de Opciones-*-*-*-*-*-*\n\n");
		printf("\t\t\t0.-Crea Arbol Balanceado \n\n");
		printf("\t\t\t1.-Crea Arbol\n\n");
		printf("\t\t\t2.-Ver Arbol Completo\n\n");
		printf("\t\t\t3.-Buscar \n\n");
		printf("\t\t\t4.-Buscar 1\n\n");
		printf("\t\t\t5.-Inserta \n\n");
		printf("\t\t\t6.-Inserta Balanceado\n\n");
		printf("\t\t\t7.-Eliminar Balanceado \n\n");
		printf("\t\t\t8.-Buscar Menor\n\n");
		printf("\t\t\t9.-Buscar Mayor \n\n");
		printf("\t\t\t10.-Hojas\n\n");
		printf("\t\t\t11.-Salir \n\n");
		printf("\t\t\t-Escoja su opcion:  ");
		scanf("%d", &sel);
		fflush(stdin);

		switch (sel)
		{
		case 1:
			system("cls");
			p = crea_arbol();
			p = carga(p);
			printf("\n\n\t\t Presione ENTER para continuar: ");
			getchar();
			break;

		case 2:
			system("cls");
			if (p != NULL)
			{
				printf("\n\nListado en PREORDEN\n");
				printf("\nVisita Raiz, ");
				printf("Recorre SubArbol Izquierdo ");
				printf(" y Recorre SubArbol Derecho\n\n");
				pre_orden(p);
				printf("\n\nListado en INORDEN\n");
				printf("\nRecorre SubArbol Izquierdo, ");
				printf("Visita Raiz ");
				printf(" y Recorre SubArbol Derecho\n\n");
				in_orden(p);
				printf("\n\nListado en POSORDEN\n");
				printf("\nRecorre SubArbol Izquierdo, ");
				printf(" Recorre SubArbol Derecho  ");
				printf(" y Visita Raiz \n\n");
				pos_orden(p);
			}
			else
				printf("\n\n\t\t El arbol no ha sido Cargado ");
			printf("\n\n\t\t Presione ENTER para continuar: ");
			getchar();
			break;

		case 3:
			break;
		}
	} while (sel != 3);
	return 0;
}

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

arbol *crea_arbol()
{
	return (arbol *)crea_memoria(sizeof(arbol));
}

arbol *carga(arbol *p)
{
	arbol *q;
	int infor;
	char resp;

	printf("Introduzca la informacion--->");
	scanf("%d", &infor);
	fflush(stdin);
	p->info = infor;
	printf("Hay rama por la izquierda de %d ? [s/n]--->", p->info);
	scanf("%c", &resp);
	fflush(stdin);
	if (resp == 's' || resp == 'S')
	{
		q = crea_arbol();
		p->izq = q;
		carga(p->izq);
	}
	else
		p->izq = NULL;

	printf("Hay rama por la derecha de %d ? [s/n]--->", p->info);
	scanf("%c", &resp);
	fflush(stdin);
	if (resp == 's' || resp == 'S')
	{
		q = crea_arbol();
		p->der = q;
		carga(p->der);
	}
	else
		p->der = NULL;
	return (p);
}

void pre_orden(arbol *p)
{
	if (p != NULL)
	{
		printf("[%d] ", p->info);
		pre_orden(p->izq);
		pre_orden(p->der);
	}
	return;
}
void pos_orden(arbol *p)
{
	if (p != NULL)
	{
		pos_orden(p->izq);
		pos_orden(p->der);
		printf("[%d] ", p->info);
	}
	return;
}

void in_orden(arbol *p)
{
	if (p != NULL)
	{
		in_orden(p->izq);
		printf("[%d] ", p->info);
		in_orden(p->der);
	}
	return;
}
