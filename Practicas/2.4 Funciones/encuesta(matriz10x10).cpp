/*
	problema:
	una matriz encuesta de 10x10 elementos se declara para registrar las respuestas de 10 personas a 10 preguntas
	sobre sus conocimientos de alfabetizacion en salud. Cada pregunta puede tener 5 alternativas de respuestas:
	|| 1.muy facil || 2.facil || 3.dificil || 4.muy dificil || 5. no sabe ||.
	-Debe cargar la matriz con estos valores aleatoriamente.
	
	-hacer un menu con las siguientes opciones:
	1.imprimir la matriz encuesta
	2.contabilizar por pregunta cantidad de 1,2,3,4 y 5
	3.imprimir un vector con el mayor numero (1,2,3,4 o 5) de respuestas por persona
	4.presente una grafica por cantidad de 1,2,3,4 y 5
	5.salir
*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

void cargar(int [][10]);
void imprimir(int [10][10]);
void contabilizar(int [10][10], int[]);
void mayor(int []);
void orden(int []);

int main()
{
	int opc = 0;
	int respuestas[5];
	int encuesta[10][10];
	
	// cargando matriz
	cout<<"\n ingresar datos a matriz: "<<endl;
	cargar(encuesta);
	// menu
	do{
		system("cls");
		cout<<"\n 1.imprimir la matriz de encuesta"
			<<"\n 2.contabilizar por pregunta cantidad (1,2,3,4,5)"
			<<"\n 3.imprime un vector con la mayor numero(1,2,3,4,5)"
			<<"\n 4.presente una grafica"
			<<"\n 5.salir"
			<<"\n\n opcion: ";	cin>>opc;

			cout<<"\n";
			switch(opc)
			{
				case 1: imprimir(encuesta);               	break;
				case 2: contabilizar(encuesta,respuestas); 	break; 
				case 3: mayor(respuestas);        			break;
				case 4: orden(respuestas);             		break;
				case 5: cout<<"\n OK";						break;
				default: cout<<"\n opcion invalida";		break;
			}
			fflush(stdin);
			getchar();
  	}while(opc != 5);
 	return 0;
}

void cargar(int matriz[10][10])
{
	for (int i = 0; i < 10; ++i)	
		for (int k = 0; k < 10; ++k)	
			cin>>matriz[i][k];
}

// funciones menu
void imprimir(int matriz[10][10])
{
	for (int i = 0; i < 10; ++i)
	{	
		for (int k = 0; k < 10; ++k)	
			cout<<" "<<matriz[i][k];	
		
		cout<<endl;		
	}
}

void contabilizar(int encuesta[][10], int respuestas[5])
{
	for (int i = 0; i < 5; ++i) respuestas[i] = 0;

	for (int i = 0; i < 10; ++i)
	{
		for (int k = 0; k < 10; ++k)
		{
			if(encuesta[i][k] == 1) respuestas[0]++;
			if(encuesta[i][k] == 2) respuestas[1]++;
			if(encuesta[i][k] == 3) respuestas[2]++;
			if(encuesta[i][k] == 4) respuestas[3]++;
			if(encuesta[i][k] == 5) respuestas[4]++;
		}
	}

	cout<<"\n contabilizado"<<endl;
}


void mayor(int encuesta[5])
{
	int mayor = 0, pos = 0;
	char tipos[5][15] = {"muy facil", "facil", "dificil", "muy dificil", "no sabe"};

	for (int i = 0; i < 5; ++i)
	{	
		if (encuesta[i] > mayor)
		{ 
			mayor = encuesta[i];	
			pos = i; 
		}  
	}

	cout<<" el mayor numero de las encuestas fue: ["<<(pos+1)<<"] "<<tipos[pos];
	cout<<"\n con cantidad: "<<mayor;
}


void orden(int encuesta[5])
{
	string cant[] = {"[1] muy facil", "[2] facil", "[3] dificil", "[4] muy dificil", "[5] no sabe"};
	string aux2;
	int aux=0, min=0;

	for (int i = 0; i < 5; ++i)
	{	
		min = i;
		for (int k = i+1; k < 5; ++k)
			if (encuesta[k] < encuesta[min])
				min = k;


		aux = encuesta[i];
		encuesta[i] = encuesta[min];
		encuesta[min] = aux;
		
		aux2 = cant[i];
		cant[i] = cant[min];
		cant[min] = aux2;
	}

	cout<<" grafica: "<<endl;
	for (int i = 4, k = 1; i >= 0; --i, ++k)
		cout<<k<<".cantidad "<<cant[i]<<": "<<encuesta[i]<<endl;
}