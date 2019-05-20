#include<stdio.h>
#include<graphics.h>

typedef int VertexData;

//�ڽӵ�
typedef struct EdgeNode{	
	int adjvex;	//�ڽӵ���±�
	int weight;	//Ȩ��
	EdgeNode *next;
} EdgeNode;

//����ڵ�
typedef struct VertexNode{
	VertexData data;	//������
	EdgeNode *firstEdge;	//�߱�ͷָ��
} VertexNode;

//�ڽӱ�
typedef struct GraphAdjList{
	VertexNode *vertexNodeList;	//ָ��һ������ڵ�����
	int vertexNodeSize;	//�ڵ����
	int edgeNodeSize;	//�߶���
} GraphAdjList;


/*������ȱ����ڽӱ�
	G �ڽӱ�
	i ��ǰ������±�
	visited[] ���ʱ�־������ Ϊ0��ʾ�ö���δ�����ʹ�, Ϊ1�򱻷��ʹ�
*/
void DFS(GraphAdjList *G, int i, int visited[])
{
	VertexNode *vertexNode = (G->vertexNodeList + i);	//��ǰ�ڵ�	(��β)
	printf("%d\n", vertexNode->data);	//��ӡ��ǰ�ڵ������
	visited[i] = 1;	

	EdgeNode *edgeNode = vertexNode->firstEdge;	
	int edgeNode_index = -1;	//��ͷ���±�
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