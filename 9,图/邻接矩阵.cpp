#include<stdlib.h>
#include<iostream>
#include<queue>


using namespace std;

#define VERTEX_SIZE 4

typedef struct Vertex	//����
{
	char data;
} Vertex;

typedef struct MGraph	//ͼ
{
	Vertex vertexs[VERTEX_SIZE];	//��������
	int edges[VERTEX_SIZE][VERTEX_SIZE];	//������
} MGraph;

//������ȫͼ
MGraph *create_undirected_complete_graph()
{
	MGraph *mGraph = (MGraph *)malloc( sizeof(MGraph) );
	int i, j;
	for(i = 0; i < VERTEX_SIZE; i++)
	{
		for(j = 0; j < VERTEX_SIZE; j++)
		{
			mGraph->edges[i][j] = 0;
		}
	}

	for(i = 1; i < (VERTEX_SIZE - 1); i++)
	{
		mGraph->vertexs[i].data = 65 + i;
		mGraph->edges[i][i+1] = 1;
		mGraph->edges[i][i-1] = 1;
	}
	mGraph->vertexs[i].data = 65 + i;
	mGraph->edges[i][0] = 1;
	mGraph->edges[i][i-1] = 1;

	mGraph->vertexs[0].data = 65;
	mGraph->edges[0][i] = 1;
	mGraph->edges[0][0+1] = 1;

	return mGraph;
}

//��ӡ��ά����
void print_Array(int arr[VERTEX_SIZE][VERTEX_SIZE])
{
	for(int i = 0, j; i < VERTEX_SIZE; i++)
	{
		for(j = 0; j < VERTEX_SIZE; j++)
		{
			printf("%d\t", arr[i][j]);
		}
		putchar('\n');
	}
}

//������ȱ����㷨����ͼ�����нڵ�
void BFS_Graph(MGraph *mGraph, int root)
{
	int vertexs_symbol[VERTEX_SIZE] = {0};	//������ʾ�����Ƿ񱻱�����,��0��ʾ�Ѿ�������
	queue<int> q;	//װ����
	q.push(root);
	vertexs_symbol[root]++;


	while(!q.empty())
	{
		int vertex = q.front();	
		cout << mGraph->vertexs[vertex].data << endl; 

		q.pop();	
		for(int i = 0; i < VERTEX_SIZE; i++)	
		{
			if(mGraph->edges[vertex][i] != 0)	
			{
				if(vertexs_symbol[i] == 0)
				{
					q.push(i);
					vertexs_symbol[i]++;
				}
			}
		}
	}


}

int main()
{
	MGraph *mGraph = (MGraph *)create_undirected_complete_graph();
	//print_Array(mGraph->edges);
	BFS_Graph(mGraph, 2);
	

	return 0;
}