# EJERCICIOS

1. Defina un algoritmo para insertar un elemento antes de otro nodo dado como referencia, en una lista ordenada.

## algoritmo
* **p** es el apuntador al primer nodo de la lista
* **x** es la información del nodo de referencia
* **dato** es la información del nodo a insertar
* **q, t, nodo** son variables de tipo apuntador
* **num, liga** son los campos de cada nodo de la lista

````c

inserta_antes_x(p, dato, x)
{
	Hacer q = p

	repetir mientras((q->liga != NULL) y (q->num < x))
	{
		t = q
		q = q->liga
	}
	
	Si (q->num == x)
	{
		Crear(nodo)
		nodo->num = dato
	
		Si (q == p) {primer nodo de la lista}
		{
			nodo->liga = p
			p = nodo
		}
		Sino
		{
			t->liga = nodo
			nodo->liga = q
		}
	}
	Sino 
		escribir("no se encontro referencia X en la lista")

    retornar(p)
}
````

> este algoritmo inserta el nodo en una lista ordenada ascendente.
> para adaptarlo a una lista descendente solo debe cambiar :
> `repetir mientras((q->liga != NULL) y (q->num < x))` por `repetir mientras((q->liga != NULL) y (q->num > x))`


## Código en C

````c

NODO *inserta_antes_x(NODO *p, int dato, int x)
{
    NODO *t;
	NODO *q = p;

	while(q->liga != NULL && q->num < x)
	{
		t = q;
		q = q->liga;
	}
	
	if (q->num == x)
	{
		NODO *nodo = creaNodo();
		nodo->num = dato;
	
		if (q == p) //primer nodo
		{
			nodo->liga = p;
			p = nodo;
		}
		else
		{
			t->liga = nodo;
			nodo->liga = q;
		}
	}
	else 
		printf("\n\tno se encontro referencia x en la lista");
    
	return(p);
}
````

2. Defina un algoritmo para insertar un elemento siguiendo a otro nodo dado como referencia, en una lista ordenada.

## algoritmo

* **p** es el apuntador al primer nodo de la lista
* **x** es la información del nodo de referencia
* **dato** es la información del nodo a insertar
* **q, nodo** son variables de tipo apuntador
* **num, liga** son los campos de cada nodo de la lista

```c
inserta_despues_x(p, dato, x)
{
	Hacer q = p

	mientras((q->liga != NULL) y (q->num < x))
		q = q->liga

	Si (q->num == x)
	{
		Crear(nodo)
		nodo->num = dato
		nodo->liga = q->liga
		q->liga = nodo
	}
	Sino
		escribir("no se encontro referencia x en la lista")
		
	retornar(p)
}
```

> este algoritmo inserta el nodo en una lista ordenada ascendente.
> para adaptarlo a una lista descendente solo debe cambiar :
> `mientras((q->liga != NULL) y (q->num < x))` por `mientras((q->liga != NULL) y (q->num > x))`

## Código en C

```c
NODO *inserta_despues_x(NODO *p, int dato, int x)
{
	NODO *q = p;

	while(q->liga != NULL && q->num < x)
		q = q->liga;

	if (q->num == x)
	{
		NODO *nodo = creaNodo();
		nodo->num = dato;
		nodo->liga = q->liga;
		q->liga = nodo;
	}
	else
		printf("\n\tno se encontro referencia x en la lista");
		
	return (p);
}
```

3. algoritmo para insertar un elemento en una lista ordenada de tal manera que no se altere el orden de la misma.

## algoritmo

* **p** es el apuntador al primer nodo de la lista
* **dato** es la información del nodo a insertar
* **q, r, nodo** son variables de tipo apuntador
* **num, liga** son los campos de cada nodo de la lista
* **band** variable de tipo booleano

```c
insertar_ordenado_asc(p, dato)
{
	Crea(nodo)
	nodo->num = dato

	Si (dato <= p->num) {insertar al inicio}
	{
		nodo->liga = p
		p = nodo
	}
	Sino
	{
		q = p
		band = false

		mientras((q->liga != NULL) y (band == false))
		{
			r = q->liga

			Si ((q->num < dato) y (dato <= r->num))
			{
				q->liga = nodo
				nodo->liga = r
				band = true
			}
			Sino 
				q = q->liga
		}


		Si (band == false) {insertar al final}
		{
			q->liga = nodo
			nodo->liga = NULL
		}	
	}

	retornar(p)
}
```

> este algoritmo inserta el nodo en una lista ordenada ascendente.
> para adaptarlo a una lista descendente solo debe cambiar :
> `if (dato <= p->num)` por `if (dato >= p->num)` 
> `if ((q->num < dato) y (dato <= r->num))` por `if ((q->num > dato) y (dato >= r->num))` 


## Código en C

```c
NODO *insertar_ordenado_asc(NODO *p, int dato)
{
	NODO *nodo = creaNodo();
	nodo->num = dato;

	if (dato <= p->num) //insertar al inicio
	{
		nodo->liga = p;
		p = nodo;
	}
	else
	{
		NODO *q = p;
		bool band = false;

		while(q->liga != NULL && band == false)
		{
			NODO *r = q->liga;

			if (q->num < dato && dato <= r->num)
			{
				q->liga = nodo;
				nodo->liga = r;
				band = true;
			}
			else 
				q = q->liga;
		}


		if (band == false) //insertar al final
		{
			q->liga = nodo;
			nodo->liga = NULL;
		}	
	}

	return (p);
}
```

4. algoritmo para eliminar un nodo de una lista ordenada.

## algoritmo

* **p** es el apuntador al primer nodo de la lista
* **dato** es la información del nodo a insertar
* **q, t** son variables de tipo apuntador
* **num, liga** son los campos de cada nodo de la lista

```c
eliminar_ordenado_asc(p, dato)
{
	q = p

	mientras((q->num < dato) y (q->liga != NULL))
	{
		t = q
		q = q->liga
	}

	Si (q->num == dato)
	{
		Si (q == p) 	{primer elemento}
			p = p->liga
		Sino
			t->liga = q->liga

		Eliminar(q)
		Escribir("elemento %d a sido eliminado", dato)
	}
	Sino
		Escribir("no se encontro referencia x en la lista")
	
	Retornar(p)
}
```

> este algoritmo elimina el nodo con la info **dato** en una lista ordenada ascendente.
> para adaptarlo a una lista descendente solo debe cambiar :
> `mientras((q->num < dato) y (q->liga != NULL))` por `mientras((q->num > dato) y (q->liga != NULL))`


## Código en C

```c
NODO *eliminar_ordenado_asc(NODO *p, int dato)
{
	NODO *q = p, *t;

	while(q->num < dato && q->liga != NULL)
	{
		t = q;
		q = q->liga;
	}

	if (q->num == dato)
	{
		if (q == p) //primer nodo
			p = p->liga;
		else
			t->liga = q->liga;

		free(q);
		printf("\n\telemento %d a sido eliminado", dato);
	}
	else
		printf("\n\tno se encontro referencia x en la lista");
	
	return (p);
}
```

5. con dos listas ordenadas, formar una tercera con la mezcla de los elementos de ambas listas, en forma ordenada.

## algoritmo

* **p** es el apuntador al primer nodo de la lista 1
* **s** es el apuntador al primer nodo de la lista 2
* **dato** es la información del nodo a insertar
* __ \*q __ es puntero a puntero
* **q, t, n, r, nodo** son variables de tipo apuntador
* **num, liga** son los campos de cada nodo de la lista
> **Este algoritmo va asistido por la funcion: _enlazado()_ esta funcion es importante para proximos algoritmos**

### algoritmo:
```c
merge_list(p, s)
{
	q = p
	t = s

	mientras((q != NULL) o (t != NULL))
	{
		Si (t == NULL)
		{
			n = enlazado(n, &r, q->num)
			q = q->liga
		}
		Sino Si(q == NULL)
		{
			n = enlazado(n, &r, t->num)
			t = t->liga
		}
		Sino Si (q->num <= t->num)
		{
			n = enlazado(n, &r, q->num)
			q = q->liga
		}
		Sino Si ((t->num < q->num))
		{
			n = enlazado(n, &r, t->num)
			t = t->liga
		}
	}

	retornar(n)
}
```
### funcion enlazado (clasica insercion al final):
```c
enlazado(p, *q, dato)
{
	Si (p == NULL)
	{
		Crea(p)
		p->liga = NULL
		p->num = dato
		*q = p
	}else
	{
		Crea(nodo)
		nodo->liga = NULL
		nodo->num = dato
		(*q)->liga = nodo
		*q = nodo
	}

	return (p)
}
```

## Código en C

### algoritmo:
```c
NODO *merge_list(NODO *p, NODO *s)
{
	NODO *q = p, *t = s;
	NODO *n = NULL, *r = NULL;

	while((q != NULL) || (t != NULL))
	{
		if (t == NULL)
		{
			n = enlazado(n, &r, q->num);
			q = q->liga;
		}
		else if(q == NULL)
		{
			n = enlazado(n, &r, t->num);
			t = t->liga;
		}
		else if (q->num <= t->num)
		{
			n = enlazado(n, &r, q->num);
			q = q->liga;
		}
		else if ((t->num < q->num))
		{
			n = enlazado(n, &r, t->num);
			t = t->liga;
		}
	}

	return (n);
}
```

### funcion:
```c
NODO *enlazado(NODO *p, NODO **q, int dato)
{
	if (p == NULL)
	{
		p = creaNodo();
		p->liga = NULL;
		p->num = dato;
		*q = p;
	}else
	{
		NODO *nodo = creaNodo();
		nodo->liga = NULL;
		nodo->num = dato;
		(*q)->liga = nodo;
		*q = nodo;
	}

	return (p);
}
```

6. programa recursivo que dadas dos listas ordenadas ascendentemente las mezcle y genere una nueva lista de forma descendente.

> para mejor comprension y para lograr deducir el algoritmo que resuelve este problema primero se realizo un algoritmo recursivo para recorrer ambas listas de forma ordenada ascendentemente.
> aunque luego se pudo deducir que hay otra forma mas rapida y directa de hacer el algoritmo pedido. decidi hacerlo de esta forma para retar mi capacidad y ver si era posible hacerlo de la forma que imagine.

## algoritmo

* **p** es el apuntador al primer nodo de la lista 1
* **s** es el apuntador al primer nodo de la lista 2
* **num, liga** son los campos de cada nodo de la lista

> algoritmo que recorre dos listas ordenadas ascendente y descendente.
```	
(9)		 =		=		(10)
		 |		|
(7)		[7] -> [8]		(8)
		 |^\____|
(5)		[5]	-> [6]		(6)
		 |^\____|
(3)		[3]	-> [4]		(4)
		 |^\____|
(1)		[1]	-> [2]		(2)
   		/		  \
  	   p           s
```
output
```
[1]
[2]
[3]
[4]
[5]
[6]
[7]
[8]
```

> al ser algoritmo recursivo al retornar  se consigue el output inverso.

output retorno
```
[8]
[7]
[6]
[4]
[3]
[5]
[2]
[1]
```
> aqui ya claramente se puede deducir la idea de como resolver el problema.

* algoritmo de recorrido
```c
recorre_ascen_descen(p, s)
{
	Si ((p != NULL) o (s != NULL))
	{
		Si (p == NULL)
		{
			escribir(s->num)
			recorre_ascen_descen(p, s->liga)
			escribir(s->num)	
		}
		Sino Si (s == NULL)
		{
			escribir(p->num)
			recorre_ascen_descen(p->liga, s)
			escribir(p->num)
		}
		Sino Si (p->num <= s->num)
		{
			escribir(p->num)
			recorre_ascen_descen(p->liga, s)
			escribir(p->num)
		}
		Sino Si (s->num < p->num)
		{
			escribir(s->num)
			recorre_ascen_descen(p, s->liga)
			escribir(s->num)
		}
	}

	retornar
}
```

* algoritmo **mezcla descendente** trabaja en conjunto con algoritmo de recorrido y funcion: __enlazado()__ visto anteriormente.

```c
mezcla_descendente(p, s, n, *q)
{
	Si ((p != NULL) o (s != NULL))
	{
		Si (p == NULL)
		{
			n = mezcla_descendente(p, s->liga, n, &(*q))
			escribir("\n [%i] ", s->num)	

			dato = s->num
		}
		Sino Si (s == NULL)
		{
			n = mezcla_descendente(p->liga, s, n, &(*q))
			escribir("\n [%i] ", p->num)

			dato = p->num
		}
		Sino Si (p->num <= s->num)
		{
			n = mezcla_descendente(p->liga, s, n, &(*q))
			escribir("\n [%i] ", p->num)

			dato = p->num
		}
		Sino Si (s->num < p->num)
		{
			n = mezcla_descendente(p, s->liga, n, &(*q))
			escribir("\n [%i] ", s->num)

			dato = s->num
		}

		// ------------------------------------
		n = enlazado(n, &(*q), dato)
	}

	retornar(n)
}
```


## Código en C

* algoritmo de recorrido
```c
void recorre_ascen_descen(NODO *p, NODO *s)
{
	if ((p != NULL) || (s != NULL))
	{
		if (p == NULL)
		{
			printf("\n [%i] ", s->num);
			recorre_ascen_descen(p, s->liga);
			printf("\n [%i] ", s->num);	
		}
		else if (s == NULL)
		{
			printf("\n [%i] ", p->num);
			recorre_ascen_descen(p->liga, s);
			printf("\n [%i] ", p->num);
		}
		else if (p->num <= s->num)
		{
			printf("\n [%i] ", p->num);
			recorre_ascen_descen(p->liga, s);
			printf("\n [%i] ", p->num);
		}
		else if (s->num < p->num)
		{
			printf("\n [%i] ", s->num);
			recorre_ascen_descen(p, s->liga);
			printf("\n [%i] ", s->num);
		}
	}else
		printf("\n------------------------------");

	return;
}
```

* algoritmo **mezcla descendente**
```c
NODO *mezcla_descendente(NODO *p, NODO *s, NODO *n, NODO **q)
{
	int dato;

	if ((p != NULL) || (s != NULL))
	{
		if (p == NULL)
		{
			n = mezcla_descendente(p, s->liga, n, &(*q));
			printf("\n [%i] ", s->num);	

			dato = s->num;
		}
		else if (s == NULL)
		{
			n = mezcla_descendente(p->liga, s, n, &(*q));
			printf("\n [%i] ", p->num);

			dato = p->num;
		}
		else if (p->num <= s->num)
		{
			n = mezcla_descendente(p->liga, s, n, &(*q));
			printf("\n [%i] ", p->num);

			dato = p->num;
		}

		else if (s->num < p->num)
		{
			n = mezcla_descendente(p, s->liga, n, &(*q));
			printf("\n [%i] ", s->num);

			dato = s->num;
		}

		// ------------------------------------
		n = enlazado(n, &(*q), dato);

	}else
		printf("\n------------------------------");

	return (n);
}
```

7. dada una lista con numeros, dividala en dos listas independientes. una con numeros positivos y otra con los numeros negativos.

este algoritmo trabaja en conjunto con la funcion: _enlazado()_ vista anteriormente(algoritmo 5).

## algoritmo
* **p** es el apuntador al primer nodo de la lista
* **dato** es la información del nodo a insertar
* **q, r, t, pos, neg** son variables de tipo apuntador
* **num, liga** son los campos de cada nodo de la lista
* la funcion: _recorreRecursivo()_ es solo para mostrar la lista (opcional)

````c
divide_lista(p)
{
	Para (q = p; q != NULL ; q = q->liga)
	{
		Si (q->num < 0)
			neg = enlazado(neg, &r, q->num);
		Sino
			pos = enlazado(pos, &t, q->num);		
	}

	escribir("\nMostrar negativos: "); recorreRecursivo(neg);
	escribir("\nMostrar positivos: "); recorreRecursivo(pos);
}
````


## Código en C

````c
void divide_lista(NODO *p)
{
	NODO *pos = NULL, *neg = NULL;
	NODO *t = NULL, *r = NULL;
	NODO *q;

	for (q = p; q != NULL ; q = q->liga)
	{
		if (q->num < 0)
			neg = enlazado(neg, &r, q->num);
		
		else
			pos = enlazado(pos, &t, q->num);		
	}

	printf("\nMostrar negativos: "); recorreRecursivo(neg);
	printf("\nMostrar positivos: "); recorreRecursivo(pos);
}
````

8. programa recursivo para imprimir toda la informacion de una lista.

## algoritmo
* **p** es el apuntador al primer nodo de la lista
* **num, liga** son los campos de cada nodo de la lista

````c
recorreRecursivo(p)
{
	Si (p != NULL)
	{
		escribir("%2d-> ", p->num)

		Si(p->liga != NULL)
		  	recorreRecursivo(p->liga)
	}
	Sino 
	    escribir("\tLa lista esta vacia")

	retornar
}
````


## Código en C

````c
void recorreRecursivo(NODO *p)
{
	if (p != NULL)
	{
		printf("%2d-> ", p->num);

		if(p->liga != NULL)
		  	recorreRecursivo(p->liga);
	}
	else 
	    printf("\tLa lista esta vacia");

	return;
}
````

9. programa recursivo que busque un elemento en una lista doblemente ligada.

## algoritmo

* **p** es el apuntador al primer nodo de la lista}
* **f** es el apuntador al ultimo nodo de la lista}
* **x** es la información del nodo a buscar}
* **num, der, izq** son los campos de cada nodo de la lista}

```c
busqueda_x_doble(p, f, x)
{
	Si ((p != NULL) y (f != NULL))
	{
		Si ((p->num == x) o (f->num == x))
			escribir("Elemento [%d] encontrado", x)
		Sino Si((p == f) o (p->der == f))
			escribir("Elemento [%d] no se encontro en la lista", x)
		Sino
			busqueda_x_doble(p->der, f->izq, x)
	}

	retornar
}
```


## Código en C

```c
void busqueda_x_doble(const NODO *p,const NODO *f, int x)
{
	if (p != NULL && f != NULL)
	{
		if (p->num == x || f->num == x)
			printf("\n Elemento [%d] encontrado", x);
		else if(p == f || p->der == f)
			printf("\n Elemento [%d] no se encontro en la lista",x);
		else
			busqueda_x_doble(p->der, f->izq, x);
	}

	return;
}
```

11. define un algoritmo para insertar elementos en una lista circular.
**este algoritmo es para insertar, no para crear la lista.**

## algoritmo

* **p** es el apuntador al primer nodo de la lista
* **dato** es la información del nodo a insertar
* **q, nodo** son variables de tipo apuntador
* **num, liga** son los campos de cada nodo de la lista

```c
insertarFinal_c(p, dato)
{
	Si (p != NULL)
	{
		q = p
		
		Crear(nodo)
		nodo->num = dato

		Si(q->liga != NULL)
		{
			Mientras(q->liga != p)
				q = q->liga
		}

		q->liga = nodo
		nodo->liga = p
	}

	Retornar(p)
}
```

> este algoritmo inserta al fina de la lista.



## Código en C

```c
NODO *insertarFinal_c(NODO *p, int dato)
{
	if (p != NULL)
	{
		NODO *q = p;
		
		NODO *nodo = creaNodo();
		nodo->num = dato;

		if(q->liga != NULL)
		{
			while(q->liga != p)
				q = q->liga;
		}

		q->liga = nodo;
		nodo->liga = p;
	}

	return p;
}
```

13. programa recursivo que permite recorrer una lista doble ligada en ambos sentidos.

## algoritmo
* **p** es el apuntador al primer nodo de la lista
* **f** es el apuntador al ultimo nodo de la lista
* **num, der, izq** son los campos de cada nodo de la lista
	
````c
recorreRecursivo_doble(p, f)
{
	Si (p != NULL && f != NULL)
	{
		escribir("%2d%2d", p->num, f->num);

		Si(p->der != NULL)
		  	recorreRecursivo(p->der, f->izq);
	}
	Sino 
	    escribir("\tLa lista esta vacia");

	retornar;
}
````


## Código en C

````c
void recorreRecursivo_doble(NODO *p, NODO *f)
{
	if (p != NULL && f != NULL)
	{
		printf("%2d%2d", p->num, f->num);

		if(p->der != NULL)
		  	recorreRecursivo_doble(p->der, f->izq);
	}
	else 
	    printf("\tLa lista esta vacia");

	return;
}
````

14. algoritmo recursivo para insertar un elemento siguiendo a otro nodo dado como referencia, en una lista doblemente ligada.

## algoritmo

* **p** es el apuntador al primer nodo de la lista
* **f** es puntero a puntero al ultimo nodo de la lista
* **x** es la información del nodo de referencia
* **dato** es la información del nodo a insertar
* **q, t, nodo** son variables de tipo apuntador
* **num, der, izq** son los campos de cada nodo de la lista
* **band** variable tipo entero

```c
inserta_despues_x(p, *f, x, dato)
{
	static band = 1

	Si ((band == 1) y (p != NULL) y (*f != NULL))
	{
		Si ((p->num == x) o ((*f)->num == x))
		{
			Crear(q)
			q->num = dato

			Si (p->num == x)  {si lo encuentra p}
			{
				t = p->der

				q->der = t
				q->izq = p
				t->izq = q
				p->der = q
			}
			Sino  {si lo encuentra f}
			{
				Si((*f)->der == NULL) {si es el ultimo nodo}
				{
					q->der = NULL
					q->izq = *f
					(*f)->der = q
					*f = q
				}
			}
			
			band = 0
		}
		Sino Si (p == *f)
		{
			Escribir("NODO [%d] dado como referencia no se encontro en la lista", x)
			band = 0
		}
		Sino
			p->der = inserta_despues_x(p->der, &(*f), x, dato)
	}
	Sino
		Escribir("La lista esta vacia")

	retornar(p)
}
```


## Código en C

```c
NODO *inserta_despues_x(NODO *p, NODO **f, int x, int dato)
{
	static int band = 1;

	if (band == 1 && p != NULL && *f != NULL)
	{
		if (p->num == x || (*f)->num == x)
		{
			NODO *q = creaNodo();
			q->num = dato;

			if (p->num == x) // si lo encuentra p
			{
				NODO *t = p->der;

				q->der = t;
				q->izq = p;
				t->izq = q;
				p->der = q;
			}
			else // si lo encuentra f
			{
				if((*f)->der == NULL) // si es el ultimo nodo
				{
					q->der = NULL;
					q->izq = *f;
					(*f)->der = q;
					*f = q;
				}
			}
			
			band = 0;
		
		}else if (p == *f)
		{
			printf(" NODO [%d] dado como referencia no se encontro en la lista", x);
			band = 0;
		}else
			p->der = inserta_despues_x(p->der, &(*f), x, dato);
	}else
		printf(" La lista esta vacia");

	return p;
}
```

16. Defina los algoritmos necesarios para implementar estructura tipo cola mediante listas.
**algoritmos: mete_cola y saca_cola**

## algoritmo

* **p** es el apuntador al primer nodo de la lista
* **dato** es la información del nodo a insertar
* **q, t, nodo** son variables de tipo apuntador
* **num, liga** son los campos de cada nodo de la lista

* algoritmo mete_cola
```c
Mete_Cola(p, dato)
{
	Si(p == NULL)
	{
		Crea(p)
		p->num = dato
		p->liga = NULL
	}
	Sino
	{
		Crea(nodo)
		nodo->num = dato
		nodo->liga = NULL

		q = p

		mientras(q->liga != NULL)
			q = q->liga

		q->liga = nodo
	}

	retornar(p)
}
```

* algoritmo saca_cola
```c
Saca_Cola(p)
{
	Si(p != NULL)
	{
		q = p

		p = p->liga { MOVER AL SIGUIENTE NODO }
		
		escribir("NODO [%i] eliminado", q->num)
		Quitar(q)
	}

	retornar(p)
}
```

## Código en C

* algoritmo mete_cola
```c
NODO *Mete_Cola(NODO *p, int dato)
{
	NODO *nodo;

	if (p == NULL)
	{
		p = creaNodo();
		p->num = dato;
		p->liga = NULL;
	}
	else
	{
		nodo = creaNodo();
		nodo->num = dato;
		nodo->liga = NULL;

		NODO *q;

		for (q = p; q->liga != NULL; q = q->liga);

		q->liga = nodo;
	}

	return p;
}
```

* algoritmo saca_cola
```c
NODO *Saca_Cola(NODO *p)
{
	if(p != NULL)
	{
		NODO *q = p;

		p = p->liga; //	MOVER AL SIGUIENTE NODO
		
		printf("\n NODO [%i] eliminado\n", q->num);
		free(q);
	}

	return(p);
}
```

18. programa que elimine los elementos repetidos de una lista ordenada ascendentemente.

## algoritmo

* **p** es el apuntador al primer nodo de la lista
* **q, t** son variables de tipo apuntador
* **num, liga** son los campos de cada nodo de la lista


```c
unique_or(p)
{
	q = p

	meintras(q->liga != NULL)
	{
		t = q->liga
		
		Si (q->num == t->num)
		{
			q->liga = t->liga
			t->liga = NULL
			Quitar(t)
		}
		Sino
			q = q->liga
	}

	retornar(p)
}
```


## Código en C


```c
NODO *unique_or(NODO *p)
{
	NODO *q = p;
	NODO *t;

	while(q->liga != NULL)
	{
		t = q->liga;
		if (q->num == t->num)
		{
			q->liga = t->liga;
			t->liga = NULL;
			free(t);
		}else
			q = q->liga;
	}

	return p;
}
```