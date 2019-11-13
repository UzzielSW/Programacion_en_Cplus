/*9. Realice un programa que lea una cadena de caracteres de la entrada est�ndar y 
muestre en la salida est�ndar cu�ntas ocurrencias de cada vocal existen en la cadena.*/
#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char frase[30];
	int vocal_a = 0, vocal_e = 0, vocal_i = 0, vocal_o = 0, vocal_u = 0;
	
	cout<<"Digite una frase: ";
	cin.getline(frase, 30, '\n');
	
	for(int i=0; i < 30; i++)
	{
		switch(frase[i])
		{
			case 'a': vocal_a++; break;
			case 'e': vocal_e++; break;
			case 'i': vocal_i++; break;
			case 'o': vocal_o++; break;
			case 'u': vocal_u++; break;
		}
	}
	
	cout<<"\nContador de vocales"
		<<"\nVocal a: "<< vocal_a
		<<"\nVocal e: "<< vocal_e
		<<"\nVocal i: "<< vocal_i
		<<"\nVocal o: "<< vocal_o
		<<"\nVocal u: "<< vocal_u <<endl;
		
	getchar();
	return 0;
}