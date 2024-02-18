#ifndef HELP11_15_H
#define HELP11_15_H 

// PROTOTIPO DE FUNCIONES
	
	// EXTRA
	void reverse (NODO **x);

	// ALGORITMOS
	NODO *elimina_antes_X(NODO *);
	void busqueda_desordenada(NODO *);
	void busqueda_ordenada(NODO *);
	void busqueda_recursiva(NODO *);
	
	
// DEFINICION DE FUNCIONES


NODO *elimina_antes_X(NODO *p)
{
	if(p == NULL) return p; // VALIDANDO

	// DATOS

	NODO *q, *t, *r;
	int BAND = 1, X;
	int i;

	printf("\n [NODO X] Introduzca un valor entero: ");
	i = scanf("%i",&X);
	
	if(!i) return p; // VALIDANDO

	// ALGORITMO

    if (p->num == X) // EN EL CASO QUE SEA EL PRIMER NODO
	    q = p->liga;	   	
	else
       	q = p;

   	t = p;
				 
    while ((q->num != X) && (BAND == 1))
    {
		if(q->liga != NULL)
		{
			r = t;
			t = q;
			q = q->liga;
		}
		else 
			BAND = 0;   
	}
      
    if (BAND == 1) // SI LO ENCONTRO
    {
    	if (p->liga == q) // SI SE ELIMINARA EL PRIMER ELEMENTO
		   	p = q;
        else
		    r->liga = q;

        free(t);
    }
    else
    	printf("\n el NODO dado como referencia [X]:[%d] no fue encontrado en la lista o no hay nodo que le anteceda\n",X);
  	     
   
	return(p);	
}

void busqueda_desordenada(NODO *p)
{
	if(p == NULL) return; // VALIDANDO
	

	// DATOS
	NODO *q = p;
	int i, X;
	
	printf("\n [NODO X] Introduzca un valor entero: ");
	i = scanf("%i",&X);
	
	if(!i) return; // VALIDANDO


	// BUSQUEDA
	while ((q != NULL) && (q->num != X)) 
   		q = q->liga;
	
	if (q == NULL)
	 	printf("\n\n\t El elemento X:[%d] no fue encontrado en la lista",X);
	else
	    printf("\n\n\t Elemento [%d] esta en la lista",X);
}


void busqueda_ordenada(NODO *p)
{
	if(p == NULL) return; // VALIDANDO
	

	// DATOS
	NODO *q = p;
	int i, X;
	
	printf("\n [NODO X] Introduzca un valor entero: ");
	i = scanf("%i",&X);
	
	if(!i) return; // VALIDANDO


	// BUSQUEDA
	while ((q != NULL) && (q->num < X)) 
   		q = q->liga;
	
	if ((q == NULL)  || (q->num > X))
	 	printf("\n\n\t El elemento X:[%d] no fue encontrado en la lista",X);
	else
	    printf("\n\n\t Elemento [%d] esta en la lista",X);
}


void busqueda_recursiva(NODO *p, int X)
{
	if (p != NULL)
	{
	  	if (p->num == X){
	  	  	printf("\n\n\t Elemento [%d] esta en la lista",X);
	  	  	return;	  
	  	}
	   	else
	       	busqueda_recursiva(p->liga, X);
    } 
	else
	    printf("\n\n\t El elemento X:[%d] no esta en la lista",X);	         
}


void reverse(NODO **x)
{
	NODO  *q, *r, *s;
	q = *x;
	r = NULL;

	while (q != NULL)
	{
		s = r;
		r = q;
		q = q->liga;
		r->liga = s;
	}

	*x = r;
}

#endif
