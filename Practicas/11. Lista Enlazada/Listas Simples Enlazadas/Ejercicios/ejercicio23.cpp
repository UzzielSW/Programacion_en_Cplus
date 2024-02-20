/*
    23.Considere que se tiene una lisa de numeros enteros, ordenados crecientemente, como la que se muestra a continuacion. Observe que faltan algunos numeros para tener todos los valores comprendidos entre el primero 12 y el ultimo 18. Escriba un programa que "complete" la lista, de tal manera que la misma, una vez modificada, almacene todos los valores a partir de numero del primer nodo hasta el numero del ultimo. Para el ejemplo, la lista guardara los numeros 12, 13, 14, 15, 16, 17, 18.

    Ejemplo:
    P-> | 12 | 13 | 15 | 18 |

    Lista resultante:
    L-> | 12 | 13 | 14 | 15 | 16 | 17 | 18 |
 */
#include <stdio.h>
#include <stdlib.h>
#include "help.h"

NODO *completa_lista(NODO *);              // ejercicio 23
int main()
{
    NODO *p = NULL;
    int valores[] = {12, 13, 15, 18};

    for (int i = 0; i < 4; i++)
        p = insertar(p, valores[i]);

    system("cls");
    printf("\n Lista inicial: ");
    recorreRecursivo(p);

    printf("\n\n Completando lista... ");
    p = completa_lista(p);

    printf("\n\n Lista final: ");
    recorreRecursivo(p);

    p = liberaMemoria(p);
    return 0;
}

NODO *completa_lista(NODO *p)
{
    NODO *q = p;
    int nextValue = 0;

    while (q->liga != NULL)
    {
        nextValue = q->num + 1;

        if (nextValue != q->liga->num)
        {
            NODO *nodo = creaNodo();
            nodo->num = nextValue;
            nodo->liga = q->liga;
            q->liga = nodo;
        }

        q = q->liga;
    }

    return (p);
}