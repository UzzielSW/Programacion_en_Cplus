#ifndef SUMAR_H
#define SUMAR_H 

	Polinomio *sumar_polinomios(Polinomio *p1, Polinomio *p2);
	Polinomio *sumar_polinomios_of(Polinomio *, Polinomio *);


///////////	 	SUMAR 2 POLINOMIOS 	 ///////////

Polinomio *sumar_polinomios(Polinomio *p1, Polinomio *p2)
{
	Polinomio *q1, *q2, *ps, *qs, *ts, *rs, *fs, *g;
	bool band = false, aux, indicador;

	q1 = p1;
	q2 = p2;

	while((q1 != NULL) && (q2 != NULL) && (band == false)) // 1
	{
		ps = crea_polinomio();

		if (q1->grado == q2->grado) // 1.1
		{
			ps->coef = (q1->coef + q2->coef);
			ps->grado = q1->grado;
			ps->liga = NULL;

			q1 = q1->liga;
			q2 = q2->liga;

			if (ps->coef != 0)	band = true;  // 1.1.1
			else	free(ps);	// 1.1.2
		}
		else{	// 1.2
			if (q1->grado > q2->grado) // 1.2.1
			{
				ps->coef = q1->coef;
				ps->grado = q1->grado;
				ps->liga = NULL;

				q1 = q1->liga;
				band = true;
			}
			else{	// 1.2.2
				ps->coef = q2->coef;
				ps->grado = q2->grado;
				ps->liga = NULL;

				q2 = q2->liga;
				band = true;
			}
		}
	} // 1


	while((q1 != NULL) && (q2 != NULL) && (band == true)) // 2
	{
		indicador = true;

		qs = crea_polinomio();

		if (q1->grado == q2->grado)	// 2.1
		{
			qs->coef = (q1->coef + q2->coef);
			qs->grado = q1->grado;

			if (qs->coef == 0)	// 2.1.1
			{
				free(qs);
				indicador = false;
			}

			q1 = q1->liga;
			q2 = q2->liga;
		}
		else{	// 2.2
			if (q1->grado > q2->grado) //2.2.1
			{
				qs->coef = q1->coef;
				qs->grado = q1->grado;

				q1 = q1->liga;
			}
			else{	// 2.2.2
				qs->coef = q2->coef;
				qs->grado = q2->grado;

				q2 = q2->liga;
			}
		}


		if (indicador == true)	// 2.3
		{
			if (qs->grado >= ps->grado) // 2.3.1
			{
				qs->liga = ps;
				ps = qs;
			}
			else{	// 2.3.2
				if (ps->liga == NULL)	// 2.3.2.1
				{
					ps->liga = qs;
					qs->liga = NULL;
				}
				else{	// 2.3.2.2
					aux = true;
					ts->grado = ps->grado;

					while(ts->liga != NULL){	// 2.3.2.2.1
						rs = ts->liga;

						if ((ts->grado > qs->grado) && (qs->grado >= rs->grado)) //2.3.2.2.1.1
						{
							ts->liga = qs;
							qs->liga = rs;
							aux = false;
						}
					}

					if(aux == true){	// 2.3.2.2.2
						ts->liga = qs;
						qs->liga = NULL;
					}
				}
			}
		}
	} // 2

	if (band == false) // 3
	{
		ps = NULL;
		return ps;
	}
	else{ // 4
		fs = ps;

		while(fs->liga != NULL){ 	// 4.1
			fs = fs->liga;
		}

		if ((q1 == NULL) && (q2 != NULL))	// 4.2
		{
			while(q2 != NULL)
			{		// 4.2.1
				g = crea_polinomio();

				g->coef = q2->coef;
				g->grado = q2->grado;
				g->liga = NULL;

				fs->liga = g;
				fs = g;

				q2 = q2->liga;
			}
		}
		else{	// 4.3
			if ((q1 != NULL) && (q2 == NULL))	// 4.3.1
			{
				while(q1 != NULL){	// 4.3.1.1
					g = crea_polinomio();

					g->coef = q1->coef;
					g->grado = q1->grado;
					g->liga = NULL;

					fs->liga = g;
					fs = g;

					q1 = q1->liga;
				}
			}
		}
	}

	return ps;
}


Polinomio *sumar_polinomios_of(Polinomio *p1, Polinomio *p2)
{
	Polinomio *q;
	Polinomio *suma = NULL;

	for(q = p1; q != NULL; q = q->liga)
		suma = insertar_in(suma, q->coef, q->grado);

	for(q = p2; q != NULL; q = q->liga)
		suma = insertar_in(suma, q->coef, q->grado);

	suma = reduce_polinomio(suma);

	return suma;
}

// corregir
Polinomio *suma(Polinomio *a,Polinomio *b)
{
	Polinomio *x, *t, *q;
	x=NULL;
	int coef , grado;
	
	while(a!=NULL && b!=NULL)
      {
      	if(a->grado == b->grado){
      		coef = a->coef+b->coef;
      		grado = a->grado;
      		a = a->liga;
      		b=b->liga;
		  }
		  else if(a->grado > b->grado){
		  		coef=a->coef;
      		    grado=a->grado;
      		    b=b->liga;
		  }
		  else if(a->grado<b->grado){
		  		coef=b->coef;
      		    grado=b->grado;
      		    a=a->liga;
		  }	 
		  	if(x==NULL){
		  		x=(Polinomio*)malloc(sizeof(Polinomio));
		  		x->coef=coef;
		  		x->grado=grado;
		    	x->liga=NULL;
			    t=x;
		  }
		  else if(x!=NULL){
		  	q=(Polinomio*)malloc(sizeof(Polinomio));
		  	q->coef=coef;
		  	q->grado=grado;
			q->liga=NULL;
			t->liga=q;
			t=q;
		  }
		  
	}
	return x;
}

#endif