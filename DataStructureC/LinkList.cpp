
#include "LinkList.h"


//��ʼ��һ��˳���
Status InitList(LinkList *L)
{
	L->head = NULL;
	L->tail = NULL;
	L->length = 0;
	return OK;
}
//����
Status DestroyList(LinkList *L)
{
	return ClearList(L);
}
//�Ƿ�Ϊ�ձ�
int ListEmpty(LinkList L)
{

	if (L.length == 0)
		return TRUE;
	else
		return FALSE;
}
//����Ϊ�ձ�
Status ClearList(LinkList *L)
{
	struct LNode *pt = L->head, *p = NULL;
	if (!(L->head))
		return INFEASIBLE;
	for (; pt;)
	{
		p = pt;
		pt = pt->next;
		free(p);
	}
	L->head = NULL;
	L->tail = NULL;
	L->length = 0;
	return OK;
}
//����L��Ԫ�ظ���
int ListLength(LinkList L)
{
	return L.length;
}
//�����i��i>=1����Ԫ��
Status ListInsert(LinkList *L, int i, ElemType e)
{
	int j, n = L->length;
	LNode *pt = L->head, *p = NULL;

	if (i < 1 || i > n + 1)
		return OVERFLOW;

	if (i==1){
		p = (LNode*)malloc(sizeof(LNode));
		if (!p)
			return ERROR;
		p->data = e;
		L->head = p;
		p->next = pt;
		L->length++;
		return OK;
	}
	for (j = 1; j < i-1; j++)
	{
		pt = pt->next;
	}
	p = (LNode*)malloc(sizeof(LNode));
	if (!p)
		return ERROR;
	p->data = e;
	p->next = pt->next;
	pt->next = p;
	L->length++;
	return OK;
}
//ɾ����i��Ԫ��, ��e����
Status ListDelete(LinkList *L, int i, ElemType* e)
{
	LNode *pt = L->head, *p = NULL;
	if (i == 1){
		p = L->head;
		*e = p->data;
		L->head = L->head->next;
		free(p);
		L->length--;
		return OK;
	}
	for (int j = 1; j < i-1; j++)
	{
		pt = pt->next;
	}
	p = pt->next;
	*e = p->data;
	pt->next = p->next;
	free(p);
	L->length--;
	return OK;
}
//����˳���
Status ListTraverse(LinkList L, void(*visit)(ElemType))
{
	for (LNode* p = L.head; p; p = p->next){
		visit(p->data);
	}
	printf("; %d��Ԫ��\n", L.length);
	return OK;
}
//����L��i��i>=1����Ԫ��
Status GetElem(LinkList L, int i, ElemType *e)
{
	if (!L.head)
		return INFEASIBLE;
	if (i < 1 || i > L.length)
		return OVERFLOW;
	LNode* p = L.head;
	for (int j = 1; j < i; i++){
		p = p->next;
	}
	*e = p->data;
	return OK;
}
//����cur_e�ĺ��
Status NextElem(LinkList L, ElemType cur_e, ElemType *next_e)
{

	for (LNode* p = L.head; p; p = p->next){
		if (p->data == cur_e && p->next){
			*next_e = p->next->data;
			return OK;
		}
	}
	return INFEASIBLE;
}
//����cur_e��ǰ��
Status PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e)
{
	LNode* pt = L.head;
	for (LNode* p = pt->next; p; pt = pt->next, p = pt->next){
		if (p->data == cur_e){
			*pre_e = pt->data;
			return OK;
		}
	}
	return INFEASIBLE;
}

int LocateElem(LinkList L, ElemType e, bool (*func)(ElemType, ElemType))
{
	int i = 0;
	for (LNode* p = L.head; p; p = p->next){
		i++;
		if (func(e, p->data))
			return i;
	}
	return 0;
}



//������pָ���ֵΪe�Ľ�㣬������OK������ʧ�ܷ���ERROR
Status MakeNode(LNode *p, ElemType e){
	p = (LNode*)malloc(sizeof(LNode));
	if (!p)
		return ERROR;
	p->data = e;
	return OK;
}
//�ͷ�p��ָ���
void freeNode(LNode *p)
{
	free(p);
	p = NULL;
}
//��node�����һ�����֮ǰ
Status InsertFirst(LNode *head, LNode *node)
{

	return OK;
}
//p����L�� ��s����p֮ǰ
Status InsertBefore(LinkList *L, LNode *p, LNode *s)
{
	return OK;
}
//p����L�� ��s����p֮��
Status InsertAfter(LinkList *L, LNode *p, LNode *s)
{
	return OK;
}
//��ĩβ���p
Status Append(LinkList *L, LNode *p)
{
	L->tail->next = p;
	p->next = NULL;
	return OK;
}
//ɾ����һ����㣬��q����
Status DeleteFirst(LNode *head, LNode *q)
{
	return OK;
}
//ɾ��ĩβ��㣬��q����
Status Remove(LinkList *L, LNode *q)
{
	return OK;
}