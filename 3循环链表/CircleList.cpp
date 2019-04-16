#include"CircleList.h"
#include<stdlib.h>



//��ʼ������
CircleList * init_CircleList()
{
	CircleList *list = (CircleList *)malloc(sizeof(CircleList));
	list->head = (CircleNode *)list;
	list->length = 0;
	return list;
}
//�������������
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

	//����ָ��
	CircleNode *pCurren = (CircleNode *)list;
	for (int i = 0; i < pos; i++)
	{
		pCurren = pCurren->next;
	}
	node->next = pCurren->next;
	pCurren->next = node;
	list->length++;
}
//ɾ��ĳ��Ԫ��
void deleteEle_fromCircleList(CircleList *list, CircleNode *node)
{
	if (list == NULL || node == NULL)
	{
		return;
	}

	//����ָ��
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
	if (deleteNodePre != NULL)	//�ҵ���Ҫɾ���Ľڵ�
	{
		deleteNodePre->next = deleteNodePre->next->next;
		list->length--;
	}
}
//�����������Ԫ��
void clearAll_fromCircleList(CircleList *list)
{
	if (list != NULL)
	{
		list->head = list->head;
		list->length = 0;
	}
}
//��������
void destory_CircleList(CircleList **list)
{
	if (*list != NULL)
	{
		free(*list);
		*list = NULL;
	}
}
//��ӡ����
void print_CircleList(CircleList *list, void(*p)(CircleNode*))
{
	if (list != NULL)
	{
		//����ָ��
		CircleNode *pCurren = list->head;
		while (pCurren != (CircleNode *)list)
		{
			p(pCurren);
			pCurren = pCurren->next;
		}

	}
}