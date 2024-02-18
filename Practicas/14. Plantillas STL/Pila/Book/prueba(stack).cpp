#include <stdio.h>

// la estructura siempre debe ir primero que el llamado a la libreria "stack.h"
typedef struct
{
	char ch;
} StackData;

#include "stack.h"

int main()
{
	StackData temp;
	char c;
	Stack S = initStack();

	printf("\n ingrese caracteres para agregar a la pila: ");
	while ((c = getchar()) != '\n')
	{
		temp.ch = c;
		push(S, temp);
	}

	printf("\n Sacando de la Pila: ");
	while (!empty(S))
		putchar(pop(S).ch);

	getchar();
	return 0;
}