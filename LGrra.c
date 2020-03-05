
#define MaxVertexNum 100  /*z��󶥵���*/
typedef int Vertex;  /*�����±��ʾ����*/
typedef int WeightType;  /*Ȩֵ*/
typedef char DataType;/*���㴢�����������*/
typedef struct GNode* PtrToGNode;
struct GNode
{
	int Ne; /*����*/
	int Nv;/*������*/
	AdjList G;/*�ڽӱ�ͷ*/
	
};
typedef PtrToGNode LGraph;
/*�ߵĶ���*/
typedef struct ENode* PtrToGNode;
struct ENode
{
	Vertex v1, v2;
	WeightType Weight;
};
typedef PtrToGNode Edge;
/*�ڽӵ�Ķ���*/
typedef struct AdjVNode* PtrToAdjVNode;
struct AdjVNode
{
	Vertex AdjV;
	WeightType Weight;
	PtrToAdjVNode Next;
};
/*�����ͷ�ڵ�*/
typedef struct Vnode
{
	PtrToAdjVNode FirstEdge;
	DataType Data;
}AdjList[MaxVertexNum];
/*��ʼ��һ����VertexNum�����㵥û�бߵ�ͼ*/
LGraph CreateGraph(int VertexNum)
{
	LGraph Graph;
	Vertex V;
	Graph = (LGraph)malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	for (V = 0; V < VertexNum; V++)
	{
		Graph->G[V].FirstEdge = NULL;
	}
	return Graph;
}
/*�����*/
void InsertEdge(LGraph Graph, Edge E)
{
	PtrToAdjVNode NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));  
	NewNode->AdjV = E->v2;
	NewNode->Weight = E->Weight;
	/*���µĽڵ�鵽��ͷ��*/
	NewNode->Next = Graph->G[E->v1].FirstEdge;
	Graph->G[E->v1].FirstEdge = NewNode;
	/*����ͼ������з������*/
	NewNode->AdjV = E->v1;
	NewNode->Weight = E->Weight;
	/*���µĽڵ�鵽��ͷ��*/
	NewNode->Next = Graph->G[E->v2].FirstEdge;
	Graph->G[E->v2].FirstEdge = NewNode;
}
/*����ͼ*/
LGraph BuildGraph()
{
	LGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;
	scanf("%d", &Nv);
	Graph=CreateGraph(Nv);
	sancf("%d", &Graph->Ne);
	if (Graph->Ne)
		E = (Edge)malloc(sizeof(struct ENode));
	for (i = 0; i < Graph->Ne; i++)
	{
		scanf("%d %d %d", E->v1, E->v2, E->Weight);
		InsertEdge(Graph, E);
	}
	return Graph;
}