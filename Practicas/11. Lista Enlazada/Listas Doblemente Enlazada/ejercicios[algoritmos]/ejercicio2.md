2. Defina un algoritmo para insertar un elemento siguiendo a otro nodo dado como referencia, en una lista ordenada.

> ## algoritmo
>
> {**p** es el apuntador al primer nodo de la lista}
> {**x** es la información del nodo de referencia}
> {**dato** es la información del nodo a insertar}
> {**q, r, nodo** son variables de tipo apuntador}
> {**num, der, izq** son los campos de cada nodo de la lista}

```c
inserta_despues_x(p, dato, x)
{
	Hacer q = p

	mientras((q->der != NULL) y (q->num < x))
		q = q->der

	Si (q->num == x)
	{
		Crear(nodo)
		nodo->num = dato

		r = q->der

		nodo->der = r
		r->izq = nodo
		q->der = nodo
		nodo->izq = q
	}
	Sino
		escribir("no se encontro referencia x en la lista")
		
	retornar(p)
}
```

> este algoritmo inserta el nodo en una lista ordenada ascendente.
> para adaptarlo a una lista descendente solo debe cambiar :
> `mientras((q->der != NULL) y (q->num < x))` por `mientras((q->der != NULL) y (q->num > x))`



## Código en C

```c
NODO *inserta_despues_x(NODO *p, int dato, int x)
{
	NODO *q = p;
	NODO *r;

	while(q->der != NULL && q->num < x)
		q = q->der;

	if (q->num == x)
	{
		NODO *nodo = creaNodo();
		nodo->num = dato;

		r = q->der;

		nodo->der = r;
		r->izq = nodo;
		q->der = nodo;
		nodo->izq = q;
	}
	else
		printf("\n\tno se encontro referencia x en la lista");
		
	return (p);
}
```