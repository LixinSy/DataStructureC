//SqQueue.h
#define QElemType struct TreeNode*
//队节点
struct QNode
{
	QElemType data;
	struct QNode *next;
};

//队列
struct LinkQueue
{
	struct QNode *front;
	struct QNode *rear;
};

//声明各函数
void InitQueue(struct LinkQueue *Q); //构造队列
void DestroyQueue(struct LinkQueue *Q); //销毁队列
void EnQueue(struct LinkQueue *Q, QElemType e); //入队
void DeQueue(struct LinkQueue *Q, QElemType *e); //出队
int QueueEmpty(struct LinkQueue *Q); //是否为空