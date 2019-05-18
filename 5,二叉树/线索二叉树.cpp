#include <stdio.h>
#include<stdlib.h>

typedef enum{link, thread} pointTag;

typedef struct BinaryNode
{
	char ch;
	struct BinaryNode *lchild, *rchild;
	pointTag lTag, rTag;
} BinaryNode;

BinaryNode *pre;
	
// 创建一棵二叉树
void CreateBiThrTree( BinaryNode **T )
{
	char c;

	scanf("%c", &c);
	if( ' ' == c )
	{
		*T = NULL;
	}
	else
	{
		*T = (BinaryNode *)malloc(sizeof(BinaryNode));
		(*T)->ch = c;
		(*T)->lTag = link;
		(*T)->rTag = link;

		CreateBiThrTree(&(*T)->lchild);
		CreateBiThrTree(&(*T)->rchild);
	}
}
	
void inorder_threadBinaryTree(BinaryNode *Node)
{
	if(Node != NULL)
	{
		inorder_threadBinaryTree(Node->lchild);
		if(Node->lchild == NULL)
		{
			Node->lTag = thread;
			Node->lchild = pre;
		}	
		if(pre->rchild == NULL)
		{
			pre->rTag = thread;
			pre->rchild = Node;
		}
		pre = Node;
		inorder_threadBinaryTree(Node->rchild);
	}			
}

BinaryNode *createHead_inorder_threadBinaryTree(BinaryNode *Node)
{
	//初始化头结点
	BinaryNode *head = (BinaryNode *)malloc(sizeof(BinaryNode));
	head->lTag = link;
	head->lchild = Node;
	head->rTag = thread;
	head->rchild = NULL;
	pre = head;
	
	inorder_threadBinaryTree(Node);
	head->rchild = pre;
	pre->rchild = head;
	
	return head;	
}


int main () {
	
	BinaryNode *binaryTree = NULL;
	CreateBiThrTree(&binaryTree);
	BinaryNode *head = createHead_inorder_threadBinaryTree(binaryTree);	 
	
	putchar('c');
	return 0;
}