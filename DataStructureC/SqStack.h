
//SqStack.h

#define TRUE 1
#define FLASE 0
#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10
#define ElemType struct TreeNode*

#ifndef SQ_STACK_H
#define SQ_STACK_H
//定义顺序栈
typedef struct
{
	ElemType *base;
	ElemType *top;
	int stacksize;
}SqStack;

//函数声明
void InitStack(SqStack *S);  //构造顺序栈
void DestroyStack(SqStack *S); //销毁
int StackEmpty(SqStack S);  //判断是否为空
int StackFull(SqStack S); //判断是否为满
void ClearStack(SqStack *S);  //清空栈
int StackLength(SqStack S);  //返回栈元素个数
void Push(SqStack *S, ElemType e);  //压入栈
void Pop(SqStack *S, ElemType *e); //删除栈顶元素，用e返回
void GetTop(SqStack S, ElemType *e);  //用e返回栈顶元素

#endif