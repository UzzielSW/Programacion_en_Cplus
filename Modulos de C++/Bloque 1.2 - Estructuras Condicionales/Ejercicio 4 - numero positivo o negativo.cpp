//4. Comprobar si un numero digitado por el usuario es positivo o negativo.
#include<iostream>
using namespace std;

int main()
{
	int numero;
	
	cout<<"Digite un numero: "; 
	cin>>numero;
	
	cout<<"\n El numero es ";
	if(numero == 0)
		cout<<"cero";
	else if(numero > 0)
		cout<<"positivo";
	else
		cout<<"negativo";
	
	return 0;
}