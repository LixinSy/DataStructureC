
#include "SqList.h"


//��ʼ��һ��˳���
Status InitList(SqList *L) 
{
	L->list = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!(L->list))
        exit(ERROR);
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	return OK;
}
//����
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
//�Ƿ�Ϊ�ձ�
int ListEmpty(SqList L)
{
	if (!(L.list))
		exit(INFEASIBLE);
	if (L.length == 0)
		return TRUE;
	else
		return FALSE;
}
//����Ϊ�ձ�
Status ClearList(SqList *L) 
{
	if (!(L->list))
		exit(INFEASIBLE);
	L->length = 0;
	return OK;
}
//����L��Ԫ�ظ���
int ListLength(SqList L) 
{
	return L.length;
}
//�����i��i>=1����Ԫ�أ��±�Ϊi-1
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
//ɾ����i��Ԫ�أ��±�Ϊi-1, ��e����
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
 //����˳���
Status ListTraverse(SqList L, Status(*visit)(ElemType))
{
	if (!L.list)
		return INFEASIBLE;
	int n = ListLength(L);
	for (int i = 0; i < n; i++)
	{
		visit(*(L.list + i));
	}
	printf("\n");
	return OK;
}
//����L��i��i>=1����Ԫ�أ��±�Ϊi-1
Status GetElem(SqList L, int i, ElemType *e)
{
	if (ListEmpty(L))
		return INFEASIBLE;
	if ( ListLength(L) < i || i < 1)
		return OVERFLOW;
	*e = *(L.list + i - 1);
	return OK;
}
//����cur_e�ĺ��
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
//����cur_e��ǰ��
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

//�۰����
int BinarySearch(SqList L, ElemType key)
{
	ElemType e;
	int low, high, mid;
	low = 1, high = L.length;
	while (low <= high){
		mid = (low + high) / 2;
		GetElem(L, mid, &e);
		if (e == key)
			return mid;
		else if (key < e)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return 0;
}

//��������
bool equal(ElemType ea, ElemType eb){
	if (ea == eb)
		return true;
	else
		return false;
}

// ------------------------   �㷨  -------------------------

/*����Lb�в���La�е�Ԫ�ز��뵽La*/
void Union(SqList *La, SqList Lb)
{
	int La_len = ListLength(*La);
	int Lb_len = ListLength(Lb);
	ElemType e;
	for (int i = 1; i <= Lb_len; i++){
		GetElem(Lb, i, &e);
		if (!LocateElem(*La, e, equal))
			ListInsert(La, ++La_len, e);
	}
}

/*��֪la��lb��Ԫ�ذ��ǵݼ�����
 �鲢la��lb��lc��lcҲ���ǵݼ�����
*/
void MergeList(SqList La, SqList Lb, SqList *Lc)
{

	int la_len = ListLength(La);
	int lb_len = ListLength(Lb);
	int i = 1, j = 1, k = 1;
	ElemType ea, eb;
	for (; i <= la_len && j <= lb_len; k++){
		GetElem(La, i, &ea);
		GetElem(Lb, j, &eb);
		if (ea < eb){
			ListInsert(Lc, k, ea);
			i++;
		}
		else{
			ListInsert(Lc, k, eb);
			j++;
		}
	}
	while (i <= la_len)
	{
		GetElem(La, i, &ea);
		ListInsert(Lc, k, ea);
		k++;
		i++;
	}
	while (j <= lb_len)
	{
		GetElem(Lb, j, &eb);
		ListInsert(Lc, k, eb);
		k++;
		j++;
	}
}

/*ɾ����������ֵΪx��Ԫ��
ʱ�临�Ӷ�O(n), �ռ临�Ӷ�O(1)*/
void DeleteElem(SqList *L, ElemType x){
	int len = ListLength(*L);
	int delNum = 0;
	ElemType e;
	for (int i = 0; i < len; i++){
		e = *(L->list + i);
		if (e == x ){
			delNum++;
		}
		else if (delNum > 0){
			*(L->list + i - delNum) = *(L->list + i);
		}
	}
	L->length -= delNum;
}
