/*Ejercicio 14: Realiza una funci�n que tome como par�metros un vector de enteros y su
tama�o e imprima un vector con los elementos impares del vector recibido.*/
#include<iostream>
using namespace std;

void pedirDatos();
void impares(int vec[], int);

int tam, vec[100];

int main()
{
	pedirDatos();
	impares(vec, tam);
	
	getchar();
	return 0;
}

void pedirDatos()
{
	cout<<"Digite el tamanio del vector: ";
	cin>>tam;
	
	for(int i=0; i < tam; i++)
	{
		cout<<(i + 1)<<". Digite un numero: ";
		cin>>vec[i];
	}
}

void impares(int vec[], int tam)
 { 
 	int vecImpares[100];
	int j = 0;

	for(int i=0; i < tam; i++)
	{
		if((vec[i] % 2) != 0)
		{
			vecImpares[j] = vec[i];
			j++;
		}
	}
	
	cout<<"\nImprimiendo los elementos impares del vector: "<<endl;
	for(int i=0; i < j; i++)
		cout<<vecImpares[i]<<" ";
}