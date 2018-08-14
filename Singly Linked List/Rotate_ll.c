#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

void push(struct Node **head_ref , int data)
{
	struct Node *newNode = (struct Node*)(malloc(sizeof(struct Node)));
	newNode->data = data;
	newNode->next = NULL;

	if(*head_ref == NULL)
	{
		*head_ref = newNode;
		return;
	}

	newNode->next = *head_ref;
	*head_ref = newNode;
}

void printList(struct Node *head)
{
	while(head!=NULL)
	{
		printf("%d\n",head->data);
		head = head->next;
	}
	return;
}

void rotate(struct Node **head_ref , int k)
{
	struct Node *newHead = *head_ref;
	struct Node *prev = *head_ref;

	while(newHead != NULL && k>0)
	{
		prev = newHead;
		newHead = newHead->next;
		k--;
	}

	if(newHead == NULL)
	{
		return;
	}	

	struct Node *last = newHead;

	while(last->next != NULL)
		last = last->next;

	last->next = *head_ref;
	prev->next = NULL;
	*head_ref = newHead;
	return;
}

int main()
{
	struct Node *head = NULL;

	push(&head,60);
	push(&head,50);
	push(&head,40);
	push(&head,30);
	push(&head,20);
	push(&head,10);

	printList(head);
	printf("\n");
	rotate(&head,5);

	printList(head);
}