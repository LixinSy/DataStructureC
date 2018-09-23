
//linkQueue.cpp

#include "LinkQueue.h"

//------------------------------  �������� ----------------------------

//�����¶���
Status InitQueue(LinkQueue *Q)
{
	Q->front = Q->rear = (QNode *)malloc(sizeof(QNode));
	if (!Q->front)
		exit(ERROR);
	Q->front->next = NULL;
	return OK;
}
//���ٶ���
Status DestroyQueue(LinkQueue *Q)
{
	while (Q->front){
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	return OK;
}
//�������
Status ClearQueue(LinkQueue *Q)
{
	QNode *p = Q->front->next;
	while (p){
		Q->rear = p->next;
		free(p);
		p = Q->rear;
	}
	Q->rear = Q->front;
	return OK;
}
//�����Ƿ�Ϊ��
Status QueueEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
}
//���г��ȣ�Ԫ�ظ���
int QueueLength(LinkQueue Q)
{
	return Q.length;
}
//��e���ض�ͷԪ��
Status GetHead(LinkQueue Q, ElemType *e)
{
	if (Q.front == Q.rear)
		return INFEASIBLE;
	*e = Q.front->next->data;
	return OK;
}
//���
Status EnQueue(LinkQueue *Q, ElemType e)
{
	QNode *p = (QNode*)malloc(sizeof(QNode));
	if (!p)
		exit(ERROR);
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return OK;
}
//����
Status DeQueue(LinkQueue *Q, ElemType *e)
{
	if (Q->front == Q->rear)
		return INFEASIBLE;
	QNode *p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;
	if (p == Q->rear)
		Q->rear = Q->front;
	free(p);
	return OK;
}
//��������
Status QueueTraverce(LinkQueue Q, void(*visit)(ElemType))
{
	QNode *p = Q.front->next;
	while (p){
		visit(p->data);
		p = p->next;
	}
	printf("; %d��Ԫ��\n", Q.length);
	return OK;
}
