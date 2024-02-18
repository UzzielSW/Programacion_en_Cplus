#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "help.h"

int cal_altura(Arbol *p, int altura)
{
    int Max, Mder, Mizq;
    if (p == NULL)
        return altura;
    else
    {
        altura++;
        Mder = cal_altura(p->der, altura);
        Mizq = cal_altura(p->izq, altura);
        if (Mder > Mizq)
            Max = Mder;
        else
            Max = Mizq;
    }
    return Max;
}

int cal_longitud(Arbol *p, int x, int longitud)
{
    int lon = 0;
    if (p == NULL)
    {
        printf("\nNo se encontro el nodo x");
        return -1;
    }
    else
    {
        longitud++;
        if (x < p->info)
            lon = cal_longitud(p->izq, x, longitud);
        else if (x > p->info)
            lon = cal_longitud(p->der, x, longitud);
        else
        {
            printf("\nnodo x encontrado");
            return longitud;
        }
    }
    return lon;
}

int main()
{
    Arbol *raiz = NULL;
    int opc, info, lon;
    char resp;
    char op;

    do
    {
        system("cls");
        printf("\n\t\toperaciones basicas con arboles");
        printf("\n 1.crear ABB");
        printf("\n 2.ver arbol [recorridos]");
        printf("\n 3.ver arbol [grafico]");
        printf("\n 4.busqueda ABB");
        printf("\n 5.insercion ABB");
        printf("\n 6.eliminacion ABB");
        printf("\n 7.altura ABB");
        printf("\n 8.logitud de camino de nodo X");
        // printf("\n .Buscar Mayor");
        // printf("\n .Buscar Menor");
        // printf("\n .Hojas");
        printf("\n-----------------------------------------------------\n");
        // printf("\n .crear AVL");
        // printf("\n .insercion AVL");
        // printf("\n .eliminacion AVL ");

        printf("\n 11. !SALIR!");
        printf("\n opc:>> ");
        scanf("%d", &opc);
        fflush(stdin);

        // ------------------------------------------------------------------

        if (opc == 1)
        {
            if (raiz == NULL)
                raiz = crear_arbol();
            else
                printf("\n\tarbol creado");
        }

        else if (opc == 2 && raiz != NULL)
        {
            printf("\n\nListado en PREORDEN\n");
            printf("\nVisita Raiz, ");
            printf("Recorre SubArbol Izquierdo ");
            printf(" y Recorre SubArbol Derecho\n\n");
            pre_orden(raiz);

            printf("\n\nListado en INORDEN\n");
            printf("\nRecorre SubArbol Izquierdo, ");
            printf("Visita Raiz ");
            printf(" y Recorre SubArbol Derecho\n\n");
            in_orden(raiz);

            printf("\n\nListado en POSORDEN\n");
            printf("\nRecorre SubArbol Izquierdo, ");
            printf(" Recorre SubArbol Derecho  ");
            printf(" y Visita Raiz \n\n");
            pos_orden(raiz);
        }

        else if (opc == 3 && raiz != NULL)
            Graf(raiz, 0);

        else if (opc == 4 && raiz != NULL)
        {
            printf("\n buscar info: ");
            scanf("%d", &info);
            busqueda_ABB(raiz, info);
        }

        else if (opc == 5 && raiz != NULL)
        {
            printf("\n insertar info: ");

            do
            {
                printf("\n :>> ");
                scanf("%d", &info);

                raiz = insercion_ABB(raiz, info);

                printf("\n desea seguir insertando: (s/n)\n >> ");
                fflush(stdin);
                scanf("%c", &resp);

            } while (resp == 's' || resp == 'S');
        }

        else if (opc == 6 && raiz != NULL)
        {
            printf("\n Eliminar: ");
            scanf("%d", &info);
            raiz = eliminacion_ABB(raiz, info);
        }

        else if (opc == 7 && raiz != NULL)
            printf("\n altura: %d", cal_altura(raiz, 0));

        else if (opc == 8 && raiz != NULL)
        {
            printf("\n buscar nodo x: ");
            scanf("%d", &info);
            lon = cal_longitud(raiz, info, 0);

            if (lon != -1)
                printf("\n Longitud: %d", lon);
        }
        else if (opc == 11)
            printf("\nbye");
        else
            printf("\n\topcion no valida");

        // --------------------------------------------------------------------
        printf("\n");
        fflush(stdin);
        getchar();
    } while (opc != 11);

    return 0;
}