#ifndef ALGORITHM_H
#define ALGORITHM_H 

	// ALGORITMOS
	NODO *inserta_inicio(NODO *, NODO **, int);
	NODO *inserta_final(NODO *, NODO **, int);
	NODO *inserta_antes_x(NODO *, int, int);
	NODO *elimina_inicio(NODO *, NODO **);
	NODO *elimina_final(NODO *, NODO **);
	NODO *elimina_x(NODO *, NODO **, int);
	NODO *elimina_antes_x(NODO *, int);


// ALGORITMOS

NODO *inserta_inicio(NODO *p, NODO **f, int dato)
{
	if (p != NULL)
	{
		NODO *q = creaNodo();
		q->num = dato;
		q->der = p;
		q->izq = NULL;
		p->izq = q;
		p = q;
	}else
	{
		p = creaNodo();
		p->num = dato;
		p->der = p->izq = NULL;
		*f = p;
	}

	return p;
}

NODO *inserta_final(NODO *f, NODO **p, int dato)
{
	if (f != NULL)
	{
		NODO *q = creaNodo();
		q->num = dato;
		q->der = NULL;
		q->izq = f;
		f->der = q;
		f = q;
	}else
	{
		f = creaNodo();
		f->num = dato;
		f->der = f->izq = NULL;
		*p = f;
	}

	return f;
}

NODO *inserta_antes_x(NODO *p, int x, int dato)
{
	if(p == NULL)
		return p;
	
	NODO *q = p,
		 *t, *r;

	while(q->der != NULL && q->num != x)
		q = q->der;


	if(q->num == x)
	{
		t = creaNodo();
		t->num = dato;
		t->der = q;
		r = q->izq;
		q->izq = t;

		if (q == p) //primer nodo
		{
			t->izq = NULL;
			p = t;
		}else{
			r->der = t;
			t->izq = r;
		}
	}else
		printf("\n elemento x dado como referencia no se encuentra en la lista");

	return p;
}

NODO *elimina_inicio(NODO *p, NODO **f)
{
	if (p != NULL)
	{
		NODO *q = p;

		if (q->der == NULL)
			p = *f = NULL;
		else{
			p = p->der;
			p->izq = NULL;
			q->der = NULL;
		}

		free(q);
	}

	return p;
}

NODO *elimina_final(NODO *f, NODO **p)
{
	if (f != NULL)
	{
		NODO *q = f;

		if (q->izq == NULL)
			f = *p = NULL;
		else{
			f = f->izq;
			f->der = NULL;
			q->izq = NULL;
		}

		free(q);
	}

	return f;
}

NODO *elimina_x(NODO *p, NODO **f, int x)
{	
	if(p == NULL)
		return p;

	NODO *q = p,
		*t, *r;

	while(q->der != NULL && q->num != x)
		q = q->der;


	if (q->num == x)
	{
		if (p == q && q == *f) //solo un nodo
			p = *f = NULL;
		else if (p == q) // primer nodo
		{
			p = p->der;
			p->izq = NULL;
			q->der = NULL;
		}
		else if (q == *f) // ultimo nodo
		{
			*f = (*f)->izq;
			(*f)->der = NULL;
			q->izq = NULL;
		}
		else
		{
			t = q->izq;
			r = q->der;
			t->der = r;
			r->izq = t;
			q->der = q->izq = NULL;
		}

		free(q);
	}else
		printf("\n el elemento no se encontro en la lista");
	

	return p;
}

NODO *elimina_antes_x(NODO *p, int x)
{
	NODO *q = p;
	NODO *t, *r;

	while(q->der != NULL && q->num != x)
		q = q->der;

	if (q->num == x)
	{
		if (p == q)
			printf("\n No hay nodo antecesor");
		else
		{
			t = q->izq;
			if (t == p) //primer nodo
			{
				p = q;
				p->izq = NULL;
				t->der = NULL;
			}
			else 
			{
				r = t->izq;
				r->der = q;
				q->izq = r;
				t->izq = t->der = NULL;
			}

			free(t);
		}
	}else
		printf("\n no se encontro nodo dado como referencia");
	
	return p;
}


#endif