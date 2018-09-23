
#ifndef SQ_LIST_H
#define SQ_LIST_H

#include "macro.h"

#define ElemType int
#define LIST_INIT_SIZE 100
#define LIST_INCREMENT 10

//����˳���
typedef struct
{
	ElemType *list;
	int length;
	int listsize;
}SqList;

//��������

Status InitList(SqList *L);  //��ʼ��һ��˳���
Status DestroyList(SqList *L); //����
int ListEmpty(SqList L); //�Ƿ�Ϊ�ձ�
Status ClearList(SqList *L);  //����Ϊ�ձ�
int ListLength(SqList L); //����L��Ԫ�ظ���
Status GetElem(SqList L, int i, ElemType *e); //����L��i��i>=1����Ԫ�أ��±�Ϊi-1
Status ListInsert(SqList *L, int i, ElemType e); //�����i��Ԫ�أ��±�Ϊi-1
Status ListDelete(SqList *L, int i, ElemType* e);//ɾ����i��Ԫ�أ� �±�Ϊi-1��, ��e����
Status ListTraverse(SqList L, Status(*visit)(ElemType)); //����˳���
Status NextElem(SqList L, ElemType cur_e, ElemType *next_e); //����cur_e�ĺ��
Status PriorElem(SqList L, ElemType cur_e, ElemType *pre_e); //����cur_e��ǰ��
int LocateElem(SqList L, ElemType e, bool (*func)(ElemType, ElemType));//�ж�e��L��Ԫ�صĹ�ϵ
int BinarySearch(SqList L, ElemType key);//�۰����

//------------------------------- �㷨 -------------------------------

/*����Lb�в���La�е�Ԫ�ز��뵽La*/
void Union(SqList *La, SqList Lb);

/*��֪la��lb��Ԫ�ذ��ǵݼ�����
 *�鲢la��lb��lc��lcҲ���ǵݼ�����
*/
void MergeList(SqList La, SqList Lb, SqList *Lc);

/*ɾ����������ֵΪx��Ԫ��
ʱ�临�Ӷ�O(n), �ռ临�Ӷ�O(1)*/
void DeleteElem(SqList *L, ElemType x);

/*ɾ����������ֵ����mink��С��maxk��Ԫ��*/
Status DeleteBetween_min_max(SqList *L, ElemType mink, ElemType maxk);    

/*ɾ����������ֵ��ͬ�Ķ���Ԫ��*/
void DeleteEqualElem(SqList *L); 

#endif

