#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<sys/timeb.h>

#define MAX 10000

long getCurrenTime()
{
	struct timeb tb;
	ftime(&tb);
	return (tb.time * 1000 + tb.millitm);
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

void bubbleArr(int arr[], int length)
{
	int flag = 0;
	for (int i = 0; i < length-1 && flag == 0; i++)
	{
		flag = 1;
		for (int j = 0; j < length-1-i; j++)
		{
			if (arr[j] > arr[j+1])
			{
				flag = 0;
				swap(&arr[j], &arr[j + 1]);
			}
		
		}
	}
}

void test()
{
	srand(time(NULL));
	int arr[MAX];
	for (int i = 0; i < MAX; i++)
	{
		arr[i] = rand() % 10;
	}
	printArr(arr, MAX);
	long start_t = getCurrenTime();
	bubbleArr(arr, MAX);
	long end_t = getCurrenTime();
	printf("%排序时间用了ld\n", end_t - start_t);
	printArr(arr, MAX);
}

int main()
{
	test();

	return 0;
}