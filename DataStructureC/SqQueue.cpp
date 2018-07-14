//SqQueue.cpp
#include<stdlib.h>
#include"SqQueue.h"

void InitQueue(struct LinkQueue *Q) //构造队列
{
	Q->front = Q->rear = (struct QNode*)malloc(sizeof(struct QNode));
	if (!Q->front)
	{
		exit(1);
	}
	(Q->front)->next = NULL;
}

void DestroyQueue(struct LinkQueue *Q) //销毁队列
{
	struct QNode *p = Q->front, *t;
	while (p)
	{
		t = p->next;
		free(p);
		p = t;
	}
}

void EnQueue(struct LinkQueue *Q, QElemType e) //入队
{
	struct QNode *p = (struct QNode *)malloc(sizeof(struct QNode));
	if (!p)
	{
		exit(1);
	}
	p->data = e;
	p->next = NULL;
	(Q->rear)->next = p;
	Q->rear = p;
}

void DeQueue(struct LinkQueue *Q, QElemType *e) //出队
{
	struct QNode *p = NULL;
	if (Q->front == Q->rear)
	{
		return;
	}
	p = (Q->front)->next;
	*e = p->data;
	(Q->front)->next = p->next;
	if (Q->rear == p)
	{
		Q->rear = Q->front;
	}
	free(p);
}

int QueueEmpty(struct LinkQueue *Q) //是否为空
{
	if (Q->front == Q->rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}