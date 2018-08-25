#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

struct Node 
{
	int top;
	int capacity;
	char *array;
};

struct Node *createStack(int capacity)
{
	struct Node *stack = (struct Node*)(malloc(sizeof(struct Node)));
	stack->top = -1;
	stack->capacity = capacity;
	stack->array = (char*)(malloc(sizeof(char)*capacity));

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

void push(struct Node *stack , char x)
{

	if(isFull(stack))
		return;

	stack->array[++stack->top] = x;
	printf("Pushed %c\n",x);
}

char pop(struct Node *stack)
{
	if(isEmpty(stack))
		return(CHAR_MIN);

	return(stack->array[stack->top--]);
}

char peek(struct Node *stack)
{
	if(isEmpty(stack))
		return(CHAR_MIN);

	return(stack->array[stack->top]);
}

bool ifOperand(char x)
{
	return(x>='a' && x<='z') || (x>='A' && x<='Z');
}

int prec(char x)
{
	switch(x)
	{
		case '+'	:
		case '-'	:	return(1);
						break;
		case '*'	:
		case '/'	:	return(2);
						break;
		case '^'	:	return(3);
						break;
	}
	return(-1);
}

void infixtopostfix(char *exp)
{
	struct Node *stack = createStack(strlen(exp));

	if(!stack)
		{
			printf("Stack Not Created \n");
			return;
		}

	
	int k = -1 , i;
	int x = strlen(exp);
	for(i = 0 ; i<x ; i++)
	{

		if(ifOperand(exp[i]))
		{
			exp[++k] = exp[i];
		}

		if(exp[i] == '(')
			push(stack , exp[i]);

		else if(exp[i] == ')')
		{
			while(!isEmpty(stack) && peek(stack) != '(')
				exp[++k] = pop(stack);

			if(!isEmpty(stack) && peek(stack) != '(')
				return;

			else
				pop(stack);
		}
		else if(!ifOperand(exp[i]) && exp[i]!='(' && exp[i]!=')')
		{
			while(!isEmpty(stack) && prec(exp[i]) <= prec(peek(stack)))
			{
				exp[++k] = pop(stack);
			}
			push(stack,exp[i]);
		}
	}
	while(!isEmpty(stack))
		exp[++k] = pop(stack);

	exp[++k] = '\0';
	printf("%s",exp);
	printf("\n");
}

int main()
{
	char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
	printf("%s\n",exp);
	infixtopostfix(exp);
	return 0;
}