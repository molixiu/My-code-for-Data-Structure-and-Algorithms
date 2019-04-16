#define _CRT_SECURE_NO_DEPRECATE
#include"myStack.h"
#include<stdlib.h>

//初始化栈
myStack *init_myStack()
{
	myStack *stack = (myStack *)malloc(sizeof(myStack));
	stack->head = NULL;
	stack->size = 0;
	return stack;
}
//判断栈是否为空,为空返回1 否则0
int empty_myStack(myStack *stack)
{
	if (stack == NULL)
	{
		return -1;
	}
	return stack->size == 0 ? TRUE : FALSE;
}
//移除栈顶元素
void pop_myStack(myStack *stack)
{
	if (stack != NULL && stack->head  != NULL)
	{
		stack->head = stack->head->next;
		stack->size--;
	}
}
//在栈顶增加元素
void push_myStack(myStack *stack, stackNode *node)
{
	if (stack != NULL)
	{
		node->next = stack->head;
		stack->head = node;
		stack->size++;
	}
}
//返回栈中元素数目
int size_myStack(myStack *stack)
{
	if (stack != NULL)
	{
		return stack->size;
	}
}
//返回栈顶元素
stackNode *top_myStack(myStack *stack)
{
	if (stack != NULL)
	{
		return stack->head;
	}
	return NULL;
}
//释放栈
void free_myStack(myStack *stack)
{
	if (stack != NULL)
	{
		free(stack);
	}
}