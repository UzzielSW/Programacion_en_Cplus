#ifndef HELPP_H
#define HELPP_H 

struct Polinomio
{
	int grado, coef;
	Polinomio *liga;
};

	Polinomio *crea_polinomio();
	void *crea_memoria_polinomio(int n);
	
	int getd();
	float getf();

	Polinomio *leer_polinomio();
	
	Polinomio *insertar_in(Polinomio *, int , int);

	void recorre_iterativo(const Polinomio *);
	void imprimir(const Polinomio *);

	Polinomio *eliminar(Polinomio *, int , int);

	Polinomio *change(Polinomio *);

// -------------------------------------------------------------
Polinomio *crea_polinomio(){	return (Polinomio *) crea_memoria_polinomio(sizeof(Polinomio));}

void *crea_memoria_polinomio(int n)
{
	void *p = (int *) malloc(n);
	
	if (p == NULL)
	{
		puts("\n no hay memoria disponible");
		getchar();
		exit(1);
	}
	
	return p;
}


// GETS
int getd()
{
	int dato, i;

	do
	{
		i = scanf("%d", &dato);
		fflush(stdin);
	}while(i != 1);

	return dato;
}

float getf()
{
	int i;
	float dato;

	do
	{
		i = scanf("%f", &dato);
		fflush(stdin);
	}while(i != 1);
	
	return dato;
}


////////////    CREAR POLINOMIO 	/////////
Polinomio *leer_polinomio()
{
	int i;
	bool band, aux, verif;
	Polinomio *p, *q, *r, *t;

	/* se crea el inicio de la lista en caso de coeficiente 0*/
	do
	{
		p = crea_polinomio();
		p->liga = NULL;

		printf("\n Polinomio:");
		printf("\n coeficiente: ");	p->coef = getd();
		printf(" grado: ");	p->grado = getd();

		if (p->coef == 0)
		{
			band = false;
			free(p);
		}
		else
			band = true;

	}while(band == false);
	

	do
	{	
		verif = true;

		q = crea_polinomio(); 
		
		printf("\n coeficiente: ");
		scanf("%d", &q->coef);  
		

		// en caso de coeficiente invalido
		if (q->coef == 0) verif = false;

		printf(" grado: ");
		i = scanf("%d", &q->grado);	
		
		fflush(stdin); //*****
		
		if (i == 0)	band = false; // detener ciclo
		
		

		// buscar lugar de ubicacion de q
		if (band == true && verif == true)	//2.4
		{
			// caso de insertar al incio
			if (q->grado >= p->grado)	//2.4.1
			{
				q->liga = p;
				p = q;
			}
			else //2.4.2
			{
				if (p->liga == NULL) //caso que solo hay un elemento
				{
					p->liga = q;
					q->liga = NULL;
				}
				else // mas de un elemento
				{
					aux = true;
					t = p;

					// buscar lugar donde debe estar
					while(t->liga != NULL && aux == true) 
					{
						r = t->liga;

						if ((t->grado > q->grado) && (q->grado >= r->grado))
						{
							t->liga = q;
							q->liga = r;
							aux = false; // en caso de encontrarse
						}

						t = r; // mover al siguiente
					}

					if (aux == true) // en caso que vaya al final
					{
						t->liga = q;
						q->liga = NULL;
					}
				}
			}
		}
		// eliminar en caso de invalides de los datos ingresados
		else
			free(q);

	} while (band == true);

	return p;
}


////////////    INSERTAR EN POLINOMIO 	/////////
Polinomio *insertar_in(Polinomio *p, int coef, int grado)
{
	int i;
	bool aux;
	Polinomio *q, *r, *t;

	/* se crea el inicio de la lista en caso de coeficiente 0*/
	if (p == NULL && coef != 0)
	{
		p = crea_polinomio();
		p->liga = NULL;
		p->coef = coef;
		p->grado = grado;
	}
	else if(coef != 0)
	{
		q = crea_polinomio();
		q->coef = coef;
		q->grado = grado;

		// caso de insertar al incio
		if (q->grado >= p->grado)	//2.4.1
		{
			q->liga = p;
			p = q;
		}
		else //2.4.2
		{
			if (p->liga == NULL) //caso que solo hay un elemento
			{
				p->liga = q;
				q->liga = NULL;
			}
			else // mas de un elemento
			{
				aux = true;
				t = p;

				// buscar lugar donde debe estar
				while(t->liga != NULL && aux == true) 
				{
					r = t->liga;

					if ((t->grado > q->grado) && (q->grado >= r->grado))
					{
						t->liga = q;
						q->liga = r;
						aux = false; // en caso de encontrarse
					}

					t = r; // mover al siguiente
				}

				if (aux == true) // en caso que vaya al final
				{
					t->liga = q;
					q->liga = NULL;
				}
			}
		}
	}	
	
	return p;
}


//////////	MOSTRAR EL POLINOMIO ITERATIVAMENTE	  //////////
void recorre_iterativo(const Polinomio *p)
{
	if (p != NULL)
	{
		for (const Polinomio *q = p; q != NULL; q = q->liga)
		{
			if (q->grado != 0) // si hay x
			{
				if (q->grado == 1) // caso exclusivo para omitir exponencial 1
				{
					if ((q->coef == 1) || (q->coef == -1)) // caso exclusivo para omitir coeficiente 1
					{
						if (q->coef == 1)
							printf(" + x");
						else
							printf(" - x");
					}
					else
					{
						if (q->coef > 0)
							printf(" + %dx",q->coef);
						else
							printf(" %dx",q->coef);
					}
				}
				else // x^
				{
					if (q->coef > 0) // positive
					{
						if (q->coef == 1)
							printf(" + [x^%d]", q->grado);
						else
							printf(" + %d[x^%d]",q->coef, q->grado);
					}
					else // negative
					{
						if (q->coef == -1)
							printf(" - [x^%d]", q->grado);
						else
							printf(" %d[x^%d]",q->coef, q->grado);
					}
				}
			}
			else // en caso que solo es numero
			{
				if (q->coef > 0)
					printf(" + %d",q->coef);	
				else
					printf(" %d",q->coef);	
			}	
		}
	}else
		printf("\tNo hay Polinomio");
}

void imprimir(const Polinomio *p)
{
	if (p != NULL)
	{
		for(const Polinomio *q = p; q != NULL; q = q->liga)
		{
			if (q->liga == NULL)
				printf(" [%dx^%d]",q->coef, q->grado);
			else
				printf(" [%dx^%d] ->",q->coef, q->grado);
		}
	}else
		printf("\t Polinomio vacio");
}


/////////////	MODIFICANDO POLINOMIO 	//////////////////
Polinomio *change(Polinomio *p)
{
	if (p != NULL)
	{
		int coefx, gradox;
		bool ver = false;

		printf("\n ingrese los datos del elemento: ");
		
		printf("\n coeficiente: "); 
		scanf("%d",&coefx);
		
		printf(" grado: "); 
		scanf("%d",&gradox);


		for(Polinomio *q = p; q != NULL; q = q->liga)
		{
			if (q->coef == coefx && q->grado == gradox)
			{
				printf("\n OK, elemento fue encontrado, ingrese los datos nuevos: ");
				printf("\n coeficiente: ");
				scanf("%d",&q->coef);
			
				printf(" grado: ");
				scanf("%d",&q->grado);

				printf("\n\tCambios realizados correctamente\n");

				ver = true; break;
			}
		}

		if (ver == false)
			printf("\n\tel elemento no fue encontrado");
	}

	return p;
}


/////////////	ELIMINANDO ELEMENTO EN POLINOMIO 	//////////////////
Polinomio *eliminar(Polinomio *p, int coefx, int gradox)
{
	if (p != NULL)
	{
		Polinomio *q = p;
		Polinomio *t;
		bool band = false;

		while(q != NULL && band == false)
		{
			if (q->coef == coefx && q->grado == gradox)
				band = true;
			else
			{
				t = q;
				q = q->liga;
			}
		}


		if (band == true)
		{
			if (q == p)
				p = p->liga;
			else
				t->liga = q->liga;
	   
	   		free(q);
	   		printf("\n elemento eliminado");
		}
		else
			printf("\n el elemento no fue encontrado");
	}

	return p;
}
#endif