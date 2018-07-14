
#include <stdio.h>
#include <stdlib.h>
#include "SqList.h"

int test(ElemType e)
{
	int i;
	SqList La = { NULL, 0, 20 }, Lb = { NULL, 0, 20 };
	struct LNode *p;
	InitList(&La);
	InitList(&Lb);
	puts("输入La的元素: ");
	for (i = 1; i <= 4; i++)
	{
		scanf("%f", &e);
		ListInsert(&La, i, e);
	}
	puts("\n输入Lb的元素: ");
	for (i = 1; i <= 7; i++)
	{
		scanf("%f", &e);
		ListInsert(&Lb, i, e);
	}

	Union(&La, Lb);  //合并表

	puts("\n合并后La的元素有: ");
	for (i = 1; i <= La.length; i++)
	{
		GetElem(La, i, &e);
		printf("%.0f ", e);
	}
	puts("\n");

	//删除表中所有值大于mink且小于maxk的元素
	/*	DeleteBetween_min_max(&La, 2, 6);
	printf("%d",La.length);
	puts("\nLa的元素有: ");
	for(i = 1; i <= La.length; i++)
	{
	GetElem(La, i, &e);
	printf("%.0f ", e);
	}
	puts("\n");

	i=0;
	p = La.list;
	while( p)
	{
	i++;
	p = p->next;
	}
	printf("%d",i);*/
	//删除表中所有值相同的多余元素
	/*	DeleteEqualElem(&La);

	printf("%d",La.length);
	puts("\nLa的元素有: ");
	for(i = 1; i <= La.length; i++)
	{
	GetElem(La, i, &e);
	printf("%.0f ", e);
	}
	puts("\n");

	i=0;
	p = La.list;
	while( p)
	{
	i++;
	p = p->next;
	}
	printf("%d",i);*/

	DestroyList(&La);
	DestroyList(&Lb);
	return 0;
}

//定义各函数
Status InitList(SqList *L)  //初始化一个顺序表
{
	L->list = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!(L->list))
		exit(INFEASIBLE);
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	return OK;
}

Status DestroyList(SqList *L) //销毁
{
	if (!(L->list))
		return INFEASIBLE;
	free(L->list);
	L->list = NULL;
	L->length = 0;
	L->listsize = 0;
	return OK;
}

int ListEmpty(SqList L) //是否为空表
{
	if (!(L.list))
		exit(INFEASIBLE);
	if (L.length == 0)
		return TRUE;
	else
		return FALSE;
}

Status ClearList(SqList *L)   //重置为空表
{
	if (!(L->list))
		exit(INFEASIBLE);
	L->length = 0;
	return OK;
}

int ListLength(SqList L) //返回L的元素个数
{
	return L.length;
}

Status ListInsert(SqList *L, int i, ElemType e) //插入第i（i>=1）个元素，下标为i-1
{
	int n = L->length;
	if (i < 1 || i > n)
	{
		return OVERFLOW;
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

Status ListDelete(SqList *L, int i, ElemType* e)//删除第i个元素，下标为i-1, 用e返回
{
	if (ListEmpty(*L))
		return INFEASIBLE;
	if (i < 1 || i > L->length)
		return OVERFLOW;
	*e = *(L->list + i - 1);
	for (int n = i; n <= L->length; n++)
		*(L->list + n - 1) = *(L->list + n);
	L->length--;
	return OK;
}

Status GetElem(SqList L, int i, ElemType *e) //返回L第i（i>=1）个元素，下标为i-1
{
	if (ListEmpty(L))
		return INFEASIBLE;
	*e = *(L.list + i - 1);
	return OK;
}

Status NextElem(SqList L, ElemType cur_e, ElemType *next_e) //返回cur_e的后继
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

Status PriorElem(SqList L, ElemType cur_e, ElemType *pre_e) //返回cur_e的前驱
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

int LocateElem(SqList L, ElemType e, int(*fun)(ElemType, ElemType))
{
	int j;
	for (j = 1; j <= L.length; j++)
		if (fun(e, *(L.list + j)))
			return j;
}

Status DeleteBetween_min_max(SqList *L, ElemType mink, ElemType maxk)    //删除表中所有值大于mink且小于maxk的元素
{
	
}

void DeleteEqualElem(SqList *L) //删除表中所有值相同的多余元素
{
	
}

void Union(SqList *La, SqList Lb)
{
	
}