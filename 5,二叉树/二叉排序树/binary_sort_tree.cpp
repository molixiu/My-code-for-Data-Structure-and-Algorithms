#include"binary_sort_tree.h"

//创建树的节点
BTNode *newBTNode(Data data)
{
	BTNode *newBTNode = (BTNode *)malloc( sizeof(BTNode) );
	newBTNode->data = data;
	newBTNode->left = NULL;
	newBTNode->right = NULL;
	return newBTNode;
}

//查找二叉树的最大节点
int getMax(BTNode *root, BTNode *rootParent, BTNode **max, BTNode **maxParent)
{
	if(root == NULL) //如果树是空的
		return 0;
	
	if(root->right == NULL)	//说明找到最大值了
	{
		*max = root;
		*maxParent = rootParent;
		return 1;
	}

	return getMax(root->right, root, max, maxParent);
}

//查找	search为找到的节点地址，searchParent为找到的节点的双亲地址，
int searchEle(int key, BTNode *pCurren, BTNode *parent, BTNode **search, BTNode **searchParent)
{
	if(pCurren == NULL)	//如果树为空 或者遍历树也找不到
	{
		*search = pCurren;
		*searchParent = parent;
		return 0;
	}
	if(key == pCurren->data.key) //如果找到了
	{
		*search = pCurren;
		*searchParent = parent;
		return 1;
	}
	
	//遍历整个二叉树直到找到或者遍历完也找不到为止
	if(key < pCurren->data.key)
		return searchEle(key, pCurren->left, pCurren, search, searchParent);
	else
		return searchEle(key, pCurren->right, pCurren, search, searchParent);
}

//向二叉排序树插入元素
int push(Data data,BTNode **pCurren, BTNode **parent)
{
	BTNode *search = NULL;
	BTNode *searchParent = NULL;
	int key = data.key;

	if(!searchEle(key, *pCurren, *parent, &search, &searchParent))	//如果要插入的元素树没有
	{
		BTNode *newNode = newBTNode(data);
		if(search == NULL && searchParent == NULL)	//这棵树为空 插入为根节点
		{
			*pCurren = newNode;
		}
		else if(search == NULL && searchParent != NULL)	//在叶子节点插入新节点有两种情况
		{
			if(key < searchParent->data.key)		//成为我双亲的左孩子
				searchParent->left = newNode;
			else									//成为我双亲的右孩子
				searchParent->right = newNode;
		}

		return 1;	//表示插入成功
	}
	else	//如果要插入的元素树已经存在
	{
		search->data = data;
		return 0;	//表示没有插入只是把原值更改
	}

}

//删除二叉树的节点	
int deleteNode(BTNode **root, int key)
{
	BTNode *search = NULL;
	BTNode *searchParent = NULL;
	if ( searchEle(key, *root, NULL, &search, &searchParent) ) //如果要删除的节点存在
	{
		if(search->left == NULL && search->right == NULL)	//如果要删除的节点是叶子节点
		{	
			if(search == *root)	//如果删除的是根节点
			{
				free(*root);
				*root = NULL;
			}
			else
			{
				if(searchParent->right = search)	//如果要删除的节点的双亲的右孩子是他
					searchParent->right = NULL;
				else								//如果要删除的节点的双亲的左孩子是他
					searchParent->right = NULL;		
					free(search);	//释放节点的空间
			}

		}
		else if(search->right == NULL && search->left != NULL)	//如果要删除的节点仅他的右子树为空
		{
			if(search == *root)	//如果删除的是根节点
			{
				*root = search->left;
				free(search);
			}
			else
			{
				if(searchParent->left = search)
					searchParent->left = search->left;
				else
					searchParent->right = search->left;
				free(search);	
			}
		}
		else if(search->left == NULL && search->right != NULL)	//如果要删除的节点仅他的左子树为空
		{
			if(search == *root)	//如果删除的是根节点
			{
				*root = search->right;
				free(search);
			}
			else
			{
				if(searchParent->left = search)
					searchParent->left = search->right;
				else
					searchParent->right = search->right;
				free(search);	
			}
		}
		else			//如果要删除的节点他的左右子树都不为空	//这个就有点复杂了
		{
			BTNode *max = NULL;
			BTNode *maxParent = NULL;
			getMax(search->left, NULL, &max, &maxParent);	//找到search的左子树的最大节点
			search->data = max->data;
			maxParent->right = max->left;
			free(max);
		}
		
		return 1;	//删除成功
	}
	else	//如果要删除的节点不存在
	{
		return 0;	//删除失败
	}
}
