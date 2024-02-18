/*
	miremos un ejemplo en ejecucion:

	ingrese la expresion infija: (7 - 8 / 2 / 2) * ((7 - 2) * 3 - 6)

	Forma posfija: 7 8 2 / 2 / - 7 2 - 3 * 6 - *

	El valor de la expresion: 45

	hay que tener en cuenta que este algoritmo solo acepta
	expresiones donde los numeros varian de 0-9
	por lo que si ponemos numeros mayores a nueve no funcionara correctamente.

*/
#include <stdio.h>
#include <ctype.h>
#include <stack> //libreria para pila

typedef struct
{
	char ch;
	int num;
} StackData;

int main()
{
	int readConvert(char[]);
	void printPostfix(char[], int);
	int eval(char[], int);
	char post[50];

	int n = readConvert(post);
	printPostfix(post, n);
	printf("\n El valor de la expresion: %d", eval(post, n));

	fflush(stdin);
	getchar();
	return 0;
}

// funcion para leer y convertir a posfija
int readConvert(char post[])
{
	char getToken(), token, c;
	int precedence(char);
	StackData temp;
	int h = 0;
	std::stack<StackData> Pila; // inicializando pila

	printf("\n ingrese la expresion infija: ");
	token = getToken();

	while (token != '\n')
	{
		if (isdigit(token))
			post[h++] = token; // si es un numero
		else if (token == '(') // de ser '(' se agrega a la pila
		{
			temp.ch = token;
			Pila.push(temp);
		}

		else if (token == ')') // de ser ')' se saca de la pila
		{
			while ((c = Pila.top().ch) != '(')
			{
				post[h++] = c;
				Pila.pop();
			}

			Pila.pop(); // sacando el '('
		}

		else // si es un operador aritmetico
		{
			while (!Pila.empty() && precedence(Pila.top().ch) >= precedence(token))
			{
				post[h++] = Pila.top().ch;
				Pila.pop();
			}

			temp.ch = token;
			Pila.push(temp);
		}

		token = getToken();
	} // end while

	while (!Pila.empty())
	{
		post[h++] = Pila.top().ch;
		Pila.pop();
	}

	return h;
}

// funcion para imprimir la expresion en forma posfija
void printPostfix(char post[], int n)
{
	printf("\n Forma posfija: ");
	for (int h = 0; h < n; h++)
		printf("%c ", post[h]);

	printf("\n");
}

char getToken()
{
	char ch;
	while ((ch = getchar()) == ' ')
		; // cuerpo vacio
	return ch;
}

int precedence(char c)
{
	if (c == '(')
		return 0;
	if (c == '+' || c == '-')
		return 3;
	if (c == '*' || c == '/')
		return 5;
}

// funcion para evaluar la expresion posfija
int eval(char post[], int n)
{
	int a, b, c;
	StackData temp;
	std::stack<StackData> Pila;

	for (int h = 0; h < n; h++)
	{
		if (isdigit(post[h]))
		{
			temp.num = post[h] - '0'; // conversion a entero
			Pila.push(temp);
		}
		else
		{
			b = Pila.top().num;
			Pila.pop();

			a = Pila.top().num;
			Pila.pop();

			if (post[h] == '+')
				c = a + b;
			if (post[h] == '-')
				c = a - b;
			if (post[h] == '*')
				c = a * b;
			if (post[h] == '/')
				c = a / b;

			temp.num = c;
			Pila.push(temp);
		}
	}

	temp = Pila.top();
	Pila.pop();

	return temp.num;
}