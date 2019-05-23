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

//创建企业链表
LinkedList init_LinkedList();
//清空链表
void empty_LinkedList(LinkedList *list);
//从链表指定位置获得元素
void* getEle_fromLinkedList(LinkedList *list, int pos);
//从链表指定位置插入元素
void insertEle_toLinkedList(LinkedList *list, int pos, LinkedNode *node);
//删除链表中某个节点
void deleteEle_fromLinkedList(LinkedList *list, LinkedNode *node);
//销毁链表
void destory_LinkedList(LinkedList *list);
//打印链表
void print_LinkedList(LinkedList *list, void(*p)(LinkedNode*));

#endif