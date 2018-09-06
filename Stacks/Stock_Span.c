#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <limits.h>

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
	return(stack->top == (stack->capacity));
}

void push(struct Node *stack , int data)
{
	if(isFull(stack))
		{
			return;
		}

	stack->array[++stack->top] = data;
}

int pop(struct Node *stack)
{
	if(isEmpty(stack))
		return(INT_MIN);

	return(stack->array[stack->top--]);
}

int top(struct Node *stack)
{
	if(isEmpty(stack))
		return(INT_MIN);

	return(stack->array[stack->top]);
}

void stockspan(int price[] , int length)
{
	struct Node *stack = createStack(length);
	
	int array[length],y;
	
	push(stack,0);
	array[0] = 1;

	for(int i=1 ; i<length ; i++)
	{
		
		while(!isEmpty(stack) && price[top(stack)]<=price[i])
			 y = pop(stack);

		array[i] = isEmpty(stack)?i+1:(i-top(stack));

		push(stack,i);
	}

	for(int i=0 ; i<length ; i++)
		printf("%d ",array[i]);

	printf("\n");
}

int main()
{
	int array[]={10,4,5,90,120,80};
	stockspan(array,6);
}