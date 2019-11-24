/*Ejercicio 1: Comprobar si un n�mero es par o impar, y se�alar la posicion de memoria 
donde se est� guardando el n�mero. Con punteros.*/
#include<iostream>
using namespace std;

int main()
{
	int numero, *dir_numero;
	
	cout<<"Digite un numero: "; cin>>numero; //Pedimos el numero al usuario
	
	dir_numero = &numero;
	
	cout<<"El numero: "<<*dir_numero<<" es "<< ( ((*dir_numero % 2) == 0)? "par" : "impar" ) <<endl;
	cout<<"Posicion: "<<dir_numero<<endl;
	
	getchar();
	return 0;
}