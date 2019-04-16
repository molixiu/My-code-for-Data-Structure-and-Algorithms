#include"LinkedList.h"

//������ҵ����
LinkedList init_LinkedList()
{
	LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
	list->head = NULL;
	list->length = 0;
	return *list;
}
//�������
void empty_LinkedList(LinkedList *list)
{
	if (list != NULL)
	{
		list->head = NULL;
		list->length = 0;
	}
}
//������ָ��λ�û��Ԫ��
void* getEle_fromLinkedList(LinkedList *list, int pos)
{
	if (list == NULL || pos < 0 || pos > list->length)
	{
		return NULL;
	}
	//����ָ��
	LinkedNode *pCurren = (LinkedNode *)list;
	for (int i = 0; i <= pos; i++)
	{
		pCurren = pCurren->next;
	}
	return pCurren;
}
//������ָ��λ�ò���Ԫ��
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
	//����ָ��
	LinkedNode *pCurren = (LinkedNode *)list;
	for (int i = 0; i < pos; i++)
	{
		pCurren = pCurren->next;
	}

	node->next = pCurren->next;
	pCurren->next = node;
}
//ɾ��������ĳ���ڵ�
void deleteEle_fromLinkedList(LinkedList *list, LinkedNode *node)
{
	if (list == NULL || node == NULL)
	{
		return;
	}
	//����ָ��
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
//��������
void destory_LinkedList(LinkedList *list)
{
	if (list == NULL)
	{
		free(list);
	}
}
//��ӡ����
void print_LinkedList( LinkedList *list, void(*p)(LinkedNode*) )
{
	//����ָ��
	LinkedNode *pCurren = list->head;
	while (pCurren != NULL)
	{
		p(pCurren);
		pCurren = pCurren->next;
	}
}