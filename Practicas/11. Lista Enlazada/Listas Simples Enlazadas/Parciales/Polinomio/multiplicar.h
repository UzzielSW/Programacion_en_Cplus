#ifndef MULTIPLICAR_H
#define MULTIPLICAR_H 

	Polinomio *multiplicar_polinomios(Polinomio *p1, Polinomio *p2);
	Polinomio *mtp2(Polinomio *a, Polinomio *b);

/////////		MULTIPLICAR 2 POLINOMIOS	/////////////
	
Polinomio *multiplicar_polinomios(Polinomio *p1, Polinomio *p2)
{
	Polinomio *q1, *q2, *pm, *tm, *rm;
	Polinomio *qm;
	bool band = false, aux;

	q1 = p1;

	while(q1 != NULL){ // 1
		q2 = p2;

		while(q2 != NULL){ // 1.1

			if (band == false) // 1.1.1
			{
				pm = crea_polinomio();
				pm->coef = (q1->coef * q2->coef);
				pm->grado = q1->grado + q2->grado;
				pm->liga = NULL;

				if (pm->coef != 0) // 1.1.1.1
					band = true;
				else // 1.1.1.2
					free(pm);

				q2 = q2->liga;
			}
			else
			{ // 1.1.2
				qm = crea_polinomio();
				qm->coef = (q1->coef * q2->coef);
				qm->grado = q1->grado + q2->grado;

				if (qm->coef != 0)	// 1.1.2.1
				{
					if (qm->grado >= pm->grado)	// 1.1.2.1.1
					{
						qm->liga = pm;
						pm = qm;
					}
					else
					{ // 1.1.2.1.2

						if (pm->liga == NULL) // 1.1.2.1.2.1
						{
							pm->liga = qm;
							qm->liga = NULL;
						}
						else
						{	//1.1.2.1.2.2
							aux = true;
							tm = pm;

							while(tm->liga != NULL && aux == true){
								rm = tm->liga;

								if ((tm->grado > qm->grado) && (qm->grado >= rm->grado))
								{
									tm->liga = qm;
									qm->liga = rm;
									aux = false;
								}else
									tm = tm->liga;
							}

							if (aux == true)
							{
								tm->liga = qm;
								qm->liga = NULL;
							}
						}
					}

					q2 = q2->liga;
				}
				else  free(qm);
			}	
		}

		q1 = q1->liga;		
	}

	pm = reduce_polinomio(pm);

	return pm;
}


Polinomio *mtp2(Polinomio *a, Polinomio *b)
{
	int coef, grado;
	Polinomio *x = NULL, *s, *t, *q;
	
	s = a;

	while(a != NULL && b != NULL)
	{
		while(a != NULL)
		{
		    coef = a->coef * b->coef;
			grado = a->grado + b->grado;
			
			if(x == NULL)
			{
				x = (Polinomio*) malloc(sizeof(Polinomio));
				x->coef = coef;
				x->grado = grado;
				x->liga = NULL;
				t = x;
			}
			else if(x != NULL)
			{
				q = (Polinomio*) malloc(sizeof(Polinomio));
				q->coef	= coef;
				q->grado = grado;
				q->liga = NULL;
				t->liga = q;
				t = q;
			}

			a = a->liga;
		}


		if(b->liga != NULL)
		{
			a = s;
			b = b->liga;
		}
	}

	x = reduce_polinomio(x);

	return x;
}


#endif