/* Arboles */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define V 1
#define F 0

struct datos
{

	int info;
	int fe;
	struct datos *der;
	struct datos *izq;
};

typedef struct datos arbol;

void *crea_memoria(int infor);
arbol *crea_arbol();

arbol *carga_balanceado(arbol *p);
arbol *carga(arbol *p);
void pre_orden(arbol *p);
void in_orden(arbol *p);
void pos_orden(arbol *p);
void busqueda(arbol *p, int infor);
void busqueda1(arbol *p, int infor);
void insercion(arbol *p, int infor);
int buscar_menor(arbol *p, int menor);
int buscar_mayor(arbol *p, int mayor);
void hojas(arbol *p);
void inser_bal(arbol **nodo, int *bo, int infor);
void elim_bal(arbol **p, int *bo, int infor);
void restructura1(arbol **p, int *bo);
void restructura2(arbol **p, int *bo);
void borra(arbol **aux, arbol **otro, int *bo);
arbol *borraTodoElArbol(arbol *nodo);

int main(void)
{
	arbol *p = NULL;
	int bol, inf, sel, val, menor, mayor;
	char op;

	do
	{
		system("cls");
		printf("\n\t\t\t*_*_*_*_*_*_Menu de Opciones-*-*-*-*-*-*\n\n");
		printf("\t\t\t1.-Crea Arbol Balanceado \t2.-Crea Arbol\n");
		printf("\t\t\t3.-Ver Arbol Completo \t\t4. Borra El Arbol\n\n");
		printf("\t\t\t5.-Buscar \t\t\t6.-Buscar 1\n\n");
		printf("\t\t\t7.-Inserta \n");
		printf("\t\t\t8.-Inserta Balanceado\t\t9.-Eliminar Balanceado\n ");
		printf("\t\t\t10.-Buscar Menor\t\t11.-Buscar Mayor\n ");
		printf("\t\t\t12.-Hojas\t\t\t\n");
		printf("\t\t\t13.-Salir \n");
		printf("\t\t\t-Escoja su opcion:  ");
		scanf("%d", &sel);
		fflush(stdin);

		switch (sel)
		{

		case 1:
			system("cls");
			p = carga_balanceado(p);

			printf("\n\n\t\t Presione ENTER para continuar: ");
			getchar();
			break;

		case 2:
			system("cls");
			p = crea_arbol();
			p = carga(p);
			printf("\n\n\t\t Presione ENTER para continuar: ");
			getchar();
			break;

		case 3:
			system("cls");
			if (p != NULL)
			{
				printf("\n\nListado en PREORDEN\n");
				printf("\nVisita Raiz, ");
				printf("Recorre SubArbol Izquierdo ");
				printf(" y Recorre SubArbol Derecho\n\n");
				pre_orden(p);
				printf("\n\nListado en INORDEN\n");
				printf("\nRecorre SubArbol Izquierdo, ");
				printf("Visita Raiz ");
				printf(" y Recorre SubArbol Derecho\n\n");
				in_orden(p);
				printf("\n\nListado en POSORDEN\n");
				printf("\nRecorre SubArbol Izquierdo, ");
				printf(" Recorre SubArbol Derecho  ");
				printf(" y Visita Raiz \n\n");
				pos_orden(p);
			}
			else
				printf("\n\n\t\t El arbol no ha sido Cargado ");
			printf("\n\n\t\t Presione ENTER para continuar: ");
			getchar();
			break;

		case 4:
			system("cls");
			if (p != NULL)
			{
				printf("\n Lista de datos in_orden: \n");
				in_orden(p);
				p = borraTodoElArbol(p);
				hojas(p);
			}
			else
			{

				printf("\n\n\t\t El arbol no ha sido Cargado ");
			}

			printf("\n\n\t\t Presione ENTER para continuar: ");
			getchar();
			break;

		case 5:
			system("cls");
			if (p != NULL)
			{
				printf("\n El dato que desea buscar es: ? ");
				val = scanf("%d", &inf);
				fflush(stdin);
				if (val == V)
				{
					busqueda(p, inf);
					printf("\n\n\t\t Presione ENTER para continuar: ");
					getchar();
				}
			}
			else
			{

				printf("\n\n\t\t El arbol no ha sido Cargado ");
				printf("\n\n\t\t Presione ENTER para continuar: ");
				getchar();
			}
			break;

		case 6:
			system("cls");
			if (p != NULL)
			{
				printf("\n El dato que desea buscar es: ? ");
				val = scanf("%d", &inf);
				fflush(stdin);
				if (val == V)
				{
					busqueda1(p, inf);
					printf("\n\n\t\t Presione ENTER para continuar: ");
					getchar();
				}
			}
			else
			{

				printf("\n\n\t\t El arbol no ha sido Cargado ");
				printf("\n\n\t\t Presione ENTER para continuar: ");
				getchar();
			}

			break;

		case 7:
			system("cls");
			if (p != NULL)
			{
				printf("\n Lista de datos in_orden: \n");
				in_orden(p);
				printf("\n El dato que desea insertar es: ? ");
				val = scanf("%d", &inf);
				fflush(stdin);
				if (val == V)
				{
					insercion(p, inf);
					printf("\n Lista de datos in_orden: \n");
					in_orden(p);
					printf("\n\n\t\t Presione ENTER para continuar: ");
					getchar();
				}
			}
			else
			{

				printf("\n\n\t\t El arbol no ha sido Cargado ");
				printf("\n\n\t\t Presione ENTER para continuar: ");
				getchar();
			}

			break;

		case 8:
			system("cls");
			if (p != NULL)
			{
				printf("\n Lista de datos in_orden: \n");
				in_orden(p);
				printf("\n El dato que desea insertar es: ? ");
				val = scanf("%d", &inf);
				fflush(stdin);
				if (val == V)
				{
					inser_bal(&p, &bol, inf);
					printf("\n Lista de datos in_orden: \n");
					in_orden(p);
				}
			}
			else
			{

				printf("\n\n\t\t El arbol no ha sido Cargado ");
			}

			printf("\n\n\t\t Presione ENTER para continuar: ");
			getchar();
			break;

		case 9:
			system("cls");
			if (p != NULL)
			{
				printf("\n Lista de datos in_orden: \n");
				in_orden(p);
				printf("\n El dato que desea Eliminar es: ? ");
				val = scanf("%d", &inf);
				fflush(stdin);
				if (val == V)
				{
					elim_bal(&p, &bol, inf);
					printf("\n Lista de datos in_orden: \n");
					in_orden(p);

				} // fin del condicional (val == V)
			}	  // fin del condicional (p != NUll)
			else

				printf("\n\n\t\t El arbol no ha sido Cargado ");
			printf("\n\n\t\t Presione ENTER para continuar: ");
			getchar();
			break;

		case 10:

			system("cls");
			if (p != NULL)
			{
				printf("\n Lista de datos in_orden: \n");
				in_orden(p);
				buscar_menor(p, menor);
			}
			else
			{

				printf("\n\n\t\t El arbol no ha sido Cargado ");
			}

			printf("\n\n\t\t Presione ENTER para continuar: ");
			getchar();
			break;

		case 11:
			system("cls");
			if (p != NULL)
			{
				printf("\n Lista de datos in_orden: \n");
				in_orden(p);
				buscar_mayor(p, menor);
			}
			else
			{

				printf("\n\n\t\t El arbol no ha sido Cargado ");
			}

			printf("\n\n\t\t Presione ENTER para continuar: ");
			getchar();
			break;

		case 12:
			break;

		default:
			printf("\n\n\t\t Error la Opcion no es valida");
			printf("\n\n\t\t Presione ENTER para continuar: ");
			getchar();
			break;
		}
	} while (sel != 12);
	return 0;
}

void *crea_memoria(int n)
{
	void *p = (int *)malloc(n);
	if (p == NULL)
	{
		puts("LO siento no hay memoria disponible");
		getchar();
		exit(1);
	}

	return (p);
}

arbol *crea_arbol()
{
	return (arbol *)crea_memoria(sizeof(arbol));
}

arbol *carga_balanceado(arbol *p)
{
	arbol *q;
	int infor, bo;
	char resp;
	p = crea_arbol();
	printf("Introduzca la informacion--->");
	scanf("%d", &infor);
	fflush(stdin);
	p->info = infor;
	p->izq = NULL;
	p->der = NULL;
	printf("Desea Introducir otro nodo ? [s/n]--->  ");
	scanf("%c", &resp);
	fflush(stdin);
	if (resp == 's' || resp == 'S')
	{
		do
		{
			printf("Introduzca la informacion--->");
			scanf("%d", &infor);
			fflush(stdin);
			inser_bal(&p, &bo, infor);
			printf("Desea Introducir otro nodo ? [s/n]--->  ");
			scanf("%c", &resp);
			fflush(stdin);

		} while (resp == 's' || resp == 'S');
	}
	return (p);
}
arbol *carga(arbol *p)
{
	arbol *q;
	int infor;
	char resp;

	printf("Introduzca la informacion--->");
	scanf("%d", &infor);
	fflush(stdin);
	p->info = infor;
	printf("Hay rama por la izquierda de %d ? [s/n]--->", p->info);
	scanf("%c", &resp);
	fflush(stdin);
	if (resp == 's' || resp == 'S')
	{
		q = crea_arbol();
		p->izq = q;
		carga(p->izq);
	}
	else
		p->izq = NULL;

	printf("Hay rama por la derecha de %d ? [s/n]--->", p->info);
	scanf("%c", &resp);
	fflush(stdin);
	if (resp == 's' || resp == 'S')
	{
		q = crea_arbol();
		p->der = q;
		carga(p->der);
	}
	else
		p->der = NULL;
	return (p);
}

void pre_orden(arbol *p)
{
	if (p != NULL)
	{
		printf("[%d] ", p->info);
		pre_orden(p->izq);
		pre_orden(p->der);
	}
	return;
}
void pos_orden(arbol *p)
{
	if (p != NULL)
	{
		pos_orden(p->izq);
		pos_orden(p->der);
		printf("[%d] ", p->info);
	}
	return;
}

void in_orden(arbol *p)
{
	if (p != NULL)
	{
		in_orden(p->izq);
		printf("[%d] ", p->info);
		in_orden(p->der);
	}
	return;
}

void busqueda(arbol *p, int infor)
{
	if (infor < p->info)
	{
		if (p->izq == NULL)
			printf("\n\n\t\t -*- %d No esta en el arbol -*-", infor);
		else
			busqueda(p->izq, infor);
	}
	else if (infor > p->info)
	{
		if (p->der == NULL)
			printf("\n\n\t\t -*- %d No esta en el arbol -*-", infor);
		else
			busqueda(p->der, infor);
	}
	else
		printf("\n\t\t -*- %d esta en el arbol -*-", p->info);

	return;
}

void busqueda1(arbol *p, int infor)
{
	if (p != NULL)
	{

		if (infor < p->info)

			busqueda1(p->izq, infor);

		else if (infor > p->info)
			busqueda1(p->der, infor);
		else
			printf("\n\t\t -*- %d esta en el arbol -*-", p->info);
	}
	else
		printf("\n\n\t\t -*- %d No esta en el arbol -*-", infor);

	return;
}

void insercion(arbol *p, int infor)
{
	arbol *q;

	if (infor < p->info)
	{
		if (p->izq == NULL)
		{
			q = crea_arbol();
			q->izq = NULL;
			q->der = NULL;
			q->info = infor;
			p->izq = q;
		}
		else
			insercion(p->izq, infor);
	}
	else if (infor > p->info)
	{
		if (p->der == NULL)
		{
			q = crea_arbol();
			q->izq = NULL;
			q->der = NULL;
			q->info = infor;
			p->der = q;
		}
		else
			insercion(p->der, infor);
	}
	else
		printf("\n\n\t\t -*- %d ya esta en el arbol -*-", infor);

	return;
}

void inser_bal(arbol **nodo, int *bo, int infor)
{

	arbol *nodo1, *nodo2;
	nodo1 = nodo2 = NULL;

	if (*nodo != NULL)
	{

		if (infor < (*nodo)->info)
		{

			inser_bal(&(*nodo)->izq, bo, infor);

			if (*bo == V)
			{
				switch ((*nodo)->fe)
				{
				case 1:
				{
					(*nodo)->fe = 0;
					*bo = F;
					break;
				}
				case 0:
				{
					(*nodo)->fe = -1;
					break;
				}
				case -1:
				{

					nodo1 = (*nodo)->izq;
					if (nodo1->fe <= 0) // Rotacion II
					{
						(*nodo)->izq = nodo1->der;
						nodo1->der = *nodo;
						(*nodo)->fe = 0;
						*nodo = nodo1;
					}	 // Termina Rotacion II
					else // Rotacion ID
					{
						nodo2 = nodo1->der;
						(*nodo)->izq = nodo2->der;
						nodo2->der = *nodo;
						nodo1->der = nodo2->izq;
						nodo2->izq = nodo1;

						if (nodo2->fe == -1)
							(*nodo)->fe = 1;
						else
							(*nodo)->fe = 0; // fin 1.1.1.1.1.A
						if (nodo2->fe == 1)
							nodo1->fe = -1;
						else
							nodo1->fe = 0; // fin 1.1.1.1.1.C
						*nodo = nodo2;	   // Termina Rotacion ID
					}
					(*nodo)->fe = 0;
					*bo = F;
					break;
				} // fin del case -1
				} // fin del switch
			}	  // fin del condicional Si(*bo == V)
		}		  // fin del condicional si (infor < p->info )
		else if (infor > (*nodo)->info)
		{

			inser_bal(&(*nodo)->der, bo, infor);

			if (*bo == V)
			{
				switch ((*nodo)->fe)
				{
				case -1:
				{

					(*nodo)->fe = 0;
					*bo = F;
					break;
				}
				case 0:
				{

					(*nodo)->fe = 1;
					break;
				}
				case 1:
				{
					nodo1 = (*nodo)->der;

					if (nodo1->fe >= 0) // Rotacion DD
					{

						(*nodo)->der = nodo1->izq;
						nodo1->izq = (*nodo);
						(*nodo)->fe = 0;
						*nodo = nodo1;
					}	 // Termina la Rotacion DD
					else // Rotacion DI
					{
						nodo2 = nodo1->izq;
						(*nodo)->der = nodo2->izq;
						nodo2->izq = *nodo;
						nodo1->izq = nodo2->der;
						nodo2->der = nodo1;
						if (nodo2->fe == 1)
							(*nodo)->fe = -1;
						else
							(*nodo)->fe = 0; // fin Cond interno

						if (nodo2->fe == -1)
							nodo1->fe = 1;
						else
							nodo1->fe = 0;
						*nodo = nodo2;
					} // Termina la Rotacion DI
					(*nodo)->fe = 0;
					*bo = F;
					break;
				} // fin del case 1
				} // fin del switch
			}	  // fin del condicional Si(bo == V)
		}		  // fin del condicional si (infor > nodo->info )
		else
			printf("\n\n\t\t -*- %d ya esta en el arbol -*-", infor);
	}
	else
	{
		*nodo = crea_arbol();
		(*nodo)->info = infor;
		(*nodo)->izq = NULL;
		(*nodo)->der = NULL;
		(*nodo)->fe = 0;
		*bo = V;
	}
	return;
}

void elim_bal(arbol **nodo, int *bo, int infor)
{

	arbol *otro;

	if (*nodo != NULL)
	{
		if (infor < (*nodo)->info)
		{
			elim_bal(&(*nodo)->izq, bo, infor);
			restructura1(&(*nodo), bo);
		}
		else if (infor > (*nodo)->info)
		{
			elim_bal(&(*nodo)->der, bo, infor);
			restructura2(&(*nodo), bo);
		}
		else
		{
			otro = *nodo;
			*bo = V;
			if (otro->der == NULL)
			{

				*nodo = otro->izq;
				//  *bo = V;
			}
			else if (otro->izq == NULL)
			{
				*nodo = otro->der;
				//		   *bo = V;
			}
			else
			{
				borra(&otro->izq, &otro, bo);
				restructura1(&(*nodo), bo);
			} // fin del else
			free(otro);
		}
	} // Fin del p != NUUL
	else
		printf("\n\n\t\t -*- %d No esta en el arbol -*-", infor);

	return;
}

void restructura1(arbol **nodo, int *bo)
{
	arbol *nodo1, *nodo2;
	nodo1 = nodo2 = NULL;

	if (*bo == V)
	{
		switch ((*nodo)->fe)
		{
		case -1:
		{
			(*nodo)->fe = 0;
			break;
		}
		case 0:
		{
			(*nodo)->fe = 1;
			*bo = F;
			break;
		}
		case 1:
		{

			nodo1 = (*nodo)->der;
			if (nodo1->fe >= 0)
			{
				// rotacion DD
				(*nodo)->der = nodo1->izq;
				nodo1->izq = *nodo;

				switch (nodo1->fe)
				{
				case 0:
				{
					(*nodo)->fe = 1;
					nodo1->fe = -1;
					*bo = F;
					break;
				}
				case 1:
				{
					(*nodo)->fe = 0;
					nodo1->fe = 0;
					break;
				}
				} // switch interno

				*nodo = nodo1;
			}
			else
			{ // Rotacion DI
				nodo2 = nodo1->izq;
				(*nodo)->der = nodo2->izq;
				nodo2->izq = *nodo;
				nodo1->izq = nodo2->der;
				nodo2->der = nodo1;

				if (nodo2->fe == 1)
					(*nodo)->fe = -1;
				else
					(*nodo)->fe = 0;

				if (nodo2->fe == -1)
					nodo1->fe = 1;
				else
					nodo1->fe = 0;
				*nodo = nodo2;
				nodo2->fe = 0;
			}
			break;
		} // fin del case 1
		} // Fin del switch  nodo-> fe
	}
	return;
}

void restructura2(arbol **nodo, int *bo)
{
	arbol *nodo1, *nodo2;
	nodo1 = nodo2 = NULL;
	if (*bo == V)
	{
		switch ((*nodo)->fe)
		{
		case 1:
		{
			(*nodo)->fe = 0;

			break;
		}
		case 0:
		{

			(*nodo)->fe = -1;
			*bo = F;
			break;
		}
		case -1:
		{

			nodo1 = (*nodo)->izq;

			if (nodo1->fe <= 0)
			{ // Rotacion II
				(*nodo)->izq = nodo1->der;
				nodo1->der = (*nodo);

				switch (nodo1->fe)
				{
				case 0:
				{

					(*nodo)->fe = -1;
					nodo1->fe = 1;
					*bo = F;
					break;
				}
				case -1:
				{

					(*nodo)->fe = 0;
					nodo1->fe = 0;
					break;
				}
				} // fin switch interno
				*nodo = nodo1;
			} // fin de nodo1->fe <= 0
			else
			{ // rotacion ID
				nodo2 = nodo1->der;
				(*nodo)->izq = nodo2->der;
				nodo2->der = *nodo;
				nodo1->der = nodo2->izq;
				nodo2->izq = nodo1;

				if (nodo2->fe == -1)
					(*nodo)->fe = 1;
				else
					(*nodo)->fe = 0;

				if (nodo2->fe == 1)
					nodo1->fe = -1;
				else
					nodo1->fe = 0;

				*nodo = nodo2;

				nodo2->fe = 0;
			}
			break;
		} //  fin del case -1
		} // fin del switch nodo -> fe
	}	  // Fin del condicional (BO == V)

	return;
}

int buscar_menor(arbol *p, int menor)
{
	if (p != NULL)
	{
		if (p->izq != NULL)
		{
			return (buscar_menor(p->izq, menor));
		}
		menor = p->info;
		printf("\n El menor es %d", menor);
	}
	return 0;
}

int buscar_mayor(arbol *p, int mayor)
{
	if (p != NULL)
	{
		if (p->der != NULL)
		{
			return (buscar_mayor(p->der, mayor));
		}
		mayor = p->info;
		printf("\n El mayor es %d", mayor);
	}
	return 0;
}

void hojas(arbol *p)
{
	if (p != NULL)
	{
		if (p->izq == NULL && p->der == NULL)
		{
			printf("\n La hoja en el arbol es: %d", p->info);
		}
		hojas(p->izq);
		hojas(p->der);
	}
}

void borra(arbol **aux, arbol **otro, int *bo)
{
	if ((*aux)->der != NULL)
	{
		borra(&(*aux)->der, &(*otro), bo);
		restructura2(&(*aux), bo);
	}
	else
	{
		(*otro)->info = (*aux)->info;
		*otro = *aux;
		*aux = (*aux)->izq;
		*bo = V;
	}

	return;
}

arbol *borraTodoElArbol(arbol *nodo)
{
	if (nodo)
	{
		borraTodoElArbol(nodo->izq);
		borraTodoElArbol(nodo->der);
		free(nodo);
		return (NULL);
	}
	else
		return (nodo);
}
