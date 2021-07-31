/*9. Realice un programa que calcule el valor que toma la siguiente funcion para 
unos valores dados de x e y: f(x,y) = sqrt(x) / (pow(y,2)-1)*/
#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	float x,y,resultado = 0;
	
	cout<<"Digite el valor de x: "; cin>>x;
	cout<<"Digite el valor de y: "; cin>>y;
	
	if(y == 1){
		cout<<"\n no division entre cero";
		return 1;	
	} 
	
	resultado = sqrt(x) / (pow(y, 2) - 1);
	
	cout<<"\nEl resultado es: "<<resultado;
	
	return 0;
}