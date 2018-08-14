#include <stdio.h>
#include <stdlib.h>
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
	while(head != NULL)
	{
		printf("%d\n",head->data);
		head = head->next;
	}

	return;
}

int pop(struct Node **head_ref)
{
	int data;
	struct Node *temp = *head_ref;


	if(temp == NULL)
		return(INT_MIN);

	data = (temp)->data;
	*head_ref = (*head_ref)->next;

	free(temp);
	return(data);
}

struct Node* add(struct Node **head1_ref , struct Node **head2_ref)
{
	struct Node *add = NULL;
	int carry = 0;
	int digit1 , digit2 , sum;

	while(*head1_ref != NULL || *head2_ref != NULL)
	{
		if(*head1_ref == NULL)
		{
			printf("head1_ref == NULL \n");
			while(*head2_ref != NULL)
			{
				digit2 = pop(head2_ref);
				digit1 = carry;
				printf("Adding %d , %d \n",digit1,digit2);
				sum = digit2+digit1;
				carry = 0;
				while(sum>=10)
				{
					sum = sum-10;
					carry++;
				}
				printf("Pushed Value %d \n",sum);
				push(&add,sum);
			}
			break;
		}

		if(*head2_ref == NULL)
		{
			printf("head2_ref == NULL \n");
			while(*head1_ref != NULL)
			{
				digit1 = pop(head1_ref);
				digit2 = carry;
				printf("Adding %d , %d \n",digit1,digit2);
				sum = digit2+digit1;
				carry = 0;
				while(sum>=10)
				{
					sum = sum-10;
					carry++;
				}
				printf("Pushed Value %d \n",sum);
				push(&add,sum);
			}
			break;
		}
		
		digit1 = pop(head1_ref);
		digit2 = pop(head2_ref);

		printf("Adding %d , %d \n",digit1,digit2);

		int sum = digit1+digit2+carry;
		carry = 0;
	
		while(sum>=10)
		{
			sum = sum-10;
			carry++;
		}
		printf("Pushed Value %d aand carry = %d \n",sum,carry);
		push(&add , sum);
	}
	return(add);
}

int main()
{
	struct Node *head1 = NULL;
	struct Node *head2 = NULL;

	push(&head1,6);
	push(&head1,4);
	push(&head1,9);
	push(&head1,5);
	push(&head1,7);
	printList(head1);
	push(&head2,4);
	push(&head2,8);
	printList(head2);

//	printf("%d\n",pop(&head1));
	struct Node *answer = 0;
	answer = add(&head2,&head1);
	printList(answer);
}