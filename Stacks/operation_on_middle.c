#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>

struct DLLNode
{
	struct DLLNode *next , *prev;
	int data;
};

struct Stack
{
	struct DLLNode *mid , *head;
	int count;
};

struct Stack* createStack()
{
	struct Stack *mystack = (struct Stack*)(malloc(sizeof(struct Stack)));
	mystack->mid = NULL;
	mystack->head = NULL;
	mystack->count = 0;
}

void push(struct Stack *mystack , int data)
{
	struct DLLNode *newNode = (struct DLLNode*)(malloc(sizeof(struct DLLNode)));

	newNode->data = data;
	newNode->prev = NULL;
	newNode->next = mystack->head;

	mystack->count += 1;

	if(mystack->count == 1)
		mystack->mid = newNode;
	else 
	{	
		mystack->head->prev = newNode;
		if(mystack->count %2 != 0)
			mystack->mid = mystack->mid->prev;
	}
	mystack->head = newNode;
}

int findMiddle(struct Stack *mystack)
{
	if(mystack->count == 0)
		return(INT_MIN);
	return(mystack->mid->data);
}

int pop(struct Stack *mystack)
{
	if(mystack->count == 0)
		return(INT_MIN);

	int item = mystack->head->data;
	struct DLLNode *head = mystack->head;

	mystack->head = head->next;
	mystack->count -= 1;

	if(mystack->head != NULL)
		head->next->prev = NULL;

	if(mystack->count%2 == 0)
		mystack->mid = mystack->mid->next;

	free(head);
	return(item);
}

void deleteMiddle(struct Stack *mystack)
{
	struct DLLNode *ref = mystack->mid;

	mystack->count = mystack->count - 1;

	if(ref->next != NULL)
		ref->next->prev = ref->prev;
	if(ref->prev != NULL)
		ref->prev->next = mystack->mid->next;

	if(mystack->count%2 == 0)
		mystack->mid = mystack->mid->next;
	if(mystack->count%2 != 0)
		mystack->mid = mystack->mid->prev;

	free(ref);
}

int main()
{
	struct Stack *mystack = (struct Stack*)(malloc(sizeof(struct Stack)));

	push(mystack,10);
	push(mystack,20);
	push(mystack,30);
	push(mystack,40);
	push(mystack,50);
	deleteMiddle(mystack);
	deleteMiddle(mystack);
	printf("%d \n",pop(mystack));
	printf("%d \n",pop(mystack));
	printf("%d \n",pop(mystack));
	printf("%d \n",pop(mystack));
}