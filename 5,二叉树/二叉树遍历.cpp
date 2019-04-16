#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>

typedef struct BinaryNode
{
	char ch;
	BinaryNode *lchild;
	BinaryNode *rchild;
} BinaryNode;

//ÏÈÐò±éÀú
void rlrRecursion(BinaryNode *root)
{
	if (root == NULL)
	{
		return;
	}
	
	printf("%c ", root->ch);
	rlrRecursion(root->lchild);
	rlrRecursion(root->rchild);
}

int mian()
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

	rlrRecursion(&bNodeA);

	return 0;
}