
#ifndef LINK_LIST_H
#define LINK_LIST_H

#include "macro.h"

#define MAX_SIZE 100
#define ElemType int

//������
typedef struct  LNode
{
	ElemType data;
	LNode *next;
}LNode, pos;

//������
typedef struct
{
	LNode *head;
	LNode *tail;
	int length;
}LinkList;

//------------------------------  �������� ----------------------------

Status InitList(LinkList *L);  //��ʼ��һ����
Status DestroyList(LinkList *L); //����
int ListEmpty(LinkList L); //�Ƿ�Ϊ�ձ�
Status ClearList(LinkList *L);  //����Ϊ�ձ�
int ListLength(LinkList L); //����L��Ԫ�ظ���
Status GetElem(LinkList L, int i, ElemType *e); //����L��i��i>=1����Ԫ��
Status ListInsert(LinkList *L, int i, ElemType e); //�����i��Ԫ�أ�
Status ListDelete(LinkList *L, int i, ElemType* e);//ɾ����i��Ԫ�أ�  ��e����
Status ListTraverse(LinkList L, void(*visit)(ElemType)); //����˳���
Status NextElem(LinkList L, ElemType cur_e, ElemType *next_e); //����cur_e�ĺ��
Status PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e); //����cur_e��ǰ��
int LocateElem(LinkList L, ElemType e, bool (*func)(ElemType, ElemType));//�ж�e��L��Ԫ�صĹ�ϵ


Status MakeNode(LNode &p, ElemType e); //������pָ���ֵΪe�Ľ�㣬������OK������ʧ�ܷ���ERROR
void freeNode(LNode &p); //�ͷ�p��ָ���
Status InsertFirst(LNode *head, LNode *node); //��node�����һ�����֮ǰ
Status InsertBefore(LinkList *L, LNode *p, LNode *s); //p����L�� ��s����p֮ǰ
Status InsertAfter(LinkList *L, LNode *p, LNode *s); //p����L�� ��s����p֮��
Status Append(LinkList *L, LNode *p); //��ĩβ���p
Status DeleteFirst(LNode *head, LNode *q); //ɾ����һ����㣬��q����
Status Remove(LinkList *L, LNode *q); //ɾ��ĩβ��㣬��q����


//------------------------------- �㷨 -------------------------------

/*����Lb�в���La�е�Ԫ�ز��뵽La*/
void Union(LinkList *La, LinkList Lb);

/*��֪la��lb��Ԫ�ذ��ǵݼ�����
*�鲢la��lb��lc��lcҲ���ǵݼ�����
*/
void MergeList(LinkList La, LinkList Lb, LinkList *Lc);

/*ɾ����������ֵ����mink��С��maxk��Ԫ��*/
Status DeleteBetween_min_max(LinkList *L, ElemType mink, ElemType maxk);

//ɾ����������ֵ��ͬ�Ķ���Ԫ��*/
void DeleteEqualElem(LinkList *L);

#endif


