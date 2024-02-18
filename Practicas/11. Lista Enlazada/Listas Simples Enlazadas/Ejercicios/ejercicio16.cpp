/*
	16. Defina los algoritmos necesarios para implementar estructura tipo cola mediante listas.
 */
#include <stdio.h> 
#include <stdlib.h> 

#include "help.h"

// ejercicio 16
NODO *Mete_Cola(NODO *, int dato);
NODO *Saca_Cola(NODO *);

int main()
{
	int opc, cant;
	NODO *p = NULL;

	do
	{	system("cls");
		printf("\n\tlista <cola>");
		printf("\n 1 [mete cola]");
		printf("\n 2 [saca cola]");
		printf("\n 3 [mostrar]");
		printf("\n 4 << SALIR");
		printf("\n\n >> ");
		if (!scanf("%d", &opc)) break;

		// ---------------------------------------------------
		if (opc == 1)
		{
			printf("\n cuantos elementos desea ingresar: ");
			scanf("%d", &cant);

			for (int i = 0; i < cant; ++i)
				p = Mete_Cola(p, getData());
		}
		
		else if(opc == 2 && p != NULL) p = Saca_Cola(p);
		
		else if(opc == 3 && p != NULL)
		{
			printf("\n Cola: "); 
			recorreRecursivo(p);
		}

		if (opc == 4) printf("\n OK");

		else
			printf("\n\topcion invalida");

		printf("\n");
		fflush(stdin);
		getchar();
	} while (opc != 4);

// -----------------------------------------------------------------
	p = liberaMemoria(p);
	return 0;
}


NODO *Mete_Cola(NODO *p, int dato)
{
	NODO *nodo;

	if (p == NULL)
	{
		p = creaNodo();
		p->num = dato;
		p->liga = NULL;
	}
	else
	{
		nodo = creaNodo();
		nodo->num = dato;
		nodo->liga = NULL;

		NODO *q;

		for (q = p; q->liga != NULL; q = q->liga);

		q->liga = nodo;
	}

	return p;
}

NODO *Saca_Cola(NODO *p)
{
	if(p != NULL)
	{
		NODO *q = p;

		p = p->liga; //	MOVER AL SIGUIENTE NODO
		
		printf("\n NODO [%i] eliminado\n", q->num);
		free(q);
	}

	return(p);
}