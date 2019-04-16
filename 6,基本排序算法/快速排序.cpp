#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<time.h>
#include<sys/timeb.h>
#include<string.h>
#include<stdlib.h>

#define MAX 20

void printArr(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
	putchar('\n');
}

void quickSort(int arr[], int start, int end)
{
	if (start < end)
	{
		int temp = arr[start];
		int i = start;
		int j = end;
		while (i < j)
		{
			while ( (arr[j] > temp) && ( i< j) )
			{
				j--;
			}
			if (i < j)
			{
				arr[i] = arr[j];
				i++;
			}
			else
			{
				arr[i] = temp;
			}

			while ( (arr[i] < temp) && (i < j) )
			{
				i++;
			}
			if (i < j)
			{
				arr[j] = arr[i];
				j--;
			}
			else
			{
				arr[j] = temp;
			}
		}

		if ( (i-start) > 1 )
		{
			quickSort(arr, start, i - 1);
		}
		if ( (end-i) > 1 )
		{
			quickSort(arr, i + 1, end);
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
	int arr2[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	printArr(arr, MAX);
	quickSort(arr, 0, MAX - 1);
	printArr(arr, MAX);

	return 0;
}