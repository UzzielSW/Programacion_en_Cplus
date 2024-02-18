#ifndef INGRE_H
#define INGRE_H 

struct Ingre
{
	char nombreI[30];
	Ingre *sig;

	Ingre()
	{
		this->sig = NULL;
	}
};

	Ingre *add_ingre(Ingre *, char[]);
	Ingre *remove_ingre(Ingre *, char[]);
	void view_ingres(const Ingre *);
	Ingre *change_ingre(Ingre *, char[]);

	Ingre *empty(Ingre *);
// ------------------------------------------------------------------------

Ingre *empty(Ingre *p)
{
	Ingre *q;
	while (p != NULL)
	{
		q = p;
		p = p->sig;
		free(q);
	}

	printf("\n clean<< ingredientes");
	return p;
}

Ingre *add_ingre(Ingre *p, char nameIngre[30])
{
	if (p == NULL)
	{
		p = new Ingre();
		strcpy(p->nombreI , nameIngre);
	}
	else
	{
		Ingre *q = p;
		
		Ingre *nodo = new Ingre();
		strcpy(nodo->nombreI , nameIngre);

		for(; q->sig != NULL; q = q->sig);

		q->sig = nodo;
	}

	return (p);
}


Ingre *remove_ingre(Ingre *p, char nameIngre[30])
{
	if (p != NULL)
	{
		int band = 0;
		Ingre *q;

		if (strcmp(nameIngre, p->nombreI) == 0) // primer ingrediente
		{
			p = p->sig;
			band = 1;
		} 
		
		else // buscando
		{
			q = p;
			Ingre *t;

			while((band == 0) && (q != NULL))
			{
				if(strcmp(nameIngre, q->nombreI) == 0)
				{
					t->sig = q->sig;
					band = 1;
				}
				else
				{
					t = q;
					q = q->sig;
				}
			}
		}

		if (band == 0)
				printf("\n ingrediente: [%s] no esta en lista", nameIngre);
		else
		{
			free(q);
			printf("\n\tingrediente: [%s] eliminado", nameIngre);
		}
		
	}else
		printf("\n\t Lista vacia");

	return (p);
}


void view_ingres(const Ingre *p)
{
	if (p != NULL)
	{
		const Ingre *q = p;

		printf(" [ ");

		while(q->sig != NULL)
		{
			printf("%s, ", q->nombreI);
			q = q->sig;
		}

		printf("%s ]\n", q->nombreI);
	}
	else
		printf("\tlista <ingredientes> vacia");	
}


Ingre *change_ingre(Ingre *p, char name[30])
{
	if (p != NULL)
	{
		Ingre *q = p;
		int band = 0;

		if (strcmp(name, p->nombreI) == 0) // primer ingrediente
			band = 1;
		else
		{
			while(q != NULL && band == 0)
			{
				if (strcmp(name, q->nombreI) == 0)
					band = 1;
				else
					q = q->sig;
			}
		}

		if (band == 1)
		{
			char nameNew[30];

			printf("\n Editar postre>>ingrediente:\"%s\" por: ", name);
			fflush(stdin);
			scanf("%[^\n]",&nameNew);
			strcpy(q->nombreI, nameNew);
			printf("\n ready!::ingrediente modificado");
		}
		else
			printf("\n ingredienete: [%s] no esta en lista", name);
	}else
		printf("\n\tlista <ingrediente> vacia");

	return (p);
}

#endif