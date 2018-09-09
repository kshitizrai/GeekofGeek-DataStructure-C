#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>

struct Stack
{
	int front;
	unsigned int capacity;
	int *array;
};

bool isEmpty(struct Stack *stack)
{
	return(stack->front == 0);
}

bool isFull(struct Stack *stack)
{
	return(stack->front == stack->capacity - 1);
}

struct Stack *createStack(int capacity)
{
	struct Stack *stack = (struct Stack*)(malloc(sizeof(struct Stack)));

	stack->front = 0;
	stack->capacity = capacity;

	stack->array = (int*)(malloc(sizeof(int)*capacity));
	return(stack);
}

void push(struct Stack *stack , int data)
{
	if(isFull(stack))
		return;

	stack->array[stack->front++] = data;
	return;
}

int pop(struct Stack *stack)
{
	if(isEmpty(stack))
		return(INT_MIN);

	int data = stack->array[--stack->front];

	return(data);
}

int deQueue(struct Stack *queue)
{
	struct Stack *stack2 = createStack(10);

	while(!isEmpty(queue))
		push(stack2,pop(queue));	

	int data = pop(stack2);

	while(!isEmpty(stack2))
		push(queue,pop(stack2));

	return(data);
}

int main()
{
	struct Stack *queue = createStack(10);

	push(queue,10);
	push(queue,20);
	push(queue,30);
	push(queue,40);
	push(queue,50);

	printf("%d \n" , deQueue(queue));
	push(queue,60);
	printf("%d \n" , deQueue(queue));
	printf("%d \n" , deQueue(queue));
	printf("%d \n" , deQueue(queue));
	printf("%d \n" , deQueue(queue));
	printf("%d \n" , deQueue(queue));
}