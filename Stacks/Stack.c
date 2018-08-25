#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct stack
{
	int capacity;
	int top;
	int *array;
};

struct stack* create(int size)
{
	struct stack *initialise = (struct stack*)(malloc(sizeof(struct stack)));

	initialise->top = -1;
	initialise->capacity = size;
	initialise->array = (int*)(malloc(sizeof(int)*size));

	return(initialise);
}

bool isFull(struct stack *head)
{
	return(head->top == head->capacity - 1);
}

bool isEmpty(struct stack *head)
{
	return(head->top == -1);
}

void push(struct stack *head , int data)
{
	if(isFull(head))
		return;

	head->array[++head->top] = data;
	return;
}

int pop(struct stack *head)
{
	if(isEmpty(head))
		return(INT_MIN);

	return(head->array[head->top--]);
}

int main()
{
	struct stack *head = create(5);

	push(head,5);
	push(head,4);
	push(head,3);
	push(head,2);
	push(head,1);

	printf("%d \n",pop(head));
		push(head,1);
	printf("%d \n",pop(head));
	printf("%d \n",pop(head));
	printf("%d \n",pop(head));
	printf("%d \n",pop(head));
	printf("%d \n",pop(head));
}