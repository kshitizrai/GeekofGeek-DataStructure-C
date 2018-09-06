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

void push(struct Node *stack ,int data)
{
	if(isFull(stack))
		return;

	stack->array[++stack->top] = data;
}

int pop(struct Node *stack)
{
	if(isEmpty(stack))
		return(INT_MAX);

	return(stack->array[stack->top--]);
}

void NGE(int *exp , int length)
{
	int next,element;
	struct Node *stack = createStack(length);

	push(stack,exp[0]);

	for(int i=1 ; i<length ; i++)
	{
		next = exp[i];
	
		if(!isEmpty(stack))
		{
			element = pop(stack);

			while(next > element)
			{
				printf("%d ----> %d \n",element,next);
				
				if(isEmpty(stack))
					break;
				
				element = pop(stack);
			}

			if(element>next)
				push(stack,element);
		}

		push(stack,exp[i]);
	} 

	while(!isEmpty(stack))
	{
		element=pop(stack);
		printf("%d ----> %d\n",element,-1);
	}
}

int main()
{
	int array[] = {11 , 13 , 21 , 3 };
	int length = sizeof(array)/sizeof(int);
	printf("Length %d \n",length);
	NGE(array,length);

	return(0);
}