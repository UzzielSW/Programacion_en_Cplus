/*
	
	11. define un algoritmo para insertar elementos en una lista circular.
 */

#include <stdio.h> 
#include <stdlib.h> 

#include "help.h"

NODO *creaFinal_c();
void recorre_circular(NODO *);

// ejercicio 10
NODO *elimina_x_c(NODO *, int);

// ejercicio 11
NODO *insertarFinal_c(NODO *, int);

int main()
{
	int opc;
	NODO *p = NULL;

	do
	{	system("cls");
		printf("\n\tlista circular");
		printf("\n 1 [crear lista]");
		printf("\n 2 [insertar]");
		printf("\n 3 [eliminar x]");
		printf("\n 4 [mostrar]");
		printf("\n 5 << SALIR");
		printf("\n\n >> ");
		if (!scanf("%d", &opc)) break;

		// ---------------------------------------------------
		if (opc == 1)	p = creaFinal_c();
		
		else if(opc == 2 && p != NULL) p = insertarFinal_c(p, getData());
		
		else if(opc == 3 && p != NULL) p = elimina_x_c(p, getData());

		else  if(opc == 4 && p != NULL)
		{
			printf("\n Lista: ");
			recorre_circular(p);
		}	

		if (opc == 5) printf("\n OK");

		else
			printf("\n\topcion invalida");

		printf("\n");
		fflush(stdin);
		getchar();
	} while (opc != 5);

	return 0;
}


NODO *creaFinal_c()
{
	int i, num;
	NODO *p, *t, *q;
	
	p = creaNodo();
	
	printf("\n Introduzca un valor entero: ");
	i = scanf("%d",&num);

	if(i == 1)
	{
	 	p->num = num;
	 	p->liga = NULL;

	 	t = p;

		do
		{
		 	q = creaNodo();

		 	printf("\n Introduzca un valor entero: ");
	        i = scanf("%d",&num);
	        fflush(stdin);

	        if(i == 1)
			{ 
			    q->num = num;
				q->liga = p;
				t->liga = q;
				t = q;
			} 
			else{
				free(q);
				break;
			}
				   
		}while(i == 1);	
	}
	else
		return NULL;
   
	return p;  
} 


void recorre_circular(NODO *p)
{
	register NODO *q = p;
	
	do
	{
		printf("\n[%d]", q->num);
		q = q->liga;
	}while(q != p && q != NULL);
}


NODO *elimina_x_c(NODO *p, int x)
{
	if (p != NULL)
	{
		// DATOS
		int BAND = 1;
		NODO *q, *t;

		NODO *r;

		// ALGORITMO
		q = p;
			
		while ((q->num != x) && (BAND == 1))
		{
			if(q->liga != p)
			{
			  	t = q;
			  	q = q->liga;
			}else 
			   BAND = 0;   
		}
	      

	    if (BAND == 1)
	    {
	    	if (q == p) // eliminar el primer nodo
	    	{
	          	if (p->liga == NULL) // caso de un solo nodo
	          		p = NULL;
	          	else
	          	{
	          		r = p->liga;

	          		if (r->liga == p) // en caso de dos nodos
	          		{
	          			r->liga = NULL;
	          			p = r;
	          		}
	          		else // mas de dos
	          		{
	          			while(r->liga != p)
	          				r = r->liga;
	          			
	          			p = p->liga;
	          			r->liga = p;
	          		}
	          	}
	    	}
	        else
	            t->liga = q->liga;
		   
		   free(q);
		}
	    else
	    	printf("\n el NODO dado como referencia [x]:[%d] no fue encontrado en la lista:\n",x);
	}

	return(p);
}


NODO *insertarFinal_c(NODO *p, int dato)
{
	if (p != NULL)
	{
		NODO *q = p;
		
		NODO *nodo = creaNodo();
		nodo->num = dato;

		if(q->liga != NULL)
		{
			while(q->liga != p)
				q = q->liga;
		}

		q->liga = nodo;
		nodo->liga = p;
	}

	return p;
}