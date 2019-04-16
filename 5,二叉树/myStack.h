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

//初始化栈
myStack *init_myStack();
//判断栈是否为空,为空返回1 否则0
int empty_myStack(myStack *stack);
//移除栈顶元素
void pop_myStack(myStack *stack);
//在栈顶增加元素
void push_myStack(myStack *stack, stackNode *node);
//返回栈中元素数目
int size_myStack(myStack *stack);
//返回栈顶元素
stackNode *top_myStack(myStack *stack);
//释放栈
void free_myStack(myStack *stack);
#endif