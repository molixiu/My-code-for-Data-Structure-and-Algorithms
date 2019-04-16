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

void shellSort(int arr[], int length)
{
	int increment = length;
	int temp;
	int k;

	do
	{
		increment = increment / 3 + 1;
		for (int i = 0; i < increment; i++)
		{
			for (int j = increment+i; j < length; j =j + increment)
			{
				temp = arr[j];
				for ( k = j-increment; k >= i && temp < arr[k]; k = k-increment)
				{
						arr[k + increment] = arr[k];
				}
				arr[k + increment] = temp;
			}
		}
	} while (increment > 1);

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
	shellSort(arr, MAX);
	printArr(arr, MAX);

	return 0;
}