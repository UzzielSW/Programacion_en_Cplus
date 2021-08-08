// Validando la longitud de un texto a un tamaño especifico. 
#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	string temp, textFinal;
	const int max = 10;

	cout<<"\n Digite un texto: ";
	getline(cin, temp); //Guardando la cadena de caracteres

	if(temp.length() <= max)
		textFinal = temp;
	else
		//establece un maximo de caracteres 'max' desde la posicion inicial que este caso es 0
		textFinal = temp.substr(0, max); 
		
	cout<<"\n texto final: "<< textFinal <<endl;
	
	return 0;
}