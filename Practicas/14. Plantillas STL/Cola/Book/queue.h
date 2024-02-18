#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

/*
	Estructura base de todo programa que representa
	el conjunto de todos los datos o dato que tendra cada nodo
	de la cola en este caso se utilizo solamente se uso
	solamente un int.
*/

typedef struct
{
	int num; // argumento cambiante
} QueueData;

typedef struct node
{
	QueueData data;
	struct node *next;
} Node, *NodePtr;

typedef struct queueType
{
	NodePtr head, tail;
} QueueType, *Queue;

Queue initQueue()
{
	Queue qp = (Queue)malloc(sizeof(QueueType));
	qp->head = NULL;
	qp->tail = NULL;
	return qp;
}

int empty(Queue Q)
{
	return (Q->head == NULL);
}

void enqueue(Queue Q, QueueData d)
{
	NodePtr np = (NodePtr)malloc(sizeof(Node));
	np->data = d;
	np->next = NULL;
	if (empty(Q))
	{
		Q->head = np;
		Q->tail = np;
	}
	else
	{
		Q->tail->next = np;
		Q->tail = np;
	}
}

QueueData dequeue(Queue Q)
{
	if (empty(Q))
	{
		printf("\n La cola esta vacia");
		exit(1);
	}

	QueueData hold = Q->head->data;
	NodePtr temp = Q->head;
	Q->head = Q->head->next;
	if (Q->head == NULL)
		Q->tail = NULL;
	free(temp);
	return hold;
}

QueueData peek(Queue Q)
{
	if (!empty(Q))
		return Q->head->data;
	printf("\n la cola esta vacia\n");
	exit(1);
}

#endif