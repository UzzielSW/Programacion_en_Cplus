#ifndef INSERCION_H
#define INSERCION_H

Arbol *insercion_ABB(Arbol *p, int info);
Arbol *insercion_AVL(Arbol *, int bo, int info);
// ---------------------------------------------------------------------

Arbol *insercion_ABB(Arbol *p, int info)
{
	Arbol *q;

	if (info < p->info)
	{
		if (p->izq == NULL)
		{
			q = new Arbol();
			q->info = info;
			p->izq = q;
		}
		else
			insercion_ABB(p->izq, info);
	}
	else if (info > p->info)
	{
		if (p->der == NULL)
		{
			q = new Arbol();
			q->info = info;
			p->der = q;
		}
		else
			insercion_ABB(p->der, info);
	}
	else
		printf("\n el nodo[%d] ya se encuentra en el arbol", info);

	return (p);
}
#endif