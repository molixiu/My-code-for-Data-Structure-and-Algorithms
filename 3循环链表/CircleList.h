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

//初始化链表
CircleList * init_CircleList();
//向链表插入数据
void insertEle_CircleList(CircleList *list, int pos, CircleNode *node);
//删除某个元素
void deleteEle_fromCircleList(CircleList *list, CircleNode *node);
//清除链表所有元素
void clearAll_fromCircleList(CircleList *list);
//销毁链表
void destory_CircleList(CircleList **list);
//打印链表
void print_CircleList(CircleList *list, void(*p)(CircleNode*));

#endif