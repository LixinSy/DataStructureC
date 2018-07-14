//SqQueue.h
#define QElemType struct TreeNode*
//�ӽڵ�
struct QNode
{
	QElemType data;
	struct QNode *next;
};

//����
struct LinkQueue
{
	struct QNode *front;
	struct QNode *rear;
};

//����������
void InitQueue(struct LinkQueue *Q); //�������
void DestroyQueue(struct LinkQueue *Q); //���ٶ���
void EnQueue(struct LinkQueue *Q, QElemType e); //���
void DeQueue(struct LinkQueue *Q, QElemType *e); //����
int QueueEmpty(struct LinkQueue *Q); //�Ƿ�Ϊ��