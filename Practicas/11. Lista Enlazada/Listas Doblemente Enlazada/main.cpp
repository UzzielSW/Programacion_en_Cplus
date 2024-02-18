#include <stdio.h>
#include <stdlib.h>

#include "help.h"
#include "algorithm.h"

int main()
{	
	NODO *p = NULL, *f = NULL;


	for (int i = 0; i < 3; ++i)
		p = inserta_inicio(p, &f, getData());
	recorreRecursivo(p);

	f = inserta_final(f, &p, 0); recorreRecursivo(p);
	p = inserta_antes_x(p, 3, 4); recorreRecursivo(p);
	p = elimina_inicio(p, &f);  recorreRecursivo(p);
	f = elimina_final(f, &p);  recorreRecursivo(p);
	p = elimina_x(p, &f, 2);  recorreRecursivo(p);
	p = elimina_antes_x(p, 1); recorreRecursivo(p);

// ----------------------------------
	p = liberaMemoria(p, &f);
	fflush(stdin);
	getchar();
return 0;
}