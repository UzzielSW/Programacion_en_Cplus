#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#include "ingre.h"
#include "postre.h"

/* ejercicio 17:
    * nombre de los postres ordenados alfabeticamente.
        cada postre tiene su lista de ingredientes que requiere el postre.

    1) dado el nombre de un postre, imprima la lista de ingredientes.
    2) dado el nombre de un postre, inserte nuevos ingredientes.
    3) dado el nombre de un postre, elimine alguno de sus ingredientes.
    4) dar de baja algun postre con todos sus ingredientes.
*/

int main()
{
    Postre *postre = NULL;
    Ingre *q;
    char nombre[30];
    int opc, res;

    do
    {
        system("cls");
        printf("\n\t\t<menu postre> by @{ B.Puyol 8-944-708 }");
        printf("\n 1 [agregar postre a la lista]");
        printf("\n 2 [imprimir lista de postres]");
        printf("\n 3 [imprimir lista de ingredientes de un postre]");
        printf("\n 4 [insertar nuevos ingredientes a un postre]");
        printf("\n 5 [eliminar ingredientes de un postre]");
        printf("\n 6 [eliminar postre de la lista]");
        printf("\n 7 [editar postre]");
        printf("\n 8 [editar ingrediente]");
        printf("\n 9 !SALIR!");
        printf("\n\nopc:>> ");
        if (scanf("%d", &opc))
            fflush(stdin);
        else
            break;
        // -------------------------------------------------------------------
        if (opc == 1) // agregar postre a la lista
        {
            printf("\n Nombre del Postre: ");
            scanf("%[^\n]", &nombre);

            postre = add_postre(postre, nombre);
        }

        else if (opc == 2 && postre != NULL)
        {
            printf("\n Postres: ");
            view_postres(postre);
        }

        else if (opc == 3 && postre != NULL) // imprimir lista de ingredientes de un postre
        {
            printf("\n Nombre del Postre: ");
            scanf("%[^\n]", &nombre);

            postre = search_postre(postre, nombre);
        }

        else if (opc == 4 && postre != NULL) // insertar nuevos ingredientes a un postre
        {
            printf("\n Nombre del Postre: ");
            scanf("%[^\n]", &nombre);

            postre = search_postre(postre, nombre, 2);
        }

        else if (opc == 5 && postre != NULL) // eliminar un ingrediente de un postre
        {
            printf("\n Nombre del Postre: ");
            scanf("%[^\n]", &nombre);

            postre = search_postre(postre, nombre, 3);
        }

        else if (opc == 6 && postre != NULL) // eliminar postre de la lista
        {
            printf("\n Eliminar:\n 1 [vaciar]\n 2 [one]");
            scanf("%d", &res);

            if (res == 1)
                postre = empty(postre);
            else
            {
                printf("\n Nombre del Postre: ");
                scanf("%[^\n]", &nombre);

                postre = remove_postre(postre, nombre);
            }
        }

        else if (opc == 7 && postre != NULL)
        {
            printf("\n Nombre del Postre: ");
            scanf("%[^\n]", &nombre);

            postre = change_postre(postre, nombre);
        }

        else if (opc == 8 && postre != NULL)
        {
            printf("\n Nombre del Postre: ");
            scanf("%[^\n]", &nombre);

            postre = search_postre(postre, nombre, 4);
        }

        else if (opc == 9)
            printf("\nbye");

        else
            printf("\n\t opcion no valida");

        // -------------------------------------------------------------------
        printf("\n");
        fflush(stdin);
        getchar();
    } while (opc != 9);

    return 0;
}