#ifndef REDUCIR_H
#define REDUCIR_H 

	Polinomio *reduce_polinomio(Polinomio *p);

//////////    REDUCE UN POLINOMIO    ///////////

Polinomio *reduce_polinomio(Polinomio *p)
{
	Polinomio *q, *d, *a, *b;

	q = p; //iterador verificador
	a = p; //iterador antecesor

	while(q->liga != NULL)
	{
		d = q->liga; // iterador adelanto

		// en caso de encontrar terminos semejantes
		if (q->grado == d->grado) //reduccion
		{
			q->coef += d->coef;

			if (q->coef != 0) // eliminando solo por la reduccion
				q->liga = d->liga;

		/* en caso de eliminacion del termino por ejemplo [2x][-2x] */
			else
			{
				// caso que solo aya dos nodos en el polinomio
				if (p->liga->liga == NULL)
				{
					p = NULL;
					free(d);
					break;
				}
				// mas de dos nodos
				else
				{
					// eliminando los dos ultimos nodos del polinomio
					// [][][x][x]
					if (d->liga == NULL)
					{
						b = q;
						q = a; // reubicando
						q->liga = NULL; 
					}
					//dos nodos intermedios de mas nodos [][x][x][]
					else
					{ 
						b = q;
						q = d->liga;
						a->liga = q;
					}
					free(b);
				}
			}
			// todos los casos eliminamos d
			free(d);
		}
		// en caso de no encontrar coincidencia avanzar
		else
		{ 
			a = q;
			q = q->liga;
		}	
	}
	
	return p;
}

#endif