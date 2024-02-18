#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;
#define MAX 5000 

//estructura de datos
struct burbujas
{
	int datos[MAX];
}burbuja;

// variable 
int N, aux, i, j, c, d, k;

//tipo de funciones
void leerArchivo();
void burbujaMenor();
void burbujaMayor();
void gotoxy (short x, short y);

//Funcion principal
int main()
{
	int menu = 0;	

	while(menu != 4)
	{	
		system("cls");
		printf("\n\t\t*****Metodo de Ordenamiento******\n  ");	
		printf("\n\tMENU \n");
		printf("\n 1. LEER EL ARCHIVO TXT\n ");
		printf("\n 2. METODO BURBUJA MENOR\n  ");
		printf("\n 3. METODO BURBUJA MAYOR \n   ");
		printf("\n 4. SALIR\n");
		printf("\n INTRODUZCA UNA OPCI%CN:1 al 4:",162);
		scanf("%d",&menu);fflush(stdin);
		
		switch(menu)
		{
		    case 1:	leerArchivo();		break; 
			case 2: burbujaMenor();		break;	
		    case 3:	burbujaMayor(); 	break;
		    case 4:  printf("\nSaliste del Programa\n");   break;	
		    default: printf("\nEstá opción no existe.\n"); break;
       	}

       	getch();
  	}

	return 0;	
}

void gotoxy (short x, short y)
{
	COORD pos = {x, y};
	// devolver el manippulador para la entrada y salida 
	SetConsoleCursorPosition(GetStdHandle (STD_OUTPUT_HANDLE), pos);
}
void t(int n){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n);}

//FUNCION PARA LLAMAR AL  ARCHIVO
void leerArchivo()
{
	string nombreA;
	string linea;
	ifstream miarchivo;
	i = 0;

	for(j=0; j<MAX ;burbuja.datos[j++]=0);
	
	printf("\n introduzca el nombre del archivo: ");
	cin>>nombreA;

	miarchivo.open(nombreA.c_str());
	if(miarchivo)
	{	
		miarchivo>>burbuja.datos[i];
		while(!miarchivo.eof())
		{
			if (i % 20 == 0) cout<<endl;//comentar si quieres que no salga los numeros al leer
			
			cout<<burbuja.datos[i]<<" ";//comentar
			i++;
    		miarchivo>>burbuja.datos[i];
		}

		printf("\n\n los numeros NO han sino ordenados....\n ");
		printf("\n vamos a ordenarlo pulse Enter...\n ");		
		miarchivo.close();  
	}
	else
	{
		cout<<"\n\tNo se pudo abrir el archivo :(";   
		return;
	}

	for(i=0; burbuja.datos[i] > 0;i++); N = i;    
}


void burbujaMenor()
{
	clock_t start = clock();
    
    cout<<"\n Arreglo Mayor a Menor: \n";              
	for(i=0; i<N ;i++)
	{
	    for(k=0;k < N-1;k++)
	    {
	       if(burbuja.datos[k]>burbuja.datos[k+1])
	       {
            	aux = burbuja.datos[k];
                burbuja.datos[k] = burbuja.datos[k+1];
                burbuja.datos[k+1] = aux;
		   }
	    }
	}
	              

	for(i=0;i<N;i++)
		cout<<"["<<i+1<<"]\t"<<burbuja.datos[i]<<endl;
	
	cout<<"\n iteraciones: "<<(N*N);
	cout<<"\n Tiempo transcurrido: "<< ((double)clock() - start) / CLOCKS_PER_SEC << endl;
	return;	
}


void burbujaMayor()
{
    clock_t start = clock();
	
	cout<<"\n Arreglo Mayor a Menor: \n";
    for(i=0; i<N ;i++)
	{
	    for(k=0;k < N-1;k++)
	    {
	       if(burbuja.datos[k] < burbuja.datos[k+1])
	       {
            	aux = burbuja.datos[k];
                burbuja.datos[k] = burbuja.datos[k+1];
                burbuja.datos[k+1] = aux;
		   }
	    }
	}

	for(i=0;i<N;i++)
		cout<<"["<<i+1<<"]\t"<<burbuja.datos[i]<<endl;
	
	cout<<"\n iteraciones: "<<(N*N);
	cout<<"\n Tiempo transcurrido: "<< ((double)clock() - start) / CLOCKS_PER_SEC << endl;
	return;
}
