#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "help.h"
#include "reducir.h"
#include "derivar.h"
#include "sumar.h"
#include "multiplicar.h"

Polinomio *leer_polinomio();
Polinomio *leer_polinomio(Polinomio *, int , int);

float evalua_polinomio_i(Polinomio *, float);
float evalua_polinomio_r(Polinomio *, float);

void recorre_iterativo(const Polinomio *);

int getd();
float getf();


void imprimir(Polinomio *p)
{
	if (p != NULL)
	{
		for(Polinomio *q = p; q != NULL; q = q->liga)
			printf(" %dx%d ",q->coef, q->grado);
	}else
		printf("\t Polinomio vacio");
}


int main()
{
	Polinomio *Lista;
	Polinomio *p = NULL, *p2 = NULL;
	Polinomio *pd; // derivada
	Polinomio *ps; // suma de p y p2
	Polinomio *pm; // multiplicacion p y p2
	float dato, result;

	// leer y evaluar Polinomio
	p = leer_polinomio();

	printf("\n Polinomio: ");	recorre_iterativo(p);

	// fflush(stdin);
	p2 = leer_polinomio();

	printf("\n Polinomio 2: ");	recorre_iterativo(p2);
	
	// if (p != NULL)
	// {
	// 	printf("\n ingrese valor (x) a evaluar el Polinomio: ");
	// 	result = evalua_polinomio_i(p, getf());
	// 	printf("\n resultado: %.2f", result);
	// }
	
	p = reduce_polinomio(p);
	// printf("\n Polinomio reducido: "); recorre_iterativo(p);
	p2 = reduce_polinomio(p2);
	// printf("\n Polinomio reducido: ");	recorre_iterativo(p);
	
	// derivando polinomio
	// pd = derivar_polinomio_of(p);
	// printf("\n Polinomio derivado: ");	recorre_iterativo(pd);
	// printf("\n Polinomio p: ");	recorre_iterativo(p);

	// sumando polinomios p y p2
	// ps = sumar_polinomios(p, p2);
	// printf("\n Polinomio ps: ");	recorre_iterativo(ps);
	
	// multiplicando polinomios p y p2
	// pm = multiplicar_polinomios(p, p2);
	// pm = reduce_polinomio(pm);
	// printf("\n Polinomio pm: ");	recorre_iterativo(pm);
	// -------------------------------------------------------------
	fflush(stdin);
	getchar();
	return 0;
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


/////////    CREAR UN POLINOMIO 	/////////
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

		printf("\n Creando Polinomio:\n");
		printf(" coeficiente: ");	p->coef = getd();
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


Polinomio *leer_polinomio(Polinomio *p, int coef, int grado)
{
	int i;
	bool aux;
	Polinomio *p, *q, *r, *t;

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


/////////    EVALUAR UN POLINOMIO CON X 	/////////
float evalua_polinomio_i(Polinomio *p, float x)
{
	float suma = 0;
	Polinomio *q = p;
	// en caso de tener q evaluar 0, solo sumar los numeros
	if (x == 0) // 1
	{
		while(q != NULL) // 1.1
		{
			if (q->grado == 0)	suma += q->coef;
			q = q->liga; 
		}
	}
	else // 2
	{ 
		while(q != NULL) //2.1
		{ 
			suma += q->coef * pow(x, q->grado);
			// printf("\n %.2f",suma);
			q = q->liga;
		};
	}

	return suma;
}

float evalua_polinomio_r(Polinomio *p, float x)
{
	float suma = 0;

	if(p != NULL)
	{
		if (x == 0) // 1
		{
			if (p->grado == 0)		suma += p->coef;
			if (p->liga != NULL)	suma += evalua_polinomio_r(p->liga, x); 
		}
		else // 2
		{  
			suma += p->coef * pow(x, p->grado);
			if (p->liga != NULL)	suma += evalua_polinomio_r(p->liga, x); 
		}
	}else
		printf("\n\n no se ha leido Polinomio");

	return suma;
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
				else
				{
					if (q->coef > 0)
						printf(" + %d[x^%d]",q->coef, q->grado);
					else
						printf(" %d[x^%d]",q->coef, q->grado);
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
