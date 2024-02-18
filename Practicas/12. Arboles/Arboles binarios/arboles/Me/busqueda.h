#ifndef BUSQUEDA_H
#define BUSQUEDA_H 

	// funciones
	void busqueda_ABB(Arbol *p, int info);
	// void  busqueda1(Arbol *, int info);
	// int   buscar_menor(Arbol *, int menor);
	// int   buscar_mayor(Arbol *, int mayor);
	// void  hojas(Arbol *);
	
// ---------------------------------------------------------------
void busqueda_ABB(Arbol *p, int info)
{
	if(info < p->info)
	{
		if(p->izq == NULL)
			printf("\n\tla informacion no se encuentra en el arbol");		
		else
			busqueda_ABB(p->izq, info);
	}
	else if(info > p->info)
	{
		if(p->der == NULL)
			printf("\n\tla informacion no se encuentra en el arbol");
		else 
			busqueda_ABB(p->der, info);
	}
	else 
		printf("\n\tnodo[%d] encontrado",info);

	return;
}

#endif