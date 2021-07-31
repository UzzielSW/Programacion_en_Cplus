/*1. Escribe un programa que lea de la entrada estandar dos numeros y muestre 
en la salida estandar su suma, resta, multiplicacion y division.*/
#include<iostream>
using namespace std;

int main()
{
	float n1, n2;
	
	cout<<"Digite un numero: "; cin>>n1;
	cout<<"Digite otro numero: "; cin>>n2;
	
	cout<<"\nLa suma es: "<< (n1 + n2)
		<<"\nLa resta es: "<< (n1 - n2)
		<<"\nLa multiplicacion es: "<< (n1 * n2)
		<<"\nLa division es: "<< ((n2 != 0)? (n1 / n2) : 0);
		
	return 0;
}
