#ifndef _MYVECTOR_H
#define _MYVECTOR_H

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

//初始化动态数组
dynamicArray init_dynamicArray();
//向数组最后增加元素
void push_back_dynamicArray(dynamicArray *da, int value);
//移出最后一个元素
void pop_back_dynamicArray(dynamicArray *da);
//返回指定位置元素
int at_dynamicArray(dynamicArray *da, int index);
//清空数组所有元素
void clear_dynamicArray(dynamicArray *da);
//释放数组
void free_dynamicArray(dynamicArray *da);



#endif