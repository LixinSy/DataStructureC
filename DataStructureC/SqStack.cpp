//SqStack.cpp
#include<stdlib.h>
#include<stdio.h>
#include"SqStack.h"

//定义各个函数
void InitStack(SqStack *S)  //构造顺序栈
{
	S->base = (ElemType *)malloc(sizeof(ElemType)*(S->stacksize));
	if (!S->base)
	{
		exit(1);
	}
	S->top = S->base;
}

void DestroyStack(SqStack *S) //销毁
{
	if (S->base)
	{
		free(S->base);
		printf("已销毁顺序栈！\n");
	}
	else
	{
		printf("无顺序栈，无法销毁！\n");
	}
}

int StackEmpty(SqStack S)  //判断是否为空
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
		printf("无顺序栈，无法判断是否为空！\n");
		exit(1);
	}
}

int StackFull(SqStack S) //判断是否为满
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
		printf("无顺序栈，无法判断是否为满！\n");
		exit(1);
	}
}
void ClearStack(SqStack *S)  //清空栈
{
	if (!S->base)
	{
		printf("无顺序栈，无法清空栈！\n");
		return;
	}
	S->top = S->base;
}

int StackLength(SqStack S)  //返回栈元素个数,栈长度
{
	return S.top - S.base;
}

void Push(SqStack *S, ElemType e)  //压入栈
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

void Pop(SqStack *S, ElemType *e) //删除栈顶元素，用e返回
{
	if (StackEmpty(*S))
	{
		printf("栈空!\n");
		exit(2);
	}
	*e = *(S->top);
	S->top--;
}

void GetTop(SqStack S, ElemType *e)  //用e返回栈顶元素
{
	if (StackEmpty(S))
	{
		exit(1);
	}
	*e = *(S.top);
}
