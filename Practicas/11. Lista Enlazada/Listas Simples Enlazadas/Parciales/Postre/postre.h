#ifndef POSTRE_H
#define POSTRE_H 

struct Postre
{
	char nombreP[30];
	Ingre *e;
	Postre *sig;

	Postre()
	{
		this->e = NULL;
		this->sig = NULL;
	}
};

	Postre *add_postre(Postre *, char[]);
	Postre *remove_postre(Postre *, char[]);
	void view_postres(const Postre *);

	Postre *search_postre(Postre *, char[], int accion = 1);
	Postre *change_postre(Postre, char[]);
	Postre *empty(Postre *);
// ----------------------------------------------------------------------
Postre *empty(Postre *p)
{
	Postre *q;
	while (p != NULL)
	{
		q = p;
		p = p->sig;
		free(q);
	}

	printf("\n clean<< Postres");
	return q;
}


Postre *add_postre(Postre *p, char name[30])
{
	if (p == NULL) // en caso la lista este vacia
	{
		p = new Postre();
		strcpy(p->nombreP, name);
	}
	else // lista no esta vacia
	{
		Postre *nodo = new Postre();
		strcpy(nodo->nombreP, name);

		if (strcmp(name, p->nombreP) < 0) //insertar al inicio
		{
			nodo->sig = p;
			p = nodo;
		}
		else
		{
			int band = 1;
			register Postre *q = p, 
							*r;

			while(band != 0)
			{
				if(q->sig == NULL)
					band = 0;

				else // insertar en medio de dos nodos
				{
					r = q->sig;
					if ((strcmp(q->nombreP, name) < 0) && (strcmp(name, r->nombreP) < 0))
					{
						q->sig = nodo;
						nodo->sig = r;
						break;
					}
					else
						q = q->sig;			
				}
			}

			if (band == 0) //insertar al final
			{
				q->sig = nodo; 
			}
		}
	}

	return (p);
}


Postre *remove_postre(Postre *p, char name[30])
{
	if (p != NULL)
	{
		int band = 0;
		Postre *q;

		if (strcmp(name, p->nombreP) == 0) // primer postre
		{
			p = p->sig;
			band = 1;
		} 
		
		else // buscando
		{
			q = p;
			Postre *t;

			while((band == 0) && (q != NULL))
			{
				if(strcmp(name, q->nombreP) == 0)
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
				printf("\n postre: [%s] no esta en lista", name);
		else
		{
			free(q);
			printf("\n\tpostre: [%s] eliminado", name);
		}
		
	}else
		printf("\n\t Lista vacia");

	return (p);
}


void view_postres(const Postre *p)
{
	if (p != NULL)
	{
		const Postre *q = p;

		printf("[ ");

		while(q != NULL)
		{
			if (q->e == NULL)
				printf("%s i:[%s]",q->nombreP, q->e);
			else
				printf("%s i:[...]",q->nombreP);

			if (q->sig != NULL)
				printf(", ");
			else 
				printf(" ]\n");

			q = q->sig;
		}	
	}
	else
		printf("\n lista vacia");	
}


Postre *search_postre(Postre *p, char name[30], int accion)
{
	if (p != NULL)
	{
		Postre *q = p;
		int band = 0, res;

		if (strcmp(name, p->nombreP) == 0) // primer postre
			band = 1;
		else
		{
			while(q != NULL && band == 0)
			{
				if (strcmp(name, q->nombreP) == 0)
					band = 1;
				else
					q = q->sig;
			}
		}

		if (band == 1)
		{
			char resp, nameIngre[30];

			if (accion == 1) //mostrar
			{
				printf("\n Postre: [%s]\n Ingredientes: ", name); 
                view_ingres(q->e);
			}

			else if (accion == 2) //insertar
			{
				do
				{
					fflush(stdin);
					printf("\n Ingrediente: ");
            		scanf("%[^\n]",&nameIngre);

            		q->e = add_ingre(q->e, nameIngre);

            		fflush(stdin);
            		printf("\n Desea ingresar mas ingredientes [y/n]: ");
            		scanf("%c", &resp);

				} while (resp == 'y' || resp == 'Y');
			}

			else if (accion == 3) //eliminar
			{
				printf("\n Eliminar:\n 1 [vaciar]\n 2 [one]");
            	scanf("%d", &res);

            	if (res == 1)
            		q->e = empty(q->e);
            	else
            	{
					fflush(stdin);
					printf("\n Ingrediente: ");
        			scanf("%[^\n]",&nameIngre);

        			q->e = remove_ingre(q->e, nameIngre);
            	}
			}

			else if (accion == 4) //hacer cambio
			{
				fflush(stdin);
				printf("\n Ingrediente: ");
        		scanf("%[^\n]",&nameIngre);
        		q->e = change_ingre(q->e, nameIngre);
			}
		}
		else
			printf("\n postre: [%s] no esta en lista", name);
	}else
		printf("\n\tlista <postres> vacia");

	return (p);
}


Postre *change_postre(Postre *p, char name[30])
{
	if (p != NULL)
	{
		Postre *q = p;
		int band = 0;

		if (strcmp(name, p->nombreP) == 0) // primer postre
			band = 1;
		else
		{
			while(q != NULL && band == 0)
			{
				if (strcmp(name, q->nombreP) == 0)
					band = 1;
				else
					q = q->sig;
			}
		}

		if (band == 1)
		{
			char nameNew[30];

			printf("\n Editar postre:\"%s\" por: ", name);
			fflush(stdin);
			scanf("%[^\n]",&nameNew);
			strcpy(q->nombreP, nameNew);
			printf("\n ready!::Postre modificado");
		}
		else
			printf("\n postre: [%s] no esta en lista", name);
	}else
		printf("\n\tlista <postres> vacia");

	return (p);
}
#endif