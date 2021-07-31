/*3. Realice un programa que lea un valor entero y determine si se trata de un 
numero par o impar.*/
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
	else if((numero % 2) == 0)
		cout<<"par";
	else
		cout<<"impar";
	
	return 0;
}