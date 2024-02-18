/* Arboles */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define V 1
#define F 0

struct Arbol
{
    int info;
    int fe;
    struct datos *der;
    struct datos *izq;
};

void *crea_memoria(int);
Arbol *crea_Arbol();
Arbol *add(Arbol *);
void pre_orden(Arbol *);
void in_orden(Arbol *);
void pos_orden(Arbol *);
void busqueda(Arbol *, int info);
void busqueda1(Arbol *, int info);
void insercio(Arbol *, int info);
int buscarmenor(Arbol *, int menor);
int buscarmayor(Arbol *, int mayor);
void hojas(Arbol *);
Arbol *inser_bal(Arbol *, int bo, int info);
Arbol *elim_bal(Arbol *, int bo, int info);

int main(void)
{
    Arbol *p = NULL;
    int bol, inf, sel, val, menor, mayor;
    char op;

    do
    {
        system("cls");
        printf("\n\t\toperaciones basicas con arboles");
        printf("\n\t1.ingresar datos");
        printf("\n\t2.ver arbo");
        printf("\n\t3.buscar");
        printf("\n\t4.buscar 1");
        printf("\n\t5.insertar");
        printf("\n\t6.inserta balanceado");
        printf("\n\t7.eliminar datos");
        printf("\n\t8.buscar menor");
        // printf("\n\t9.eliminar datos");
        printf("\n\t10.hojas");
        printf("\n\t11.SALIR ");
        printf("\n\topc:>> ");
        scanf("%d", &opc);
        fflush(stdin);

        // -------------------------------------------------------------------
        if (opc == 1)
        {
            p = crea_Arbol();
            p = add(p);
            printf("\n\n\t\t Presione ENTER para continuar: ");
            getchar();
        }
        else if (opc == 2)
        {
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
        }
        else
            printf("\n opcion no disponible");

        // --------------------------------------------------------------------
        printf("\n");
        getchar();
        fflush(stdin);
    } while (opc != 11);

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

Arbol *crea_Arbol() { return (Arbol *)crea_memoria(sizeof(Arbol)); }

Arbol *add(Arbol *p)
{
    Arbol *q;
    int info;
    char resp;

    printf("Introduzca la infomacion--->");
    scanf("%d", &info);
    fflush(stdin);
    p->info = info;

    printf("Hay rama por la izquierda de %d ? [s/n]--->", p->info);
    scanf("%c", &resp);
    fflush(stdin);

    if (resp == 's' || resp == 'S')
    {
        q = crea_Arbol();
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
        q = crea_Arbol();
        p->der = q;
        carga(p->der);
    }
    else
        p->der = NULL;

    return (p);
}

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