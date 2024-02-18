#ifndef EVALUAR_H
#define EVALUAR_H 
	
	float evalua_polinomio_i(Polinomio *, float);
	float evalua_polinomio_r(Polinomio *, float); // ejercicio 15


/////////    EVALUAR UN POLINOMIO CON X 	/////////

///ITERATIVO
float evalua_polinomio_i(Polinomio *p, float x)
{
	float suma = 0;
	Polinomio *q = p;
	// en caso de tener q evaluar 0, solo sumar los numeros
	if (x == 0) // 1
	{
		while(q != NULL) // 1.1
		{
			if (q->grado == 0)	suma += q->coef;
			q = q->liga; 
		}
	}
	else // 2
	{ 
		while(q != NULL) //2.1
		{ 
			suma += q->coef * pow(x, q->grado);
			q = q->liga;
			// printf("\n %.2f",suma);
		};
	}

	return suma;
}


// RECURSIVO
float evalua_polinomio_r(Polinomio *p, float x)
{
	float suma = 0;

	if(p != NULL)
	{
		if (x == 0) // 1
		{
			if (p->grado == 0)		suma += p->coef;
			if (p->liga != NULL)	suma += evalua_polinomio_r(p->liga, x); 
		}
		else // 2
		{  
			suma += p->coef * pow(x, p->grado);
			if (p->liga != NULL)	suma += evalua_polinomio_r(p->liga, x); 
		}
	}else
		printf("\n\n no se ha leido Polinomio");

	return suma;
}
#endif