//SqStack.cpp

#include"SqStack.h"

/*----------------------------------- ����������� -------------------------------*/

//����˳��ջ
Status InitStack(SqStack *S)
{
	S->base = (ElemType *)malloc(sizeof(ElemType)*(STACK_INIT_SIZE));
	if (!S->base)
		exit(ERROR);
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;
}
//����
Status DestroyStack(SqStack *S)
{
	if (!S->base)
		return INFEASIBLE;
	free(S->base);
	S->base = NULL;
	S->top = NULL;
	S->stacksize = 0;
	return OK;
}
//�ж��Ƿ�Ϊ��
Status StackEmpty(SqStack S)
{
	if (S.base == S.top)
		return TRUE;
	else
		return FALSE;
}
//���ջ
Status ClearStack(SqStack *S)
{
	if (!S->base)
		return INFEASIBLE;
	S->top = S->base;
	return OK;
}
//����ջԪ�ظ���,ջ����
int StackLength(SqStack S) 
{
	return S.top - S.base;
}
//ѹ��ջ
Status Push(SqStack *S, ElemType e)
{
	if (S->top - S->base >= S->stacksize)
	{
		S->base = (ElemType *)realloc(S->base, sizeof(ElemType)*(S->stacksize + STACK_INCREMENT));
		if (!S->base)
			exit(ERROR);
		S->top = S->stacksize + S->base;
		S->stacksize += STACK_INCREMENT;
	}
	*(S->top) = e;
	S->top++;
	return OK;
}
//ɾ��ջ��Ԫ�أ���e����
Status Pop(SqStack *S, ElemType *e) 
{
	if (S->base == S->top)
		return INFEASIBLE;
	S->top--;
	*e = *(S->top);
	return OK;
}
//��e����ջ��Ԫ��
Status GetTop(SqStack S, ElemType *e)  
{
	if (S.base == S.top)
		return INFEASIBLE;
	*e = *(S.top);
	return OK;
}
//����ջ
Status StackTraverse(SqStack S, Status (*func)(ElemType))
{
	ElemType *p;
	for (p = S.base; p != S.top; p++){
		func(*p);
	}
	printf("; %d��Ԫ��\n", S.top - S.base);
	return OK;
}

//------------------- �������� ---------------------

Status visit(ElemType e){
	printf("%c", e);
	return OK;
}

//------------------- �㷨 --------------------------

/*��ֵת���� ʮ����N������d���Ƶ�ת����N = (N div d) * d + N mod d; divΪ������ mod���ࡣ
��������Ǹ�ʮ���ƣ����d����
**************************************************************************/
void Conversion(unsigned int N, unsigned int d){
	ElemType e;
	SqStack s;
	InitStack(&s);

	while (N){
		Push(&s, N % d);
		N = N / d;
	}
	while (!StackEmpty(s)){
		Pop(&s, &e);
		printf("%d", e);
	}
	printf("\n");
	DestroyStack(&s);
}

/*����ƥ��
***********************************************************************/
void BracketMatch(){
	typedef struct Bracket{
		char left;
		char right;
	}Bracket;

	ElemType e;
	SqStack s;
	InitStack(&s);
	
	DestroyStack(&s);
}

/*�б༭��#�˸� @����
***********************************************************************/
void LineEdit(){
	ElemType ch, e;
	SqStack s;
	InitStack(&s);
	ch = getchar();
	while (ch != EOF){
		while (ch != EOF && ch != '\n'){
			switch (ch)
			{
			case '#': 
				Pop(&s, &e);
				break;
			case '@':
				ClearStack(&s);
				break;
			default:
				Push(&s, ch);
				break;
			}
			ch = getchar();
		}
		StackTraverse(s, visit);
		ClearStack(&s);
		if (ch != EOF)
			ch = getchar();
	}

	DestroyStack(&s);
}

/*���ʽ��ֵ��
1���ȳ˳���Ӽ�
2��������
3���������ڣ���������
***********************************************************************/

//��������ȼ��Ƚ�
int precede(OP fore, OP back){
	return 0;
}
//��Ԫ����
ElemType Operate(ElemType fore_num, OP op, ElemType back_num){
	return fore_num;
}
//���ʽ��ֵ
ElemType EvaluateExpression(){
	ElemType e='\0';
	return e;
}

/*�Թ����
***********************************************************************/
void MazePath(int map[HEIGHT][WIDTH], Pos startPos, Pos endPos){

}

/*hanoi���ݹ�
*********************************************************************/

//nΪԲ��������x��ʼλ�ã�y����λ�ã�zĿ��λ��;��1��n-1�Ƶ�z
void Hanoi(int n, char x, char y, char z){
	if (n == 1){
		move(x, 1, z);
	}
	else{
		Hanoi(n - 1, x, z, y);
		move(x, n, z);
		Hanoi(n - 1, y, x, z);
	}
}
//�����Ϊn��Բ�̴�x�Ƶ�z
void move(char x, int n, char z){
	static int i = 0;
	printf("%d: �����Ϊ %d ��Բ�̴� %c �Ƶ� %c\n", ++i, n, x, z);
}