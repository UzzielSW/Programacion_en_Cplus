/*
	miremos un ejemplo en ejecucion:
	
	ingrese un entero positivo: 123  
	imprimiendo la cola: 321  
*/

#include <stdio.h>
#include <queue> // definicion del adaptador queue

int main()
{
	int n;
	std::queue < int > cola; // cola con valores int

	printf("\n ingrese un entero positivo: ");
	scanf("%d",&n);

	while(n > 0)
	{
		cola.push(n % 10); //agregando a la cola
		n = n / 10;
	}

	printf("\n imprimiendo la cola: ");
	while(!cola.empty()) //mientras la cola no este vacia
	{
		printf("%d ", cola.front()); //imprime el primer elemento
		cola.pop(); // sacando de la cola
	}

	printf("\n");
	fflush(stdin);
	getchar();
	return 0;
}