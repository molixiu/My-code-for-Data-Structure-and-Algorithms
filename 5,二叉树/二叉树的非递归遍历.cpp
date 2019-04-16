#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include"myStack.h"

typedef struct BinaryNode
{
	char ch;
	BinaryNode *lchild;
	BinaryNode *rchild;
} BinaryNode;

typedef struct stackEle
{
	stackNode *next;
	BinaryNode *binaryNode;
	int state;
} stackEle;

stackEle *create_stackEle(BinaryNode *binarynode)
{
	stackEle *stackele = (stackEle *)malloc(sizeof(stackEle));
	stackele->binaryNode = binarynode;
	stackele->next = NULL;
	stackele->state = FALSE;
	return stackele;
}

void print_stackEle(stackEle *stackele)
{
	printf("%c ", stackele->binaryNode->ch);
	
}

void iterate_binaryTree(BinaryNode *root)
{
	myStack *mystack = init_myStack();	//初始化栈
	stackEle *stacele = create_stackEle(root);	//创建一个栈元素
	push_myStack(mystack,(stackNode *)stacele);	//往栈里压入第一个元素

	while (!empty_myStack(mystack))
	{
		stackEle *temp_stackEle = (stackEle *)top_myStack(mystack);
		if (temp_stackEle->state == TRUE)
		{
			print_stackEle(temp_stackEle);
			pop_myStack(mystack);
		}
		else
		{
			pop_myStack(mystack);
			temp_stackEle->state = TRUE;

			if (temp_stackEle->binaryNode->rchild != NULL)
			{
				stackEle *rchild = create_stackEle(temp_stackEle->binaryNode->rchild);
				push_myStack(mystack, (stackNode *)rchild);
			}
			if (temp_stackEle->binaryNode->lchild != NULL)
			{
				stackEle *lchild = create_stackEle(temp_stackEle->binaryNode->lchild);
				push_myStack(mystack, (stackNode *)lchild);
			}
			push_myStack(mystack, (stackNode *)temp_stackEle);
		}
	}
}

int main()
{
	BinaryNode bNodeA = { 'A', NULL, NULL };
	BinaryNode bNodeB = { 'B', NULL, NULL };
	BinaryNode bNodeC = { 'C', NULL, NULL };
	BinaryNode bNodeD = { 'D', NULL, NULL };
	BinaryNode bNodeE = { 'E', NULL, NULL };
	BinaryNode bNodeF = { 'F', NULL, NULL };
	BinaryNode bNodeG = { 'G', NULL, NULL };
	BinaryNode bNodeH = { 'H', NULL, NULL };
	bNodeA.lchild = &bNodeB;
	bNodeB.rchild = &bNodeC;
	bNodeC.lchild = &bNodeD;
	bNodeC.rchild = &bNodeE;
	bNodeA.rchild = &bNodeF;
	bNodeF.rchild = &bNodeG;
	bNodeG.lchild = &bNodeH;
	;
	iterate_binaryTree(&bNodeA);

	return 0;
}
