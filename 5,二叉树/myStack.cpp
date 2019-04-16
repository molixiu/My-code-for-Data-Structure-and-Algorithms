#define _CRT_SECURE_NO_DEPRECATE
#include"myStack.h"
#include<stdlib.h>

//��ʼ��ջ
myStack *init_myStack()
{
	myStack *stack = (myStack *)malloc(sizeof(myStack));
	stack->head = NULL;
	stack->size = 0;
	return stack;
}
//�ж�ջ�Ƿ�Ϊ��,Ϊ�շ���1 ����0
int empty_myStack(myStack *stack)
{
	if (stack == NULL)
	{
		return -1;
	}
	return stack->size == 0 ? TRUE : FALSE;
}
//�Ƴ�ջ��Ԫ��
void pop_myStack(myStack *stack)
{
	if (stack != NULL && stack->head  != NULL)
	{
		stack->head = stack->head->next;
		stack->size--;
	}
}
//��ջ������Ԫ��
void push_myStack(myStack *stack, stackNode *node)
{
	if (stack != NULL)
	{
		node->next = stack->head;
		stack->head = node;
		stack->size++;
	}
}
//����ջ��Ԫ����Ŀ
int size_myStack(myStack *stack)
{
	if (stack != NULL)
	{
		return stack->size;
	}
}
//����ջ��Ԫ��
stackNode *top_myStack(myStack *stack)
{
	if (stack != NULL)
	{
		return stack->head;
	}
	return NULL;
}
//�ͷ�ջ
void free_myStack(myStack *stack)
{
	if (stack != NULL)
	{
		free(stack);
	}
}