#ifndef _MYVECTOR_H
#define _MYVECTOR_H
#endif

#include<stdlib.h>
#include<string.h>
#define DEFAULT_DYNAMICARRAY_CAPACITY 10
#define DEFAULT_DYNAMICARRAY_CAPACIYY_INCREASE 1.5


typedef struct dynamicArray
{
	int *addr;
	int size;
	int capacity;
} dynamicArray;

//��ʼ����̬����
dynamicArray init_dynamicArray();
//�������������Ԫ��
void push_back_dynamicArray(dynamicArray *da, int value);
//�Ƴ����һ��Ԫ��
void pop_back_dynamicArray(dynamicArray *da);
//����ָ��λ��Ԫ��
int at_dynamicArray(dynamicArray *da, int index);
//�����������Ԫ��
void clear_dynamicArray(dynamicArray *da);
//�ͷ�����
void free_dynamicArray(dynamicArray *da);