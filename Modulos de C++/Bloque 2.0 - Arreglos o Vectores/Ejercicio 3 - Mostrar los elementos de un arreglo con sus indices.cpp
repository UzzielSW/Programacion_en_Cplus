/*3. Escribe un programa que lea de la entrada est�ndar un vector de n�meros y 
muestre en la salida est�ndar los n�meros del vector con sus �ndices asociados.*/
#include<iostream>
using namespace std;

int main()
{
	int numeros[100], n;
	
	cout<<"Digite el numero de elementos: ";
	cin>>n;
	
	for(int i=0; i < n; i++)
	{
		cout<<"Digite un numero: ";
		cin>>numeros[i]; //Guardamos los numeros en el arreglo
	}
	
	//Ahora, vamos a mostrar los numeros con sus indices asociados
	for(int i=0; i < n; i++)
		cout<< i <<" -> "<< numeros[i] <<endl; //Mostrando los numeros
		
	getchar();
	return 0;
}