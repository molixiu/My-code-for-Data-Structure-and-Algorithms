#include"LinkedList.h"

//创建企业链表
LinkedList init_LinkedList()
{
	LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
	list->head = NULL;
	list->length = 0;
	return *list;
}
//清空链表
void empty_LinkedList(LinkedList *list)
{
	if (list != NULL)
	{
		list->head = NULL;
		list->length = 0;
	}
}
//从链表指定位置获得元素
void* getEle_fromLinkedList(LinkedList *list, int pos)
{
	if (list == NULL || pos < 0 || pos > list->length)
	{
		return NULL;
	}
	//辅助指针
	LinkedNode *pCurren = (LinkedNode *)list;
	for (int i = 0; i <= pos; i++)
	{
		pCurren = pCurren->next;
	}
	return pCurren;
}
//从链表指定位置插入元素
void insertEle_toLinkedList(LinkedList *list, int pos, LinkedNode *node)
{
	if (list == NULL || node == NULL)
	{
		return;
	}
	if (pos < 0 || pos > list->length)
	{
		pos = list->length - 1;
	}
	//辅助指针
	LinkedNode *pCurren = (LinkedNode *)list;
	for (int i = 0; i < pos; i++)
	{
		pCurren = pCurren->next;
	}

	node->next = pCurren->next;
	pCurren->next = node;
}
//删除链表中某个节点
void deleteEle_fromLinkedList(LinkedList *list, LinkedNode *node)
{
	if (list == NULL || node == NULL)
	{
		return;
	}
	//辅助指针
	LinkedNode *pCurren = (LinkedNode *)list;
	LinkedNode *deleteNodePre = NULL;
	for (int i = 0; i <= list->length; i++)
	{
		if (pCurren->next == node)
		{
			deleteNodePre = pCurren;
			break;
		}
	}
	if (deleteNodePre != NULL)
	{
		deleteNodePre->next = deleteNodePre->next;
	}
}
//销毁链表
void destory_LinkedList(LinkedList *list)
{
	if (list == NULL)
	{
		free(list);
	}
}
//打印链表
void print_LinkedList( LinkedList *list, void(*p)(LinkedNode*) )
{
	//辅助指针
	LinkedNode *pCurren = list->head;
	while (pCurren != NULL)
	{
		p(pCurren);
		pCurren = pCurren->next;
	}
}