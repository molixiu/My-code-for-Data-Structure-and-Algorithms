#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"myStack.h"

typedef struct myChar
{
	myChar *next;
	char ch;
} myChar;

int isNumChar(char *ch)
{
 return *ch >= '0' && *ch <= '9';
}

int isLeft(const char *p)
{
	return *p == '(';
}

int isRight(const char *p)
{
	return *p == ')';
}

int isOperator(char *c)
{
	return *c == '+' || *c == '-' || *c == '*' || *c == '/';
}

void operate_Right(myStack *stack,char *suffix, int *index)
{
	myChar *mychar = (myChar *)top_myStack(stack);
	while (  mychar->ch != '(' )
	{
		myChar *temp = (myChar *)top_myStack(stack);
		suffix[(*index)++] = temp->ch;
		pop_myStack(stack);
		mychar = (myChar *)top_myStack(stack);
	}
	pop_myStack(stack);
}

void push_myChar_to_myStack(myStack *stack, char *pCurren)
{
	myChar *mychar = (myChar *)malloc(sizeof(myChar));
	mychar->ch = *pCurren;
	mychar->next = NULL;

	push_myStack(stack, (stackNode *)mychar);
}

int operator_transform_grade(char *c)
{
	if (*c == '(')
	{
		return 0;
	}
	if (*c == '+' || *c == '-')
	{
		return 1;
	}
	if (*c == '*' || *c == '/')
	{
		return 3;
	}
	return -1;
}

int compare_operator(char *c1, char *c2)	//比较两个运算符的等级
{
	int cc1 = operator_transform_grade(c1);
	int cc2 = operator_transform_grade(c2);
	return cc1 > cc2 ? TRUE : FALSE;
}

void operate_operator(myStack *stack, char *suffix, int *index, char *pCurren)
{
	myChar *mychar = (myChar *)top_myStack(stack);
	if (mychar != NULL)
	{
		while (mychar != NULL !compare_operator(pCurren, &mychar->ch))
		{
			myChar *temp = (myChar *)top_myStack(stack);
			suffix[(*index)++] = temp->ch;
			pop_myStack(stack);
			mychar = (myChar *)top_myStack(stack);
		}
	}
	push_myChar_to_myStack(stack, pCurren);
}


int main()
{
	char *source = "8 + (3 - 1) * 5";
	char *suffix = (char *)malloc(strlen(source) + 1);
	memset(suffix, 0, strlen(source) + 1);

	char *pCurren = source; //辅助指针
	int index = 0;
	myStack *stack = init_myStack();
	while (*pCurren != NULL)
	{
		if (isNumChar(pCurren)) //如果是数字
		{
			suffix[index++] = *pCurren;
		}
		if (isLeft(pCurren))	//如果是左括号
		{
			push_myChar_to_myStack(stack, pCurren);
		}
		if (isRight(pCurren))	//如果是右括号
		{
			operate_Right(stack, suffix, &index);
		}
		if (isOperator(pCurren))		//如果是运算符
		{
			operate_operator(stack, suffix, &index, pCurren);
		}

		pCurren++;
	}

	while (!empty_myStack(stack))
	{
		myChar *mychar = (myChar *)top_myStack(stack);
		suffix[index++] = mychar->ch;
		pop_myStack(stack);
	}

	printf("%s\n", suffix);
	
	return 0;
}