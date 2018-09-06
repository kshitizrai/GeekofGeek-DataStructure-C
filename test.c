#include <stdio.h>
#include <stdlib.h>

void fun1(int *array)
{
	int length = sizeof(array)/sizeof(array[0]);
	printf("%d \n" , length);
}

int main()
{
	int array[] = {1,2,3,4};

	int length = sizeof(array)/sizeof(array[0]);

	printf("%d \n",length);

	fun1(array);
}