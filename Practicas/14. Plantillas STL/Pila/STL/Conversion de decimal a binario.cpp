#include <stdio.h>
#include <stack> //libreria para pila

int main()
{
	std::stack<int> Pila; // definiendo la pila
	int n;

	printf("\n Ingrese un entero positivo: ");
	scanf("%d", &n);

	while (n > 0)
	{
		Pila.push(n % 2); // agregando a la pila
		n = n / 2;
	}

	printf("\n El numero equivalente en binario es: ");
	while (!Pila.empty()) // mientras la pila no este vacia
	{
		printf("%d", Pila.top()); // mostrando el elemento superior
		Pila.pop();				  // sacando de la pila
	}

	printf("\n");
	fflush(stdin);
	getchar();
	return 0;
}