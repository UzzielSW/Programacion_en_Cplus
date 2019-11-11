//2. Escribe la siguiente expresión como expresión en C++: (a+b)/(c+d) 
#include<iostream>
using namespace std;

int main()
{
	float a,b,c,d;
	
	cout<<"Digite el valor de a: "; cin>>a;
	cout<<"Digite el valor de b: "; cin>>b;
	cout<<"Digite el valor de c: "; cin>>c;
	cout<<"Digite el valor de d: "; cin>>d;
	
	cout.precision(2);//recorta los números despues de la coma decimal a 2
	
	cout<<"El resultado es: "<< (((c + d) != 0)? ((a + b) / (c + d)) : 0);
	
	return 0;
}