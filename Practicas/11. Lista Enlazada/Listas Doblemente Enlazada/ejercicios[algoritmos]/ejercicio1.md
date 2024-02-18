# EJERCICIOS[doble]

1. Defina un algoritmo para insertar un elemento antes de otro nodo dado como referencia, en una lista ordenada.

> ## algoritmo
	{ **p** es el apuntador al primer nodo de la lista }
	{ **x** es la información del nodo de referencia }
	{ **dato** es la información del nodo a insertar }
	{ **q, t, nodo** son variables de tipo apuntador }
	{ **num, der, izq** son los campos de cada nodo de la lista }

````c

inserta_antes_x(p, dato, x)
{
	Hacer q = p

	repetir mientras((q->der != NULL) y (q->num < x))
	{
		t = q
		q = q->der
	}
	
	Si (q->num == x)
	{
		Crear(nodo)
		nodo->num = dato
	
		Si (q == p) {primer nodo de la lista}
		{
			nodo->der = p
			p->izq = nodo
			nodo->izq = NULL
			p = nodo
		}
		Sino
		{
			t->der = nodo
			nodo->izq = t
			nodo->der = q
			q->izq = nodo
		}
	}
	Sino 
		escribir("no se encontro referencia X en la lista")

    retornar(p)
}
````

> este algoritmo inserta el nodo en una lista ordenada ascendente.
> para adaptarlo a una lista descendente solo debe cambiar :
> `repetir mientras((q->der != NULL) y (q->num < x))` por `repetir mientras((q->der != NULL) y (q->num > x))`


## Código en C

````c

NODO *inserta_antes_x(NODO *p, int dato, int x)
{
    NODO *t;
	NODO *q = p;

	while(q->der != NULL && q->num < x)
	{
		t = q;
		q = q->der;
	}
	
	if (q->num == x)
	{
		NODO *nodo = creaNodo();
		nodo->num = dato;
	
		if (q == p) //primer nodo
		{
			nodo->der = p;
			p->izq = nodo;
			nodo->izq = NULL;
			p = nodo;
		}
		else
		{
			t->der = nodo;
			nodo->izq = t;
			nodo->der = q;
			q->izq = nodo;
		}
	}
	else 
		printf("\n\tno se encontro referencia x en la lista");
    
	return(p);
}
````