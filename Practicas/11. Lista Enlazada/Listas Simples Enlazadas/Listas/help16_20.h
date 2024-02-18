#ifndef  HELP16_20_H
#define HELP16_20_H 

// PROTOTIPO DE FUNCIONES
	
	// ALGORITMOS
	NODO *ordena_descendente(NODO *);
	NODO *ordena_ascendente(NODO *);
	NODO *crea_descendente();
	NODO *crea_ascendente();
	
	
// DEFINICION DE FUNCIONES

NODO *ordena_descendente(NODO *p) // OK
{	
	int aux = 0;
	NODO *i, *j;
	i = p;

	do { 
		for(j = p; j->liga != NULL; j = j->liga)
		{  
			if (j->num <= j->liga->num)
			{
				aux = j->num;
				j->num = j->liga->num;
				j->liga->num = aux;
			}
		}   

		i = i->liga;

	  }while (i != NULL);

	return(p);
}

NODO *ordena_ascendente(NODO *p) // OK
{
	int aux = 0;
	NODO *i, *j;
	
	i = p;
	
	do
	{
		for(j = p; j->liga != NULL; j = j->liga)
		{
		  	if (j->num >= j->liga->num)
		  	{
		  	  	aux = j->num;
		  		j->num = j->liga->num;
		  		j->liga->num = aux;		  	
			}
	  	}

		i = i->liga;
	}while (i != NULL);

	return(p);
}

NODO *crea_descendente() // OK
{
	int i, num, band = 1, aux;
	
	NODO *p, *q, *r, *t;
	
	
	printf("\n [letra para terminar] Introduzca un numero entero: ");
	i = scanf("%d",&num);
	fflush(stdin);
		
	if (i != 1) // VALIDANDO SI INTRODUJO UN VALOR INCORRECTO
		return NULL;
	else   
	{
		p = creaNodo();
		p->num = num;
		p->liga = NULL;

		do {
			printf("\n [letra para terminar] Introduzca un numero entero: ");
			i = scanf("%d",&num);
			fflush(stdin);

			if (i != 1) // VALIDANDO SI INTRODUJO UN VALOR INCORRECTO
			    band = 0;
			else
			{
				q = creaNodo();
				q->num = num;

			    if(q->num >= p->num) // si es mayor al primer elemento ponerlo al inicio
		        {
		          	q->liga = p;
		          	p = q;
				}
				else 
				{
				    if (p->liga == NULL) // en el caso que solo aya un solo elemento
		            {
		                p->liga = q;
		                q->liga = NULL;
					}
					else // sino recorrer a los nodos siguientes hasta encontrar un POSICION INDICADA DEL NODO
					{	
						aux = 1;

						// MODO DE INSERTAR EN MEDIO DE DOS NODOS
						for(t = p; t->liga != NULL; t = t->liga )
						{
							r = t->liga; // nodo adelantado

							if((t->num > q->num) && (q->num >= r->num))
							{ 
								// t->num > q->num >= r->num

								t->liga = q;
								q->liga = r;
								aux = 0;
							}
						}

						if(aux == 1) // SI ES EL MENOR DE LA LISTA, VA AL FINAL
						{
							t->liga = q;
							q->liga = NULL;
						}
					}
		    	}
			}
		}while (band == 1);
	}// fin del else 1
	 
	return(p);
}


NODO *crea_ascendente() // OK
{
	int i, num, band = 1, aux;
	
	NODO *p, *q, *r, *t;
	
	
	printf("\n [letra para terminar] Introduzca un numero entero: ");
	i = scanf("%d",&num);
	fflush(stdin);
		
	if (i != 1) // VALIDANDO SI INTRODUJO UN VALOR INCORRECTO
		return NULL;
	else   
	{
		p = creaNodo();
		p->num = num;
		p->liga = NULL;

		do {
			printf("\n [letra para terminar] Introduzca un numero entero: ");
			i = scanf("%d",&num);
			fflush(stdin);

			if (i != 1) // VALIDANDO SI INTRODUJO UN VALOR INCORRECTO
			    band = 0;
			else
			{
				q = creaNodo();
				q->num = num;

			    if(q->num <= p->num) // si es mayor al primer elemento ponerlo al inicio
		        {
		          	q->liga = p;
		          	p = q;
				}
				else 
				{
				    if (p->liga == NULL) // en el caso que solo aya un solo elemento
		            {
		                p->liga = q;
		                q->liga = NULL;
					}
					else // sino recorrer a los nodos siguientes hasta encontrar un POSICION INDICADA DEL NODO
					{	
						aux = 1;

						// MODO DE INSERTAR EN MEDIO DE DOS NODOS
						for(t = p; t->liga != NULL; t = t->liga )
						{
							r = t->liga; // nodo adelantado

							if((t->num < q->num) && (q->num <= r->num))
							{ 
								// t->num < q->num <= r->num

								t->liga = q;
								q->liga = r;
								aux = 0;
							}
						}

						if(aux == 1) // SI ES EL MAYOR DE LA LISTA, VA AL FINAL
						{
							t->liga = q;
							q->liga = NULL;
						}
					}
		    	}
			}
		}while (band == 1);
	}// fin del else 1
	 
	return(p);
}

#endif