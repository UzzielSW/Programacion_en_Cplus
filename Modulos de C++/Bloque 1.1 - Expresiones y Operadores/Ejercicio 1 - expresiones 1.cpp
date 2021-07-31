//1. Escribe la siguiente expresion como expresion en C++: (a/b) + 1
#include<iostream>
using namespace std;

int main()
{
	float n1, n2;
	
	cout<<"Digite el valor de a: "; cin>>n1; 
	cout<<"Digite el valor de b: ";	cin>>n2;
	
	cout.precision(2); //recorta los numeros despues de la coma decimal a 2
	cout<<"El resultado es: "<< ((n2 != 0)? ((n1/n2) + 1) : 0);	
	
	return 0;
}