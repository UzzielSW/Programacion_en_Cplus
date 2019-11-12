/*2. Escribe un programa que defina un vector de n�meros y calcule la 
multiplicaci�n acumulada de sus elementos.*/
#include<iostream>
using namespace std;

int main()
{
	int numeros[5] = {1, 2, 3, 4, 5};
	int multiplicacion = 1;

	for(int i=0; i < 5; i++)
		multiplicacion *= numeros[i]; //Hacemos la multiplicacion iterativa
	
	cout<<"La multiplicacion de los elementos es: "<<multiplicacion<<endl;
	
	getchar();
	return 0;
}