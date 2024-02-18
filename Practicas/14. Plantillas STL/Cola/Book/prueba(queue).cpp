/*
	miremos un ejemplo en ejecucion:
	
	ingrese un entero positivo: 123  
	imprimiendo la cola: 321  
*/

#include <stdio.h>

//la estructura "QueueData" siempre debe ir primero que el llamado a la libreria "queue.h"

#include "queue.h"

int main()
{
	int n;
	QueueData temp;
	Queue Q = initQueue();
	printf("\n ingrese un entero positivo: ");
	scanf("%d",&n);

	while(n > 0)
	{
		temp.num = n % 10;
		enqueue(Q, temp);
		n = n / 10;
	}

	printf("\n imprimiendo la cola: ");
	while(!empty(Q))
		printf("%d", dequeue(Q).num);

	printf("\n");
	fflush(stdin);
	getchar();
	return 0;
}