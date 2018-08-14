#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node *next;
};

void push(struct Node **head_ref , int data)
{
	struct Node *newNode = (struct Node*)(malloc(sizeof(struct Node)));
	newNode->data = data; 

	if(*head_ref != NULL) 
		{
			*head_ref = newNode;
			return;
		}

	newNode->next = *head_ref; 
	*head_ref = newNode;
	return;
}

void printList(struct Node *head_ref)
{
	if(head_ref == NULL)
		return;

	while(head_ref != NULL)
	{
		printf("%d\n",head_ref->data);
		head_ref = head_ref->next;
	}
	return;
}

bool detectLoop(struct Node *h)
{
	unordered_set<Node *> s;
	while(h != NULL)
	{
		if(s.find(h) == s.end())
			return true;

		s.insert(h);

		h = h->next;
	}

	return false;
}

int main()
{
	struct Node *head = (struct Node*)(malloc(sizeof(struct Node)));
	head = NULL;

	push(&head ,20);
		printList(head);
	push(&head ,4);
		printList(head);
	push(&head ,15);
		printList(head);
	push(&head ,10);
		printList(head);

	head->next->next->next->next = head;

	if(detectLoop(head))
		cout<<"Loop Detected \n";
	else
		cout<<"No Loop \n";

	return(0);
}