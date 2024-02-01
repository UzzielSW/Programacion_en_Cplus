/*
	programa para validar un sistema de ecuaciones, osea comprobar la igualdad
			matriz(sistema)				bj
	[]x1 + []x2 + []x3 + []x4 + []x5 = [ ]
	[]x1 + []x2 + []x3 + []x4 + []x5 = [ ]
	[]x1 + []x2 + []x3 + []x4 + []x5 = [ ]
	[]x1 + []x2 + []x3 + []x4 + []x5 = [ ]
*/
#include <stdio.h>
#include <iostream>
using namespace std;

void jump(int);
void viewS(float **, float *, float, float);
void view(float **, float *, float, float);
void update(float **, float, float);
void update(float *, float);
void valida(float **, float *, float, float, float *);

int main()
{
	float **sistema, *bj, 
		*vars; // arreglo que contiene los valores de las variables
	int nEcu = 2; //cantidad de restricciones o ecuaciones o filas
	int nVariable = 3; //cantidad de variables o columnas

	cout<<"Ingrese la cantidad de restricciones: ";
	cin>>nEcu;

	cout<<"Ingrese la cantidad de variables: ";
	cin>>nVariable;

	// creando matriz
	vars = new float[nVariable];
	bj = new float[nEcu];
	sistema = new float* [nEcu];

	for (int i = 0; i < nEcu; i++) {
		sistema[i] = new float[nVariable];
	}

	// inicializando valores
	for (int i = 0; i < nEcu; i++) {
		for (int k = 0; k < nVariable; k++) {
			sistema[i][k] = 0.00;
		}

		bj[i] = 0.00;
	}
	
	//mostrando matriz
	cout<<" Sistema Inicial:\n";
	viewS(sistema, bj, nEcu, nVariable);

	//agregando valores
	cout<<"\n Ingrese los valores del sistema:"<<endl;
	update(sistema, nEcu, nVariable);

	cout<<"\n Ingreselos valores de bj:"<<endl;
	update(bj, nEcu);

	//mostrando matriz
	cout<<"\n Sistema:\n";
	view(sistema, bj, nEcu, nVariable);

	cout<<"\n Ingrese valor de las variables:\n";
	for(int i = 0; i < nVariable; i++)
	{
		printf("X%d: ", i+1);
		cin>>vars[i];
	}

	//validando sistema
	cout<<"\n Validando Sistema\n";
	valida(sistema, bj, nEcu, nVariable, vars);

	//liberando memoria
	for (int i = 0; i < nEcu; i++) {
		delete[] sistema[i];
	}
	delete[] sistema;
   
	fflush(stdin);
	getchar();
	return 0;
}

void view(float **sistema, float *bj, float fil, float col){
	for (int i = 0; i < fil; ++i)
	{
		for (int k = 0; k < col; ++k)
		{
			if(k!=0) cout<<" +";
			printf(" [%.1f]X%d", sistema[i][k], k+1);
		}
		printf(" = %.1f\n", bj[i]);
	}
}

void viewS(float **sistema, float *bj, float fil, float col){

	jump(col/2);
	cout<<"[sistema]";
	jump(col/2);
	cout<<"[bj]"<<endl;

	for (int i = 0; i < fil; ++i)
	{
		for (int k = 0; k < col; ++k)
		{
			printf(" [%.1f]", sistema[i][k], k+1);
		}
		printf(" | [%.1f]\n", bj[i]);
	}
}

//sobrecarga para sistema
void update(float **sistema, float fil, float col)
{
	for (int i = 0; i < fil; ++i)
	{
		for (int k = 0; k < col; ++k)
		{
			cin>>sistema[i][k];
		}
	}	
}

//sobrecarga para bj
void update(float *bj, float fil)
{
	for (int i = 0; i < fil; ++i)
	{
		cin>>bj[i];
	}	
}

void valida(float **sistema, float *bj, float fil, float col, float *vars)
{
	float suma = 0;
	bool test = true;

	for (int i = 0; i < fil; ++i)
	{
		for (int k = 0; k < col; ++k)
		{
			if(k!=0) cout<<" +";
			printf(" [%.1f](%.1f)", sistema[i][k], vars[k]);
			suma += sistema[i][k] * vars[k];
		}

		printf(" = %.1f", bj[i]);

		printf("\t\t=> [%.1f] = [%.1f]\t", suma, bj[i]);
		cout<<((bj[i] == suma)? "[/]" : "[X]")<<endl;
		suma = 0;
	}
}

void jump(int n)
{
	for (int i = 0; i <= n; ++i)
		cout<<"\t";
}