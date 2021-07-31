/*2. Escribir un programa que de la entrada estandar el precio de un producto y muestre
en la salida estandar el precio del producto al aplicarle el IVA.*/
#include<iostream>
using namespace std;

int main()
{
	float precio, IVA;
	
	cout<<"Digite el precio del producto: ";
	cin>>precio;
	
	IVA = precio * 0.7; //7%
	
	cout<<"\nEl precio final al aplicarle ITBM es: "<<precio + IVA;
	return 0;
}