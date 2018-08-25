#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

void isEmpty(struct Node **last , int data)
{
	struct Node *newNode=(struct Node*)(malloc(sizeof(struct Node)));
	newNode->data = data;

	*last = newNode;
	newNode->next = *last; 
	return;
}

void printList(struct Node *last)
{
	struct Node *last_ref = last;

	if(last != NULL)
		last = last->next;
	
	while(last!=last_ref)
	{
		printf("%d\n",last->data);
		last=last->next;
	}
}

void sortedInsert(struct Node **last , int data)
{
	struct Node *newNode=(struct Node*)(malloc(sizeof(struct Node)));
	newNode->data = data;

	struct Node *current = *last;

	if(*last == NULL)
	{
//		printf("EMPTY \n");
		isEmpty(last,data);
	}

	else if(current->data >= newNode->data)
	{
//		printf("Before Head\n");
		while(current->next != *last)
			current = current->next;

		current->next = newNode;
		newNode->next = *last;
		*last = newNode;
	}
	else
	{
//		printf("Somewhere After Head\n");
		while(current->next != *last && current->next->data >= newNode->data)
		{
			current->next = current;	
		}
		newNode->next = current->next;
		current->next = newNode;
	}
//	printList(*last);
}

int main()
{
	struct Node *last = NULL;
	int i=0;
	int arr[]={12,56,2,11,1,90};

	for(i=0 ; i<6 ;i++)
	{
		sortedInsert(&last,arr[i]);
	}

	printList(last);
}