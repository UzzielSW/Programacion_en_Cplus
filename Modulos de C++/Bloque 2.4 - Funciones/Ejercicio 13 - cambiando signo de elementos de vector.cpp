/*Ejercicio 13: Realiza una funcion que tome como parametros un vector de numeros y su
tamanio y cambie el signo de los elementos del vector.*/
#include<iostream>
using namespace std;

//Prototipos de Funciones
void pedirDatos();
void cambiarSigno();
void mostrarVector();

int tam, vec[100];

int main()
{
	//Llamada a las funciones - en orden
	pedirDatos();
	cambiarSigno();	
	mostrarVector();
	
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

void cambiarSigno()
{
	for(int i=0; i < tam; i++)
		vec[i] *= -1;
}

void mostrarVector()
{
	cout<<"\nMostrando vector con cambio de signo: "<<endl;
	for(int i=0; i < tam; i++)
		cout<<vec[i]<<" ";
}