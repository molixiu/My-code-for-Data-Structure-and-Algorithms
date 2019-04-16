#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<time.h>
#include<sys/timeb.h>
#include<string.h>
#include<stdlib.h>

#define MAX 20

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

void insertSort(int arr[], int length)
{
	int temp;
	int j;
	for (int i = 1; i < length; i++)
	{
		temp = arr[i];
		for (j = i-1; j >=0 && temp < arr[j]; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j+1] = temp;
	}

}

int main()
{
	srand((unsigned int)time(NULL));
	int arr[MAX];
	for (int i = 0; i < MAX; i++)
	{
		arr[i] = rand() % 10;
	}
	printArr(arr, MAX);
	insertSort(arr, MAX);
	printArr(arr, MAX);

	return 0;
}
