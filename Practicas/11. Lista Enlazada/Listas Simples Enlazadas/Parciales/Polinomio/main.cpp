#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "helpP.h"
#include "helpL.h"
#include "helpO.h"

void menuMod(Polinomio **);
Lista *menuOpe(Lista *);

// por terminar:
// menu de lista
//  guardar en archivo
// menu de modificaciones
// funcion ordenar en modo change

int main()
{
    Lista *lista = NULL;
    Polinomio **q;
    int opc, res;

    do
    {
        system("cls");
        printf("\n\t\t<menu lista> by @{ B.Puyol 8-944-708 }");
        printf("\n 1 [agregar nuevo polinomio]");
        printf("\n 2 [eliminar elemento]");
        printf("\n 3 [mostrar lista]");
        printf("\n 4 [modificar elemento]");
        printf("\n 5 [operaciones]");
        printf("\n 6 !SALIR!");
        printf("\n\nopc:>> ");
        if (!scanf("%d", &opc))
            break;

        // -------------------------------------------------------------------
        if (opc == 1)
        {
            printf("\n nuevo polinomio a la lista\n");
            lista = add(lista);
        }

        else if (opc == 2 && lista != NULL)
        {
            printf("\n opcion de eliminacion: \n 1 [ultimo]\n 2 [por # en lista]\n 3 [<<back]\n :> ");
            scanf("%d", &res);

            if (res == 1)
                lista = pop(lista);
            else if (res == 2)
            {
                view(lista);
                printf("\n # en lista: ");
                scanf("%d", &res);
                lista = pop(lista, res);
            }
            else
                printf("\n OK");
        }

        else if (opc == 3)
            view(lista);

        else if (opc == 4 && lista != NULL) // modificaciones
        {
            view(lista);
            printf("\n # de elemento: ");
            scanf("%d", &res);

            if (0 < res && res <= len(lista)) // si esta en rango
            {
                // buscar al nodo especifico a modificar
                q = get_element2(&lista, res);
                menuMod(&(*q));
            }
            else
                printf("\n\t fuera de rango");
        }

        else if (opc == 5 && lista != NULL) // operaciones
            lista = menuOpe(lista);

        else if (opc == 6)
            printf("\n out");

        else
            printf("\n\t opcion no valida");

        // -------------------------------------------------------------------
        printf("\n");
        fflush(stdin);
        getchar();
    } while (opc != 6);
    return 0;
}

void menuMod(Polinomio **q)
{
    int opc, i;
    int coe, gra;

    do
    {
        system("cls");
        printf("\n\t\t<menu lista>>(accion) modificar");
        printf("\n\n\t Polinomio: ");
        imprimir(*q);
        printf("\n\n 1 [insertar elemento]");
        printf("\n 2 [eliminar elemento]");
        printf("\n 3 [corregir elemento]");
        printf("\n 4 <<(BACK)");
        printf("\n\nopc:>> ");
        if (!scanf("%d", &opc))
            break;

        // ---------------------------------------------------------
        if (opc == 1)
        {
            printf("\n ingrese datos de nuevo elemento: ");
            printf("\n coeficiente: ");
            i = scanf("%d", &coe);
            printf(" grado: ");
            scanf("%d", &gra);

            if (coe != 0 && i != 0)
                *q = insertar_in(*q, coe, gra);
        }
        else if (opc == 2 && *q != NULL)
        {
            printf("\n ingrese datos del elemento: ");
            printf("\n coeficiente: ");
            i = scanf("%d", &coe);
            printf(" grado: ");
            scanf("%d", &gra);

            if (coe != 0 && i != 0)
                *q = eliminar(*q, coe, gra);
        }
        else if (opc == 3 && *q != NULL)
            *q = change(*q);

        else if (opc == 4)
            printf("\n OK");

        else
            printf("\n opcion invalida");

        // ---------------------------------------------------------
        printf("\n");
        fflush(stdin);
        getchar();
    } while (opc != 4);

    return;
}

Lista *menuOpe(Lista *lista)
{
    int opc, res;
    float dato, result;
    Polinomio *p = NULL, *p2 = NULL;
    Polinomio *pd; // derivada
    Polinomio *ps; // suma
    Polinomio *pr; // resta
    Polinomio *pm; // multiplicacion

    do
    {
        system("cls");
        printf("\n\t\t<menu lista>>(accion) operaciones");
        printf("\n 1 [evaluar]");
        printf("\n 2 [reducir]");
        printf("\n 3 [derivar]");
        printf("\n 4 [sumar  ]");
        printf("\n 5 [restar ]");
        printf("\n 6 [multiplicar]");
        printf("\n 7 [integrar]");
        printf("\n 8 <<(BACK)");
        printf("\n\nopc:>> ");
        if (!scanf("%d", &opc))
            break;
        // ---------------------------------------------------------

        if (opc == 1) // evaluar
        {
            view(lista);
            printf("\n # de elemento: ");
            p = get_element(lista, getd());

            if (p != NULL)
            {
                printf("\n ingrese valor (x) a evaluar el Polinomio: ");
                result = evalua_polinomio_i(p, getf());
                printf("\n resultado: %.2f", result);
            }
            else
                printf("\n elemento vacio");
        }
        else if (opc == 2) // reducir
        {
            view(lista);
            printf("\n # de elemento: ");
            p = get_element(lista, getd());

            if (p != NULL)
            {
                p = reduce_polinomio(p);
                printf("\n >> ");
                recorre_iterativo(p);
            }
            else
                printf("\n elemento vacio");
        }
        else if (opc == 3) // derivar
        {
            view(lista);
            printf("\n # de elemento: ");
            p = get_element(lista, getd());

            if (p != NULL)
            {
                printf("\n opcion de derivar: \n 1 [of => of]\n 2 [of => other]\n 3 [<<back]\n :> ");
                scanf("%d", &res);

                if (res == 1)
                {
                    p = derivar_polinomio(p);
                    printf("\n >> ");
                    recorre_iterativo(p);
                }
                else if (res == 2)
                {
                    pd = derivar_polinomio_of(p);
                    printf("\n >> ");
                    recorre_iterativo(pd);
                }
                else
                    printf("\n OK");
            }
            else
                printf("\n elemento vacio");
        }
        else if (opc == 4) // sumar
        {
            view(lista);
            printf("\n # de elemento: ");
            p = get_element(lista, getd());

            if (p != NULL)
            {
                printf("\t?OK");
                printf("\n # de elemento: ");
                p2 = get_element(lista, getd());

                if (p2 != NULL)
                {
                    printf("\t?OK ready bro!");
                    ps = sumar_polinomios_of(p, p2);
                    printf("\n >> ");
                    recorre_iterativo(ps);
                }
                else
                    printf("\n elemento vacio");
            }
            else
                printf("\n elemento vacio");
        }
        else if (opc == 5) // restar
        {
            view(lista);
            printf("\n # de elemento: ");
            p = get_element(lista, getd());

            if (p != NULL)
            {
                printf("\t?OK");
                printf("\n # de elemento: ");
                p2 = get_element(lista, getd());

                if (p2 != NULL)
                {
                    printf("\t?OK");
                    pr = restar_polinomios_of(p, p2);
                    printf("\n >> ");
                    recorre_iterativo(pr);
                }
                else
                    printf("\n elemento vacio");
            }
            else
                printf("\n elemento vacio");
        }
        else if (opc == 6) // multiplicar
        {
            view(lista);
            printf("\n # de elemento: ");
            p = get_element(lista, getd());

            if (p != NULL)
            {
                printf("\t?OK");
                printf("\n # de elemento: ");
                p2 = get_element(lista, getd());

                if (p2 != NULL)
                {
                    printf("\t?OK");
                    pm = multiplicar_polinomios(p, p2);
                    printf("\n >> ");
                    recorre_iterativo(pm);
                }
                else
                    printf("\n elemento vacio");
            }
            else
                printf("\n elemento vacio");
        }
        else if (opc == 7) // integrar
        {
            view(lista);
            printf("\n # de elemento: ");
            p = get_element(lista, getd());

            if (p != NULL)
            {
                printf("\n >> ");
                integrar(p);
            }
            else
                printf("\n elemento vacio");
        }
        else if (opc == 8)
            printf("\n\tOK");

        else
            printf("\n\topcion invalida");

        // ---------------------------------------------------------
        printf("\n");
        fflush(stdin);
        getchar();
    } while (opc != 8);

    return lista;
}