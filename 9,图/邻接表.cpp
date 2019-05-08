#include<stdlib.h>
#include<stdio.h>

#define MAXVERTEX 1000
typedef int DATA;

typedef struct arc_head //边表节点
{
	int arc_head_addr;	//弧头下标	
	struct arc_head *next;
} arc_element;

typedef struct vertex	//顶点表节点
{
	DATA data;	//顶点的数据 
	struct arc_head *arc_head;
} vertex;

typedef struct graphAdjList
{
	struct vertex vertexs[MAXVERTEX];	//顶点数组
	int numVertex, numArc_head;			//顶点和 边数量
} grapAdjList;

#if 0
int main()
{ 

	
	return 0;
}
#endif