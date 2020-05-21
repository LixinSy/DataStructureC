//SqQueue.cpp

#include"SqQueue.h"


//������ѭ������
Status InitQueue(SqQueue *Q)
{
	Q->base = (ElemType*)malloc(sizeof(ElemType)*MAX_SIZE);
	if (!Q->base)
		exit(ERROR);
	Q->front = Q->rear = 0;
	return OK;
}
//���ٶ���
Status DestroyQueue(SqQueue *Q)
{
	if (!Q->base)
		return INFEASIBLE;
	free(Q->base);
	return OK;
}
//�������
Status ClearQueue(SqQueue *Q)
{
	if (!Q->base)
		return INFEASIBLE;
	Q->rear = Q->front = 0;
	return OK;
}
//�����Ƿ�Ϊ��
Status QueueEmpty(SqQueue Q)
{
	if (Q.front == Q.rear) //ѭ�����п�
		return TRUE;
	else
		return FALSE;
}
//ѭ�����г��ȣ�Ԫ�ظ���
int QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAX_SIZE) % MAX_SIZE; //ѭ�����г��ȼ���
}
//��e���ض�ͷԪ��
Status GetHead(SqQueue Q, ElemType *e)
{
	if (Q.front == Q.rear)
		return INFEASIBLE;
	*e = Q.base[Q.front];
	return OK;
}
//���
Status EnQueue(SqQueue *Q, ElemType e)
{
	if ((Q->rear + 1) % MAX_SIZE == Q->front) //ѭ��������
		return ERROR;
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAX_SIZE;  //����Q.rear
	return OK;
}
//����
Status DeQueue(SqQueue *Q, ElemType *e)
{
	if (Q->front == Q->rear) //ѭ�����п�
		return ERROR;
	*e = Q->base[Q->front];
	Q->front = (Q->front + 1) % MAX_SIZE;  //����Q.front
	return OK;
}
//��������
Status QueueTraverce(SqQueue Q, void(*visit)(ElemType))
{
	int i = Q.front;
	for (; i != Q.rear; i = (i+1) % MAX_SIZE){
		visit(Q.base[i]);
    }
	return OK;
}
