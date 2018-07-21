
//SqStack.h

#define TRUE 1
#define FLASE 0
#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10
#define ElemType struct TreeNode*

#ifndef SQ_STACK_H
#define SQ_STACK_H
//����˳��ջ
typedef struct
{
	ElemType *base;
	ElemType *top;
	int stacksize;
}SqStack;

//��������
void InitStack(SqStack *S);  //����˳��ջ
void DestroyStack(SqStack *S); //����
int StackEmpty(SqStack S);  //�ж��Ƿ�Ϊ��
int StackFull(SqStack S); //�ж��Ƿ�Ϊ��
void ClearStack(SqStack *S);  //���ջ
int StackLength(SqStack S);  //����ջԪ�ظ���
void Push(SqStack *S, ElemType e);  //ѹ��ջ
void Pop(SqStack *S, ElemType *e); //ɾ��ջ��Ԫ�أ���e����
void GetTop(SqStack S, ElemType *e);  //��e����ջ��Ԫ��

#endif