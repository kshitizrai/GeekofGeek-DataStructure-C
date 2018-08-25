#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Node
{
	int data;
	struct Node *next;
};

void printList(struct Node *last)
{
	if(last == NULL)
	{
		printf("EMPTY BRO!!\n");
		return;
	}

	struct Node *last_ref = last;
	printf("%d\n",last_ref->data);
	last_ref = last_ref->next;
	while(last_ref != last)
	{
		
		printf("%d\n",last_ref->data);
		last_ref = last_ref->next;
	}
	printf("\n");
	return;
}

void isEmpty(struct Node **last , int data)
{
	struct Node *newNode = (struct Node*)(malloc(sizeof(struct Node)));
	newNode->data = data;
	*last = newNode;
	newNode->next = *last;
	return;
}

void addLast(struct Node **last , int data)
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
	*last = newNode;  
	return;
}

void split(struct Node *last , struct Node **head1 , struct Node **head2)
{
	struct Node *fast = last;
	struct Node *slow = last;

	while(fast->next != last && fast->next->next != last)
	{
		
		slow = slow->next;
		fast = fast->next->next;
	}
	slow=slow->next;
	slow->next = last->next;
	last->next = fast;

	*head1 = slow;
	*head2 = fast;

	printList(slow);
	printList(last);
}

int main()
{
	struct Node *last = NULL;

	addLast(&last , 2);
	addLast(&last , 3);
	addLast(&last , 4);
	addLast(&last , 5);
	addLast(&last , 6);

	printList(last);
	struct Node *head1;
	struct Node *head2;
	split(last , &head1 , &head2);
}
