#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct QNode
{
	int data;
	struct QNode *next;
};

struct Queue
{
	struct QNode *rear , *front;
};

struct Queue *createQueue()
{
	struct Queue *queue = (struct Queue*)(malloc(sizeof(struct Queue)));

	queue->rear = NULL;
	queue->front = NULL;

	return(queue);
}

bool isEmpty(struct Queue *queue)
{
	return(queue->rear == NULL);
}

void enQueue(struct Queue *queue , int data)
{
	struct QNode *newNode = (struct QNode*)(malloc(sizeof(struct QNode)));

	newNode->data = data;
	newNode->next = NULL;

	if(queue->rear == NULL)
	{
		queue->front = newNode;
		queue->rear = newNode;
		printf("%d Added \n" , data);
		return;
	}	

	queue->rear->next = newNode;
	queue->rear = newNode;
	printf("%d Added \n" , data);
}

int deQueue(struct Queue *queue)
{
	if(isEmpty(queue))
		return(INT_MIN);

	struct QNode *front_ref = queue->front;
	

	int item = front_ref->data;

	queue->front = front_ref->next;
	
	if(queue->front == NULL)
		queue->rear = NULL;
	
	free(front_ref);

	return(item);

}

int main()
{
	struct Queue *queue = createQueue();

	enQueue(queue,10);
	enQueue(queue,20);
	printf("%d \n" , deQueue(queue));
	enQueue(queue,30);
	printf("%d \n" , deQueue(queue));
	printf("%d \n" , deQueue(queue));
	printf("%d \n" , deQueue(queue));
}