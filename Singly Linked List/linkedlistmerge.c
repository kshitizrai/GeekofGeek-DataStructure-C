#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

void moveNode(struct Node **dest , struct Node *source)
{
	struct Node *newNode = (struct Node*)(malloc(sizeof(struct Node)));
	
	newNode->data = source->data;

	(*dest) = newNode;
}

struct Node* mergeSort(struct Node *a , struct Node *b)
{
	struct Node dummy;

	struct Node *tail = &dummy;

	if(a == NULL && b == NULL)
	{
		tail->next = NULL;
		return(dummy.next);
	}

	while(1)
	{
		if(a == NULL)
		{
			tail->next = b;
			break;
		}

		if(b == NULL)
		{
			tail->next = a;
			break;
		}

		printf("Comparing %d , %d \n",a->data,b->data);

		if(a->data < b->data)
		{
			printf("Adding %d \n\n",a->data);
			moveNode(&(tail->next),a);
			a = a->next;
		}
		else
		{
			printf("Adding %d \n\n",b->data);
			moveNode(&(tail->next),b);
			b = b->next;
		}
		tail = tail->next;
	}
	return(dummy.next);
}

void printlist(struct Node *head_ref)
{
	if(head_ref == NULL)
		{
			printf("Hey!! list is empty\n");
			return;
		}
	while(head_ref != NULL)
	{
		printf("%d\n",head_ref->data);
		head_ref = head_ref->next;
	}
	return;
}


int main()
{
	struct Node *head1 = (struct Node*)(malloc(sizeof(struct Node)));
	head1 = NULL;

	struct Node *first1 = (struct Node*)(malloc(sizeof(struct Node)));
	first1->data = 5;
	first1->next = NULL;
	head1 = first1;

	struct Node *second1 = (struct Node*)(malloc(sizeof(struct Node)));
	second1->data = 10;
	second1->next = NULL;
	first1->next = second1;

	struct Node *third1 = (struct Node*)(malloc(sizeof(struct Node)));
	third1->data = 15;
	third1->next = NULL;
	second1->next = third1;


	struct Node *head2 = (struct Node*)(malloc(sizeof(struct Node)));
	head2 = NULL;

	struct Node *first2 = (struct Node*)(malloc(sizeof(struct Node)));
	first2->data = 1;
	first2->next = NULL;
	head2 = first2;

	struct Node *second2 = (struct Node*)(malloc(sizeof(struct Node)));
	second2->data = 6;
	second2->next = NULL;
	first2->next = second2;

//	printlist(head1);
//	printlist(head2);

	struct Node *merged = mergeSort(head2 , head1);
	printlist(merged);
}
