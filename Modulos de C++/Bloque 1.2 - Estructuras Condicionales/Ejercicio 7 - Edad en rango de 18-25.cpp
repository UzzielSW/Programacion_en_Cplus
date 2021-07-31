/*7. Escriba un programa que solicite una edad (un entero) e indique en la 
salida estandar si la edad introducida esta en el rango [18-25].*/
#include<iostream>
using namespace std;

int main()
{
	int edad;
	
	cout<<"Digite su edad: "; 
	cin>>edad;
	
	cout<<"\n Su edad esta ";
	if((edad >= 18) && (edad <= 25))
		cout<<"en el rango de [18-25]";
	else
		cout<<"fuera de rango";
	
	return 0;
}