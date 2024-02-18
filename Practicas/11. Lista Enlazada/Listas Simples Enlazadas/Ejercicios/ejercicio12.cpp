/*
	12. escribe un programa "mete_pila", "saca_pila", para insertar
	y eliminar, un elemento de una pila implementada pór una lista.
 */
#include <stdio.h> 
#include <stdlib.h> 

#include "help.h"

// ejercicio 12
NODO *Mete_Pila(NODO *, int dato);
NODO *Saca_Pila(NODO *);

int main()
{
	int opc, cant;
	NODO *p = NULL;

	do
	{	system("cls");
		printf("\n\tlista <pila>");
		printf("\n 1 [mete pila]");
		printf("\n 2 [saca pila]");
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
				p = Mete_Pila(p, getData());
		}
		
		else if(opc == 2 && p != NULL) p = Saca_Pila(p);
		
		else if(opc == 3 && p != NULL)
		{
			printf("\n Pila: "); recorreRecursivo(p);
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
	fflush(stdin);
	getchar();
	return 0;
}


NODO *Mete_Pila(NODO *p, int dato)
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
		nodo->liga = p;
		p = nodo;
	}

	return (p);
}

NODO *Saca_Pila(NODO *p)
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