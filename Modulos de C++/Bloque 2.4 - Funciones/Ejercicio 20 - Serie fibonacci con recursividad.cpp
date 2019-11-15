/*Ejercicio 20: Realice una funci�n recursiva para la serie Fibonacci 
Nota: La serie de Fibonacci est� formada por la secuencia de n�meros: 
0, 1, 1, 2, 3, 5, 8, 13, 21, 34... 

	fibonacci(n) = n                              , si n<2
				   fibonacci(n-1)+fibonacci(n-2)  , si n>=2

*/
#include<iostream>
using namespace std;

int fibonacci(int n);

int main()
{
	int nElementos;
	
	//Pedimos un numero entero positivo
	do{
		cout<<"Digite el numero de elementos: ";
		cin>>nElementos;
	}while(nElementos <= 0);
	
	//Mandamos llamar a la funcion pero de forma iterativa para imprimir todos los elementos
	cout<<"Serie Fibonacci: ";
	for(int i=0; i < nElementos; i++)
		cout<<fibonacci(i)<<" , ";	
	
	getchar();
	return 0;
}

int fibonacci(int n)
{
	if(n < 2)//Caso base
		return n;
	else//Caso general
		return fibonacci(n - 1) + fibonacci(n - 2);
}