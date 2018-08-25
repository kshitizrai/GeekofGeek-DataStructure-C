#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h> 
#include <string.h>

struct Node
{
	int top;
	int capacity;
	int *array;
};

struct Node *createStack(int capacity)
{
	struct Node *stack = (struct Node*)(malloc(sizeof(struct Node)));

	stack->top = -1;
	stack->capacity = capacity;
	stack->array = (int*)(malloc(sizeof(int)*capacity));

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
}

int pop(struct Node *stack)
{
	if(isEmpty(stack))
		return(INT_MIN);

	return(stack->array[stack->top--]);
}

int peek(struct Node *stack)
{
	if(isEmpty(stack))
		return(INT_MIN);

	return(stack->array[stack->top]);
}

struct Node* reverse(struct Node *stack , int x)
{
	int y,i=0;

	struct Node *stack2 = createStack(x);

	for(i=0 ; i<x ; i++)
	{
		y = pop(stack);
		push(stack2,y); 
	}

	return(stack2);
}

int main()
{
	char exp[] = "1234567890";
	int x = strlen(exp);
	int i=0;

	struct Node *stack = createStack(x);
	
	for(i=0 ; i<x ; i++)
		push(stack,(int)exp[i]);

	stack = reverse(stack,x);

	while(peek(stack) != INT_MIN)
	{
		printf("%d",(char)pop(stack));
	}
}
