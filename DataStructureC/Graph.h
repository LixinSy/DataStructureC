
#ifndef GRAPH_H
#define GRAPH_H

#include <limits.h>
#include "LinkQueue.h"
#include "SqStack.h"

#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 20
#define VertexType int
#define VRtype int
#define InfoType void

typedef enum { DG, DN, UDG, UDN }GraphKind; //����ͼ, ������, ����ͼ, ������

/************* �����ʾ, �ڽӾ��� *******************/
typedef struct ArcCell{
    VRtype adj;     //��ʾ���ڷ񣻶���������ΪȨֵ
    InfoType *info; //�û���������Ϣ
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct {
    VertexType vexs[MAX_VERTEX_NUM]; //��������
    AdjMatrix arcs;                  //�ڽӾ���
    int vexnum, arcnum;
    GraphKind kind;
}MGraph;


/************* ��ʽ�洢�ṹ, �ڽӱ� *******************/
typedef struct ArcNode{
    int adjvex;             //�û�ָ�򶥵��λ�ã������������±꣬Ҳ������ָ������
    struct ArcNode *nextarc;//ָ����һ���ڽӶ���Ļ�
    InfoType *info;
}ArcNode;

typedef struct VNode{
    VertexType data;    //������Ϣ
    ArcNode *firstarc;  //ָ���һ����
}VNode, AdjList[MAX_VERTEX_NUM];

typedef struct {
    AdjList vertices;   //�ڽӱ�
    int vexnum, arcnum;
    GraphKind kind;
}ALGraph;


/************* ����ͼ����һ����ʽ�洢�ṹ��ʮ������ *******************/
//ʮ������������Ϊ�ڽӱ�����ڽӱ�Ľ��
typedef struct ArcBox{
    int tailvex, headvex;         //�û���β��ͷ�����λ��
    struct ArcBox *tlink, *hlink; //ָ����һ���ڽӶ���Ļ�
    InfoType *info;
}ArcBox;

typedef struct VexNode{
    VertexType data;            //������Ϣ
    ArcBox *firstin, *firstout; //ָ���һ���뻡�ͳ���
}VexNode;

typedef struct {
    VexNode xlist[MAX_VERTEX_NUM]; //ʮ������
    int vexnum, arcnum;
}OLGraph;


/************* ����ͼ����һ����ʽ�洢�ṹ���ڽӶ��ر� *******************/
typedef enum { unvisited, visited }VisitIf;
typedef struct EBox{
    VisitIf visit;              //���ʱ��
    int ivex, jvex;             //�ñ����������������λ��
    struct EBox *ilink, *jlink; //�ֱ�ָ�������������������һ����
    InfoType *info;
}EBox;

typedef struct VexBox{
    VertexType data;    //������Ϣ
    ArcNode *firsedge;  //ָ���һ����
}VexBox;

typedef struct {
    VexBox adjmulist[MAX_VERTEX_NUM];   //�ڽӶ��ر�
    int vexnum, arcnum;
}AMLGraph;




/******************* ���ú��� *******************/
int FirstAdjVex(ALGraph G, int v);
int NextAdjVex(ALGraph G, int v, int w);
void FindIndegree(ALGraph G, int indegree[MAX_VERTEX_NUM]);

/******************* ����������� *******************/
bool visited[MAX_VERTEX_NUM]; //ȫ�ֱ���
Status (*VisitFunc)(VertexType);//ȫ�ֱ���
void DFSTraverse(ALGraph G, Status (*visit)(int))
{
    VisitFunc = visit;
    for (int v=0; v < G.vexnum; v++)
        visited[i] = false;
    for (int v=0; v < G.vexnum; v++){
        if (!visited[v])
            DFS(G, v);
    }
}
void DFS(ALGraph G, int v)
{
    visited[v] = true;
    VisitFunc(v);
    for (int w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w)){
        if (!visited[i])
            DFS(G, w);
    }
}


/******************* ����������� *******************/
void BFSTraverse(ALGraph G, Status (*visit)(int))
{
    LinkQueue Q;InitQueue(&Q);
    for (int v=0; v < G.vexnum; v++)
        visited[v] = false;
    for (int v=0; v < G.vexnum; v++){
        if (!visited[v]){
            EnQueue(&Q, v);
            while(!QueueEmpty(Q)){
                DeQueue(&Q, &u);
                visit(u);
                visited[u] = true;
                for (int w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w)){
                    if (!visited[w]){
                        EnQueue(&Q, w);
                    }
                }
            }
        }
    }
    DestroyQueue(&Q);
}


/******************* �������� *******************/
///1�����ڽӱ���Ϊ����ͼ�Ĵ洢�ṹ
///2�����㷨���������������ͼ�Ƿ��л�
///3������ͼ�޻�ʱ��������������ȱ��������������򣬴�ʱ���Ϊ�����������������
Status TopoLogicalSort(ALGraph G)
{   //�л�����ERROR���޻������������
    SqStack S;InitStack(&S);
    int indegree[MAX_VERTEX_NUM];
    FindIndegree(G, indegree);
    for (int i=0; i < G.vexnum; i++)
        if (indegree[i] == 0)
            Push(&S, i);
    int count = 0; //�Ѿ�������������ж�����
    int v;
    while (!StackEmpty(S)){
        Pop(&S, &v);
        printf("%d", v);
        ++count;
        for (ArcNode *p = G.vertices[v].firstarc; p; p = p->nextarc){
            int k = p->adjvex;
            if (!(--indegree[k])){
                Push(&S, &k);
            }
        }
    }
    if (count < G.vexnum)
        return ERROR;
    else
        return OK;
}


#endif
