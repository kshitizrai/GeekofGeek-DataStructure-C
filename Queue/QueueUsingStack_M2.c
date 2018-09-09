#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

struct Node
{
	int data;
	struct Node *next;
};

struct Queue
{
	struct Node *stack1;
	struct Node *stack2;
};

void push(struct Node **stack , int data)
{
	struct Node *newNode = (struct Node*)(malloc(sizeof(struct Node)));

	newNode->data = data;
	newNode->next = *stack;

	*stack = newNode;
}

int pop(struct Node **stack)
{
	struct Node *top_ref = *stack;

	if(*stack == NULL)
		return(INT_MIN);

	int item = top_ref->data;
	*stack = top_ref->next;

	free(top_ref);

	return(item);
}

void enQueue(struct Queue *queue , int data)
{
	push(&(queue->stack1) , data);
}

int deQueue(struct Queue *queue)
{
	int item = pop(&(queue->stack1));

	while(item != INT_MIN)
	{
		push(&(queue->stack2),item);
		item = pop(&(queue->stack1));
	}

	int answer = pop(&(queue->stack2));

	item = pop(&(queue->stack2));

	while(item != INT_MIN)
	{
		push(&(queue->stack1),item);
		item = pop(&(queue->stack2));
	}

	return(answer);
}

struct Queue *createQueue()
{
	struct Queue *queue = (struct Queue*)(malloc(sizeof(struct Queue)));
	queue->stack1 = NULL;
	queue->stack2 = NULL;
}

int main()
{
	struct Queue *queue = createQueue();
	enQueue(queue,10);
	enQueue(queue,20);
	enQueue(queue,30);
	enQueue(queue,40);
	printf("%d \n",deQueue(queue));
	enQueue(queue,50);
	printf("%d \n",deQueue(queue));
	printf("%d \n",deQueue(queue));
	printf("%d \n",deQueue(queue));
	printf("%d \n",deQueue(queue));
}