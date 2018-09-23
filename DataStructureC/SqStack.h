
//SqStack.h
#ifndef SQ_STACK_H
#define SQ_STACK_H

#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10
#define ElemType int
#include "macro.h"


//����˳��ջ
typedef struct SqStack
{
	ElemType *base;
	ElemType *top;
	int stacksize;
}SqStack;

//��������

Status InitStack(SqStack *S);  //����˳��ջ
Status DestroyStack(SqStack *S); //����
Status StackEmpty(SqStack S);  //�ж��Ƿ�Ϊ��
Status ClearStack(SqStack *S);  //���ջ
int StackLength(SqStack S);  //����ջԪ�ظ���
Status Push(SqStack *S, ElemType e);  //ѹ��ջ
Status Pop(SqStack *S, ElemType *e); //ɾ��ջ��Ԫ�أ���e����
Status GetTop(SqStack S, ElemType *e);  //��e����ջ��Ԫ��
Status StackTraverse(SqStack S, Status(*func)(ElemType)); //����ջ


//------------------------- �㷨 --------------------------

/*��ֵת���� ʮ����N������d���Ƶ�ת����N = (N div d) * d + N mod d; divΪ������ mod���ࡣ
��������Ǹ�ʮ���ƣ�����˽���
*********************************************************************/
void Conversion(unsigned int N, unsigned int d);

/*����ƥ��
*********************************************************************/
void BracketMatch();

/*�б༭
*********************************************************************/
void LineEdit();

/*���ʽ��ֵ��
1���ȳ˳���Ӽ�
2��������
3���������ڣ���������
*********************************************************************/

typedef enum OP
{
	start,
	rightB,
	add,
	sub,
	mut,
	divi,
	leftB
}OP;
//��������ȼ��Ƚ�
int precede(OP fore, OP back);
//��Ԫ����
ElemType Operate(ElemType fore_num, OP op, ElemType back_num);
//���ʽ��ֵ
ElemType EvaluateExpression();


/* �Թ���� ,0·����1ǽ��2�Ѿ��߹�
*********************************************************************/

#define HEIGHT 61
#define WIDTH 61
//�����ķ���
enum Direction
{
	up = 1,
	left,
	down,
	right
};

//�����Թ�λ��
typedef struct
{
	int x;
	int y;
	Direction dir;
}Pos;

void MazePath(int map[HEIGHT][WIDTH], Pos startPos, Pos endPos);


/*hanoi���ݹ�
*********************************************************************/

//nΪԲ��������x��ʼλ�ã�y����λ�ã�zĿ��λ��;��1��n-1�Ƶ�z
void Hanoi(int n, char x, char y, char z);
//�����Ϊn��Բ�̴�x�Ƶ�z
void move(char x, int n, char z);

#endif