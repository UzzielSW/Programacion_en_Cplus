/* Arboles */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define V 1
#define F 0

struct datos {
	
	int info;
	int fe;
	struct datos *der;
	struct datos *izq;
};

typedef struct datos arbol;

void  *crea_memoria(int infor);
arbol *crea_arbol();

arbol *carga_balanceado(arbol *p);
arbol *carga(arbol *p);
void  pre_orden(arbol *p);
void  in_orden(arbol *p);
void  pos_orden(arbol *p);
void  busqueda(arbol *p, int infor);
void  busqueda1(arbol *p, int infor);
void  insercion(arbol *p, int infor);
void  elimina_elemento( arbol **p,int info);

int   buscar_menor(arbol *p, int menor);
void  buscar_menor2(arbol *p);
arbol *findMin(arbol *p);
arbol *findMinRec(arbol *p);

int   buscar_mayor(arbol *p, int mayor);
void  buscar_mayor2(arbol *p);
arbol *findMax(arbol *p);
arbol *findMaxRec(arbol *p);

void  imprime_hojas( arbol *p);
int num_hojas(arbol *p);

void inser_bal(arbol **nodo, int *bo, int infor);
void elim_bal(arbol **p, int *bo, int infor);
void restructura1(arbol **p, int *bo);
void restructura2(arbol **p, int *bo);

void borra(arbol **aux, arbol **otro, int *bo);
arbol *freeTree(arbol *p);
void liberamemoria(arbol *p);
	
int numElementos(arbol *p);

int isBSTUtil( arbol *p, int min, int max);
int sumaTodos(arbol *P);

arbol *copiarArbol(arbol *p);
int profundidadArbol(arbol *p);

arbol *deleteNode(arbol *root, int value);

int main(void)
{
	arbol *p = NULL;
	arbol *q = NULL;
	arbol *q1 = NULL;
	arbol *q2 = NULL;
	int bol, inf, sel,val,menor,mayor,cuantos,i;
	char op;
	
     do {
      	system("cls");
      	printf("\n\t\t*_*_*_*_*_*_Menu de Opciones-*-*-*-*-*-*\n\n");
    
		printf("\t\t\t1.-Crea Arbol\t\t2.-Ver Arbol \n");
      	printf("\t\t\t3.-Buscar \t\t4.-Buscar 1\n");
      	printf("\t\t\t5.-Inserta \t\t6.-Elimina \n");
      	printf("\t\t\t7.-Crea Arbol Balanceado \n");
      	printf("\t\t\t8.-Inserta Balanceado\n");
      	printf("\t\t\t9.-Eliminar Balanceado \n");
      	printf("\t\t\t10.-Buscar Menor\t11.-Buscar Mayor \n");
      	printf("\t\t\t12.-Hojas del Arbol\t13.-Numero de elementos\n");
      	printf("\t\t\t14.-Suma  los nodos  15.-Borrar Arbol Entero\n");
      	printf("\t\t\t16.-Es un Arbol Binario de Busqueda ?\n");
      	printf("\t\t\t17.-Copiar Arbol Binario  en Otro ?\n");
      	printf("\t\t\t18.-Calcula la Profundidad del Arbol\n");
      	printf("\t\t\t19.-Salir \n");
      	printf("\t\t\t-Escoja su opcion:  ");
      	scanf("%d",&sel);
      	fflush(stdin);
      	
      	switch(sel)
      	{
      		
      	
      	
      	
      	case 1: system("cls");
      		p = crea_arbol();
      		p = carga(p);
      		printf("\n\n\t\t Presione ENTER para continuar: ");
      		getchar();
      		break;
      		
      	case 2: system("cls");
      	if ( p != NULL)
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
      	
      	case 3: 
		system("cls");
		if( p != NULL)
		{
		 printf("\n El dato que desea buscar es: ? ");
		 val = scanf("%d",&inf);
		 fflush(stdin);
		 if (val == V)
		  {
		     busqueda(p,inf);
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
		 
	   case 4:
	   		system("cls");
		if( p != NULL)
		{
		 printf("\n El dato que desea buscar es: ? ");
		 val = scanf("%d",&inf);
		 fflush(stdin);
		 if (val == V)
		  {
		     busqueda1(p,inf);
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
	   
	   case 5:
	   	system("cls");
		if( p != NULL)
		{
		 printf("\n Lista de datos pre_orden: \n");
		 pre_orden(p);	
		 printf("\n Lista de datos in_orden: \n");
		 in_orden(p);
		 printf("\n Lista de datos pos_orden: \n");
		 pos_orden(p);
		 printf("\n El dato que desea insertar es: ? ");
		 val = scanf("%d",&inf);
		 fflush(stdin);
		 if (val == V)
		  {
		     insercion(p,inf);
		     printf("\n Lista de datos pre_orden: \n");
		     pre_orden(p);	
		     printf("\n Lista de datos in_orden: \n");
		     in_orden(p);
		     printf("\n Lista de datos pos_orden: \n");
		     pos_orden(p);
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
	   	
	   	case 6: system("cls");
		if( p != NULL)
		{
	   	
	   	printf("\n Lista de datos pre_orden: \n");
		 pre_orden(p);	
		 printf("\n Lista de datos in_orden: \n");
		 in_orden(p);
		 printf("\n Lista de datos pos_orden: \n");
		 pos_orden(p);
		 printf("\n El dato que desea eliminar es: ? ");
		 val = scanf("%d",&inf);
		 fflush(stdin);
		 if (val == V)
		  {
	   	p=deleteNode(p, inf);
	    //elimina_elemento( &p,inf);
	   	printf("\n Lista de datos pre_orden: \n");
		 pre_orden(p);	
		 printf("\n Lista de datos in_orden: \n");
		 in_orden(p);
		 printf("\n Lista de datos pos_orden: \n");
		 pos_orden(p);
	
	   		    	
		   }
	    }
	     else
	     {
		
	     printf("\n\n\t\t El arbol no ha sido Cargado ");
      	
      	
		}       	
	   
	  printf("\n\n\t\t Presione ENTER para continuar: ");
      getchar(); 
	   break;	
	   case 7:  system("cls");
      		p = carga_balanceado(p);
      		
      		printf("\n\n\t\t Presione ENTER para continuar: ");
      		getchar();
      		break; 	
	    	
	    case 8:
	     system("cls");
		if( p != NULL)
		{
		 printf("\n Lista de datos in_orden: \n");
		 in_orden(p);
		 printf("\n El dato que desea insertar es: ? ");
		 val = scanf("%d",&inf);
		 fflush(stdin);
		 if (val == V)
		  {
		     inser_bal(&p,&bol,inf);
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
		if( p != NULL)
		{
		 printf("\n Lista de datos in_orden: \n");
		 in_orden(p);
		 printf("\n El dato que desea Eliminar es: ? ");
		 val = scanf("%d",&inf);
		 fflush(stdin);
		 if (val == V)
		  {
		     elim_bal(&p,&bol,inf);
		     printf("\n Lista de datos in_orden: \n");
		     in_orden(p);
		    	
		   } //fin del condicional (val == V)
	    }     // fin del condicional (p != NUll)
	     else
	     
	     printf("\n\n\t\t El arbol no ha sido Cargado ");
      	printf("\n\n\t\t Presione ENTER para continuar: ");
          getchar(); 
	     break;	
	    
	    case 10:
	    	
	    	system("cls");
		if( p != NULL)
		{
		 printf("\n Lista de datos in_orden: \n");
		 in_orden(p);
	/*	 buscar_menor(p,menor);
		 buscar_menor2(p);
	*/
		 q1=findMin(p);
		 printf("\n El menor3 es %d",q1->info);
	/*	 q2= findMinRec(p);
		 printf("\n El menor4 es %d",q2->info);
		 */
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
		if( p != NULL)
		{
		 printf("\n Lista de datos in_orden: \n");
		 in_orden(p);
		 buscar_mayor(p,menor);
		 buscar_mayor2(p);
		  q1=findMax(p);
		 printf("\n El mayor3 es %d",q1->info);
	/*	 q2= findMaxRec(p);
		 printf("\n El mayor4 es %d",q2->info);
		 */
	    }
	     else
	     {
		
	     printf("\n\n\t\t El arbol no ha sido Cargado ");
      	
      	
		}       	
	   
	  printf("\n\n\t\t Presione ENTER para continuar: ");
      getchar(); 
	   break;
	   
	   case 12:
	   	system("cls");
		if( p != NULL)
		{
		 printf("\n Lista de datos in_orden: \n");
		 in_orden(p);
		 imprime_hojas(p);
		 printf("\n Cantidad de hojas: %d",num_hojas(p));
		 
	    }
	     else
	     {
		
	     printf("\n\n\t\t El arbol no ha sido Cargado ");
      	
      	
		}       	
	   
	  printf("\n\n\t\t Presione ENTER para continuar: ");
      getchar(); 
	   break;
	   	
	   case 13: 
	            system("cls");
		       if( p != NULL)
		       {
	            cuantos = numElementos(p);
	            printf("\n\n\t cantidad de elementos en el arbol: %d",cuantos);
	             }
	            else
	            {
		
	              printf("\n\n\t\t El arbol no ha sido Cargado ");
      	     	}  
	            
	            printf("\n\n\t\t Presione ENTER para continuar: ");
                getchar(); 
	            break;
	   case 14:
	   	    system("cls");
		       if( p != NULL)
		       {
	            cuantos = sumaTodos(p);
	            printf("\n\n\t Suma de elementos en el arbol: %d",cuantos);
	             }
	            else
	            {
		
	              printf("\n\n\t\t El arbol no ha sido Cargado ");
      	     	}  
	            
	            printf("\n\n\t\t Presione ENTER para continuar: ");
                getchar(); 
	            break;
	   case 15: 
	             if(p != NULL)
	              { 
	            
	            p = freeTree(p);
	            printf("\n\n\t Memoria del arbol ha sido liberada");
	           }
	           else printf("\n\n\t Arbol vacio");
	            printf("\n\n\t\t Presione ENTER para continuar: ");
                getchar(); 
	   	       break;
	   	       
	   
	  case 16: 	if(p != NULL)
	              { 
	            q2= findMin(p);
		       printf("\n El menor4 es %d",q2->info);
		       menor = q2->info;
		       q2= findMax(p);
		        printf("\n El mayor4 es %d",q2->info);
		        mayor = q2->info;
	            i = isBSTUtil(p, menor, mayor);
	            if ( i == 0)
	            printf("\n\n\t El arbol No es BST");
	            else
	             printf("\n\n\t El arbol es BST");
	             
	           }
	          else  printf("\n\n\t Arbol vacio");
	            printf("\n\n\t\t Presione ENTER para continuar: ");
                getchar(); 
	   	       break; 
	  
	   case 17:   if(p != NULL)
	              { 
	            
	            q=copiarArbol(p);
	            printf("\n\n\t El arbol ha sido copiado");
	        printf("\n\nListado en PREORDEN\n");
      		printf("\nVisita Raiz, ");
      		printf("Recorre SubArbol Izquierdo ");
      		printf(" y Recorre SubArbol Derecho\n\n");
      		pre_orden(p);
      		printf("\n\n");
      		pre_orden(q);
	           }
	           else printf("\n\n\t Arbol vacio");
	            printf("\n\n\t\t Presione ENTER para continuar: ");
                getchar(); 
	   	       break;
	                
	  case 18:	if(p != NULL)
	              { 
	            
	            printf("\n\t Profundidad: %d",profundidadArbol(p));
	             
	           }
	          else  printf("\n\n\t Arbol vacio");
	            printf("\n\n\t\t Presione ENTER para continuar: ");
                getchar(); 
	  	
	   	       break; 
	
	  case 19:
	           break;			  	       
	   default:  printf("\n\n\t\t Error la Opcion no es valida");	   
	  printf("\n\n\t\t Presione ENTER para continuar: ");
      getchar(); 
	   break;
	   
	   
		 }
	 }while(sel != 19);
return 0;
}


arbol *copiarArbol(arbol *p)
{
	arbol *q;
	
	if ( p != NULL)
	{
		q = crea_arbol();
		if(!q)
		   return NULL;
		q->info = p->info;
		q->izq = copiarArbol(p->izq);
		q->der = copiarArbol(p->der);
		return q;
	}
	else
	    return NULL;
}
int isBSTUtil( arbol *p, int min, int max)
{
	if(!p)
	   return 1;
	if(p->info < min || p->info > max)
	   return 0;
	
	return( isBSTUtil(p->izq,min,p->info) && isBSTUtil(p->der,p->info + 1, max));
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
	return( arbol *)crea_memoria(sizeof(arbol));
}


arbol *carga_balanceado(arbol *p)
{
	arbol *q;
	int infor, bo;
	char resp;
	p = crea_arbol();
	printf("Introduzca la informacion--->" );
	scanf("%d",&infor);
	fflush(stdin);
	p->info = infor;
	p->izq= NULL;
	p->der = NULL;
	printf("Desea Introducir otro nodo ? [s/n]--->  ");
	scanf("%c",&resp);
	fflush(stdin);
	if ( resp == 's' || resp == 'S')
	  {
	  	do
	  	 {
		   printf("Introduzca la informacion--->" );
	        scanf("%d",&infor);
	        fflush(stdin);
	        inser_bal(&p,&bo,infor);
	        printf("Desea Introducir otro nodo ? [s/n]--->  ");
	        scanf("%c",&resp);
	        fflush(stdin);
	  	  	
		   }while ( resp == 's' || resp == 'S');
	     
	 }
	return(p);
}
arbol *carga(arbol *p)
{
	arbol *q;
	int infor;
	char resp;
	
	printf("Introduzca la informacion--->" );
	scanf("%d",&infor);
	fflush(stdin);
	p->info = infor;
	printf("Hay rama por la izquierda de %d ? [s/n]--->",p->info);
	scanf("%c",&resp);
	fflush(stdin);
	if ( resp == 's' || resp == 'S')
	  {
	  	q = crea_arbol();
	  	p->izq = q;
	  	carga(p->izq);
	  }
	  else
	      p->izq = NULL;
	      
	printf("Hay rama por la derecha de %d ? [s/n]--->",p->info);
	scanf("%c",&resp);
	fflush(stdin);
	if ( resp == 's' || resp == 'S')
	  {
	  	q = crea_arbol();
	  	p->der = q;
	  	carga(p->der);
	  }
	  else
	      p->der = NULL;
	return(p);
}

void pre_orden(arbol *p)
{
	if( p != NULL)
      {
      	printf("[%d] - %d - ",p->info,p->fe);
      	pre_orden(p->izq);
      	pre_orden(p->der);
	 }
  return;
}
void pos_orden(arbol *p)
{
	if( p != NULL)
      {
      	pos_orden(p->izq);
      	pos_orden(p->der);
      //	printf("[%d] ",p->info);
      	printf("[%d] - %d -",p->info,p->fe);
      	
	 }
  return;
}

void in_orden(arbol *p)
{
	if( p != NULL)
      {
      	in_orden(p->izq);
      	//printf("[%d] ",p->info);
      	printf("[%d] - %d -",p->info,p->fe);
          in_orden(p->der);
	 }
  return;
}

void busqueda(arbol *p, int infor )
{
	// 1.
	if( infor < p->info)
	{
	//	1.1
		if( p->izq == NULL)
		 printf("\n\n\t\t -*- %d No esta en el arbol -*-",infor);
		else
		   busqueda(p->izq,infor);
		    // 1.1 fin del 1.1 
	}
	else
	      //1.3
	    if( infor > p->info)
	    {
	    	//1.3.1
		if( p->der == NULL)
		 printf("\n\n\t\t -*- %d No esta en el arbol -*-",infor);
		else
		   busqueda(p->der,infor);
		   // 1.3.2  fin de 1.3.1
	}
	else
	   	printf("\n\t\t -*- %d esta en el arbol -*-",p->info);
	// 1.4 fin del condicional 1.3
	// 2 fin del paso 1
	return;    
}

void busqueda1(arbol *p, int infor )
{
	// 1.
  if( p != NULL)
  {
  // 1.1
	if( infor < p->info)
	
	 busqueda1(p->izq,infor);
		   
	else
	// 1.1.1
	    if( infor > p->info)
	    	  busqueda1(p->der,infor);
	    else
             printf("\n\t\t -*- %d esta en el arbol -*-",p->info);
     // 1.1.2 fin de 1.1.1
     // 1.2 fin paso 1.1
  }
 else 
    printf("\n\n\t\t -*- %d No esta en el arbol -*-",infor);
// 2 fin del paso 1.
return;    
}

void insercion(arbol *p, int infor )
{
	arbol *q;

//1. 
	if( infor < p->info)
	{
	// 1.1	        
		if( p->izq == NULL)
		{
			q = crea_arbol();
			q->izq = NULL;
			q->der = NULL;
			q->info = infor;
			p->izq = q;
		}
		else
		    insercion(p->izq, infor);
		       //1.2 fin del paso condicional 1.1
	} 
	else
	     // 1.3
       if  ( infor >p->info)
	    {
	          // 1.3.1	
	       if( p->der == NULL)
		   {
			q = crea_arbol();
			q->izq = NULL;
			q->der = NULL;
			q->info = infor;
			p->der = q;
		   }
		   else
		    insercion(p->der, infor);
		           // 1.3.2 fin del paso 1.3.1
		}  
	 else
	 printf("\n\n\t\t -*- %d ya esta en el arbol -*-",infor);
	// 1.4 fin del paso 1.3
	// 2. Fin Paso 1.	
	return;    
}

/*
void elimina_elemento( arbol *p,int nref)
{
	arbol *aux, *aux1, *q;
	int bandera;
// 1.	
	if ( p != NULL)
//	{
		// 1.1 
		if(nref < p->info)
		 
		   elimina_elemento(p->izq,nref);
		else
		   {
		   
		    // 1.1.1
		    if(nref > p->info)
		    
		           elimina_elemento(p->der,nref);
		    	
			else
			     {
			     	q = p;
			     	// 1.1.1.1
			     	
			     	if (q->der == NULL)
			     	   p = q->izq;
			     	else
			     	   
			     	   	//1.1.1.1.1
			     	   	if ( q->izq == NULL)
			     	   	  p = q->der;
			     	   	 else
							 {
							 	aux = p->izq;
							 //	aux1 = aux;
							   bandera = 0;
					// 1.1.1.1.1.A		   
							 	while(aux->der != NULL)
							 	{
							 		aux1 = aux;
							 		aux = aux->der;
		 					 		bandera = 1;
								 };
					// 1.1.1.1.1.B	fin de 1.1.1.1.1.A		 
								 p->info = aux->info;
								 q = aux;
					// 1.1.1.1.1.C			 
								 if( bandera == 1)
								 
								     aux1->der = aux->izq;
								 else
								     p->izq = aux->izq;
					             // 1.1.1.1.1.D fin del 1.1.1.1.1.C
						 // 1.1.1.1.2 fin de 1.1.1.1.1 
					} // 1.1.1.2 fin de 1.1.1.1
				free(q);	
			         // 1.1.2 fin de 1.1.1	
}
     // 1.2 fin del 1.1		        
}
	 else 
	     printf("\n El nodo no se encuentra en el arbol");
// 2 fin del paso 1	     
return;	     
}
*/

void elimina_elemento( arbol **APNnodo,int info)
{
	arbol *aux, *aux1, *otro;
	int bandera;
// 1.	
	if ( (*APNnodo) != NULL)
	{
		// 1.1 
		if(info < ((*APNnodo)->info))
		 {
		 
		   elimina_elemento(&(*APNnodo)->izq,info);
	    }
		else
		   {
		   
		    // 1.1.1
		    if(info > ((*APNnodo)->info))
		    {
			
		           elimina_elemento(&((*APNnodo)->der),info);
		    }
			else
			     {
			     	otro = (*APNnodo);
			     	// 1.1.1.1
			     	
			     	if (otro->der == NULL)
			     	  {
					   (*APNnodo) = otro->izq;
					   }
					    
			     	else
			     	   {
						
			     	   	//1.1.1.1.1
			     	   	if ( otro->izq == NULL)
			     	   	  {
							 (*APNnodo)= otro->der;
					   	}		 
			     	   	 else
							 {
							 	aux = ((* APNnodo)->izq);
							 //	aux1 = aux;
							   bandera = 0;
					// 1.1.1.1.1.A		   
							 	while(aux->der != NULL)
							 	{
							 		aux1 = aux;
							 		aux = aux->der;
		 					 		bandera = 1;
								 };
					// 1.1.1.1.1.B	fin de 1.1.1.1.1.A		 
								 ((*APNnodo)->info) = aux->info;
								 otro = aux;
					// 1.1.1.1.1.C			 
								 if( bandera == 1)
								 {
								 
								     aux1->der = aux->izq;
							    }
								 else
								 {
								 
								     ((*APNnodo)->izq) = aux->izq;
								}
					             // 1.1.1.1.1.D fin del 1.1.1.1.1.C
						 }// 1.1.1.1.2 fin de 1.1.1.1.1 
					} // 1.1.1.2 fin de 1.1.1.1
				free(otro);
		} // 1.1.2 fin de 1.1.1	
    } // 1.2 fin del 1.1		        

	 }else 
	     printf("\n El nodo no se encuentra en el arbol");
// 2 fin del paso 1	     
return;	     
}


arbol *deleteNode(arbol *p, int value)
{
	arbol *temp = NULL;
	if (p != NULL)
	{
		if (p->info== value)
		{
			if(p->izq == NULL && p->der == NULL)
			{
				free(p);
				return NULL;
			}
			else
			    {
			    	if (p->izq == NULL)
			    	{
			    		temp = p->der;
			    		free(p);
			    		return temp;
					}
					
					if(p->der == NULL)
					{
						temp = p->izq;
						free(p);
						return temp;
					}
					
					temp =findMin(p->der);
					p->info = temp->info;
					p->der = deleteNode(p->der,temp->info);
				}
			   
		}
		else {
			
			if (p->info > value)
			{
				p->izq = deleteNode(p->izq,value);
			}
			else
			   {
			   	p->der = deleteNode(p->der,value);
			   }
		}
	}
	return p;
}



void inser_bal(arbol **nodo,int *bo, int infor )
{

	arbol *nodo1, *nodo2;
	nodo1=nodo2= NULL;
// 1.	
if( *nodo != NULL)
{
    // 1.1
	if( infor < (*nodo)->info)
	{
	//	if( p->izq != NULL)
		 inser_bal(&(*nodo)->izq,bo,infor);
		 
	// 1.1.1
		if ( *bo == V)
		{
		//	1.1.1.1
			switch( (*nodo)->fe)
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
				   // 1.1.1.1.1
					  if( nodo1->fe <= 0) // Rotacion II
					  {
					  	printf("\n Inicio Rotacion II\n");
					  	pos_orden(*nodo);
					  	(*nodo)->izq = nodo1->der;
					  	nodo1->der = *nodo;
					  	(*nodo)->fe = 0;
					  	*nodo = nodo1;
					  	printf("\n Fin Rotacion II\n");
					  	pos_orden(*nodo);
					  }   // Termina Rotacion II
					  else  // Rotacion ID
					  {
					  	printf("\n Inicio Rotacion ID\n");
					  	pos_orden(*nodo);
					  	nodo2 = nodo1->der;
					  	(*nodo)->izq = nodo2->der;
					  //	aux1->der = aux1->izq;
					  	nodo2->der = *nodo;
					  	nodo1->der = nodo2->izq;
						nodo2->izq = nodo1;
					// 1.1.1.1.1.A  
					 if ( nodo2->fe == -1)
					     (*nodo)->fe = 1;
					 else
					     (*nodo)->fe = 0;
				// 1.1.1.1.1.B	 fin 1.1.1.1.1.A
				// 1.1.1.1.1.C
					 if ( nodo2->fe == 1)
					     nodo1->fe = -1;
					 else
					     nodo1->fe = 0;
				// 1.1.1.1.1.D   fin 1.1.1.1.1.C
					 *nodo = nodo2; 
					// Termina Rotacion ID
					printf("\n Fin Rotacion ID\n");
					  	pos_orden(*nodo);
		            }
		    // 1.1.1.1.2 fin del condicional del paso 1.1.1.1.1
					 (*nodo)->fe = 0;
					 *bo = F;
					 break;	
				 
				}// fin del case -1
			} // 1.1.1.2 del condicional 1.1.1.1 fin del switch
		} // 1.1.2 fin del condicional 1.1.1  Si(*bo == V)
	  } // fin del condicional si (infor < p->info )
	  else
	  // 1.1.3 
	  if (infor > (*nodo)->info)
        {
	   
         // if(  p->der != NULL)
	        inser_bal(&(*nodo)->der,bo,infor);
	    // 1.1.3.1
		if ( *bo == V)
		  {
		  	// 1.1.3.1.1 
			switch( (*nodo)->fe)
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
					   // Restructuracion del arbol
					 // 1.1.3.1.1.A   
					   if( nodo1->fe >= 0) // Rotacion DD
					   {
					    printf("\n Inicio Rotacion DD\n");
					  	pos_orden(*nodo);
					  	(*nodo)->der = nodo1->izq;
					  	nodo1->izq = (*nodo);
					  	(*nodo)->fe = 0;
					  	*nodo = nodo1;
					  	printf("\n Fin Rotacion DD\n");
					  	pos_orden(*nodo);
					  } // Termina la Rotacion DD
					  else // Rotacion DI
					  {
					  	printf("\n Inicio Rotacion DI\n");
					  	pos_orden(*nodo);
					  	nodo2 = nodo1->izq;
					  	(*nodo)->der = nodo2->izq;
					  	 nodo2->izq = *nodo;
					  	nodo1->izq = nodo2->der;
					  	nodo2->der = nodo1;
					    if ( nodo2->fe == 1)
					         (*nodo)->fe = -1;
					    else
					        (*nodo)->fe = 0; // fin Cond interno
					   
					    if ( nodo2->fe == -1)
					        nodo1->fe = 1;
					     else
					         nodo1->fe = 0;
					 *nodo = nodo2;
				} 
				printf("\n Fin Rotacion DI\n");
					  	pos_orden(*nodo);
				// Termina la Rotacion DI
			//	1.1.3.1.1.B fin del condicional del paso 1.1.3.1.1.A
				 (*nodo)->fe = 0;
				 *bo = F;
				 break;
			   } // 1.1.3.1.2 fin del case 1
		  } // fin del switch
		} // fin del condicional Si(bo == V)
	 } // fin del condicional si (infor > nodo->info )
	 else
	 printf("\n\n\t\t -*- %d ya esta en el arbol -*-",infor);
	 
} 
else
    {
	  *nodo = crea_arbol();
	  (*nodo)->info = infor;
	  (*nodo)->izq = NULL;
	  (*nodo)->der = NULL;
	   (*nodo)->fe = 0;
	   *bo = V;
	//		p->izq = q; 
     }
	return;    
}

void elim_bal(arbol **nodo, int *bo, int infor)
{
	
	arbol *otro;
	
	
	if( *nodo != NULL)
	 {
	 	if( infor < (*nodo)->info)
	 	{
	 		elim_bal( &(*nodo)->izq, bo, infor);
	 	    restructura1(&(*nodo),bo);
		 }
		 else if(infor > (*nodo)->info)
		       {
		       	elim_bal(&(*nodo)->der,bo,infor);
		       	restructura2(&(*nodo),bo);
			  }
			  else
			  {
			  	otro = *nodo;
			  	
			  	if( otro->der == NULL)
			  	  {
					
			  	  *nodo = otro->izq;
			  	   *bo = V;
			      }
				  else if( otro->izq == NULL)
				        {
						   *nodo = otro->der;
						   *bo = V;
					    }
			  	        else
			  	        {
			  	        	borra(&otro->izq, &otro,bo);
			  	        	restructura1(&(*nodo),bo);
			  	        } // fin del else
			  	        free(otro);
			  }
	 } // Fin del p != NUUL
      else
         printf("\n\n\t\t -*- %d No esta en el arbol -*-",infor);
     
return;
}

void restructura1(arbol **nodo, int *bo)
{
	arbol *nodo1, *nodo2;
	nodo1 = nodo2 = NULL;
	
	if(*bo == V)
	 {
	    switch( (*nodo)->fe)
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
					  if( nodo1->fe >= 0)
					  {
					  	// rotacion DD
					  	(*nodo)->der = nodo1->izq;
					  	nodo1->izq = *nodo;
					  	switch(nodo1->fe)
					  	{
					  		case 0:
							       {
									 (*nodo)->fe= 1;
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
						}// switch interno
						
					  *nodo = nodo1;
					  }
					  else
					  {  // Rotacion DI
					  	nodo2 = nodo1->izq;
					  	(*nodo)->der = nodo2->izq;
					  	nodo2->izq = *nodo;
					  	nodo1->izq = nodo2->der;
					  	nodo2->der = nodo1;
					  }
					  
					 if ( nodo2->fe == 1)
					     (*nodo)->fe = -1;
					 else
					     (*nodo)->fe = 0;
					     
					 if ( nodo2->fe == -1)
					     nodo1->fe = 1;
					 else
					     nodo1->fe = 0;
					 *nodo = nodo2;
					 nodo2->fe = 0;
					
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
	if( *bo == V)
	 {
	    switch( (*nodo)->fe)
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
					  if( nodo1->fe <= 0)
					  { // Rotacion II
					  	(*nodo)->izq = nodo1->der;
					  	nodo1->der = (*nodo);
					  	
					  	switch(nodo1->fe)
					  	{
					  		case 0: 
							      {
								  
								  (*nodo)->fe= -1;
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
					      }// fin switch interno
					   *nodo = nodo1;
			        } // fin de nodo1->fe <= 0
					  else
					  { // rotacion ID
					  	nodo2 = nodo1->der;
					  	(*nodo)->izq = nodo2->der;
					  	nodo2->der = *nodo;
					  	nodo1->der = nodo2->izq;
					  	nodo2->izq = nodo1;
					  
					  
					 if ( nodo2->fe == -1)
					     (*nodo)->fe = 1;
					 else
					     (*nodo)->fe = 0;
					     
					 if ( nodo2->fe == 1)
					     nodo1->fe = -1;
					 else
					     nodo1->fe = 0;
					     
					 *nodo = nodo2;
					 
					 nodo2->fe = 0;
				    }
					 break;	
		      }//  fin del case -1
			} // fin del switch nodo -> fe
	 } // Fin del condicional (BO == V)
    
	 return;
}

int buscar_menor(arbol *p, int menor)
{
	if ( p != NULL)
	  {
	  	if( p->izq != NULL)
	  	 {
	  	 	return(buscar_menor(p->izq, menor));
		}
		menor=p->info;
		printf("\n El menor es %d", menor);
	  }
  return 0;
}

void buscar_menor2(arbol *p)
{

	  	if( p->izq != NULL)
	  	 {
	  	 	buscar_menor2(p->izq);
		}
		
	else	printf("\n El menor2 es %d",p->info);
	  

}
arbol *findMin(arbol *p)
{
	if(p != NULL)
	{
		while(p->izq)
		{
			p = p->izq;
		}
	}
	return p;
}

arbol *findMinRec(arbol *p)
{
	if(p != NULL)
	   return NULL;
	if(p->izq == NULL)
	  return p;
	else
	     return findMinRec(p->izq);
	
}
int buscar_mayor(arbol *p, int mayor)
{
	if ( p != NULL)
	  {
	  	if( p->der != NULL)
	  	 {
	  	 	return(buscar_mayor(p->der, mayor));
		}
		mayor=p->info;
		printf("\n El mayor es %d", mayor);
	  }
  return 0;
}
void buscar_mayor2(arbol *p)
{
	
	  	if( p->der != NULL)
	  	 {
	  	 	buscar_mayor2(p->der);
		}
		else
		
		printf("\n El mayor2 es %d",p->info);
	  

}

arbol *findMax(arbol *p)
{
	if(p != NULL)
	{
		while(p->der)
		{
			p = p->der;
		}
	}
	return p;
}

arbol *findMaxRec(arbol *p)
{
	if(p != NULL)
	   return NULL;
	if(p->der == NULL)
	  return p;
	else
	     return findMaxRec(p->der);
	
}

void imprime_hojas(arbol *p)
{
	if( p != NULL)
	{
		if ( p->izq == NULL && p->der == NULL)
		  {
		  	printf("\n La hoja en el arbol es: %d",p->info);
		  }
		  imprime_hojas(p->izq);
		  imprime_hojas(p->der);
	}
}

int num_hojas(arbol *p)
{
	if( ! p)
       return 0;
       	
		if ( ! p->izq  && ! p->der )
		  
		     return 1;
		  	
		 else  	
	return (num_hojas(p->der) + num_hojas(p->izq));
		      
}

/* OPcion 13 */
int numElementos(arbol *p)
{
	if (!p)
	  return 0;
	else 
	    return (1 + numElementos(p->der) + numElementos(p->izq));
}


int sumaTodos(arbol *p)
{
	 int suma, izq ,der;
	static int i=1;
	if( p == NULL)
	   return 0;
	 
	printf("%d Izquierda\n",i);  
	izq = sumaTodos(p->izq);
	printf("%d Derecha\n",i);
	der = sumaTodos(p->der);
	
	suma = izq + der + p->info;
printf("%d. %d + %d + %d = %d\n",i++,izq,der,p->info,suma);
	
	return suma;
}
int profundidadArbol(arbol *p)
{
	 static int i = 1;
	if( ! p )
	   return 0;
	else
	{
	//	printf("%d Izquierda\n",i); 
		int LDepth = profundidadArbol(p->izq);
      //  printf("%d. LDepth= %d\n",i++,LDepth);		
	//	printf("%d Derecha\n",i);
		int RDepth = profundidadArbol(p->der);
	//printf("%d. RDepth= %d\n",i++,RDepth);		
		if(LDepth > RDepth )
		   return LDepth + 1;
		else
		    return RDepth + 1;
	}
	 
}




/* Opcion 14 */
void borra(arbol **aux, arbol **otro, int *bo)
{
	if((*aux)->der != NULL)
	 {
	 	borra(&(*aux)->der, &(*otro), bo);
	 	restructura2(&(*aux),bo);
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

arbol *freeTree(arbol *p)
{
	if( p != NULL)
	 
	 {
	 	p->izq = freeTree(p->izq);
	 	p->der = freeTree(p->der);
	 	if(p->izq == NULL && p->der == NULL)
	 	{
	 		free(p);
	 		return NULL;
		 }
	 }
	 return NULL;
}
