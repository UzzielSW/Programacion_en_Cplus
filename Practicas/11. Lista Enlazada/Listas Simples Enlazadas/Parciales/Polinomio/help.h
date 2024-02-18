#ifndef HELP_H
#define HELP_H 

struct Polinomio{
	int grado, coef;
	Polinomio *liga;
};

Polinomio *crea_polinomio();
void *crea_memoria_polinomio(int n);

// -------------------------------------------------------------
Polinomio *crea_polinomio(){	return (Polinomio *) crea_memoria_polinomio(sizeof(Polinomio));}

void *crea_memoria_polinomio(int n)
{
	void *p = (int *) malloc(n);
	
	if (p == NULL)
	{
		puts("\n no hay memoria disponible");
		getchar();
		exit(1);
	}
	
	return p;
}

#endif