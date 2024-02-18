#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct GRUPOS{
	char nombre[80];
	struct GRUPOS *ligader;
	struct GRUPOS *ligaizq;
	struct SELE   *liga;
	
};

struct SELE{
	char sele[80];
	struct SELE *ligader;
	struct SELE *ligaizq;
	struct JUGADORES *liga;

};

struct PARTI{
	int Lugar;
	int PJ;
	int G;
	int E;
	int PP;
	int GF;
	int GC;
	int Pts;
	struct PARTI *ligader;
};

struct JUGADORES{
char nombre[80];
struct JUGADORES *ligader;
struct JUGADORES *ligaizq;
struct sele *liga;

};

int opc,cont;
char nombre[80],n_SELE[80];

struct GRUPOS *p = NULL;
struct GRUPOS *pp = NULL;
struct GRUPOS *q1 = NULL;
struct GRUPOS *t1 = NULL;
struct SELE *p1 = NULL;
struct SELE *q = NULL;
struct SELE *t = NULL;
struct SELE *r = NULL;
struct SELE *in = NULL;
struct PARTI *P1=NULL;



struct JUGADORES *A=NULL;
struct JUGADORES *A_N=NULL;
struct JUGADORES *B=NULL;
struct JUGADORES *PA=NULL;
struct JUGADORES *inP=NULL;
struct JUGADORES *B1=NULL;








int continuacion_GRUPOS(void);
int continuacion_SELE(void);
int continuacion_JUGADORES(void);

struct GRUPOS *crear_nodo(void);
struct SELE *crear_nodo1(void);
struct PARTI*crear_nodo2(void);
struct JUGADORES*crear_nodo3(void);
struct GRUPOS *crea_GRUPOS(struct GRUPOS *pp);
struct GRUPOS *ordenar_GRUPOS(struct GRUPOS *p,struct GRUPOS *q);
struct SELE *ordenar_ing(struct SELE *in,struct SELE *q);
struct GRUPOS *insert_GRUPOS(struct GRUPOS *p);
struct GRUPOS *elimina_GRUPOS(struct GRUPOS *p,char *nombre);
struct GRUPOS *elimina_SELE(struct GRUPOS *p,char nombre[80],char n_SELE[80]);
struct GRUPOS *inserta_SELE(struct GRUPOS *p,char nombre[80]);
struct GRUPOS *desplegar_GRUPOS(struct GRUPOS *p,char nombre[80]);
void *crear_memoria(int n);
struct JUGADORES *crea_JUGADORES(struct JUGADORES *A);
void recorre_GRUPOS(struct GRUPOS *p);
void recorre_JUGADORES(struct JUGADORES *A);

int main()
{
	p = crea_GRUPOS(pp);
	do
	{
		system("cls");
		printf("\n COPA AMERICA 2018\n");
		printf("\n1 INSERTAR GRUPO");
		printf("\n2 ELIMINAR GUPOS");
		printf("\n3 ELIMINAR SELECION");
		printf("\n4 INSERTAR SELECION");
		printf("\n5 IMPRIMIR GRUPO");
		printf("\n6 MOSTRAR GRUPOS Y SELECIONES");
		printf("\n7 ADANDONAR");
		printf("\n8 INSERTAR JUGADORES Y PAISES");
		printf("\n9 IMPRIMIR JUGADORES Y PAISES");
		printf("\n10 SALIR");
		printf("\n\nIntrodusca su opcion: ");
		scanf("%d",&opc);
		fflush(stdin);
		switch(opc)
		{
			case 1:
				p = insert_GRUPOS(p);
				break;
			case 2:
				printf("\nNombre del GRUPO a eliminar: ");
				scanf(" %[^\n]",nombre);
				fflush(stdin);
				p = elimina_GRUPOS(p,nombre);
				break;
			case 3:
				printf("\nNombre del postre a eliminar: ");
				scanf(" %[^\n]",nombre);
				fflush(stdin);
				
				printf("\nNombre del ingrediente a eliminar: ");
				scanf(" %[^\n]",n_SELE);
				fflush(stdin);
				p = elimina_SELE(p,nombre,n_SELE);
				break;
			case 4:
				printf("\nNombre del GRUPO a agregar ingrediente: ");
				scanf(" %[^\n]",nombre);
				fflush(stdin);
				p = inserta_SELE(p,nombre);
				break;
			case 5:
				printf("\nNombre del GRUPO a imprimir: ");
				scanf(" %[^\n]",nombre);
				fflush(stdin);
				p = desplegar_GRUPOS(p,nombre);
				break;
			case 6:
				recorre_GRUPOS(p);
				break;
			case 7:
				printf("\nAbandonando aplicacion...");
				break;
			case 8:
			A = crea_JUGADORES(A);
			break;
			case 9:
		//	recorre_JUGADORES(A);
		  	break;
			default:
				printf("\nOpcion invalida...\n");
		}
		printf("\n\nPresione ENTER para continuar...");
		getchar();
	}
	while(opc != 10);
	return(0);
}

struct GRUPOS *crea_GRUPOS(struct GRUPOS *pp)
{
	int i = 0,y = 0;
	pp = crear_nodo();
	printf("\n  POR FAVOR INSERTE EL GRUPO #1: ");
	scanf(" %[^\n]",pp->nombre);
	fflush(stdin);
	pp->ligader = NULL;
	pp->ligaizq = NULL;
	p = pp;
	q = crear_nodo1();
	printf("\nPOR FAVOR INSERTE EL PAIS #1: ");
	scanf(" %[^\n]",q->sele);
	fflush(stdin);
	q->ligader = NULL;
	q->ligaizq = NULL;
	in = q;
	P1=crear_nodo2();
	P1->PJ = 3;
	printf("\nINSERTE LA POSICION EN EL GRUPO: ");
	scanf("%d",&P1->Lugar);
	fflush(stdin);
	printf("\nLOS JUEGOS GANADOS: ");
	scanf("%d",&P1->G);
	fflush(stdin);
	printf("\nLOS JUEGOS EMPATADOS: ");
	scanf("%d",&P1->E);
	fflush(stdin);
	printf("\nLOS JUEGOS PERDIDOS: ");
	scanf("%d",&P1->PP);
	fflush(stdin);
	printf("\nLOS GOLES A FAVOR: ");
	scanf("%d",&P1->GF);
	fflush(stdin);
	printf("\nLOS GOLES EN CONTRA: ");
	scanf("%d",&P1->GC);
	fflush(stdin);
	printf("\nLOS PUNTOS OBTENIDOS: ");
	scanf("%d",&P1->Pts);
	fflush(stdin);
	P1->ligader = NULL;

	
	while(continuacion_SELE())
	{
		system("cls");
		y += 2;
		q = crear_nodo1();
		i++;
		printf("\nPAIS #%d: ",i+1);
		scanf(" %[^\n]",q->sele);
		fflush(stdin);
		q->ligader = NULL;
		q->ligaizq = NULL;
		P1=crear_nodo2();
	P1->PJ = 3;
	printf("\nLA POSICION EN EL GRUPO: ");
	scanf("%d",&P1->Lugar);
	fflush(stdin);
	printf("\nLOS JUEGOS GANADOS: ");
	scanf("%d",&P1->G);
	fflush(stdin);
	printf("\nLOS JUEGOS EMPATADOS: ");
	scanf("%d",&P1->E);
	fflush(stdin);
	printf("\nLOS JUEGOS PERDIDOS: ");
	scanf("%d",&P1->PP);
	fflush(stdin);
	printf("\nLOS GOLES A FAVOR: ");
	scanf("%d",&P1->GF);
	fflush(stdin);
	printf("\nLOS GOLES EN CONTRA: ");
	scanf("%d",&P1->GC);
	fflush(stdin);
	printf("\nLOS PUNTOS OBTENIDOS: ");
	scanf("%d",&P1->Pts);
	fflush(stdin);
	P1->ligader = NULL;

		
		in = ordenar_ing(in,q);
		
	}
	p->liga = in;
	cont = 1;
	while(continuacion_GRUPOS())
	{
		system("cls");
		y = 0;
		pp = crear_nodo();
		printf("\nGRUPO #%d: ",cont+1);
		scanf(" %[^\n]",pp->nombre);
		fflush(stdin);
		pp->ligader = NULL;
		pp->ligaizq = NULL;
		q = crear_nodo1();
		i = 0;
		printf("\nPAIS#1: ");
		scanf(" %[^\n]",q->sele);
		fflush(stdin);
		q->ligader = NULL;
		q->ligaizq = NULL;
		in = q;
		P1=crear_nodo2();
	P1->PJ = 3;
	printf("\nPOSICION EN EL GRUPO: ");
	scanf("%d",&P1->Lugar);
	fflush(stdin);
	printf("\nLOS JUEGOS GANADOS: ");
	scanf("%d",&P1->G);
	fflush(stdin);
	printf("\nLOS JUEGOS EMPATADOS: ");
	scanf("%d",&P1->E);
	fflush(stdin);
	printf("\nLOS JUEGOS PERDIDOS: ");
	scanf("%d",&P1->PP);
	fflush(stdin);
	printf("\nLOS GOLES A FAVOR: ");
	scanf("%d",&P1->GF);
	fflush(stdin);
	printf("\nLOS GOLES EN CONTRA: ");
	scanf("%d",&P1->GC);
	fflush(stdin);
	printf("\nLOS PUNTOS OBTENIDOS: ");
	scanf("%d",&P1->Pts);
	fflush(stdin);
	P1->ligader = NULL;
	
		while(continuacion_SELE())
		{
			system("cls");
			q = crear_nodo1();
			i++;
			printf("\nPAIS #%d: ",i+1);
			scanf(" %[^\n]",q->sele);
			fflush(stdin);
			q->ligader = NULL;
			q->ligaizq = NULL;
			P1=crear_nodo2();
	P1->PJ = 3;
	printf("\nPOSICION EN EL GRUPO: ");
	scanf("%d",&P1->Lugar);
	fflush(stdin);
	printf("\nLOS JUEGOS GANADOS: ");
	scanf("%d",&P1->G);
	fflush(stdin);
	printf("\nLOS JUEGOS EMPATADOS: ");
	scanf("%d",&P1->E);
	fflush(stdin);
	printf("\nLOS JUEGOS PERDIDOS: ");
	scanf("%d",&P1->PP);
	fflush(stdin);
	printf("\nLOS GOLES A FAVOR: ");
	scanf("%d",&P1->GF);
	fflush(stdin);
	printf("\nLOS GOLES EN CONTRA: ");
	scanf("%d",&P1->GC);
	fflush(stdin);
	printf("\nLOS PUNTOS OBTENIDOS: ");
	scanf("%d",&P1->Pts);
	fflush(stdin);
	P1->ligader = NULL;
	
			
			in = ordenar_ing(in,q);
		}
		pp->liga = in;
		cont ++;
		p = ordenar_GRUPOS(p,pp);
	}
	return p;
}

struct GRUPOS *insert_GRUPOS(struct GRUPOS *p)
{
	int i = 0,y = 0;
	system("cls");
	pp = crear_nodo();
	printf("\nGRUPO: ");
	scanf(" %[^\n]",pp->nombre);
	fflush(stdin);
	pp->ligader = NULL;
	pp->ligaizq = NULL;
	
	q = crear_nodo1();
	printf("\nPAIS #1: ");
	scanf(" %[^\n]",q->sele);
	fflush(stdin);
	q->ligader = NULL;
	q->ligaizq = NULL;
		P1=crear_nodo2();
	P1->PJ = 3;
	printf("\nPOSICION EN EL GRUPO: ");
	scanf("%d",&P1->Lugar);
	fflush(stdin);
	printf("JUEGOS GANADOS: ");
	scanf("%d",&P1->G);
	fflush(stdin);
	printf("JUEGOS EMPATADOS: ");
	scanf("%d",&P1->E);
	fflush(stdin);
	printf("\nLOS JUEGOS PERDIDOS: ");
	scanf("%d",&P1->PP);
	fflush(stdin);
	printf("\nLOS GOLES A FAVOR: ");
	scanf("%d",&P1->GF);
	fflush(stdin);
	printf("\nLOS GOLES EN CONTRA: ");
	scanf("%d",&P1->GC);
	fflush(stdin);
	printf("\nLOS PUNTOS OBTENIDOS: ");
	scanf("%d",&P1->Pts);
	fflush(stdin);
	P1->ligader = NULL;
	in = q;
	pp->liga = in;
	while(continuacion_SELE())
	{
		system("cls");
		y += 2;
		q = crear_nodo1();
		i++;
		printf("\nPAIS #%d: ",i+1);
		scanf(" %[^\n]",q->sele);
		fflush(stdin);
		q->ligader = NULL;
		q->ligaizq = NULL;
	P1=crear_nodo2();
	P1->PJ = 3;
	printf("\nPOSICION EN EL GRUPO: ");
	scanf("%d",&P1->Lugar);
	fflush(stdin);
	printf("\nLOS JUEGOS GANADOS: ");
	scanf("%d",&P1->G);
	fflush(stdin);
	printf("\nLOS JUEGOS EMPATADOS: ");
	scanf("%d",&P1->E);
	fflush(stdin);
	printf("\nLOS JUEGOS PERDIDOS: ");
	scanf("%d",&P1->PP);
	fflush(stdin);
	printf("\n LOS GOLES A FAVOR: ");
	scanf("%d",&P1->GF);
	fflush(stdin);
	printf("\nLOS GOLES EN CONTRA: ");
	scanf("%d",&P1->GC);
	fflush(stdin);
	printf("\n LOS PUNTOS OBTENIDOS: ");
	scanf("%d",&P1->Pts);
	fflush(stdin);
	P1->ligader = NULL;
		in = ordenar_ing(in,q);
		pp->liga = in;
	}
	p = ordenar_GRUPOS(p,pp);
	return p;
}

struct GRUPOS *elimina_GRUPOS(struct GRUPOS *p,char *nombre)
{
	bool band = true;
	q1 = p;
	while((strcmp(q1->nombre,nombre)!=0)&&(band == true))
	{
		if(q1->ligader != NULL)
		{
			t1 = q1;
			q1 = q1->ligader;
		}
		else
		band = false;
	}
	if(band == false)
	printf("\nEl grupo NO fue encontrado.");
	else
	{
		if(p == q1)
		{
			p = q1->ligader;
			p->ligaizq = NULL;
		}
		else
		{
			t1->ligader = q1->ligader;
			q1->ligader = t1;
		}
		free(q1);
	}
	return p;
}

struct GRUPOS *elimina_SELE(struct GRUPOS *p,char nombre[80],char n_SELE[80])
{
	bool band = true;
	q1 = p;
	t1 = p;
	while((strcmp(q1->nombre,nombre) != 0 )&&(band == true))
	{
		if(q1->ligader != NULL)
		{
			t1 = q1;
			q1 = q1->ligader;
		}
		else
		band = false;
	}
	
	if(band == false)
	printf("\nEl GRUPO NO fue encontrado.");
	else
	{
		band = true;
		q = q1->liga;
		p1 = q;
		t = q;
		while((strcmp(q->sele,n_SELE) != 0 )&&(band == true))
		{
			if(q->ligader != NULL)
			{
				t = q;
				q = q->ligader;
			}
			else
			band = false;
		}
			if(band == false)
			printf("\nEl PAIS NO fue encontrado.");
			else
			{
				if(q->ligaizq == NULL && q->ligader == NULL)
					q1->liga = NULL;
				else if(p1 == q)
				{
					p1 = q->ligader;
					p1->ligaizq = NULL;
				}
				else
				{
					r = q->ligader;
					t->ligader = r;
					r->ligaizq = t;
					q->ligader = NULL;
					q->ligaizq = NULL;
				}
				free(q);
				printf("\n LA SELECION fue eliminado");
			}
//			q1->liga = p1;
	}
	return p;
}

struct GRUPOS *inserta_SELE(struct GRUPOS *p,char nombre[80])
{
	bool band = true;
	q1 = p;
	while((strcmp(q1->nombre,nombre)!=0)&&(band == true))
	{
		if(q1->ligader != NULL)
		{
			q1 = q1->ligader;
		}
		else
		band = false;
	}
	if(band == false)
	printf("\nEl grupo NO fue encontrado.");
	else
	{
		system("cls");
		printf("\nPAIS A INGRESAR: ");
		scanf(" %[^\n]",q->sele);
		fflush(stdin);
		printf("\nPAIS:\n");
		q->ligader = NULL;
		q->ligaizq = NULL;
			in = ordenar_ing(in,q);
	P1=crear_nodo2();
	P1->PJ = 3;
	printf("\nLA POSICION EN EL GRUPO: ");
	scanf("%d",&P1->Lugar);
	fflush(stdin);
	printf("\nLOS JUEGOS GANADOS: ");
	scanf("%d",&P1->G);
	fflush(stdin);
	printf("\nLOS JUEGOS EMPATADOS: ");
	scanf("%d",&P1->E);
	fflush(stdin);
	printf("\nLOS JUEGOS PERDIDOS: ");
	scanf("%d",&P1->PP);
	fflush(stdin);
	printf("\nLOS GOLES A FAVOR: ");
	scanf("%d",&P1->GF);
	fflush(stdin);
	printf("\nLOS GOLES EN CONTRA: ");
	scanf("%d",&P1->GC);
	fflush(stdin);
	printf("\nLOS PUNTOS OBTENIDOS: ");
	scanf("%d",&P1->Pts);
	fflush(stdin);
	P1->ligader = NULL;

	}
	return p;
}

struct GRUPOS *desplegar_GRUPOS(struct GRUPOS *p,char nombre[80])
{
	system("cls");
	bool band = true;
	q1 = p;
	while((strcmp(q1->nombre,nombre)!=0)&&(band == true))
	{
		if(q1->ligader != NULL)
		{
			t1 = q1;
			q1 = q1->ligader;
			in = q1->liga;
		}
		else
		band = false;
	}
	if(band == false)
	printf("\nEl pais NO fue encontrado.");
	else
	{
		printf("\nGRUPOS: %s",q1->nombre);
		printf("\nPAISES:\n");
		printf("\n|CLUB                    PJ  G   E   P  GF  GC  Pts|\n");
		for(q = q1->liga; q != NULL; q = q->ligader)
		{
	    printf("\n|%d %-19s %3d %3d %3d %3d %3d %3d %3d |\t",P1->Lugar,q->sele,P1->PJ,P1->G,P1->E,P1->PP,P1->GF,P1->GC,P1->Pts);
		}
	}
	return p;
}

int continuacion_GRUPOS(void)
{
	int opc;
	do
	{
		system("cls");
		printf("\n introducir mas GRUPOS:\n");
		printf("\n1 para insertar\n2 para salir\n");
		printf("\nIntrodusca su opcion: ");
		scanf("%d",&opc);
		fflush(stdin);
	}
	while(opc < 1 || opc > 2);
	if(opc == 1)
	return(1);
	else
	return(0);
}

int continuacion_SELE(void)
{
	int opc;
	do
	{
		system("cls");
		printf("\nDeseas introducir mas PAISES:\n");
		printf("\n1 para insertar\n2 para salir\n");
		printf("\nIntrodusca su opcion: ");
		scanf("%d",&opc);
		fflush(stdin);
	}
	while(opc < 1 || opc > 2);
	if(opc == 1)
	return(1);
	else
	return(0);
}
int continuacion_JUGADORES(void)
{
	int opc;
	do
	{
		system("cls");
		printf("\n introducir mas JUGADORES:\n");
		printf("\n1 para insertar\n2 para salir\n");
		printf("\nIntrodusca su opcion: ");
		scanf("%d",&opc);
		fflush(stdin);
	}
	while(opc < 1 || opc > 2);
	if(opc == 1)
	return(1);
	else
	return(0);
}

struct GRUPOS *ordenar_GRUPOS(struct GRUPOS *p,struct GRUPOS *q1)
{
	struct GRUPOS *r = NULL;
	bool band = false;
	t1 = p;
	if(strcmpi(t1->nombre,q1->nombre) >= 0)
	{
		band = true;
		t1->ligaizq = q1;
		q1->ligader = t1;
		p = q1;
		return(p);
	}
	else
	{
		while(t1->ligader != NULL)
		{
			t1 = t1->ligader;
			if(strcmp(t1->nombre,q1->nombre) >= 0)
			{
				band = true;
				r = t1;
				r = t1->ligaizq;
				t1->ligaizq = NULL;
				r->ligader = NULL;
				q1->ligader = t1;
				t1->ligaizq = q1;
				q1->ligaizq = r;
				r->ligader = q1;
				break;
			}
			else
			band = false;
		}
	}
	if(band == false)
	{
		t1->ligader = q1;
		q1->ligaizq = t1;
	}
	return(p);
}

struct SELE *ordenar_ing(struct SELE *in,struct SELE *q)
{
	struct SELE *r = NULL;
	bool band = false;
	t = in;
	if(strcmp(t->sele,q->sele) >= 0)
	{
		band = true;
		t->ligaizq = q;
		q->ligader = t;
		in = q;
		return(in);
	}
	else
	{
		while(t->ligader != NULL)
		{
			t = t->ligader;
			if(strcmp(t->sele,q->sele) >= 0)
			{
				band = true;
				r = t;
				r = t->ligaizq;
				t->ligaizq = NULL;
				r->ligader = NULL;
				q->ligader = t;
				t->ligaizq = q;
				q->ligaizq = r;
				r->ligader = q;
				break;
			}
			else
			band = false;
		}
	}
	if(band == false)
	{
		t->ligader = q;
		q->ligaizq = t;
	}
	return(in);
}

void recorre_GRUPOS(struct GRUPOS *p)
{
	system("cls");
	q1 = p;
	while(q1 != NULL)
	{
		
		printf("\n\n\n\nGRUPO: %s\n",q1->nombre);
	    printf("\n|CLUB                    PJ  G   E   P  GF  GC  Pts|\n");
	
		for(q = q1->liga; q != NULL; q = q->ligader)
		{
	    printf("\n|%d %-19s %3d %3d %3d %3d %3d %3d %3d |\t",P1->Lugar,q->sele,P1->PJ,P1->G,P1->E,P1->PP,P1->GF,P1->GC,P1->Pts);
		}
		q1 = q1->ligader;
	}
}

struct GRUPOS *crear_nodo(void)
{
	void *crear_memoria(int n);
	return((struct GRUPOS *)crear_memoria(sizeof(struct GRUPOS)));
}

struct SELE *crear_nodo1(void)
{
	void *crear_memoria(int n);
	return((struct SELE *)crear_memoria(sizeof(struct SELE)));
}
struct PARTI*crear_nodo2(void)
{
	void *crear_memoria(int n);
	return((struct PARTI *)crear_memoria(sizeof(struct PARTI)));
}
struct JUGADORES*crear_nodo3(void)
{
	void *crear_memoria(int n);
	return((struct JUGADORES *)crear_memoria(sizeof(struct JUGADORES)));
}
void *crear_memoria(int n)
{
	void *p = (int *)malloc(n);
	if(p == NULL)
	printf("\nNO hay suficiente memoria\n");
	return(p);
}
struct JUGADORES *crea_JUGADORES(struct JUGADORES *A)
{
	int i = 0,y = 0;
	A = crear_nodo3();
	printf("\n  POR FAVOR INSERTE EL NOMBRE DEL JUGADOR CONVOCADO#1: ");
	scanf(" %[^\n]",A->nombre);
	fflush(stdin);
	A->ligader = NULL;
	A->ligaizq = NULL;
	A_N = A;
	
	
	
	while(continuacion_JUGADORES())
	{
		system("cls");
		y = 0;
		pp = crear_nodo();
		printf("\nJUGADOR#%d: ",cont+1);
		scanf(" %[^\n]",A->nombre);
		fflush(stdin);
		A->ligader = NULL;
		A->ligaizq = NULL;
	
		pp->liga = in;
		cont ++;
		p = ordenar_GRUPOS(p,pp);
	}
	return A;
}
/*void recorre_JUGADORES(struct JUGADORES *A)
{
	system("cls");
	A = A_N;
	
	while(A_N != NULL)
	{
		printf("\nJUGADORES: %s\n",A_N->nombre);
		for(p1 = A_N->liga;p1 !=NULL;p1 = p1->ligader)
		{
			printf("\nPAIS: %s\n",p1->sele);
		}
		A = A->ligader;
	}

}
*/

