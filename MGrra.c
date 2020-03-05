
#define MaxVertexNum 100  /*z��󶥵���*/
#define INFINITY 65535 /*��*/
typedef int Vertex;  /*�����±��ʾ����*/
typedef int WeightType;  /*Ȩֵ*/
typedef char DataType;/*���㴢�����������*/
typedef struct GNode* PtrToGNode;
struct GNode
{
	int Ne; /*����*/
	int Nv;/*������*/
	WeightType G[MaxVertexNum][MaxVertexNum];/*�ڽӾ���*/
	DataType Data[MaxVertexNum];/*�涥������ݣ���һ������*/
};
typedef PtrToGNode MGraph;
/*�ߵĶ���*/
typedef struct ENode* PtrToGNode;
struct ENode
{
	Vertex v1, v2;
	WeightType Weight;
};
typedef PtrToGNode Edge;
/*��ʼ��һ����VertexNum�����㵥û�бߵ�ͼ*/
MGraph CreateGraph(int VertexNum)
{
	MGraph Graph;
	Vertex V, W;
	Graph = (MGraph)malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	for (V = 0; V < VertexNum; V++)
	{
		for (W = 0; W < VertexNum; W++)
			Graph->G[V][W] = INFINITY;
	}
	return Graph;
}
/*�����*/
void InsertEdge(MGraph Graph, Edge E)
{
	Graph->Data[E->v1][E->v2] = E->Weight;
	Graph->Data[E->v2][E->v1] = E->Weight;
}
/*����ͼ*/
MGraph BuildGraph()
{
	MGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;
	scanf("%d", &Nv);
	Graph=CreateGraph(Nv);
	sancf("%d", &Graph->Ne);
	if (!Graph->Ne)
		E = (Edge)malloc(sizeof(struct ENode));
	for (i = 0; i < Graph->Ne; i++)
	{
		scanf("%d %d %d", E->v1, E->v2, E->Weight);
		InsertEdge(Graph, E);
	}
	return Graph;
}