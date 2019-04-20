/*选择排序是不稳定的*/
#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<time.h>
#include<sys/timeb.h>
#include<string.h>
#include<stdlib.h>

#define MAX 1000

long getCurrenTime()
{
	struct timeb tb;
	ftime(&tb);
	return tb.time + tb.millitm;
}

void printArr(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
	putchar('\n');
}

void swap(int *a1, int *a2)
{
	int temp = *a1;
	*a1 = *a2;
	*a2 = temp;
}

void selectSort(int arr[], int length)
{
	int min = 0;
	for (int i = 0; i < length - 1; i++)
	{
		min = i;
		for (int j = i+1; j < length; j++)
		{
			if (arr[min] > arr[j])
			{
				min = j;
			}
		}
		if (min != i)
		{
			swap(&arr[i], &arr[min]);
		}
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	int arr[MAX];
	for (int i = 0; i < MAX; i++)
	{
		arr[i] = rand() % MAX;
	}

	printArr(arr, MAX);
	long start_t = getCurrenTime();
	selectSort(arr, MAX);
	long end_t = getCurrenTime();
	printf("%ÅÅÐòÊ±¼äÓÃÁËld\n", end_t - start_t);
	printArr(arr, MAX);
	return 0;
}
