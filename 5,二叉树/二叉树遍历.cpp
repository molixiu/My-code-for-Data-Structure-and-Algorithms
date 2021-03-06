﻿#include <stdio.h>

struct BinaryNode
{
	char ch;
	struct BinaryNode *lchild;
	struct BinaryNode *rchild;
};
	
void rlrRecursion(struct BinaryNode *root)
{
	if (root == NULL)
	{
		return;
	}
	
	printf("%c ", root->ch);
	rlrRecursion(root->lchild);
	rlrRecursion(root->rchild);
}

int main () {
	struct BinaryNode bNodeA = { 'A', NULL, NULL };
	struct BinaryNode bNodeB = { 'B', NULL, NULL };
	struct BinaryNode bNodeC = { 'C', NULL, NULL };
	struct BinaryNode bNodeD = { 'D', NULL, NULL };
	struct BinaryNode bNodeE = { 'E', NULL, NULL };
	struct BinaryNode bNodeF = { 'F', NULL, NULL };
	struct BinaryNode bNodeG = { 'G', NULL, NULL };
	struct BinaryNode bNodeH = { 'H', NULL, NULL };
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
