#include<stdio.h>
#include<graphics.h>

typedef int VertexData;

//邻接点
typedef struct EdgeNode{	
	int adjvex;	//邻接点的下标
	int weight;	//权重
	EdgeNode *next;
} EdgeNode;

//顶点节点
typedef struct VertexNode{
	VertexData data;	//数据域
	EdgeNode *firstEdge;	//边表头指针
} VertexNode;

//邻接表
typedef struct GraphAdjList{
	VertexNode *vertexNodeList;	//指向一个顶点节点数组
	int vertexNodeSize;	//节点多少
	int edgeNodeSize;	//边多少
} GraphAdjList;


/*深度优先遍历邻接表
	G 邻接表
	i 当前顶点的下标
	visited[] 访问标志的数组 为0表示该顶点未被访问过, 为1则被访问过
*/
void DFS(GraphAdjList *G, int i, int visited[])
{
	VertexNode *vertexNode = (G->vertexNodeList + i);	//当前节点	(弧尾)
	printf("%d\n", vertexNode->data);	//打印当前节点的数据
	visited[i] = 1;	

	EdgeNode *edgeNode = vertexNode->firstEdge;	
	int edgeNode_index = -1;	//弧头的下标
	while(edgeNode != NULL)
	{
		edgeNode_index = edgeNode->adjvex;
		if( visited[ edgeNode_index ] == 0 )
			DFS(G, edgeNode_index, visited);
		edgeNode = edgeNode->next;
	}
}

int main()
{

	return 0;
}