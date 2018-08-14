#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Node
{
	int data;
	struct Node *next;
};

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

void printList(struct Node *head_ref)
{
	if(head_ref == NULL)
	{
		printf("EMPTY!!\n");
		return;
	}
	while(head_ref != NULL)
	{
		printf("%d\n",head_ref->data);
		head_ref = head_ref->next;
	}
	return;
}

void splitList(struct Node *source , struct Node **a , struct Node **b)
{
	struct Node *slow = source;
	struct Node *fast = source->next;

	while(fast != NULL)
	{
		fast = fast->next;
		if(fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}

	*a = source;
	*b = slow->next;
	slow->next = NULL;
	return;
}

struct Node* mergeSort(struct Node *a , struct Node *b)
{
	struct Node *result = NULL;
	if(a == NULL)
		return(b);
	if(b == NULL)
		return(a);

	if(a->data <= b->data)
	{
		result = a;
		result->next = mergeSort(a->next,b);
	}
	else
	{
		result = b;
		result->next = mergeSort(b->next , a);
	}

	return(result);
}

void Sorting(struct Node **head_ref)
{
	struct Node *a = NULL;
	struct Node *b = NULL;

	if(*head_ref == NULL || (*head_ref)->next == NULL)
		return;

	splitList(*head_ref , &a , &b);

	Sorting(&a);
	Sorting(&b);

	*head_ref = mergeSort(a , b);
}

int main()
{
	struct Node *head = (struct Node*)(malloc(sizeof(struct Node)));
	head = NULL;

	push(&head,1);
	push(&head,2);
	push(&head,3);

	printList(head);
	Sorting(&head);
	printList(head);
}	
