#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include<stdlib.h>

typedef struct LinkedNode
{
	LinkedNode *next;
} LinkedNode;

typedef struct LinkedList
{
	LinkedNode *head;
	int length;
} LinkedList;

//������ҵ����
LinkedList init_LinkedList();
//�������
void empty_LinkedList(LinkedList *list);
//������ָ��λ�û��Ԫ��
void* getEle_fromLinkedList(LinkedList *list, int pos);
//������ָ��λ�ò���Ԫ��
void insertEle_toLinkedList(LinkedList *list, int pos, LinkedNode *node);
//ɾ��������ĳ���ڵ�
void deleteEle_fromLinkedList(LinkedList *list, LinkedNode *node);
//��������
void destory_LinkedList(LinkedList *list);
//��ӡ����
void print_LinkedList(LinkedList *list, void(*p)(LinkedNode*));

#endif