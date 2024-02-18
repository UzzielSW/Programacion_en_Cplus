#include <stdio.h>
#include <stdlib.h>

//ALGORITMOS
#include "help1_5.h"
#include "help6_10.h"
#include "help11_15.h"
#include "help16_20.h"

int main()
{
	NODO *list = NULL;
	int opc, dato;
	int v;
	char res;

	do
	{system("cls");
		printf("\n\t\t.: LISTAS SIMPLE ENLAZADAS :.");
		printf("\n\n\t1. Crea inicio\t\t\t\t[0]{Vaciar lista}");
		printf("\n\t2. Crea final");
		printf("\n\t3. Recorrer lista");
		printf("\n\t4. Insertar al inicio");
		printf("\n\t5. Insertar al final");
		printf("\n\t6. Insertar antes de X");
		printf("\n\t7. Insertar despues de X");
		printf("\n\t8. Eliminar al inicio");
		printf("\n\t9. Eliminar el ultimo");
		printf("\n\t10.Elimina X");
		printf("\n\t11.Elimina ANTES de X");
		printf("\n\t12.Busqueda en lista Desordenada");
		printf("\n\t13.Busqueda en lista Ordenada Ascendentea");
		printf("\n\t14.Busqueda Recursiva en lista Desordenada");
		printf("\n\t15.Invertir la lista");
		printf("\n\t16.Ordenar Descendente");
		printf("\n\t17.Ordenar Ascendente");
		printf("\n\t18.Crea Descendente");
		printf("\n\t19.Crea Ascendente");

		printf("\n\nopc? ");

		fflush(stdin);
		v = scanf("%d",&opc);
		if(!v) break;

		switch(opc){

			case 0:list = liberaMemoria(list);break;

			case 1:
				if(list == NULL)
					list = creaInicio();
				else 
					printf("LA LISTA YA ESTA CREADA");
			break;

			case 2:
				if(list == NULL)
					list = creaFinal();
				else 
					printf("LA LISTA YA ESTA CREADA");
			break;

			case 3:
				if(list != NULL){
					printf("\n [R] or [I]:_");
					v = scanf("%c",&res);

					if(v)
						if(res == 'R' || res == 'r')
							recorreRecursivo(list);
						else 
							recorreIterativo(list);
					else
						 recorreIterativo(list);
				}
				else 
					printf("\n\tLa lista esta vacia");
			break;

			case 4:
				if(list == NULL)
					list = creaInicio();
				else 
					list = insertarInicio(list);
			break;

			case 5:
				if(list == NULL)
					list = creaFinal();
				else 
					list = insertarFinal(list);
			break;

			case 6:
				recorreRecursivo(list);
				list = inserta_antes_X(list);
				recorreRecursivo(list);
			break;

			case 7:
				recorreRecursivo(list);
				list = inserta_despues_X(list);
				recorreRecursivo(list);
			break;

			case 8:
				if (list != NULL){
					recorreRecursivo(list);
					list = elimina_inicio(list);				
					recorreRecursivo(list);
				}			
				else
					printf("\n\tLa lista esta vacia");
			break;

			case 9:
				if (list != NULL){
					recorreRecursivo(list);
					list = elimina_ultimo(list);
					recorreRecursivo(list);
				}
				else
					printf("\n\tLa lista esta vacia");			
			break;

			case 10:
				if (list != NULL){
					recorreRecursivo(list);
					list = elimina_X(list);
					recorreRecursivo(list);
				}
				else
					printf("\n\tLa lista esta vacia");			
			break;

			case 11:
				if (list != NULL){
					recorreRecursivo(list);
					list = elimina_antes_X(list);
					recorreRecursivo(list);
				}
				else
					printf("\n\tLa lista esta vacia");			
			break;


			case 12:
				if (list != NULL){
					recorreRecursivo(list);
					busqueda_desordenada(list);
				}
				else
					printf("\n\tLa lista esta vacia");			
			break;

			case 13:
				if (list != NULL){
					recorreRecursivo(list);
					busqueda_ordenada(list);
				}
				else
					printf("\n\tLa lista esta vacia");			
			break;

			case 14:
				if (list != NULL){
					recorreRecursivo(list);

					printf("\n [NODO X] Introduzca un valor entero: ");
					if(scanf("%i",&dato))
						busqueda_recursiva(list, dato);								
				}
				else
					printf("\n\tLa lista esta vacia");			
			break;

			case 15:
				if (list != NULL){
					recorreRecursivo(list);
					reverse(&list);
					printf("\n");
					recorreRecursivo(list);
				}
				else
					printf("\n\tLa lista esta vacia");			
			break;

			case 16:
				if (list != NULL){
					recorreRecursivo(list);
					list = ordena_descendente(list);
					printf("\n");
					recorreRecursivo(list);
				}
				else
					printf("\n\tLa lista esta vacia");			
			break;

			case 17:
				if (list != NULL){
					recorreRecursivo(list);
					list = ordena_ascendente(list);
					printf("\n");
					recorreRecursivo(list);
				}
				else
					printf("\n\tLa lista esta vacia");			
			break;

			case 18:
				if (list == NULL)
					list = crea_descendente();
				else 
					printf("LA LISTA YA ESTA CREADA");		
			break;

			case 19:
				if (list == NULL)
					list = crea_ascendente();
				else 
					printf("LA LISTA YA ESTA CREADA");		
			break;

			default: recorreRecursivo(list);
		}getchar();
	} while (true);
	return 0;
}
