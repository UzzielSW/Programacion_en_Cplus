#ifndef HELPL_H
#define HELPL_H 

struct Lista
{
	Polinomio *e;
	Lista *liga;
	Lista()
	{
		this->e = NULL;
		this->liga = NULL;
	};
};

	Lista *add(Lista *);
	Lista *pop(Lista *);

	int len(Lista *);
	Lista *pop(Lista *, int);
	
	void view(const Lista *);

	Polinomio *get_element(Lista *, int);
	Polinomio **get_element2(Lista **, int);

	Lista *empty(Lista *p);
	
// ---------------------------------------------------------------
Lista *add(Lista *p)
{
	if (p == NULL)
	{
		p = new Lista();
		p->e = leer_polinomio();
	}
	else
	{
		Lista *q;
		
		for(q = p; q->liga != NULL; q = q->liga);
		
		Lista *nodo = new Lista();
		nodo->e = leer_polinomio();

		q->liga = nodo;
	}

	return p;
}


Lista *pop(Lista *p)
{
	if (p != NULL)
	{
		Lista *q = p;

		if (q->liga == NULL) // SI HAY UN SOLO ELEMENTO
			p = NULL;
		else
		{
			Lista *t;
			while(q->liga != NULL) // MOVERSE HASTA EL ULTIMO ELEMENTO
			{
				t = q;
				q = q->liga;
			}

			t->liga = NULL;
		}

		printf("\n Elemento eliminado\n");
		free(q);
	}else
		printf("\n\t Lista vacia");

	return(p);
}


Lista *pop(Lista *p, int n)
{
	if(p != NULL)
	{
		if (0 < n && n <= len(p)) // posicion en rango
		{
			if(n == len(p)) // ultimo
				p = pop(p);
			else
			{	
				Lista *q = p;

				if (n == 1) // primero
					p = p->liga;
				
				else // buscando
				{
					int i = 1;
					Lista *t;

					for(; i <= n; i++)
					{
						t = q;
						q = q->liga;
					}

					t->liga = q->liga;
				}

				free(q);
			}

			printf("\n\tElemento eliminado");
		}
		else
			printf("\n posicion fuera de rango");
	}else
		printf("\n\t Lista vacia");

	return p;
}

int len(Lista *p)
{
	if (p == NULL)
		return 0;
	else
	{
		int i = 1;
		register Lista *q = p;
		for(; q->liga != NULL; q = q->liga) i++;

		return i;
	}
}


void view(const Lista *p)
{
	if (p != NULL)
	{
		printf("\n\t\t.:listado de polinomios:.\n");
		printf("----------------------------------------------------------------------------------------------");
		int i=1;

		for(const Lista *q = p; q != NULL; q = q->liga, i++)
		{
			printf("\n |#%d| {",i);
			recorre_iterativo(q->e);
			printf(" }__{"); imprimir(q->e); printf("}");
		}
		printf("\n----------------------------------------------------------------------------------------------\n");
	}
	else
		printf("\n\tlista vacia");
}


Polinomio *get_element(Lista *p, int n)
{
	int i = 1;
	Lista *q = p;

	while(q->liga != NULL && i != n)
	{
		i++;
		q = q->liga;
	}

	if (i == n)
		return (q->e);
	else
		return NULL;
}

//funciona pero mueve el puntero inicial al siguiente
// Polinomio **get_element2(Lista **p, int n)
// {
// 	int i = 1;
// 	Lista **q = &(*p);

// 	while((*q)->liga != NULL && i != n)
// 	{
// 		i++;
// 		(*q) = (*q)->liga;
// 	}

// 	return &((*q)->e);
// }

//test //funcionando
Polinomio **get_element2(Lista **p, int n)
{
	int i = 1;
	Lista *q = *p;

	while((q)->liga != NULL && i != n)
	{
		i++;
		(q) = (q)->liga;
	}

	return &((q)->e);
}



Lista *empty(Lista *p)
{
	if (p != NULL)
	{
		Lista *q;

		while(p != NULL)
		{
			q = p;
			p = p->liga;
			free(q);	
		}

		printf("\n\tSe vacio la lista");	
	}
	else
		printf("\n\tlista vacia");

	return(p);
}

#endif