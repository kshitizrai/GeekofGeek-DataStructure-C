#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Node
{
	int data;
	struct Node *next;
};

void printList(struct Node *head_ref)
{
	if(head_ref == NULL)
	{
		printf("EMPTY!!\n");
		return;
	}
	while(head_ref != NULL)
	{
		printf("%d ",head_ref->data);
		head_ref = head_ref->next;
	}
	printf("\n");
	return;
}

void push(struct Node **head_ref , int data)
{
	struct Node *newNode = (struct Node*)(malloc(sizeof(struct Node)));
	newNode->data = data;

	if(*head_ref == NULL)
	{
		*head_ref = newNode;
		return;
	}

	newNode->next = *head_ref;
	*head_ref = newNode;
}

struct Node* reverse(struct Node *head , int k)
{
	struct Node *current = head;
	struct Node *prev = NULL;
	struct Node *next = NULL;
	int count = 0;

	while(current != NULL && k>count)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}

	if(next != NULL)
		head->next = reverse(next , k);

	return(prev);
}

int main()
{
	struct Node *head = (struct Node*)(malloc(sizeof(struct Node)));
	
	head = NULL;

	push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,4);
	push(&head,5);
	push(&head,6);
	push(&head,7);
	push(&head,8);
	push(&head,9);
//	push(&head,10);

	printList(head);
	
	printf("\n");
	head = reverse(head,3);

	printList(head);
}