#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include <math.h>

struct Node 
{
	int top;
	int capacity;
	int *array;
};

struct Node* createStack(int capacity)
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
	return(stack->top == stack->capacity-1);
}

void push(struct Node *stack , int data)
{
	if(isFull(stack))
		return;

	stack->array[++stack->top] = data;
	return;
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
		return(0);

	return(stack->array[stack->top]);
}

bool isDigit(char x)
{
	return(x>='0' && x<='9');
}

int evaluate(char *exp)
{
	int x=strlen(exp);
	int num = 0 , operand1 , operand2;
	char operator;
	
	int i=0;

	struct Node *stack = createStack(x);

	for(i=0 ; i<x ; i++)
	{
		num = 0;
		
		if(exp[i] == ' ')
			continue;

		if(isDigit(exp[i]))
		{
			while(isDigit(exp[i]))
			{
				num = num*10 + (exp[i++] - '0');
			}
			i--;
			push(stack,num);
		}

		if(!isDigit(exp[i]))
		{
			operator = exp[i];
			operand1 = pop(stack);
			operand2 = pop(stack);
			switch(operator)
			{
				case '+'	: 	push(stack,operand1+operand2);
								break;
				case '-'	:	push(stack,operand2 - operand1);
								break;
				case '*'	:	push(stack,operand1 * operand2);
								break;
				case '/'	:	push(stack,operand2/operand1);
								break;
			}
		}
	}
	return(pop(stack));
}

int main()
{
	char exp[] = "100 200 + 2 / 5 * 7 +";
	int ans = evaluate(exp);
	printf("%d\n",ans);
}