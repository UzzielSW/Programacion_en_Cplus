#ifndef HELP6_10_H
#define HELP6_10_H 

// PROTOTIPO DE FUNCIONES

	// VACIAR LISTA
	NODO *liberaMemoria(NODO *);
	
	// ALGORITMOS
	NODO *inserta_antes_X(NODO *);
	NODO *inserta_despues_X(NODO *);
	NODO *elimina_inicio(NODO *);
	NODO *elimina_ultimo(NODO *);
	NODO *elimina_X(NODO *);

// DEFINICION DE FUNCIONES

// VACIAR LISTA

NODO *liberaMemoria(NODO *p)
{
	if(p == NULL) return p; //VALIDANDO

	NODO *q;

	while(p != NULL)
	{
		q = p;
		p = p->liga;
		free(q);		
	}

	printf("\n\n\tLa memoria ha sido liberada");	

	return(p);
}

// ALGORITMOS

NODO *inserta_antes_X(NODO *p)
{
	//VALIDAR QUE LA LISTA SE AYA CREADO

	if(p == NULL){
		printf("\nNO SE PUEDE INSERTAR EN LA LISTA SIN ANTES CREARLA");
		return p;
	}

	// DATOS

	int band = 1, dato, X;
	int i, j;
	NODO *t, *q, *n;


	printf("\n [NODO a Insertar] Introduzca un valor entero: ");
		i = scanf("%i",&dato);
	printf(" ANTES del elemento: ");
		j = scanf("%i",&X);
	
	if(!i || !j) return p; // VALIDANDO

	// ALGORITMO
	q = p;

	while((q->num != X) && (band == 1)) // BUSCANDO NODO X
	{
		if (q->liga != NULL)
		{
			t = q; 	// NODO t persigue a q	
			q = q->liga; 
		}
		else // si llego al final [no se encontro NODO X]
			band = 0;
	}

	if (band == 1) // si lo encontro
	{
		n = creaNodo();
		n->num = dato;

		if (p == q) //para el primer NODO
		{
			n->liga = p;  
			p = n;

		}else{ // en cualquier otra posicion
			t->liga = n;  
			n->liga = q;
		}
	}
	else	// si llego al final
		printf("\n el NODO dado como referencia [X]:[%d] no fue encontrado en la lista:\n",X);

	return(p);	
}


NODO *inserta_despues_X(NODO *p)
{
	//VALIDAR QUE LA LISTA SE AYA CREADO

	if(p == NULL){
		printf("\nNO SE PUEDE INSERTAR EN LA LISTA SIN ANTES CREARLA");
		return p;
	}

	// DATOS

	int band = 1, dato, X;
	int i, j;
	NODO *t, *q;


	printf("\n [NODO a Insertar] Introduzca un valor entero: ");
		i = scanf("%i",&dato);
	printf(" DESPUES del elemento: ");
		j = scanf("%i",&X);
	
	if(!i || !j) return p; // VALIDANDO

	// ALGORITMO
	q = p;

	while((q->num != X) && (band == 1)) // BUSCANDO ELEMENTO X
	{
		if (q->liga != NULL)
			q = q->liga;
		else // SI LLEGO AL FINAL
			band = 0;
	}

	if (band == 1) // SI SE ENCONTRO
	{
		t = creaNodo();
		t->num = dato;
		t->liga = q->liga;
		q->liga = t;

	}else // SI LLEGO AL FINAL
		printf("\n el NODO dado como referencia [X]:[%d] no fue encontrado en la lista:\n",X);
	
	return(p);
}


NODO *elimina_inicio(NODO *p)
{	
	if(p == NULL) return p; // VALIDANDO

	NODO *q = p;

	p = q->liga; //	MOVER AL SIGUIENTE NODO
	
	printf("\n NODO [%i] eliminado\n", q->num);
	free(q);

	return(p);
}


NODO *elimina_ultimo(NODO *p)
{
	if(p == NULL) return p; // VALIDANDO

	NODO *t, *q = p;

	if (q->liga == NULL) // SI HAY UN SOLO ELEMENTO
		p = NULL;
	else
	{
		while(q->liga != NULL) // MOVERSE HASTA EL ULTIMO ELEMENTO
		{
			t = q;
			q = q->liga;
		}

		t->liga = NULL;
	}

	printf("\n NODO [%i] eliminado\n", q->num);
	free(q);

	return(p);
}


NODO *elimina_X(NODO *p)
{
	if(p == NULL) return p; // VALIDANDO

	// DATOS

	int BAND = 1, X;
	int i, j;
	NODO *q, *t;
	

	printf("\n Elemento X a eliminar: ");
		i = scanf("%i",&X);
	
	if(!i) return p; // VALIDANDO

	// ALGORITMO
	q = p;
	
	while ((q->num != X) && (BAND == 1))
	{
		if(q->liga != NULL)
		{
		  	t = q;
		  	q = q->liga;
		}else 
		   BAND = 0;   
	}
      
    if (BAND == 1)
    {
    	if (p == q)
          	p = p->liga;
        else
            t->liga = q->liga;
	   
	   free(q);
	}
    else
    	printf("\n el NODO dado como referencia [X]:[%d] no fue encontrado en la lista:\n",X);

	return(p);
}


#endif