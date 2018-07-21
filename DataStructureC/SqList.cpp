
#include <stdio.h>
#include <stdlib.h>
#include "SqList.h"



//初始化一个顺序表
Status InitList(SqList *L) 
{
	L->list = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!(L->list))
		exit(OVERFLOW);
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	return OK;
}
//销毁
Status DestroyList(SqList *L)
{
	if (!(L->list))
		return INFEASIBLE;
	free(L->list);
	L->list = NULL;
	L->length = 0;
	L->listsize = 0;
	return OK;
}
//是否为空表
int ListEmpty(SqList L)
{
	if (!(L.list))
		exit(INFEASIBLE);
	if (L.length == 0)
		return TRUE;
	else
		return FALSE;
}
//重置为空表
Status ClearList(SqList *L) 
{
	if (!(L->list))
		exit(INFEASIBLE);
	L->length = 0;
	return OK;
}
//返回L的元素个数
int ListLength(SqList L) 
{
	return L.length;
}
//插入第i（i>=1）个元素，下标为i-1
Status ListInsert(SqList *L, int i, ElemType e) 
{
	int n = L->length;
	if (i < 1 || i > n+1)
	{
		return ERROR;
	}
	if ( n >= L->listsize)
	{
		ElemType* p = (ElemType *)realloc(L->list, (L->listsize + LIST_INCREMENT) * sizeof(ElemType));
		if (p == NULL)
			return ERROR;
		L->list = p;
		L->listsize += LIST_INCREMENT;
	}
	for (; n >= i; n--)
		*(L->list + n) = *(L->list + n - 1);
	*(L->list + n) = e;
	L->length++;
	return OK;
}
//删除第i个元素，下标为i-1, 用e返回
Status ListDelete(SqList *L, int i, ElemType* e)
{
	if (L->length == 0)
		return INFEASIBLE;
	if (i < 1 || i > L->length)
		return OVERFLOW;
	*e = *(L->list + i - 1);
	for (int n = i; n < L->length; n++)
		*(L->list + n - 1) = *(L->list + n);
	L->length--;
	return OK;
}
 //遍历顺序表
Status ListTraverse(SqList L, void(*visit)(ElemType))
{
	if (!L.list)
		return INFEASIBLE;
	int n = ListLength(L);
	for (int i = 0; i < n; i++)
	{
		visit(*(L.list + i));
	}
}
//返回L第i（i>=1）个元素，下标为i-1
Status GetElem(SqList L, int i, ElemType *e)
{
	if (ListEmpty(L))
		return INFEASIBLE;
	if ( ListLength(L) < i || i < 1)
		return OVERFLOW;
	*e = *(L.list + i - 1);
	return OK;
}
//返回cur_e的后继
Status NextElem(SqList L, ElemType cur_e, ElemType *next_e) 
{
	ElemType t;
	int i;
	if (ListEmpty(L))
	{
		return INFEASIBLE;
	}
	for (i = 1; i < L.length; i++)
	{
		GetElem(L, i, &t);
		if (t == cur_e)
		{
			GetElem(L, i + 1, next_e);
			return OK;
		}
	}
	return OVERFLOW;
}
//返回cur_e的前驱
Status PriorElem(SqList L, ElemType cur_e, ElemType *pre_e)
{
	ElemType t;
	int i;
	if (ListEmpty(L))
		return INFEASIBLE;
	for (i = 2; i <= L.length; i++)
	{
		GetElem(L, i, &t);
		if (t == cur_e)
		{
			GetElem(L, i - 1, pre_e);
			return OK;
		}
	}
	return OVERFLOW;
}

int LocateElem(SqList L, ElemType e, bool (*func)(ElemType, ElemType))
{
	int j;
	for (j = 1; j <= L.length; j++)
		if (func(e, *(L.list + j)))
			return j;
	return 0;
}


//辅助函数
bool equal(ElemType ea, ElemType eb){
	if (ea == eb)
		return true;
	else
		return false;
}

// ------------------------   算法  -------------------------

/*将在Lb中不在La中的元素插入到La*/
void Union(SqList *La, SqList Lb)
{
	int La_len = ListLength(*La);
	int Lb_len = ListLength(Lb);
	ElemType e;
	for (int i = 1; i <= Lb_len; i++){
		GetElem(Lb, i, &e);
		if (!LocateElem(*La, e, equal))
			ListInsert(La, La_len, e);
	}
}

/*已知la和lb的元素按非递减排列
*归并la和lb到lc，lc也按非递减排列
*/
void MergeList(SqList La, SqList Lb, SqList &Lc)
{

}