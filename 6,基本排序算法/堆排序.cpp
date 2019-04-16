#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<time.h>
#include<sys/timeb.h>
#include<string.h>
#include<stdlib.h>

#define MAX 10

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int *createArray(int capacity)
{
	return (int *)malloc(sizeof(int)*capacity);
}

void freeArray(int *arr)
{
	free(arr);
}

void printArr(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
	putchar('\n');
}

void heapAdjust(int arr[], int index, int len)
{
	int max = index;
	int lchild = 2 * index + 1;
	int rchild = 2 * index + 2;
	
	if (lchild < len && arr[lchild] < arr[max])
		max = lchild;
	if (rchild < len && arr[rchild] < arr[max])
		max = rchild;
	if (max != index)
		swap(&arr[max],&arr[index]);
}

void heapSort(int arr[], int len)
{
	while (len>1)
	{
		for (int i = (len / 2 - 1); i >= 0; i--)
		{
			heapAdjust(arr, i, len);
		}
		swap(&arr[0], &arr[--len]);
	}
}

int main()
{
	srand(time(NULL));
	int *arr = (int *)malloc(sizeof(int)*MAX);
	for (int i = 0; i < MAX; i++)
	{
		arr[i] = rand() % MAX;
	}
	printArr(arr, MAX);
	heapSort(arr, MAX);
	printArr(arr, MAX);

	free(arr);
	return 0;
}