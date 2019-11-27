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
#include "iostream"
#include "conio.h"
#include "stdlib.h"
#include "string.h"
using namespace std;

int main()
{
	int opc=0;
	int respuestas[5];
	int encuesta[10][10];
	void cargar(int [][10]);
	void imprimir(int [10][10]);
	void contabilizar(int [10][10],int[]);
	void mayor(int[]);
	void orden(int[]);
	
	// cargando matriz
	cout<<"\n ingresar datos a matriz: "<<endl;
	cargar(encuesta);
	// menu
do{
	system("cls");
	cout<<"\n 1.imprimir la matriz de encuesta"<<endl
		<<" 2.contabilizar por pregunta cantidad (1,2,3,4,5)"<<endl
		<<" 3.imprime un vector con la mayor numero(1,2,3,4,5)"<<endl
		<<" 4.presente una grafica"<<endl
		<<" 5.salir"<<endl
		<<"\n opcion: ";cin>>opc;

		switch(opc){
			case 1:  cout<<endl; imprimir(encuesta);                break;
			case 2:	 cout<<endl; contabilizar(encuesta,respuestas); break;	 
			case 3:	 cout<<endl; mayor(respuestas);        			break;
			case 4:	 cout<<endl; orden(respuestas);             	break;
			case 5:  exit(0);              				            break;
			default: cout<<endl; cout<<"fail";           			break;
		}
  getch();
  }while(opc!=5);
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
	for (int i = 0; i < 10; ++i){	
		for (int k = 0; k < 10; ++k){	
			cout<<" "<<matriz[i][k];	
		}
		cout<<endl;		
	}
}



void contabilizar(int encuesta[][10],int respuestas[5]){
	int uno,dos,tres,cuatro,cinco;
	uno=dos=tres=cuatro=cinco=0;
	for (int i = 0; i < 10; ++i)
	{
		for (int k = 0; k < 10; ++k)
		{
			if(encuesta[i][k]==1) uno++;
			if(encuesta[i][k]==2) dos++;
			if(encuesta[i][k]==3) tres++;
			if(encuesta[i][k]==4) cuatro++;
			if(encuesta[i][k]==5) cinco++;
		}
	}
	respuestas[0]=uno; respuestas[1]=dos; respuestas[2]=tres; respuestas[3]=cuatro; 
	respuestas[4]=cinco;
	cout<<" contabilizado"<<endl;
}


void mayor(int encuesta[5]){
	int mayor=0,pos=0;

	for (int i = 0; i < 5; ++i){	if (encuesta[i]>mayor){ mayor = encuesta[i];	pos = i; }  }

	if(pos==0) cout<<" el mayor numero de las encuestas fue: [1] muy facil";
	if(pos==1) cout<<" el mayor numero de las encuestas fue: [2] facil";
	if(pos==2) cout<<" el mayor numero de las encuestas fue: [3] dificil";
	if(pos==3) cout<<" el mayor numero de las encuestas fue: [4] muy dificil";
	if(pos==4) cout<<" el mayor numero de las encuestas fue: [5] no sabe";

	cout<<"\n con cantidad: "<<mayor;

}


void orden(int encuesta[5]){
	
	string cant[]={"[1] muy facil","[2] facil","[3] dificil","[4] muy dificil","[5] no sabe"};
	string aux2;
	int aux=0,min=0;

	for (int i = 0; i < 5; ++i){	
		min = i;
		for (int k=i+1; k < 5; ++k)
		{
			if (encuesta[k]<encuesta[min])
			{
				min = k;
			}
		}
		aux = encuesta[i];
		aux2 = cant[i];
		encuesta[i] = encuesta[min];
		cant[i] = cant[min];
		encuesta[min] = aux;
		cant[min] = aux2;
	  }

	cout<<" grafica: "<<endl;
	for (int i = 4,k = 1; i >= 0; --i,++k)
	{
		cout<<k<<".cantidad "<<cant[i]<<": "<<encuesta[i]<<endl;
	}
}
