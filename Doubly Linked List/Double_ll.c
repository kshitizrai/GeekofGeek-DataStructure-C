#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Node
{
	int data;
	struct Node *next;
	struct Node *prev;
};

void printList(struct Node *head_ref)
{
	if(head_ref == NULL)
		printf("EMPTY\n");

	while(head_ref != NULL)
	{
		printf("%d " , head_ref->data);
		head_ref = head_ref->next;
	}
	printf("\n");
}

void addFront(struct Node **head_ref , int data)
{
	struct Node *newNode=(struct Node*)(malloc(sizeof(struct Node)));
	newNode->data = data;
	newNode->prev = NULL;

	if((*head_ref) == NULL)
	{
		newNode->next = NULL;
		*head_ref = newNode;
		return;
	}

	newNode->next = *head_ref;
	(*head_ref)->prev = newNode;

	*head_ref = newNode;
	return;
}

void append(struct Node **head_ref , int data)
{
	struct Node *newNode=(struct Node*)(malloc(sizeof(struct Node)));
	newNode->data = data;
	newNode->next = NULL;

	if(*head_ref == NULL)
	{
		newNode->prev = NULL;
		*head_ref = newNode;
		return;
	}

	struct Node *head = *head_ref;
	while(head->next != NULL)
		head = head->next;
	head->next = newNode;
	newNode->prev = head;
	return;
}

struct Node* find(struct Node *head_ref,int key)
{
	while(head_ref != NULL)
	{
		if(head_ref->data == key)
			break;
		else
			head_ref = head_ref->next;
	}
	return(head_ref);
}

void addAfter(struct Node **head , int data , int key)
{
	struct Node *after = find(*head , key);

	if(after == NULL)
	{
		printf("Sorry! %d doesn't exist \n",key);
		return;
	}

	struct Node *newNode=(struct Node*)(malloc(sizeof(struct Node)));
	newNode->data = data;
 	newNode->next = after->next;

 	if(after->next != NULL)
 		after->next->prev = newNode;

 	after->next = newNode;
 	newNode->prev = after;

 	return;
}

void addBefore(struct Node **head_ref , int data , int key)
{
	struct Node *answer = find(*head_ref , key);

	if(answer == NULL)
	{
		printf("Sorry!! The Key you enetered doesn't exist \n");
		return;
	}

	struct Node *newNode=(struct Node*)(malloc(sizeof(struct Node)));
	newNode->data = data;

	if(answer->prev != NULL)
		answer->prev->next = newNode;

	newNode->prev = answer->prev;
	answer->prev = newNode;
	newNode->next = answer;
	return;
}

void deleteNode(struct Node **head , int key)
{
	struct Node *answer = find(*head,key);

	if(answer == NULL)
	{
		printf("Sorry!! %d doesn't exist \n",key);
		return;
	}

	if(answer->next != NULL)
		answer->next->prev = answer->prev;
	
	if(answer->prev != NULL)
		answer->prev->next = answer->next;
	else
		*head = (*head)->next;

	free(answer);
	return;
}

void reverse(struct Node **head_ref)
{
	if(*head_ref == NULL)
	{
		printf("EMPTY \n");
		return;
	}

	struct Node *swap = NULL;
	struct Node *head = *head_ref;
	struct Node *nexthead;
	while(nexthead != NULL)
	{
		nexthead = head;
		nexthead = nexthead->next;
		swap = head->prev;
		head->prev = head->next;
		head->next = swap;
		if(nexthead!=NULL)
			head = nexthead;
	}
	*head_ref = head;
}

void swap(int *a , int *b)
{
	int swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

struct Node* partition(struct Node *l , struct Node *h)
{
	int pivot = h->data;
	struct Node *i = l->prev;

	for(struct Node *j = l ; j!=h ; j=j->next)
	{
		if(j->data <= pivot)
		{
			i= (i==NULL) ? l : i->next;
			swap(&(i->data),&(j->data));
		}
	}

	i = (i==NULL) ? l : i->next;
	swap(&(i->data),&(h->data));
	return(i);
}

void _quicksort(struct Node *l , struct Node *h)
{
	if(h!=NULL && h!=l && h->next != l)
	{
		struct Node *p = partition(l,h);
		_quicksort(l,p->prev);
		_quicksort(p->next,h);
	}
}

void quickSort (struct Node *l)
{
	struct Node *h = l;

	while(h->next!=NULL)
		h=h->next;

	_quicksort(l,h);
}

int main()
{
	int ch;
	int data , key;
	struct Node *head = NULL;
	printf("MENU : \n");
	printf("    1. Add Element at front\n");
	printf("    2. Add Element at last\n");
	printf("    3. Add Element after an element\n");
	printf("    4. Add Element before an element\n");
	printf("    5. Delete Node with a given data\n");
	printf("    6. Reverse the list \n");
	printf("    7. Quick Sort the list\n");
	printf("    8. Merge Sort the list\n");
	printf("    9. Print List \n");
	printf("    10. EXIT\n");
	printf("\n");

	printf("Enter your choice : ");
	scanf("%d",&ch);

	switch (ch)
	{
		case 1		:	printf("Enter the element to be added : ");
						scanf("%d\n",&data);	
						addFront(&head,data);
						printList(head);
						break;
		case 2		:	printf("Enter the element to be added : ");
						scanf("%d\n",&data);	
						append(&head,data);
						printList(head);
						break;
		case 3		:	printf("Enter the element to be added : ");
						scanf("%d\n",&data);	
						printf("Enter the element after which you which to be added : ");
						scanf("%d\n",&key);
						addAfter(&head,data,key);
						printList(head);
						break;
		case 4		:	printf("Enter the element to be added : ");
						scanf("%d\n",&data);	
						printf("Enter the element before which you which to be added : ");
						scanf("%d\n",&key);
						addBefore(&head,data,key);
						printList(head);
						break; 
		case 5		:	printf("Enter the element the you want to delete : ");
						scanf("%d\n",&data);
						deleteNode(&head,data);
						printList(head);
						break;
		case 6		:	reverse(&head);
						printf("Reversed List : ");
						printList(head);
						break;
		case 7		:	quickSort(head);
						printf("Sorted List :");
						printList(head);
						break;
		case 8		:	break;
		case 9		:	printList(head);
						break;
		case 10		:	exit(0);
						break;
		default		:	printf("TRY AGAIN !!!\n");
						break;
	}
}