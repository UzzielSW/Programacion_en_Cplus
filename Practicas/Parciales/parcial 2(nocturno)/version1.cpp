/*
	programa para implementar metodo de ordenacion burbuja.
	en archivos de texto almacenar cantidad de numeros de: 
		* mil numeros
		* 3mil numeros
		* 5mil numeros

	leerlos independientemente cada archivo y almacenarlo en un arreglo.
	luego aplicarle el metodo de ordenamiento (ascendente o descendente).
	mostrar el arreglo ordenado. mostrar la cantidad de iteraciones y el tiempo que tomo ordenarlo.
 */

#include<stdio.h>
#include<fstream>
#include<time.h>
using namespace std;
#define cinco 5000
#define tres 3000
#define mil 1000

void ordenacion_burbuja(int arreglo[cinco]);

int main()
{
	ifstream archivo;
	int dato, cant = 0;
	int arreglo[cinco];

	archivo.open("cincoMil.txt", ios::in);

	if(archivo.fail())
	{
		printf("error en la apertura del archivo");
		return 1;
	}
	else
	{
		printf("\n leyendo el archivo...");

		//leyendo un numero en el archivo y almacenando en el arreglo posicion [0]
		archivo >> arreglo[cant];  

		while(! archivo.eof()) // mientras no llegue al final del archivo
		{	
			cant++;
			//leyendo los demas numeros y almacenando en las siguientes posiciones
			archivo >> arreglo[cant];
		}

		printf("\n se a leido correctamente el archivo ");
		getchar();
		archivo.close(); // cerrando el archivo
	}

	clock_t start = clock();
	ordenacion_burbuja(arreglo); // llamando al metodo para ordenar el arreglo

	// imprimir el arreglo
	for (int i = 0; i < cant; ++i)
	{
		if (i % 15 == 0)
			printf("\n");

		printf(" %d,", arreglo[i]);
	}
	
	printf("\n Tiempo transcurrido: %.5lf",((double) clock() - start) / CLOCKS_PER_SEC);
	printf("\n iteraciones : [%d]", cinco * cinco);
	getchar();
	return 0;
}


void ordenacion_burbuja(int arreglo[cinco])
{
	int aux;

	for (int i = 0; i < cinco; ++i)
	{
		for (int k = 0; k < cinco-1; ++k)
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