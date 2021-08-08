/*Ejercicio 21: Escriba una funcion recursiva que calcule un numero elevado a una 
potencia entera mayor o igual que cero: x^y. 

	potencia(x, y) = x    , y=1
	x * potencia(x, y-1)  , y>1
*/
#include<iostream>
using namespace std;

int potencia(int, int);

int main()
{
	int base, exponente;
	
	//Pedimos los datos al usuario
	cout<<"Digite numero base: ";
	cin>>base;

	cout<<"Digite exponente: ";
	cin>>exponente;
	
	//Mostramos el resultado
	cout<<"\nResultado: "<<potencia(base, exponente)<<endl;	
	
	return 0;
}

int potencia(int x, int y)
{
	int pot;
	if(y == 1)//Caso base
		pot = x;
	else//Caso general
		pot = x * potencia(x, y - 1);
		
	return pot;
}