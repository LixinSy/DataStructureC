//SqStack.cpp
#include<stdlib.h>
#include<stdio.h>
#include"SqStack.h"

//�����������
void InitStack(SqStack *S)  //����˳��ջ
{
	S->base = (ElemType *)malloc(sizeof(ElemType)*(S->stacksize));
	if (!S->base)
	{
		exit(1);
	}
	S->top = S->base;
}

void DestroyStack(SqStack *S) //����
{
	if (S->base)
	{
		free(S->base);
		printf("������˳��ջ��\n");
	}
	else
	{
		printf("��˳��ջ���޷����٣�\n");
	}
}

int StackEmpty(SqStack S)  //�ж��Ƿ�Ϊ��
{
	if (S.base)
	{
		if (S.top == S.base)
		{
			return TRUE;
		}
		else
		{
			return FLASE;
		}
	}
	else
	{
		printf("��˳��ջ���޷��ж��Ƿ�Ϊ�գ�\n");
		exit(1);
	}
}

int StackFull(SqStack S) //�ж��Ƿ�Ϊ��
{
	if (S.base)
	{
		if (S.top - S.base >= S.stacksize)
		{
			return TRUE;
		}
		else
		{
			return FLASE;
		}
	}
	else
	{
		printf("��˳��ջ���޷��ж��Ƿ�Ϊ����\n");
		exit(1);
	}
}
void ClearStack(SqStack *S)  //���ջ
{
	if (!S->base)
	{
		printf("��˳��ջ���޷����ջ��\n");
		return;
	}
	S->top = S->base;
}

int StackLength(SqStack S)  //����ջԪ�ظ���,ջ����
{
	return S.top - S.base;
}

void Push(SqStack *S, ElemType e)  //ѹ��ջ
{
	if (StackFull(*S))
	{
		S->base = (ElemType *)realloc(S->base, sizeof(ElemType)*(S->stacksize + STACKINCREMENT));
		if (!S->base)
		{
			exit(2);
		}
		S->top = S->stacksize + S->base;
		S->stacksize += STACKINCREMENT;
	}
	S->top++;
	*(S->top) = e;

}

void Pop(SqStack *S, ElemType *e) //ɾ��ջ��Ԫ�أ���e����
{
	if (StackEmpty(*S))
	{
		printf("ջ��!\n");
		exit(2);
	}
	*e = *(S->top);
	S->top--;
}

void GetTop(SqStack S, ElemType *e)  //��e����ջ��Ԫ��
{
	if (StackEmpty(S))
	{
		exit(1);
	}
	*e = *(S.top);
}
