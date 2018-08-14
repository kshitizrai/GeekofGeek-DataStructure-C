#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

void printList(struct Node *head_ref)
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

void insertFront(int data , struct Node **head_ref)
{
	struct Node *NewNode = (struct Node*)(malloc(sizeof(struct Node)));

	NewNode->data = data;
	NewNode->next = *head_ref;

	*head_ref = NewNode; 
}

struct Node* searchElement(struct Node *head_ref , int key)
{
	if(head_ref == NULL)
		return(NULL);

	while(head_ref != NULL)
	{
		if(head_ref->data == key)
			return(head_ref);
		else
			head_ref=head_ref->next;
	}

	if(head_ref == NULL)
		return(NULL);
}

void insertBefore(int data , struct Node **head_ref , int key)
{
	if(*head_ref == NULL)
		{
			printf("EMPTY\n");
			return;
		}

	struct Node *catch = searchElement(*head_ref , key);

	if(catch == NULL)
	{
		printf("Yeah!! %d number is not in the llst \n",key);
		return;
	}

	struct Node *NewNode = (struct Node*)(malloc(sizeof(struct Node)));
	NewNode->data = data;
	NewNode->next = catch->next;
	catch->next = NewNode;
	return;
}

void insertLast(int data , struct Node **head_ref)
{
	struct Node *NewNode = (struct Node*)(malloc(sizeof(struct Node)));
	
	NewNode->data = data;
	NewNode->next = NULL;

	if(*head_ref == NULL)
	{
		*head_ref = NewNode;
		return;
	}

	struct Node *dummy = *head_ref;

	while((dummy)->next != NULL)
	{
		dummy = (dummy)->next;
	}

	(dummy)->next = NewNode;
}

void deleteNode(struct Node **head_ref , int key)
{
	if(*head_ref == NULL)
		{
			printf("EMPTY\n");
			return;
		}

	struct Node *dummy = *head_ref;

	if((*head_ref)->data == key)
	{
		*head_ref = (*head_ref)->next;
		free(dummy);
		return;
	}

	struct Node *prev = *head_ref;
	while(dummy->data != key)
	{
		prev = dummy;
		dummy = dummy->next;
	}

	if(dummy == NULL)
		return;

	prev->next = dummy->next;
	free(dummy);
}

void deleteKey(struct Node **head_ref , int pos)
{
	struct Node *temp = (struct Node*)(malloc(sizeof(struct Node)));

	int i=0;

	if(*head_ref == NULL)
		return;

	if(pos == 1)
	{
		*head_ref = (*head_ref)->next;
		free(temp);
		return;
	}

	for(i=0 ; temp!=NULL && i<pos-1 ; i++)
	{
		temp = temp->next;
	}

	if(temp==NULL)
		return;

	temp->next = temp->next->next ;
}

int getLengthrecursion(struct Node *head_ref)
{
	if(head_ref == NULL)
		return(0);

	return(1+getLengthrecursion(head_ref->next));
}

int getLengthiterative(struct Node *head_ref)
{
	int count = 0;

	while(head_ref != NULL)
	{
		head_ref = head_ref->next;
		count++;
	}

	return(count);
}

void swaplist(struct Node **head_ref , int x , int y)
{
	if(x==y)
		return;

	if(*head_ref == NULL)
		return;

	struct Node *prevx = NULL ;
	struct Node *currx = *head_ref;

	while(currx != NULL && currx->data != x)
	{
		prevx = currx;
		currx = currx->next;
	}

	struct Node *prevy = NULL;
	struct Node *curry 	= *head_ref;
	
	while(curry != NULL && curry->data != y)
	{
		prevy = curry ;
		curry = curry->next;
	}

	if(currx == NULL || curry == NULL)
		return;

	int data = currx->data;
	currx->data = curry->data;
	curry->data = data;

}

void reverse(struct Node **head_ref)
{
	if(*head_ref == NULL)
		return;

	struct Node *curr = *head_ref;
	struct Node *prev = NULL;
	struct Node *next = NULL;

	while(curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*head_ref = prev;
	return;
}

int main()
{
	struct Node *head = (struct Node*)(malloc(sizeof(struct Node)));

	head = NULL;

	puts("Menu : ");
	puts("   1. For printing list");
	puts("   2. For adding an element at front");
	puts("   3. For adding an element at last");
	puts("   4. For adding element after an element");
	puts("   5. For deleting an element");
	puts("   6. For deleting from a particylar position");
	puts("   7. Get length recursively");
	puts("   8. Get length iteratively");
	puts("   9. Swapping elements");
	puts("   10. Reverse List");
	puts("   11. EXIT");

	do
	{	
		int ch;
		int data,key,length;

		printf("Enter your choice : ");
		scanf(" %d",&ch);

		switch (ch)
		{
			case 1	: 	printList(head);
						break;

			case 2	: 	printf("Enter the data : ");
						scanf(" %d",&data);
						insertFront(data,&head);
						break;

			case 3	:	printf("Enter the data : ");
						scanf(" %d",&data);
						insertLast(data,&head);
						break;

			case 4	: 	printf("Enter the element after which you which to add : ");
						scanf("%d" , &key);
						printf("Enter the data : ");
						scanf("%d",&data);
						insertBefore(data , &head , key);
						break;

			case 5	:	printf("Enter the element to be deleted : ");
						scanf(" %d",&data);
						deleteNode(&head , data);
						break;

			case 6	:	printf("Enter position from which you want to delete :");
						scanf("%d",&key);
						deleteKey(&head , key);
						break;

			case 7	:	length = getLengthrecursion(head);
						printf("Length iteratively = %d\n",length);
						break;

			case 8 	:	length = getLengthiterative(head);
						printf("Length recursively = %d\n",length);
						break;

			case 9  :	printf("Enter the elements to be swapped : ");
						int first;
						int second;
						scanf("%d",&first);
						scanf("%d",&second);
						swaplist(&head,first,second);
						break;

			case 10	:	reverse(&head);
						printf("Reversed\n");
						break;

			case 11	: 	printf("Thank You !!\n");
						exit(0);
						break;

			default	: 	printf("TRY AGAIN\n");
						break;

		}
		printf("\n");

	}while(1);

}