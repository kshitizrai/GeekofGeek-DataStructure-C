#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

struct Node 
{
	int top;
	int capacity;
	int *array;
	struct Node *aux;
};

struct Node *createStack(int capacity)
{
	struct Node *stack = (struct Node*)(malloc(sizeof(struct Node)));
	struct Node *auxillary = (struct Node*)(malloc(sizeof(struct Node)));

	stack->top = -1;
	auxillary->top = -1;
	stack->capacity = capacity;
	auxillary->capacity = capacity;
	stack->array = (int*)(malloc(sizeof(int)*capacity));
	auxillary->array = (int*)(malloc(sizeof(int)*capacity));

	stack->aux = auxillary;
	return(stack);
}

bool isEmpty(struct Node *stack)
{
	return(stack->top == -1);
}

bool isFull(struct Node *stack)
{
	return(stack->top == stack->capacity - 1);
}

void push(struct Node *stack , int data)
{
	if(isFull(stack))
		return;

	stack->array[++stack->top] = data;
//	printf("Stack Pushed %d \n",data);

	if(isEmpty(stack->aux))
	{
		stack->aux->array[++stack->aux->top] = data;
//		printf("AUX Stack Pushed1 %d \n",data);
	}

	else if(stack->aux->array[stack->aux->top]>data)
	{
		stack->aux->array[++stack->aux->top] = data;
//		printf("AUX Stack Pushed2 %d \n",data);
	}
	else
	{
		stack->aux->array[stack->aux->top+1] = stack->aux->array[stack->aux->top];
//		printf("AUX Stack Pushed3 %d \n",stack->aux->array[stack->aux->top]);
		stack->aux->top = stack->aux->top + 1;
	}
}

int pop(struct Node *stack)
{
	if(isEmpty(stack))
		return(INT_MIN);

	stack->aux->top--;

	return(stack->array[stack->top--]);
}

void getMin(struct Node *stack)
{
	if(isEmpty(stack))
		return;

	printf("%d \n",(stack->aux->array[stack->aux->top]));
}

int main()
{
	struct Node *stack = createStack(5);

	push(stack,10);
	push(stack,20);
	push(stack,30);

	getMin(stack);
	push(stack,5);
	getMin(stack);
	int x=pop(stack);
	getMin(stack);
}

