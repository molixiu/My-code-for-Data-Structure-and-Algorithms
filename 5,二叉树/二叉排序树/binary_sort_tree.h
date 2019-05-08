#ifndef BINARY_SORT_TREE_H

#include<stdlib.h>

typedef struct Data
{
	int key;
	char value ;
} Data;

typedef struct binary_Tree
{
	struct Data data;
	struct binary_Tree *left;
	struct binary_Tree *right;
} BTNode;

//创建树的节点
BTNode *newBTNode(Data data);

//查找二叉树的最大节点
int getMax(BTNode *root, BTNode *rootParent, BTNode **max, BTNode **maxParent);

//查找	search为找到的节点地址，searchParent为找到的节点的双亲地址，找到返回1，否则0
int searchEle(int key, BTNode *pCurren, BTNode *parent, BTNode **search, BTNode **searchParent); 

//向二叉排序树插入元素
int push(Data data,BTNode **pCurren, BTNode **parent);

//删除二叉树的节点
int deleteNode(BTNode **root, int key);


#endif