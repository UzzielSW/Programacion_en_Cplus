/*5. Escriba un programa que lea de la entrada est�ndar un car�cter e indique 
en la salida est�ndar si el car�cter es una vocal min�scula o no.*/
#include<iostream>
using namespace std;

int main()
{
	char letra;
	
	cout<<"Digite un caracter: "; 
	cin>>letra;
	
	switch(letra)
	{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u': cout<<"Es una vocal minuscula"; break;
	}
		
	return 0;
}