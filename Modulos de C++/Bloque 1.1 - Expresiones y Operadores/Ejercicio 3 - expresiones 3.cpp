//3. Escribe la siguiente expresión como expresión en C++: (a+(b/c))/(d+(e/f))
#include<iostream>
using namespace std;

int main()
{
	float a,b,c,d,e,f;
	
	cout<<"Digite el valor de a: "; cin>>a;
	cout<<"Digite el valor de b: "; cin>>b;
	cout<<"Digite el valor de c: "; cin>>c;
	cout<<"Digite el valor de d: "; cin>>d;
	cout<<"Digite el valor de e: "; cin>>e;
	cout<<"Digite el valor de f: "; cin>>f;
	
	cout.precision(2);//recorta los números despues de la coma decimal a 2
	
	if( (c != 0) && (f != 0) && (((d + (e / f)) != 0)) )
		cout<<"El resultado es: "<<(a + (b / c))/(d + (e / f));
	else 
		cout<<"\n no div by zero";
	
	return 0;
}