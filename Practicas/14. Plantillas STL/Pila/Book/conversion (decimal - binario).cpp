#include <stdio.h>

typedef struct
{
	int bit;
} StackData;

#include "stack.h"

int main()
{
	StackData temp;
	int n;
	Stack S = initStack();

	printf("\n Ingrese un entero positivo: ");
	scanf("%d", &n);

	while (n > 0)
	{
		temp.bit = n % 2;
		push(S, temp); // agregando a la pila
		n = n / 2;
	}

	printf("\n El numero equivalente en binario es: ");
	while (!empty(S))			  // mientras la pila no este vacia
		printf("%d", pop(S).bit); // mostrando el elemento superior

	printf("\n");
	fflush(stdin);
	getchar();
	return 0;
}