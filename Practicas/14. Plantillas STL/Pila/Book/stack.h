#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

/*
	Estructura base de todo programa que representa
	el conjunto de todos los datos o dato que tendra cada nodo
	de la pila en este caso se utilizo solamente se uso
	solamente un char.

	typedef struct
	{
		char ch; //argumento cambiante
	}StackData;
*/

typedef struct node
{
	StackData data;
	struct node *next;
} Node, *NodePtr;

typedef struct stackType
{
	NodePtr top;
} StackType, *Stack;

Stack initStack()
{
	Stack sp = (Stack)malloc(sizeof(StackType));
	sp->top = NULL;
	return sp;
}

int empty(Stack S)
{
	return (S->top == NULL);
}

void push(Stack S, StackData d)
{
	NodePtr np = (NodePtr)malloc(sizeof(Node));
	np->data = d;
	np->next = S->top;
	S->top = np;
}

StackData pop(Stack S)
{
	if (empty(S))
	{
		printf("\n La pila esta vacia");
		exit(1);
	}

	StackData hold = S->top->data;
	NodePtr temp = S->top;
	S->top = S->top->next;
	free(temp);
	return hold;
}

StackData peek(Stack S)
{
	if (!empty(S))
		return S->top->data;
	printf("\n la pila esta vacia\n");
	exit(1);
}

#endif