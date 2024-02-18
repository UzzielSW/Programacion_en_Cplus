#ifndef HELP1_5_H
#define HELP1_5_H 

// ESTRUCTURA
struct NODO{
	int num;
	struct NODO *liga;
};

// PROTOTIPO DE FUNCIONES

	// CREAR NODO
	void *creaMemoria(int n);
	NODO *creaNodo();
	
	// ALGORITMOS
	NODO *creaInicio();
	NODO *creaFinal();
	void recorreIterativo(NODO *);
	void recorreRecursivo(NODO *);
	NODO *insertarInicio(NODO *);
	NODO *insertarFinal(NODO *);


// DEFINICION DE FUNCIONES

// CREAR NODO
	
void *creaMemoria(int n)
{
	void *p = (int *) malloc(n);
	if (p == NULL)
	{
	 	puts("Lo siento no hay memoria disponible");
	 	getchar();
	    exit(1);
	}
	
  return (p);	
}

NODO *creaNodo() {	return (NODO *) creaMemoria(sizeof(NODO));	}

// ALGORITMOS

NODO *creaInicio()
{
	int i, num;
	NODO *p, *q;
	
	p = creaNodo();
	
	printf("\n Introduzca un valor entero: ");
	i = scanf("%d",&num);
	fflush(stdin);
	
	if(i == 1)
	{
		p->num = num;
		p->liga = NULL;
		 
		do{
		 	q = creaNodo();

		 	printf("\n Introduzca un valor entero: ");
	        i = scanf("%d",&num);
	        fflush(stdin);

	        if(i == 1)
	    	{ 
			    q->num = num;
				q->liga = p;
				p = q;
		    }else{
		     	free(q);
		     	break;
			}
				   
		}while(i == 1);
   }
   else // en caso de que la validacion del primer nodo no sea correcta
   		return NULL;
   
   return p;  
}  


NODO *creaFinal()
{
	int i, num;
	NODO *p, *t, *q;
	
	p = creaNodo();
	
	printf("\n Introduzca un valor entero: ");
	i = scanf("%d",&num);

	if(i == 1)
	{
	 	p->num = num;
	 	p->liga = NULL;

	 	t = p;

		do
		{
		 	q = creaNodo();

		 	printf("\n Introduzca un valor entero: ");
	        i = scanf("%d",&num);
	        fflush(stdin);

	        if(i == 1)
			{ 
			    q->num = num;
				q->liga = NULL;
				t->liga = q;
				t = q;
			} 
			else{
				free(q);
				break;
			}
				   
		}while(i == 1);	
	}
	else
		return NULL;
   
	return p;  
}  


NODO *insertarInicio(NODO *p)
{	
	//VALIDAR QUE LA LISTA SE AYA CREADO

	if(p == NULL){
		printf("\nNO SE PUEDE INSERTAR EN LA LISTA SIN ANTES CREARLA");
		return p;
	}

	// ALGORITMO

	int num, i;
	NODO *q, *t;
	
	q = creaNodo();

	printf("\n Introduzca un valor entero: ");
	i = scanf("%d",&num);
	fflush(stdin);
	
	if(i == 1)
	{
		q->num = num;
		q->liga = p;
		p = q;

		do{
		 	t = creaNodo();

		 	printf("\n Introduzca un valor entero: ");
	        i = scanf("%d",&num);
	        fflush(stdin);

	        if(i == 1)
	    	{ 
			    t->num = num;
				t->liga = p;
				p = t;
		    }else{
		     	free(t);
		     	break;
			}
				   
		}while(i == 1);

	}else
		free(q);
	
	return p;
}


NODO *insertarFinal(NODO *p)
{	
	//VALIDAR QUE LA LISTA SE AYA CREADO

	if(p == NULL){
		printf("\nNO SE PUEDE INSERTAR EN LA LISTA SIN ANTES CREARLA");
		return p;
	}

	// ALGORITMO

	NODO *q, *t, *f;
	int num, i;

	t = p;
	
	while (t->liga != NULL) // RECORRER HASTA EL FINAL DE LA LISTA
	      t = t->liga;


	q = creaNodo();

	printf("\n Introduzca un valor entero: ");
	i = scanf("%d",&num);
	fflush(stdin);
	
	if(i == 1)
	{
		q->num = num;
		q->liga = NULL;
		t->liga = q;
		t = t->liga;

		do{
		 	f = creaNodo();

		 	printf("\n Introduzca un valor entero: ");
	        i = scanf("%d",&num);
	        fflush(stdin);

	        if(i == 1)
	    	{ 
			    f->num = num;
				f->liga = NULL;
				t->liga = f;
				t = t->liga;
		    }else{
		     	free(f);
		     	break;
			}
				   
		}while(i == 1);

	}else
		free(q);
	
	return(p);	   
}


// RECORRER LA LISTA

void recorreRecursivo(NODO *p)
{
	if (p != NULL)
	{
		printf("%2d-> ", p->num);

		if(p->liga != NULL)
		  	recorreRecursivo(p->liga);
		else
		    printf("%s", p->liga);	
	}
	else 
	    printf("\n\t\tLa lista esta vacia");
}


void recorreIterativo(NODO *p)
{
	if(p != NULL)
	{
		NODO *q;
		printf("\n [");

		for(q = p; q != NULL; q = q->liga)
        	printf("%2d,",q->num);

		printf("%s]",q);			
	}
	else
		printf("\n\tLa lista esta vacia");
}

#endif
