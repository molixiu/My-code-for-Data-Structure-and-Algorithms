#include"DynamicArray.h"
#include<stdio.h>

dynamicArray init_dynamicArray()
{
	dynamicArray da;
	da.addr = (int *)malloc( sizeof(int)*DEFAULT_DYNAMICARRAY_CAPACITY );
	da.capacity = DEFAULT_DYNAMICARRAY_CAPACITY;
	da.size = 0;
	return da;
}

void push_back_dynamicArray(dynamicArray *da, int value)
{
	if (da->capacity <= da->size)	//如果数组的容量满了
	{
		int temp_capacity = da->capacity * DEFAULT_DYNAMICARRAY_CAPACIYY_INCREASE;
		int *temp_addr = (int *)malloc(temp_capacity*sizeof(int));
		memcpy(temp_addr, da->addr, da->capacity*sizeof(int));
		free(da->addr);
		da->addr = temp_addr;
		da->capacity = temp_capacity;
	}
	da->addr[da->size] = value;
	//printf("%d\n", da->addr[da->size]);
	da->size++;
}

void pop_back_dynamicArray(dynamicArray *da)
{
	da->size--;	
}

int at_dynamicArray(dynamicArray *da, int index)
{
	return da->addr[index];
}

void clear_dynamicArray(dynamicArray *da)
{
	da->size = 0;
}

void free_dynamicArray(dynamicArray *da)
{
	if (da != NULL)
	{
		free(da);
		da = NULL;
	}
}