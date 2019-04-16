#ifndef MYSTACK_H
#define MYSTACK_H

#define FALSE 0
#define TRUE 1

typedef struct stackNode
{
	stackNode * next;
} stackNode;

typedef struct myStack
{
	stackNode *head;
	int size;
} myStack;

//��ʼ��ջ
myStack *init_myStack();
//�ж�ջ�Ƿ�Ϊ��,Ϊ�շ���1 ����0
int empty_myStack(myStack *stack);
//�Ƴ�ջ��Ԫ��
void pop_myStack(myStack *stack);
//��ջ������Ԫ��
void push_myStack(myStack *stack, stackNode *node);
//����ջ��Ԫ����Ŀ
int size_myStack(myStack *stack);
//����ջ��Ԫ��
stackNode *top_myStack(myStack *stack);
//�ͷ�ջ
void free_myStack(myStack *stack);
#endif