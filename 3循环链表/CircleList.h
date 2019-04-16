#ifndef _CIRCLELIST_H
#define _CIRCLELIST_H

typedef struct CircleNode
{
	CircleNode *next;
} CircleNode;

typedef struct CircleList
{
	CircleNode *head;
	int length;
} CircleList;

//��ʼ������
CircleList * init_CircleList();
//�������������
void insertEle_CircleList(CircleList *list, int pos, CircleNode *node);
//ɾ��ĳ��Ԫ��
void deleteEle_fromCircleList(CircleList *list, CircleNode *node);
//�����������Ԫ��
void clearAll_fromCircleList(CircleList *list);
//��������
void destory_CircleList(CircleList **list);
//��ӡ����
void print_CircleList(CircleList *list, void(*p)(CircleNode*));

#endif