#ifndef DERIVAR_H
#define DERIVAR_H 

	Polinomio *derivar_polinomio(Polinomio *p);
	Polinomio *derivar_polinomio_of(const Polinomio *p);

/////////	DERIVAR UN POLINOMIO  	//////////
Polinomio *derivar_polinomio(Polinomio *p)
{
	Polinomio *q, *a, *d;
	a = NULL;
	q = p;

	while(q != NULL)
	{
		if (q->grado == 0)  // caso derivar una constante = 0
		{
			d = q; // seleccionando al nodo a eliminar

			if (a == NULL) // primer recorrido
			{
				if (q->liga == NULL) // caso que solo sea un nodo
				{
					p = NULL;
					q = NULL;
					free(d);
					printf("\n\tLa derivada es cero...");
				}
				else // caso le sigan mas nodos
					q = q->liga;	
			}
			else  // en recorrido
			{
				if (q->liga != NULL)  // caso le sigan mas nodos
					a->liga = q->liga;
				
				else // ultimo nodo
					a->liga = NULL;	

				q = q->liga;
			}		
			
			free(d); // eliminando el nodo
		}
		else // caso grado != 0 
		{
			q->coef *= q->grado;
			(q->grado)--;
			a = q;
			q = q->liga;
		}
	}

	return p;
}


Polinomio *derivar_polinomio_of(const Polinomio *p)
{
	Polinomio *s = NULL; // derivada de p
	Polinomio *t, *a = NULL;
	const Polinomio *q = p;

	while(q != NULL)
	{
		if (q->grado == 0) // caso que sea un numero
		{
			if (a == NULL && q->liga == NULL) // unico nodo 
				printf("\n\tLa derivada de %d es cero", q->coef);
		}
		else // caso grado != 0 
		{
			if (s == NULL) // inicializando nodo copia derivado
			{
				s = crea_polinomio();
				s->coef = q->coef * q->grado;
				s->grado = (q->grado - 1);
				s->liga = NULL;
				a = s;
			}
			else // en caso de +1 nodo
			{
				t = crea_polinomio();
				t->coef = q->coef * q->grado;
				t->grado = (q->grado - 1);
				t->liga = NULL;
				a->liga = t;
				a = t;
			}
		}
		
		q = q->liga;
	}

	return s;
}

#endif