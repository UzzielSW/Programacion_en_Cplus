#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct
{
	int grado, coef;
	struct Polinomio *liga;
} Polinomio;

Polinomio *crea_polinomio();
void *crea_memoria_polinomio(int n);
Polinomio leer_poli(Polinomio *p);
Polinomio reduce_poli(Polinomio *p);
float evalua_poli(Polinomio *p, int x);
Polinomio derivar_poli(Polinomio *p);
Polinomio multiplicar_polis(Polinomio *p1, Polinomio *p2);
Polinomio sumar_polis(Polinomio *p1, Polinomio *p2);
void recorre_iterativo(Polinomio *p);

int main()
{
	float suma, x1, i;
	Polinomio *p, *p2;
	Polinomio *pd; // derivada de p
	Polinomio *pm; // multiplicacion p1 y p2

	// leyendo polinomio 1 y reduciendolo
	p = leer_poli(p);
	p = reduce_poli(p);

	do
	{
		printf("\n ingrese valor (x) a evaluar el Polinomio: ");
		i = scanf("%i", &x1);
	} while (i == 0);

	// evaluando polinomio 1
	suma = evalua_poli(p, x1);

	// derivando polinomio
	pd = derivar_poli(p);

	// leyendo polinomio 2 y reduciendolo
	p2 = leer_poli(p2);
	p2 = reduce_poli(p2);

	// multiplicando polinomio 1 y 2
	pm = multiplicar_polis(p, p2);

	getchar();
	return 0;
}

///   FUNCIONES POLINOMIO   ///

Polinomio *crea_polinomio()
{
	return (Polinomio *)crea_memoria_polinomio(sizeof(Polinomio));
}

void *crea_memoria_polinomio(int N)
{
	void *p = (int *)malloc(N);
	if (p == NULL)
	{
		puts("\n no hay memoria disponible");
		getchar();
		exit(1);
	}
	return p;
}

///////////		 LEER UN POLINOMIO     //////////

Polinomio leer_poli(Polinomio *p)
{
	int i;
	bool band, aux, emergente;
	Polinomio *q, *r, *t;

	do
	{
		p = crea_polinomio();
		printf("\n ingrese el grado del Polinomio: ");
		i = scanf("%i", &p->grado);
		if (i == 0)
		{
			free(p);
			return NULL;
		}
		printf(" ingrese el coeficiente del Polinomio: ");
		scanf("%i", &p->coef);

		if (p->coef == 0)
			band = false;
		else
			band = true;
	} while (band == false);

	do
	{
		emergente = true;
		q = crea_polinomio(); // 2.1
		printf("\n ingrese el grado del Polinomio: ");
		i = scanf("%i", &q->grado); // 2.2
		if (i == 0)
			band = false;

		printf(" ingrese el coeficiente del Polinomio: ");
		scanf("%i", &q->coef); // 2.3

		if (q->coef == 0)
			emergente = false;

		if (band == true && emergente == true) // 2.4
		{
			if (q->grado >= p->grado) // 2.4.1
			{
				q->liga = p;
				p = q;
			}
			else
			{
				if (p->liga == NULL)
				{
					p->liga = q;
					q->liga = NULL;
				}
				else
				{
					aux = true;
					t = p;
					while (t->liga == NULL)
					{ // 2.4.1.1.1
						r = t->liga;
						if ((t->grado > q->grado) && (q->grado >= r->grado)) // 2.4.1.1.1.1
						{
							t->liga = q;
							q->liga = r;
							aux = false;
						}
					}

					if (aux == false) // 2.4.1.1.2
					{
						t->liga = q;
						q->liga = NULL;
					}
				}
			}
		}
	} while (band == true);
	return p;
}

//////////    REDUCE UN POLINOMIO    ///////////

Polinomio reduce_poli(Polinomio *p)
{
	Polinomio *q, *d, *a, *r, *b;

	q = p;
	a = p;

	while (q->liga != NULL)
	{ // 1
		d = q->liga;
		if (q->grado == d->grado) // 1.1
		{
			q->coef = q->coef + d->coef;

			if (q->coef != NULL) // 1.1.1
			{
				if (d->liga != NULL) // 1.1.1.1
				{
					r = d->liga;
					q->liga = r;
					free(d);
				}
				else
				{ // 1.1.1.2
					q->liga = NULL;
					free(d);
				}
			}
			else
			{							   // 1.1.2
				if (p->liga->liga == NULL) // 1.1.2.1
				{
					p = NULL;
					free(d);
					return p;
				}
				else
				{						 // 1.1.2.2
					if (d->liga == NULL) // 1.1.2.2.1
					{
						b = q;
						q = a;
						q->liga = NULL;
					}
					else
					{ // 1.1.2.2.2
						b = q;
						q = d->liga;
						a->liga = q;
					}
					free(b);
					free(d);
				}
			}
		}
		else
		{ // 1.2
			a = q;
			q = q->liga;
		}
	}
	return p;
}

/////////    EVALUAR UN POLINOMIO CON X 	/////////

float evalua_poli(Polinomio *p, int x)
{
	// int cont;
	float suma;
	Polinomio *q;

	if (x == 0) // 1
	{
		q = p;
		while (q != NULL)
		{ // 1.1

			if (q->grado == 0) // 1.1.1
				suma += q->coef;

			q = q->liga;
		}
		return suma;
	}
	else
	{ // 2
		q = p;
		while (q != NULL)
		{ // 2.1
			suma += (q->coef * pow(x, q->grado));
			q = q->liga;
		}
		return suma;
	}
}

/////////	DERIVAR UN POLINOMIO  	//////////

Polinomio derivar_poli(Polinomio *p)
{
	bool band = true;
	Polinomio *q, *pd, *qd, *td;

	pd = crea_polinomio(); // 1

	if (p->grado > 0)
	{ // 2
		pd->coef = (p->grado * p->coef);
		pd->grado = (p->grado - 1);
		pd->liga = NULL;
	}
	else
	{ // 3
		free(pd);
		band = false;
		printf("\n La derivada es cero...");
		// pd = NULL;
		return p;
	}

	q = p->liga;
	td = pd;

	while ((q != NULL) && (band == true))
	{ // 4
		qd = crea_polinomio;

		if (q->grado > 0) // 4.1
		{
			qd->coef = (q->grado * q->coef);
			qd->grado = (q->grado - 1);
			qd->liga = NULL;
			td->liga = qd;
			td = qd;
			q = q->liga;
		}
		else
		{ // 4.2
			free(qd);
			band = false;
		}
	}

	return pd;
}

/////////		MULTIPLICAR 2 POLINOMIOS	/////////////

Polinomio multiplicar_polis(Polinomio *p1, Polinomio *p2)
{
	Polinomio *q1, *q2, *pm, *tm, *rm;
	bool band = false, aux;

	q1 = p1;

	while (q1 != NULL)
	{ // 1
		q2 = p2;

		while (q2 != NULL)
		{ // 1.1

			if (band == false) // 1.1.1
			{
				pm = crea_polinomio();
				pm->coef = (q1->coef * q2->coef);
				pm->grado = q1->grado + q2->grado;
				pm->liga = NULL;

				if (pm->coef != 0) // 1.1.1.1
					band = true;
				else // 1.1.1.2
					free(pm);

				q2 = q2->liga;
			}
			else
			{ // 1.1.2
				qm = crea_polinomio();
				qm->coef = (q1->coef * q2->coef);
				qm->grado = q1->grado + q2->grado;
				if (qm->coef != NULL) // 1.1.2.1
				{
					if (qm->grado >= pm->grado) // 1.1.2.1.1
					{
						qm->liga = pm;
						pm = qm;
					}
					else
					{ // 1.1.2.1.2

						if (pm->liga == NULL) // 1.1.2.1.2.1
						{
							pm->liga = qm;
							qm->liga = NULL;
						}
						else
						{ // 1.1.2.1.2.2
							aux = true;
							tm = pm;

							while (tm->liga != NULL)
							{
								rm = tm->liga;

								if ((tm->grado > qm->grado) && (qm->grado >= rm->grado))
								{
									tm->liga = qm;
									qm->liga = rm;
									aux = false;
								}
							}

							if (aux == true)
							{
								tm->liga = qm;
								qm->liga = NULL;
							}
						}
					}

					q2 = q2->liga;
				}
				else
					free(qm);
			}
		}

		q1 = q1->liga;
	}

	return pm;
}

///////////	 	SUMAR 2 POLINOMIOS 	 ///////////

Polinomio sumar_polis(Polinomio *p1, Polinomio *p2)
{
	Polinomio *q1, *q2, *ps, *qs, *ts, *rs, *fs, *g;
	bool band = false, aux, indicador;

	q1 = p1;
	q2 = p2;

	while ((q1 != NULL) && (q2 != NULL) && (band == false)) // 1
	{
		ps = crea_polinomio();

		if (q1->grado == q2->grado) // 1.1
		{
			ps->coef = (q1->coef + q2->coef);
			ps->grado = q1->grado;
			ps->liga = NULL;

			q1 = q1->liga;
			q2 = q2->liga;

			if (ps->coef != 0)
				band = true; // 1.1.1
			else
				free(ps); // 1.1.2
		}
		else
		{							   // 1.2
			if (q1->grado > q2->grado) // 1.2.1
			{
				ps->coef = q1->coef;
				ps->grado = q1->grado;
				ps->liga = NULL;

				q1 = q1->liga;
				band = true;
			}
			else
			{ // 1.2.2
				ps->coef = q2->coef;
				ps->grado = q2->grado;
				ps->liga = NULL;

				q2 = q2->liga;
				band = true;
			}
		}
	} // 1

	while ((q1 != NULL) && (q2 != NULL) && (band == true)) // 2
	{
		indicador = true;

		qs = crea_polinomio();

		if (q1->grado == q2->grado) // 2.1
		{
			qs->coef = (q1->coef + q2->coef);
			qs->grado = q1->grado;

			if (qs->coef == 0) // 2.1.1
			{
				free(qs);
				indicador = false;
			}

			q1 = q1->liga;
			q2 = q2->liga;
		}
		else
		{							   // 2.2
			if (q1->grado > q2->grado) // 2.2.1
			{
				qs->coef = q1->coef;
				qs->grado = q1->grado;

				q1 = q1->liga;
			}
			else
			{ // 2.2.2
				qs->coef = q2->coef;
				qs->grado = q2->grado;

				q2 = q2->liga;
			}
		}

		if (indicador == true) // 2.3
		{
			if (qs->grado >= ps->grado) // 2.3.1
			{
				qs->liga = ps;
				ps = qs;
			}
			else
			{						  // 2.3.2
				if (ps->liga == NULL) // 2.3.2.1
				{
					ps->liga = qs;
					qs->liga = NULL;
				}
				else
				{ // 2.3.2.2
					aux = true;
					ts->grado = ps->grado;

					while (ts->liga != NULL)
					{ // 2.3.2.2.1
						rs = ts->liga;

						if ((ts->grado > qs->grado) && (qs->grado >= rs->grado)) // 2.3.2.2.1.1
						{
							ts->liga = qs;
							qs->liga = rs;
							aux = false;
						}
					}

					if (aux == true)
					{ // 2.3.2.2.2
						ts->liga = qs;
						qs->liga = NULL;
					}
				}
			}
		}
	} // 2

	if (band == false) // 3
	{
		ps = NULL;
		return ps;
	}
	else
	{ // 4
		fs = ps;

		while (fs->liga != NULL)
		{ // 4.1
			fs = fs->liga;
		}

		if ((q1 == NULL) && (q2 != NULL)) // 4.2
		{
			while (q2 != NULL)
			{ // 4.2.1
				g = crea_polinomio();

				g->coef = q2->coef;
				g->grado = q2->grado;
				g->liga = NULL;

				fs->liga = g;
				fs = g;

				q2 = q2->liga;
			}
		}
		else
		{									  // 4.3
			if ((q1 != NULL) && (q2 == NULL)) // 4.3.1
			{
				while (q1 != NULL)
				{ // 4.3.1.1
					g = crea_polinomio();

					g->coef = q1->coef;
					g->grado = q1->grado;
					g->liga = NULL;

					fs->liga = g;
					fs = g;

					q1 = q1->liga;
				}
			}
		}
	}

	return ps;
}

//////////	MOSTRAR EL POLINOMIO ITERATIVAMENTE	  //////////

void recorre_iterativo(Polinomio *p)
{
	Polinomio *q;
	bool band;

	if (p != NULL)
	{
		if (p->grado != 0)
		{
			if (p->grado == 1)
			{
				if ((p->coef == 1) || (p->coef == -1))
				{
					if (p->coef == 1)
						printf("X");
					else
						printf("-X");
				}
			}
			else
			{
			}
		}
	}
}