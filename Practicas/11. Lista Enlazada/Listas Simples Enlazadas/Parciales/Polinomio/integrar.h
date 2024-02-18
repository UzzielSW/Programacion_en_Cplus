#ifndef INTEGRAR_H
#define INTEGRAR_H 

// en correccion
void integrar(Polinomio *p) 
{ 
	int coef, grado;
	bool band = false; //forma normal

	for(Polinomio *q = p; q != NULL; q = q->liga)
	{
		coef = q->coef;
		
		if (q->grado != -1) // excepcion de integracion
		{
			grado = q->grado + 1;

			if((coef % grado) == 0)
			{
				coef = coef / grado;
				band = true;
			}

			if (band == true)
			{
				if (coef < 0)
					printf(" %d[x^%d]",coef,grado);
				else
					printf(" + %d[x^%d]",coef,grado);
			}
			else //forma normal
			{
				if ((coef<0 && grado>0) || (coef>0 && grado<0)) // signos contrarios
					printf(" - (%d / %d)[x^%d]",coef,grado,grado);
				else
					printf(" + (%d / %d)[x^%d]",coef,grado,grado);
			}
		}
		else // en caso de q->grado = -1
		{
			if (coef < 0)
				printf(" %dLn(x)",coef);
			else
				printf(" + %dLn(x)",coef);
		}
	} 
} 

#endif