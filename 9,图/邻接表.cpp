#include<stdlib.h>
#include<stdio.h>

#define MAXVERTEX 1000
typedef int DATA;

typedef struct arc_head //�߱�ڵ�
{
	int arc_head_addr;	//��ͷ�±�	
	struct arc_head *next;
} arc_element;

typedef struct vertex	//�����ڵ�
{
	DATA data;	//��������� 
	struct arc_head *arc_head;
} vertex;

typedef struct graphAdjList
{
	struct vertex vertexs[MAXVERTEX];	//��������
	int numVertex, numArc_head;			//����� ������
} grapAdjList;

#if 0
int main()
{ 

	
	return 0;
}
#endif