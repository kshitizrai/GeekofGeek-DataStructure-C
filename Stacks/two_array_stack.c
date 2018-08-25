#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

struct Node
{
	int top1,top2;
	int capacity;
	int *array;
};

struct Node* createStack(int capacity)
{
	struct Node *stack = (struct Node*)(malloc(sizeof(struct Node)));
	stack->top1 = -1;
	stack->top2 = capacity-1;
	stack->capacity = capacity;
	stack->array = (int*)(malloc(sizeof(int)*capacity));
	return(stack);
}

bool isEmpty(struct Node *stack)
{
	return((stack->top2 - stack->top1) == stack->capacity);
}

bool isFull(struct Node *stack)
{
	return((stack->top2 - stack->top1) == 0);
}

void push1(struct Node *stack , int data)
{
	if(isFull(stack))
		return;

	stack->array[++stack->top1] = data;
}

void push2(struct Node *stack , int data)
{
	if(isFull(stack))
		return;

	stack->array[stack->top2--] = data;
}

int pop1(struct Node *stack)
{
	if(isEmpty(stack))
		return(INT_MIN);

	return(stack->array[stack->top1--]);
}

int pop2(struct Node *stack)
{
	if(isEmpty(stack))
		return(INT_MIN);

	return(stack->array[++stack->top2]);
}

int main()
{
	struct Node *stack = createStack(4);

	push1(stack,10);
	push2(stack,5);
	push1(stack,11);

	printf("%d\n",pop1(stack));
	printf("%d\n",pop2(stack));
	printf("%d\n",pop1(stack));

}

