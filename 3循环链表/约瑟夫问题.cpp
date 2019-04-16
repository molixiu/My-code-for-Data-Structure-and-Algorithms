#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include"CircleList.h"

#define LENGTH 8 
#define BOUND 3

typedef struct Mynum
{
	CircleNode *next;
	int num;
} Mynum;

void print_Mynum(CircleNode *node)
{
	Mynum *num = (Mynum *)node;
	printf("%d\n", num->num);
}


int main()
{
   CircleList *list = init_CircleList();

	int count = LENGTH;
	Mynum num[8];
	for (int i = 0; i < LENGTH; i++)
	{
		num[i].num = i;
		insertEle_CircleList(list, i, (CircleNode *)&num[i]);
	}
	print_CircleList(list, print_Mynum);
	putchar('\n');

	//辅助指针
	CircleNode *pCurrenPre = (CircleNode *)list;
	while (count >1)
	{
		for (int i = 0; i < (BOUND-1); i++)
		{
			pCurrenPre = pCurrenPre->next;
			if (pCurrenPre->next == (CircleNode *)list)
			{
				pCurrenPre = pCurrenPre->next;
			}
		}
		printf("我挂了: ");
		print_Mynum(pCurrenPre->next);

		pCurrenPre->next = pCurrenPre->next->next;
		printf("剩下的队员:\n");
		print_CircleList(list, print_Mynum);
		count--;
	}

	putchar('\n');
	print_CircleList(list, print_Mynum);

	return 0;
}