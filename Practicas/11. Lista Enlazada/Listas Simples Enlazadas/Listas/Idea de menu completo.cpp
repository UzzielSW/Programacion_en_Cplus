// Listasimples.cpp
#include <stdio.h>
#include <stdlib.h>

struct datos
{
	int num;
	struct datos *liga;
};

typedef struct datos nodo;

void *creamemoria(int n);
nodo *creanodo();
void recorrecursivo(nodo *p);
void recorreiterativo(nodo *p);
nodo *creainicio();
nodo *creafinal(nodo *p);

nodo *creadescendente(nodo *p);
nodo *crea_ascendente(nodo *p);

nodo *liberamemoria(nodo *p);

nodo *insertainicio(nodo *p, int dato);
nodo *insertafinal(nodo *p, int dato);
nodo *insertantes(nodo *p, int dato, int ref);
nodo *insertadespues(nodo *p, int dato, int ref);
nodo *eliminaprimero(nodo *p);
nodo *eliminaultimo(nodo *p);
nodo *eliminax(nodo *p, int ref);
nodo *eliminantesx(nodo *p, int ref);
void buscadesordenada(nodo *p, int ref);
void buscaordenada(nodo *p, int ref);
void buscarecursiva(nodo *p, int ref);
void reverse(nodo **x);
nodo *ordenacionburbuja(nodo *p, int n);
void ordenadesendente(nodo *p);
void ordenaasendente(nodo *p);
nodo *mezcla_lista(nodo *p, nodo *q, nodo *r, nodo *s, nodo *v, nodo *w);
void merge(nodo *p, nodo *q, nodo **s);
nodo *mergedos(nodo *p, nodo *q);
void guardarlista(nodo *p);
nodo *cargarlista(nodo *p);
void remueveduplicado(nodo *p);
void remueveduplicado_ord(nodo *p);

int main()
{

	nodo *p = NULL, *q = NULL, *r = NULL, *s = NULL;
	nodo *t = NULL, *v = NULL, *w = NULL, *z = NULL;

	int i, opcion, ref, dato, band;

	do
	{
		system("CLS");
		printf("\t\t  Listas Enlezadas");
		printf("\n\t\t  1. Creainicio \t\t\t\t2. Creafinal");
		printf("\n\t\t  3. Recorrerecursivo \t\t\t\t4. Recorreiterativo");
		printf("\n\t\t  5. Liberamemoria\t\t\t\t6. Incerta al inicio");
		printf("\n\t\t  7. Insertantes de una referencia\t\t8. Inserta despues de una referencia");
		printf("\n\t\t  9. Inserta al final\t\t\t\t10. Elimina primer nodo");
		printf("\n\t\t 11. Elimina el ultimo nodo\t\t\t12. Elimina el nodo con contenido num");
		printf("\n\t\t 13. Elimina el nodo antes otro con num\t\t14. Busqueda en lista Desordenada");
		printf("\n\t\t 15. Busqueda en lista Ordenada Ascendente\t16. Busqueda Recursiva en lista Ordenada Ascendente");
		printf("\n\t\t 17. Invertir la lista\t\t\t\t18. Ordenar Desendente");
		printf("\n\t\t 19. Ordenar Ascendente\t\t\t\t20. Crea Descendente");
		printf("\n\t\t 21. Crea Ascendente\t\t\t\t22. Mezcla de 2 listas");
		printf("\n\t\t 23. Mezcla dos listas restrigiendo los terminos comunes");
		printf("\n\t\t 24. Guarda la Lista\t\t\t\t25. Carga una Lista");
		printf("\n\t\t 26. Remueve elementos repetidos");
		printf("\n\t\t 27. Remueve elementos repetidos en una lista ordenada");
		printf("\n\t\t 28. Mezcla dos listas ascendentes");
		printf("\n\t\t 29. Salir");
		printf("\n\t\t  Cual opcion desea ?:  ");
		i = scanf("%d", &opcion);
		fflush(stdin);
		if (i != 1)
			opcion = 28;
		switch (opcion)
		{
		case 1:
			if (p != NULL)
				p = liberamemoria(p);
			p = creainicio();

			break;
		case 2:
			if (p != NULL)
				p = liberamemoria(p);
			p = creafinal(p);
			break;
		case 3:
			printf("\n\n");
			recorrecursivo(p);
			getchar();
			break;

		case 4:
			recorreiterativo(p);
			getchar();
			break;
		case 5:
			if (p != NULL)
			{
				p = liberamemoria(p);
				printf("\n\n\t\t\t Memoria de la lista Libre");
			}
			else
				printf("\n\n\t\t\t La lista esta vacia");
			getchar();
			break;
		case 6:
			if (p != NULL)
			{
				recorreiterativo(p);
				printf("Introduzca un valor entero: ");
				i = scanf("%d", &dato);
				fflush(stdin);
				if (i == 1)
				{
					p = insertainicio(p, dato);
					recorreiterativo(p);
				}
				else
					printf("\n\n\t Error");
			}
			else
				printf("\n\n\t\t La lista esta vacia");
			getchar();
			break;
		case 7:
			if (p != NULL)
			{
				recorreiterativo(p);
				printf("\n\n\tIntroduzca un valor entero: ");
				i = scanf("%d", &dato);
				fflush(stdin);
				if (i == 1)
				{
					printf("\n\n\tIntroduzca la referencia: ");
					i = scanf("%d", &ref);
					fflush(stdin);
					if (i == 1)
					{

						p = insertantes(p, dato, ref);
						recorreiterativo(p);
					}
					else
						printf("\n\n\t Error");
				}
				else
					printf("\n\n\t\t La referencia no esta en la lista");
			}
			else
				printf("\n\n\t\t La lista esta vacia");
			getchar();
			break;

		case 8:
			if (p != NULL)
			{
				recorreiterativo(p);
				printf("\n\n\tIntroduzca un valor entero: ");
				i = scanf("%d", &dato);
				fflush(stdin);
				if (i == 1)
				{
					printf("\n\n\tIntroduzca la referencia: ");
					i = scanf("%d", &ref);
					fflush(stdin);
					if (i == 1)
					{

						p = insertadespues(p, dato, ref);
						recorreiterativo(p);
					}
					else
						printf("\n\n\t Error");
				}
				else
					printf("\n\n\t\t La referencia no esta en la lista");
			}
			else
				printf("\n\n\t\t La lista esta vacia");
			getchar();
			break;

		case 9:
			if (p != NULL)
			{
				recorreiterativo(p);
				printf("\n\n\tIntroduzca un valor entero: ");
				i = scanf("%d", &dato);
				fflush(stdin);
				if (i == 1)
				{

					p = insertafinal(p, dato);
					recorreiterativo(p);
				}
				else
					printf("\n\n\t Error");
			}
			else
				printf("\n\n\t\t La lista esta vacia");
			getchar();
			break;
		case 10:
			if (p != NULL)
			{
				recorreiterativo(p);
				p = eliminaprimero(p);
				recorreiterativo(p);
			}
			else
				printf("\n\n\t\t La lista esta vacia");
			getchar();
			break;

		case 11:
			if (p != NULL)
			{
				recorreiterativo(p);
				p = eliminaultimo(p);
				recorreiterativo(p);
			}
			else
				printf("\n\n\t\t La lista esta vacia");
			getchar();
			break;

		case 12:
			if (p != NULL)
			{
				recorreiterativo(p);
				printf("\n\n\tIntroduzca el valor del nodo a eliminar: ");
				i = scanf("%d", &dato);
				fflush(stdin);
				if (i == 1)
				{

					p = eliminax(p, dato);
					recorreiterativo(p);
				}
				else
					printf("\n\n\t Error");
			}
			else
				printf("\n\n\t\t La lista esta vacia");
			getchar();
			break;
		case 13:
			if (p != NULL)
			{
				recorreiterativo(p);
				printf("\n\n\tIntroduzca el dato del nodo referencia: ");
				i = scanf("%d", &dato);
				fflush(stdin);
				if (i == 1)
				{

					p = eliminantesx(p, dato);
					recorreiterativo(p);
					getchar();
				}
				else
					printf("\n\n\t Error");
			}
			else
				printf("\n\n\t\t La lista esta vacia");
			getchar();
			break;
		case 14:
			if (p != NULL)
			{
				recorreiterativo(p);
				printf("\n\n\tIntroduzca el dato del nodo que busca: ");
				i = scanf("%d", &dato);
				fflush(stdin);
				if (i == 1)
				{

					buscadesordenada(p, dato);
					recorreiterativo(p);
				}
				else
					printf("\n\n\t Error");
			}
			else
				printf("\n\n\t\t La lista esta vacia");
			getchar();
			break;
		case 15:
			if (p != NULL)
			{
				recorreiterativo(p);
				printf("\n\n\tIntroduzca el dato del nodo que busca: ");
				i = scanf("%d", &dato);
				fflush(stdin);
				if (i == 1)
				{

					buscaordenada(p, dato);
					recorreiterativo(p);
				}
				else
					printf("\n\n\t Error");
			}
			else
				printf("\n\n\t\t La lista esta vacia");
			getchar();
			break;
		case 16:
			if (p != NULL)
			{
				recorreiterativo(p);
				printf("\n\n\tIntroduzca el dato del nodo que busca: ");
				i = scanf("%d", &dato);
				fflush(stdin);
				if (i == 1)
				{

					buscarecursiva(p, dato);
					recorreiterativo(p);
				}
				else
					printf("\n\n\t Error");
			}
			else
				printf("\n\n\t\t La lista esta vacia");
			getchar();
			break;
		case 17:
			if (p != NULL)
			{
				recorreiterativo(p);
				reverse(&p);
				recorreiterativo(p);
			}
			else
				printf("\n\n\t\t\t La lista esta vacia");
			getchar();
			break;

		case 18:
			if (p != NULL)
			{
				recorreiterativo(p);
				ordenadesendente(p);
				recorreiterativo(p);
			}

			else
			{
				printf("\n\n\t\t\t La lista esta vacia");
			}
			getchar();
			break;
		case 19:
			if (p != NULL)
			{
				recorreiterativo(p);
				ordenaasendente(p);
				recorreiterativo(p);
			}

			else
			{
				printf("\n\n\t\t\t La lista esta vacia");
			}
			getchar();
			break;
		case 20:
			if (p != NULL)
				p = liberamemoria(p);
			p = creadescendente(p);

			break;

		case 21:
			if (p != NULL)
				p = liberamemoria(p);
			p = crea_ascendente(p);
			break;
		case 22:
			if (p != NULL && q != NULL)
			{
				p = liberamemoria(p);
				q = liberamemoria(q);
			}
			printf("\n Ingrese su primera lista Ascendente");
			p = crea_ascendente(p);
			printf("\n Ingrese su segunda lista Ascendente");
			q = crea_ascendente(q);
			r = creanodo();
			r->liga = NULL;
			s = r;
			v = p;
			w = q;
			t = mezcla_lista(p, q, r, s, v, w);
			recorreiterativo(p);
			recorreiterativo(q);
			recorreiterativo(t);
			getchar();
			break;
		case 23:
			if (p != NULL && q != NULL)
			{
				p = liberamemoria(p);
				q = liberamemoria(q);
			}
			printf("\n Ingrese su primera lista Ascendente");
			p = crea_ascendente(p);
			printf("\n Ingrese su segunda lista Ascendente");
			q = crea_ascendente(q);

			merge(p, q, &z);
			recorreiterativo(p);
			recorreiterativo(q);
			recorreiterativo(z);
			getchar();
			break;

		case 24:
			guardarlista(p);
			break;

		case 25:
			p = cargarlista(p);
			break;
		case 26:

			if (p != NULL)
			{
				recorreiterativo(p);

				remueveduplicado(p);
				recorreiterativo(p);
			}
			else
				printf("\n\n\t\t La lista esta vacia");
			getchar();
			break;
		case 27:

			if (p != NULL)
			{
				recorreiterativo(p);

				remueveduplicado_ord(p);
				recorreiterativo(p);
			}
			else
				printf("\n\n\t\t La lista esta vacia");
			getchar();
			break;
		case 28: /*if ( p != NULL && q != NULL)
				   {
					 p= liberamemoria(p);
					 q= liberamemoria(q);
				  */
			printf("\n Ingrese su primera lista Ascendente");
			p = crea_ascendente(p);
			printf("\n Ingrese su segunda lista Ascendente");
			q = crea_ascendente(q);

			z = mergedos(p, q);

			recorreiterativo(p);
			recorreiterativo(q);
			recorreiterativo(z);
			remueveduplicado(z);
			p = z;
			recorreiterativo(p);

			getchar();

			/*   }
			   else printf("\n\n\t\t La lista esta vacia");
			   */
			getchar();
			break;
		case 29:
			break;
		default:
			printf("\n\n\t\t\t Opcion no valida");
			getchar();
			break;
		}

	} while (opcion != 29);
}

nodo *mergedos(nodo *p, nodo *q)
{
	nodo *t = NULL, *last = NULL;
	// verifica si la lista p o q estan vacias
	if (p == NULL)
		return p;
	if (q == NULL)
		return q;
	// ambas listas no estan vacias

	while (p != NULL && q != NULL)
	{
		if (p->num < q->num)
		{
			if (t == NULL)
				t = p;
			else
				last->liga = p;
			last = p;
			p = p->liga;
		}
		else
		{
			if (t == NULL)
				t = q;
			else
				last->liga = q;
			last = q;
			q = q->liga;
		}

	} // end while

	if (p == NULL)
		last->liga = q;
	else
		last->liga = p;
	return t;
} // fin del merge 2

void *creamemoria(int n)
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

nodo *creanodo()
{
	return (nodo *)creamemoria(sizeof(nodo));
}

void recorrecursivo(nodo *p)
{
	if (p != NULL)
	{

		printf("%5d->", p->num);
		if (p->liga != NULL)
			recorrecursivo(p->liga);
		else
			printf("%s", p->liga);
	}
	else

		printf("\n\n\t\t La lista esta vacia");
}

nodo *liberamemoria(nodo *p)
{
	nodo *q = NULL;
	while (p != NULL)
	{
		q = p;
		p = p->liga;
		free(q);
	}
	printf("\n\n\t\t La memoria ha sido liberada");
	return (p);
}

nodo *creainicio()
{
	int i, num;
	nodo *p, *q;

	p = creanodo();

	printf("\n Introduzca un valor entero: ");
	i = scanf("%d", &num);
	fflush(stdin);
	if (i == 1)
	{
		p->num = num;
		p->liga = NULL;

		do
		{
			q = creanodo();
			printf("\n Introduzca un valor entero: ");
			i = scanf("%d", &num);
			fflush(stdin);
			if (i == 1)
			{
				q->num = num;
				q->liga = p;
				p = q;
			}
			else
			{
				free(q);
				break;
			}

		} while (i == 1);
	}

	q = p;

	return p;
}

void recorreiterativo(nodo *p)
{
	nodo *q;
	if (p != NULL)
	{
		printf("\n\n");
		for (q = p; q != NULL; q = q->liga)
			printf("%5d->", q->num);
		printf("%s", q);
		printf("\n\n");
	}
	else
		printf("\n\n\t\t La lista esta vacia");

	return;
}

nodo *creafinal(nodo *p)
{
	int i, num;
	nodo *t, *q;

	p = creanodo();

	printf("\n Introduzca un valor entero: ");
	i = scanf("%d", &num);
	fflush(stdin);
	if (i == 1)
	{
		p->num = num;
		p->liga = NULL;
		t = p;
		do
		{
			q = creanodo();
			printf("\n Introduzca un valor entero: ");
			i = scanf("%d", &num);
			fflush(stdin);
			if (i == 1)
			{
				q->num = num;
				q->liga = NULL;
				t->liga = q;
				t = q;
			}
			else
			{
				free(q);
				break;
			}

		} while (i == 1);
	}

	return p;
}

nodo *insertainicio(nodo *p, int dato)
{
	nodo *q;
	q = creanodo();
	q->num = dato;
	q->liga = p;
	p = q;
	return (p);
}

nodo *insertafinal(nodo *p, int dato)
{
	nodo *q, *t;
	t = p;
	while (t->liga != NULL)
		t = t->liga;
	q = creanodo();
	q->num = dato;
	q->liga = NULL;
	t->liga = q;
	return (p);
}

nodo *insertantes(nodo *p, int dato, int ref)
{
	nodo *q, *t, *x;
	int band;

	// 1.
	q = p;
	band = 1;
	// 2.
	while (q->num != ref && band == 1)
	{
		if (q->liga != NULL)
		{
			t = q;
			q = q->liga;
		}
		else
			band = 0;

	} // 3. fin del paso 2
	  // 4.
	if (band == 1)
	{
		x = creanodo();
		x->num = dato;
		// 4.1
		if (p == q)
		{
			x->liga = p;
			p = x;
		}
		else
		{
			t->liga = x;
			x->liga = q;
		}

		return (p);
	}
	// 4.2 fin 4.1
	else
		printf("\n\n El nodo dado como referencia no esta en la lista");

	return (p);
}

nodo *insertadespues(nodo *p, int dato, int ref)
{
	nodo *q, *t;
	int band;
	// 1.
	q = p;
	band = 1;
	// 2.
	while (q->num != ref && band == 1)
	{
		// 2.1
		if (q->liga != NULL)
		{

			q = q->liga;
		}
		else
			band = 0;
		// 2.2 fin del paso 2.1
	}
	// 3 fin del paso 2.
	// 4.
	if (band == 1)
	{
		t = creanodo();
		t->num = dato;
		t->liga = q->liga;
		q->liga = t;
	}
	else
		printf("\n\n El nodo dado como referencia no esta en la lista");

	// 5. fin del paso 4

	return (p);
}

nodo *eliminaprimero(nodo *p)
{
	nodo *q;
	// 1.
	q = p;
	// 2.
	if (q->liga != NULL)
		// 2.
		p = q->liga;
	else
		p = NULL;
	// 3.
	free(q);
	return (p);
}

nodo *eliminaultimo(nodo *p)
{
	nodo *q, *t;
	// 1.
	q = p;
	// 2.
	if (p->liga == NULL)
	{
		// free(p);
		p = NULL;
	}
	else
	{ // 2.1

		while (q->liga != NULL)
		{
			t = q;
			q = q->liga;
		}
		// 2.2 fin del 2.1
		t->liga = NULL;
	}
	// 3. fin del paso 2
	// 4.
	free(q);
	return (p);
}

nodo *eliminax(nodo *p, int ref)
{

	nodo *q, *t;
	// 1.
	int BAND = 1;

	q = p;

	// 2.
	while ((q->num != ref) && (BAND == 1))
	{
		// 2.1
		if (q->liga != NULL)
		{
			t = q;
			q = q->liga;
		}
		else
			BAND = 0;
		// 2.2 fin del 2.1
	}
	// 3. fin del paso 2
	// 4.
	if (BAND == 0)
	{
		printf("\n\n El elemento no fue encontrado");
	}
	else
	{
		// 4.1
		if (p == q)
			p = q->liga;
		else
			t->liga = q->liga;
		// 4.2 fin de 4.1

		free(q);
	}
	// 5. fin del 4.
	return (p);
}

nodo *eliminantesx(nodo *p, int ref)
{
	nodo *q, *t, *r;
	int BAND;
	// 1.
	if (p->num == ref)
	{
		printf("\n\n\t\t No hay nodo que preceda a la referencia");
	}
	else
	{
		q = p;
		t = p;
		BAND = 1;
		// 1.1
		while ((q->num != ref) && (BAND == 1))
		{
			// 1.1.1
			if (q->liga != NULL)
			{
				r = t;
				t = q;
				q = q->liga;
			}
			else
				BAND = 0;
		}
		// 1.1.2 fin del 1.1.1
		// 1.2 fin del ciclo 1.1
		//  1.3
		if (BAND == 0)
		{
			printf("\n\n El elemento no fue encontrado");
		}
		else
		{ // 1.3.1
			if (p->liga == q)
			{
				p = q;
			}
			else
			{
				r->liga = q;
			}
			// 1.3.2 fin 1.3.1

			free(t);
		}
		// 1.4 fin 1.3
	}
	// 2. fin del 1.
	return (p);
}

void buscadesordenada(nodo *p, int ref)
{
	nodo *q;
	// 1.
	q = p;
	// 2.
	while ((q != NULL) && (q->num != ref))
	{
		q = q->liga;
	}
	// 3. fin del 2.
	// 4.
	if (q == NULL)
	{
		printf("\n\n\t El elemento no fue encontrado en la lista");
	}
	else
	{
		printf("\n\n\t %5d se encuentra en la lista", q->num);
	}
	// 5. fin del 4.
}

void buscaordenada(nodo *p, int ref)
{
	nodo *q;
	// 1.
	q = p;
	// 2.
	while ((q != NULL) && (q->num < ref))
	{
		q = q->liga;
	}
	// 3. fin del 2.
	// 4.
	if ((q == NULL) || (q->num > ref))
	{
		printf("\n\n\t El elemento no fue encontrado en la lista");
	}
	else
	{
		printf("\n\n\t %5d se encuentra en la lista", q->num);
	}
	// 5. fin del 4.
}

void buscarecursiva(nodo *p, int ref)
{
	// 1.
	if (p != NULL)
	{
		// 1.1
		if (p->num == ref)
			printf("\n\n\t %5d esta en la lista", p->num);
		else
			buscarecursiva(p->liga, ref);
		// 1.2 fin del 1.1
	}
	else
		printf("\n\n\t El elemento no esta en la lista");
	// 2. fin del 1.
}

void reverse(nodo **x)
{
	nodo *q, *r, *s;
	q = *x;
	r = NULL;
	/* traverse the entire linked list */
	while (q != NULL)
	{
		s = r;
		r = q;
		q = q->liga;
		r->liga = s;
	}

	*x = r;
}

/*
nodo *ordenacionburbuja(nodo *p, int cont)
{
	nodo *q,  *r;

	int i, min, temp;

	for ( i = cont;  i != 0; i = i - 1)
	   {
		 for ( q = p; q->liga != NULL; q = q->liga)
			{
				r = q->liga;
				if( q->num < r->num)
				 {
				   min = q->num;
				   q->num = r->num;
				   r->num = min;
				   temp = q->
					}
			   }
	   }
}

*/
/*
nodo *insertaordenascendente(nodo *p)
{
	nodo *t, *q;
	int i, num;
	nodo *t, *q;

	p= creanodo();

	printf("\n Introduzca un valor entero: ");
	i= scanf("%d",&num);
	fflush(stdin);
	if( i == 1)
	{
		 p->num = num;
		 p->liga = NULL;
		 t=p;
		 do
		 {
			q= creanodo();
			printf("\n Introduzca un valor entero: ");
			i= scanf("%d",&num);
			fflush(stdin);
			if( i == 1)
			  {
				q->num = num;
				while ( q->num <= )
				if( q->num < t->num)
				 {
				  q->liga = t;
				  if (p->liga == NULL)
				  {
					p=q;

				  }


				 }
				 else
					 if( q->num == t->num)
					  {
					   t->num=q->num + t->num;

					   free(q);
					   }
					   else if(  t->liga == NULL)
							 {
								t->liga = q;
								q->liga = NULL;
							 }
							 else t = t->liga;
					break;
				  }

	}while(i== 1);

   }

   return p;

}


*/

void ordenadesendente(nodo *p)
{
	int aux = 0;
	nodo *i = NULL, *j = NULL;
	i = p;
	do
	{
		for (j = p; j->liga != NULL; j = j->liga)
		{
			if (j->num <= j->liga->num)
			{
				aux = j->num;
				j->num = j->liga->num;
				j->liga->num = aux;
			}
		}
		i = i->liga;
	} while (i != NULL);
}

void ordenaasendente(nodo *p)
{

	int aux = 0;
	nodo *i = NULL, *j = NULL;

	i = p;

	do
	{
		for (j = p; j->liga != NULL; j = j->liga)
		{
			if (j->num >= j->liga->num)
			{
				aux = j->num;
				j->num = j->liga->num;
				j->liga->num = aux;
			}
		}
		i = i->liga;
	} while (i != NULL);
}

nodo *creadescendente(nodo *p)
{
	int i, band = 1, aux;

	nodo *q, *r, *t;

	p = creanodo();

	printf("\n Introduzca un numero entero (letra para terminar)");
	i = scanf("%d", &p->num);
	fflush(stdin);
	p->liga = NULL;

	if (i != 1) // 1
	{
		free(p);
		p = NULL;
		return (p);
	}
	else
	{
		do
		{
			q = creanodo();
			printf("\n Introduzca un numero entero (letra para terminar)");
			i = scanf("%d", &q->num);
			fflush(stdin);
			if (i != 1)
			{
				free(q);
				band = 0;
			}
			else // 2
			{
				if (q->num >= p->num)
				{
					q->liga = p;
					p = q;
				}
				else // 3
				{
					if (p->liga == NULL)
					{
						p->liga = q;
						q->liga = NULL;
					}
					else // 4
					{
						aux = 1;
						for (t = p; t->liga != NULL; t = t->liga)
						{
							r = t->liga;
							if ((t->num > q->num) && (q->num >= r->num))
							{
								t->liga = q;
								q->liga = r;
								aux = 0;
							}
						}
						if (aux == 1)
						{
							t->liga = q;
							q->liga = NULL;
						}
					} // fin del else 4
				}	  // fin del else 3
			}		  // fin del else 2
		} while (band == 1);
	} // fin del else 1
	return (p);
}

nodo *crea_ascendente(nodo *p)
{
	int i, band = 1, aux;

	nodo *q, *r, *t;

	p = creanodo();

	printf("\n Introduzca un numero entero (letra para terminar)");
	i = scanf("%d", &p->num);
	fflush(stdin);
	p->liga = NULL;

	if (i != 1) // 1
	{
		free(p);
		p = NULL;
		return (p);
	}
	else
	{
		do
		{
			q = creanodo();
			printf("\n Introduzca un numero entero (letra para terminar)");
			i = scanf("%d", &q->num);
			fflush(stdin);
			if (i != 1)
			{
				free(q);
				band = 0;
			}
			else // 2
			{
				if (q->num <= p->num)
				{
					q->liga = p;
					p = q;
				}
				else // 3
				{
					if (p->liga == NULL)
					{
						p->liga = q;
						q->liga = NULL;
					}
					else // 4
					{
						aux = 1;
						for (t = p; t->liga != NULL; t = t->liga)
						{
							r = t->liga;
							if ((t->num < q->num) && (q->num <= r->num))
							{
								t->liga = q;
								q->liga = r;
								aux = 0;
							}
						}
						if (aux == 1)
						{
							t->liga = q;
							q->liga = NULL;
						}
					} // fin del else 4
				}	  // fin del else 3
			}		  // fin del else 2
		} while (band == 1);
	} // fin del else 1
	return (p);
}

nodo *mezcla_lista(nodo *p, nodo *q, nodo *r, nodo *s, nodo *v, nodo *w)
{
	nodo *t;

	if (v->num <= w->num)
	{
		s->num = v->num;
		v = v->liga;
		t = creanodo();
		t->liga = s;
		s = t;
	}
	else
	{
		s->num = w->num;
		w = w->liga;
		t = creanodo();
		t->liga = s;
		s = t;
	}
	if (v != NULL && w != NULL)
	{
		t = mezcla_lista(p, q, r, s, v, w);
	}
	else
	{
		if (v == NULL)
			while (w != NULL)
			{
				t->num = w->num;
				if (w->liga != NULL)
				{
					t = creanodo();
					t->liga = s;
					s = t;
				}
				w = w->liga;
			}
		else
		{
			while (v != NULL)
			{
				t->num = v->num;
				if (v->liga != NULL)
				{
					t = creanodo();
					t->liga = s;
					s = t;
				}
				v = v->liga;
			}
		}
		return (t);
	}
}
void merge(nodo *p, nodo *q, nodo **s)
{
	nodo *z;
	z = NULL;

	/* si ambas listas estan vacia */
	if (p == NULL && q == NULL)
		return;
	/*Recorre ambas listas hasta su final. Si el fin de
	 alguna lista es alcanzado el bucle termina */

	while (p != NULL && q != NULL)
	{
		/* Si un nodo ha sido agregado como primer nodo */

		if (*s == NULL)
		{
			*s = creanodo();
			z = *s;
		}
		else
		{
			z->liga = creanodo();
			z = z->liga;
		}
		if (p->num < q->num)
		{
			z->num = p->num;
			p = p->liga;
		}
		else
		{
			if (q->num < p->num)
			{
				z->num = q->num;
				q = q->liga;
			}
			else
			{
				if (p->num == q->num)
				{
					z->num = q->num;
					p = p->liga;
					q = q->liga;
				}
			}
		}
	}

	/* Si el final de la lista no ha sido alcanzada */

	while (p != NULL)
	{
		z->liga = creanodo();
		z = z->liga;
		z->num = p->num;
		p = p->liga;
	}

	/* Si no se ha alcanzado el fin de la segunda lista */

	while (q != NULL)
	{
		z->liga = creanodo();
		z = z->liga;
		z->num = q->num;
		q = q->liga;
	}

	z->liga = NULL;
}

void guardarlista(nodo *p)
{
	nodo *q = p;
	char archivo[20];
	FILE *fp;

	printf("Introduzca el nombre del archivo");
	scanf("%s", archivo);
	fflush(stdin);
	if ((fp = fopen(archivo, "wb")) == NULL)
	{
		printf("\n No se puede habrir el archivo: %s", archivo);
		exit(1);
	}

	q = p;
	while (q != NULL)
	{

		printf("\n Guardando la lista... \n");

		fwrite(q, sizeof(nodo), 1, fp);
		q = q->liga;
	}
	fclose(fp);
}
nodo *cargarlista(nodo *p)
{
	nodo *q, *t;
	char archivo[20];

	int i, op, e;
	FILE *fp;

	printf("Introduzca el nombre del archivo que desea leer");
	scanf("%s", archivo);
	fflush(stdin);
	if ((fp = fopen(archivo, "rb")) == NULL)
	{
		printf("\n No existe el archivo: %s", archivo);
		//	exit(1);
		e = 1;
	}

	if (e != 1)
	{

		printf("\n La lista actual se elimina para cargar la del archivo");
		printf("\nDesea continuar presione el numero uno 1: ");
		scanf("%d", &op);
		fflush(stdin);

		if (op == 1)
		{
			while (p != NULL)
			{
				q = p;
				p = p->liga;
				free(q);
			}

			printf("\n Cargando la lista . . . ");

			p = creanodo();

			q = p;

			while (!feof(fp))
			{
				if (1 != fread(q, sizeof(nodo), 1, fp))
					break;
				q->liga = creanodo();
				t = q;
				q = q->liga;
			}
			t->liga = NULL;
			fclose(fp);
		}
	}

	return (p);
}

void remueveduplicado_ord(nodo *p)
{
	nodo *q, *t;

	q = p;
	t = p;

	while (q != NULL)
	{
		if ((q->liga != NULL) && q->num == q->liga->num)
		{
			t = q->liga;
			q->liga = t->liga;
			t->liga = NULL;
			free(t);
			t = p;
		}
		else
		{
			q = q->liga;
		}
	}

	q = p->liga;

	if (q != NULL)
		remueveduplicado_ord(q);
}

void remueveduplicado(nodo *p)
{
	nodo *q, *t;

	q = p;
	t = p;

	while (q != NULL)
	{
		if ((q->liga != NULL) && t->num == q->liga->num)
		{
			t = q->liga;
			q->liga = t->liga;
			t->liga = NULL;
			free(t);
			t = p;
		}
		else
		{
			q = q->liga;
		}
	}

	q = p->liga;

	if (q != NULL)
		remueveduplicado(q);
}
