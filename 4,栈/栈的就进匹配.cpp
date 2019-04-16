#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include"myStack.h"

struct myChar
{
	stackNode *next;
	char *ch;
	int index;
};

int isLeft(const char *p)
{
	return *p == '(';
}

int isRight(const char *p)
{
	return *p == ')';
}

stackNode *createStackNode_forMyChar( char *ch, const int index)
{
	myChar *mychar = (myChar *)malloc(sizeof(myChar));
	mychar->ch = ch;
	mychar->index = index;
	mychar->next = NULL;
	return (stackNode *)mychar;
}

void showError_right(const int index)
{
	printf("µÚ%dÓÒÀ¨ºÅ²»Æ¥Åä\n", index);
}

void showError_left(myStack *stack)
{
	while (!empty_myStack(stack))
	{
		myChar *mychar = (myChar *)top_myStack(stack);
		printf("µÚ%d×óÀ¨ºÅ²»Æ¥Åä\n", mychar->index);
		pop_myStack(stack);
	}
}

int main()
{
	char *ch = "()pp(((";

	myStack *stack = init_myStack();
	char *pCurren = ch;
	int index = 0;
	do
	{
		if (isLeft(pCurren))	//Óöµ½×óÀ¨ºÅ
		{
			push_myStack(stack, createStackNode_forMyChar(pCurren, index));
		}
		if (isRight(pCurren))	//Óöµ½ÓÒÀ¨ºÅ
		{
			if (empty_myStack(stack))	//Õ»Îª¿Õ
			{
				showError_right(index);
			}
			else
			{
				pop_myStack(stack);
			}
		}
		index++;
	} while ( *(++pCurren) != 0 );

	if (empty_myStack(stack))
	{
		printf("À¨ºÅÈ«²¿Æ¥Åä\n");
	}
	else
	{
		showError_left(stack);
	}

	return 0;
}