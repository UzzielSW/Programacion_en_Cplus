#ifndef ELIMINACION_H
#define ELIMINACION_H

// funciones
Arbol *eliminacion_ABB(Arbol *p, int info);
Arbol *eliminacion_AVL(Arbol *, int bo, int info);

// -----------------------------------------------------------------------
Arbol *eliminacion_ABB(Arbol *p, int info)
{
	if (p == NULL)
	{
		printf("\n el nodo[%d] no se encuentra en el Arbol", info);
		return (p);
	}

	if (info < p->info)
		p->izq = eliminacion_ABB(p->izq, info);

	else if (info > p->info)
		p->der = eliminacion_ABB(p->der, info);

	else
	{
		Arbol *q = p;
		Arbol *aux;

		if (p->der == NULL)
			p = p->izq;

		else if (p->izq == NULL)
			p = p->der;

		else
		{
			aux = p;
			q = p->izq;

			while (q->der != NULL)
			{
				aux = q;
				q = q->der;
			}

			p->info = q->info;

			if (aux == p)
				p->izq = q->izq;
			else
				aux->der = q->izq;
		}

		free(q);
	}

	return (p);
}

#endif