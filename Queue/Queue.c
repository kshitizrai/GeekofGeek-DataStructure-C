#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

struct Queue
{
	int front , rear , size;
	unsigned capacity;
	int *array;
};

struct Queue* createQueue(unsigned capacity)
{
	struct Queue *queue = (struct Queue*)(malloc(sizeof(struct Queue)));

	queue->front = 0;
	queue->rear = capacity-1;
	queue->size = 0;
	queue->capacity = capacity;
	queue->array = (int*)(malloc(sizeof(int)*capacity));

	return(queue);
}

bool isFull(struct Queue *queue)
{
	return(queue->size == queue->capacity - 1);
}

bool isEmpty(struct Queue *queue)
{
	return(queue->size == 0);
}

void enQueue(struct Queue *queue , int data)
{
	if(isFull(queue))
		return;

	queue->rear = (queue->rear+1)%queue->capacity;
	queue->array[queue->rear] = data;
	queue->size = queue->size+1;

	printf("Element Added %d \n",data);
}

int deQueue(struct Queue *queue)
{
	if(isEmpty(queue))
		return(INT_MIN);

	int item = queue->array[queue->front];

	queue->front=(queue->front+1)%queue->capacity;
	queue->size = queue->size-1;

	return(item);
}

int main()
{
	struct Queue *queue = createQueue(100);

	enQueue(queue,10);
	enQueue(queue,20);
	enQueue(queue,30);
	enQueue(queue,40);
	enQueue(queue,50);
	enQueue(queue,60);

	printf("%d \n" , deQueue(queue));
	printf("%d \n" , deQueue(queue));
	printf("%d \n" , deQueue(queue));
	printf("%d \n" , deQueue(queue));
}