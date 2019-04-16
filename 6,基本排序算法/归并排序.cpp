#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<time.h>
#include<sys/timeb.h>
#include<string.h>
#include<stdlib.h>

#define MAX 10

int *createArray(int capacity)
{
	return (int *)malloc(sizeof(int)*capacity);
}

void printArr(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
	putchar('\n');
}

void merge(int arr[], int start, int mid, int end, int *temp)
{
	if (arr == NULL ||start == end || temp == NULL)
	{
		return;
	}

	int i_start = start;
	int i_end = mid;
	int j_start = mid + 1;
	int j_end = end;
	int length = 0;	//temp数组的长度

	while ( i_start <= i_end && j_start <= j_end )
	{
		if (arr[i_start] < arr[j_start])
			temp[length++] = arr[i_start++];
		else
			temp[length++] = arr[j_start++];
	}
	while (i_start <= i_end)
		temp[length++] = arr[i_start++];
	while (j_start <= j_end)
		temp[length++] = arr[j_start++];

	for (int i = 0; i < length; i++)
	{
		arr[start + i] = temp[i];
	}
}

void mergeSort(int arr[], int start, int end, int *temp)
{
	if (start == end)
	{
		return;
	}

	int mid = (start + end) / 2;
	mergeSort(arr, start, mid, temp);
	mergeSort(arr, mid + 1, end, temp);
	merge(arr, start, mid, end, temp);
}

int main()
{
	srand((unsigned int)time(NULL));
	int arr[MAX];
	for (int i = 0; i < MAX; i++)
	{
		arr[i] = rand() % MAX;
	}
	printArr(arr,MAX);
	int *temp = createArray(MAX);
	mergeSort(arr, 0, MAX - 1, temp);
	printArr(arr, MAX);

	return 0;
}