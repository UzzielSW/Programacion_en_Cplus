/*5. Desarrolle un programa que lea de la entrada est�ndar un vector de enteros 
y determine el mayor elemento del vector.*/
#include<iostream>
using namespace std;

int main()
{
	int numeros[100], n, mayor = 0;
	
	cout<<"Digite el numero de elementos: ";
	cin>> n;
	
	for(int i=0; i < n; i++)
	{
		cout<<(i + 1)<<". Digite un numero: ";
		cin>>numeros[i]; //Guardamos los elementos en el arreglo
		
		if(numeros[i] > mayor) //Determinamos el mayor elemento en cada
			mayor = numeros[i]; //iteracion del bucle
	}
	
	cout<<"\nEl mayor elemento del vector es: "<< mayor <<endl;
	
	getchar();	
	return 0;
}