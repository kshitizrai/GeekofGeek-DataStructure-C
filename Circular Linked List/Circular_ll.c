#include <stdio.h>
#include <stdlib.h>

struct Node 
{
	int data;
	struct Node *next;
};

void isEmpty(struct Node **last, int data)
{
	struct Node *newNode = (struct Node*)(malloc(sizeof(struct Node)));
	newNode->data = data;
	*last = newNode;
	newNode->next = *last;
}

void addBegin(struct Node **last , int data)
{
	if(*last == NULL)
	{
		isEmpty(last , data);
		return;
	}

	struct Node *newNode = (struct Node*)(malloc(sizeof(struct Node))); 
	newNode->data = data;
	newNode->next = (*last)->next;

	(*last)->next = newNode;
	return;
}

void addLast(struct Node **last , int data)
{
	if(*last == NULL)
	{
		isEmpty(last,data);
		return;
	}

	struct Node *newNode = (struct Node*)(malloc(sizeof(struct Node)));
	newNode->data = data;

	newNode->next = (*last)->next;
	(*last)->next = newNode;
	*last = newNode;

	return;
}

void printList(struct Node *last)
{
	if(last == NULL)
		return;

	struct Node *last_ref = last;
	printf("%d\n",last->data);
	
	last = last->next;
	while(last != last_ref)
	{
		printf("%d\n",last->data);
		last = last->next;
	}

	return;
}

int main()
{
	struct Node *last = NULL;

	addLast(&last,1);
	addLast(&last,2);
	addLast(&last,3);
//s	addBegin(&last,4);
	printList(last);
}


