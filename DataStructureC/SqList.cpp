
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
	puts("����La��Ԫ��: ");
	for (i = 1; i <= 4; i++)
	{
		scanf("%f", &e);
		ListInsert(&La, i, e);
	}
	puts("\n����Lb��Ԫ��: ");
	for (i = 1; i <= 7; i++)
	{
		scanf("%f", &e);
		ListInsert(&Lb, i, e);
	}

	Union(&La, Lb);  //�ϲ���

	puts("\n�ϲ���La��Ԫ����: ");
	for (i = 1; i <= La.length; i++)
	{
		GetElem(La, i, &e);
		printf("%.0f ", e);
	}
	puts("\n");

	//ɾ����������ֵ����mink��С��maxk��Ԫ��
	/*	DeleteBetween_min_max(&La, 2, 6);
	printf("%d",La.length);
	puts("\nLa��Ԫ����: ");
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
	//ɾ����������ֵ��ͬ�Ķ���Ԫ��
	/*	DeleteEqualElem(&La);

	printf("%d",La.length);
	puts("\nLa��Ԫ����: ");
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

//���������
Status InitList(SqList *L)  //��ʼ��һ��˳���
{
	L->list = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!(L->list))
		exit(INFEASIBLE);
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	return OK;
}

Status DestroyList(SqList *L) //����
{
	if (!(L->list))
		return INFEASIBLE;
	free(L->list);
	L->list = NULL;
	L->length = 0;
	L->listsize = 0;
	return OK;
}

int ListEmpty(SqList L) //�Ƿ�Ϊ�ձ�
{
	if (!(L.list))
		exit(INFEASIBLE);
	if (L.length == 0)
		return TRUE;
	else
		return FALSE;
}

Status ClearList(SqList *L)   //����Ϊ�ձ�
{
	if (!(L->list))
		exit(INFEASIBLE);
	L->length = 0;
	return OK;
}

int ListLength(SqList L) //����L��Ԫ�ظ���
{
	return L.length;
}

Status ListInsert(SqList *L, int i, ElemType e) //�����i��i>=1����Ԫ�أ��±�Ϊi-1
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

Status ListDelete(SqList *L, int i, ElemType* e)//ɾ����i��Ԫ�أ��±�Ϊi-1, ��e����
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

Status GetElem(SqList L, int i, ElemType *e) //����L��i��i>=1����Ԫ�أ��±�Ϊi-1
{
	if (ListEmpty(L))
		return INFEASIBLE;
	*e = *(L.list + i - 1);
	return OK;
}

Status NextElem(SqList L, ElemType cur_e, ElemType *next_e) //����cur_e�ĺ��
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

Status PriorElem(SqList L, ElemType cur_e, ElemType *pre_e) //����cur_e��ǰ��
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

Status DeleteBetween_min_max(SqList *L, ElemType mink, ElemType maxk)    //ɾ����������ֵ����mink��С��maxk��Ԫ��
{
	
}

void DeleteEqualElem(SqList *L) //ɾ����������ֵ��ͬ�Ķ���Ԫ��
{
	
}

void Union(SqList *La, SqList Lb)
{
	
}