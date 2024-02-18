#include<stdio.h>
#include<fstream>
using namespace std;

void cargarArreglo(int[], int, const char *);
void ordenacion_descendente(int[], int);
void ordenacion_ascendente(int[], int);
void mostrar(int[], int);

int main ()
{
	int arreglo1[1000];
	int arreglo3[3000];
	int arreglo5[5000];
	int opcion=0, opc;

	do
	{	system("cls");
		printf("\t\t-------------Metodo de ordenacion burbuja-------------\n");
		printf("\t\t1. Para 1,000 numeros\n");
		printf("\t\t2. Para 3,000 numeros\n");
		printf("\t\t3. Para 5,000 numeros\n");
		printf("\t\t---------Ingrese 4 para salir de la operacion---------\n");
		printf("\n\n\topcion? ");
		scanf("%d",&opcion);

		if(opcion == 1)
		{
			cargarArreglo(arreglo1, 1000, "mil.txt");
			printf("\n ordenar:\n 1.ascendente\n 2.descendente\n : ");
			scanf("%d",&opc);

			if (opc == 1)
				ordenacion_ascendente(arreglo1, 1000);
			else
				ordenacion_descendente(arreglo1, 1000);

			mostrar(arreglo1, 1000);
		}
		else if(opcion == 2)
		{
			cargarArreglo(arreglo3, 3000, "tresMil.txt");
			printf("\n ordenar:\n 1.ascendente\n 2.descendente\n : ");
			scanf("%d",&opc);

			if (opc == 1)
				ordenacion_ascendente(arreglo3, 3000);
			else
				ordenacion_descendente(arreglo3, 3000);

			mostrar(arreglo3, 3000);
		}
		else if(opcion == 3)
		{
			cargarArreglo(arreglo5, 5000, "cincoMil.txt");
			printf("\n ordenar:\n 1.ascendente\n 2.descendente\n : ");
			scanf("%d",&opc);

			if (opc == 1)
				ordenacion_ascendente(arreglo5, 5000);
			else
				ordenacion_descendente(arreglo5, 5000);

			mostrar(arreglo5, 5000);
		}
		else if(opcion == 4) printf("\n OK");
		else
			printf("\n opcion invalida");

		printf("\n");
		fflush(stdin);
		getchar();

	} while (opcion != 4);
	return 0;
}

void ordenacion_ascendente(int arreglo[], int cant)
{
	int aux;

	for (int i = 0; i < cant; ++i)
	{
		for (int k = 0; k < cant-1; ++k)
		{
			if (arreglo[k] > arreglo[k+1])
			{
				aux = arreglo[k];
				arreglo[k] = arreglo[k+1];
				arreglo[k+1] = aux;
			}
		}
	}
}


void ordenacion_descendente(int arreglo[], int cant)
{
	int aux;

	for (int i = 0; i < cant; ++i)
	{
		for (int k = 0; k < cant-1; ++k)
		{
			if (arreglo[k] < arreglo[k+1])
			{
				aux = arreglo[k];
				arreglo[k] = arreglo[k+1];
				arreglo[k+1] = aux;
			}
		}
	}
}

void mostrar(int arreglo[], int cant)
{
	for (int i = 0; i < cant; ++i)
	{
		if (i % 20 == 0)
			printf("\n");


		printf(" %d ", arreglo[i]);
	}
	
	printf("\n\n iteraciones: [%d]", cant * cant);
}


void cargarArreglo(int arreglo[], int cant, const char *name)
{
	ifstream archivo;
	int iter = 0;
	archivo.open(name, ios::in);

	if(archivo.fail())
	{
		printf("error en la apertura del archivo");
		exit(0);
	}
	else
	{
		printf("\n leyendo el archivo...");
		//leyendo un numero en el archivo y lo almaceno en en el arreglo posicion [0] 
		archivo >> arreglo[iter]; 

		while(! archivo.eof()) // mientras no llegue al final del archivo
		{	
			iter++;
			archivo >> arreglo[iter]; //leyendo los demas numeros y almacenando en las siguientes posiciones
		}

		printf("\n se a leido correctamente el archivo ");
		getchar();
		archivo.close(); // cerrando el archivo
	}
}