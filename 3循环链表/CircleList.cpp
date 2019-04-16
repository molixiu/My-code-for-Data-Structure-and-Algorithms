#include"CircleList.h"
#include<stdlib.h>



//初始化链表
CircleList * init_CircleList()
{
	CircleList *list = (CircleList *)malloc(sizeof(CircleList));
	list->head = (CircleNode *)list;
	list->length = 0;
	return list;
}
//向链表插入数据
void insertEle_CircleList(CircleList *list, int pos, CircleNode *node)
{
	if (list == NULL || node == NULL)
	{
		return;
	}
	if (pos < 0 || pos > list->length)
	{
		pos = list->length;
	}

	//辅助指针
	CircleNode *pCurren = (CircleNode *)list;
	for (int i = 0; i < pos; i++)
	{
		pCurren = pCurren->next;
	}
	node->next = pCurren->next;
	pCurren->next = node;
	list->length++;
}
//删除某个元素
void deleteEle_fromCircleList(CircleList *list, CircleNode *node)
{
	if (list == NULL || node == NULL)
	{
		return;
	}

	//辅助指针
	CircleNode *pCurren = (CircleNode *)list;
	CircleNode *deleteNodePre = NULL;
	for (int i = 0; i < list->length; i++)
	{
		if (node == pCurren->next)
		{
			deleteNodePre = pCurren;
			break;
		}
		pCurren = pCurren->next;
	}
	if (deleteNodePre != NULL)	//找到了要删除的节点
	{
		deleteNodePre->next = deleteNodePre->next->next;
		list->length--;
	}
}
//清除链表所有元素
void clearAll_fromCircleList(CircleList *list)
{
	if (list != NULL)
	{
		list->head = list->head;
		list->length = 0;
	}
}
//销毁链表
void destory_CircleList(CircleList **list)
{
	if (*list != NULL)
	{
		free(*list);
		*list = NULL;
	}
}
//打印链表
void print_CircleList(CircleList *list, void(*p)(CircleNode*))
{
	if (list != NULL)
	{
		//辅助指针
		CircleNode *pCurren = list->head;
		while (pCurren != (CircleNode *)list)
		{
			p(pCurren);
			pCurren = pCurren->next;
		}

	}
}