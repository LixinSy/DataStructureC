
#ifndef SQ_LIST_H
#define SQ_LIST_H


	#define ElemType int

	#ifndef LIST_INIT_SIZE
	#define LIST_INIT_SIZE 100
	#endif

	#ifndef LIST_INCREMENT
	#define LIST_INCREMENT 10
	#endif

#define  TRUE			1
#define  FALSE			0
#define  OK				1
#define  ERROR			-1
#define  INFEASIBLE		-1
#define  OVERFLOW		-2

typedef   int  Status;

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
Status ListTraverse(SqList L, void(*visit)(ElemType)); //����˳���
Status NextElem(SqList L, ElemType cur_e, ElemType *next_e); //����cur_e�ĺ��
Status PriorElem(SqList L, ElemType cur_e, ElemType *pre_e); //����cur_e��ǰ��
int LocateElem(SqList L, ElemType e, bool (*func)(ElemType, ElemType));//�ж�e��L��Ԫ�صĹ�ϵ

//------------------------------- �㷨 -------------------------------

/*����Lb�в���La�е�Ԫ�ز��뵽La*/
void Union(SqList *La, SqList Lb);

/*��֪la��lb��Ԫ�ذ��ǵݼ�����
 *�鲢la��lb��lc��lcҲ���ǵݼ�����
*/
void MergeList(SqList La, SqList Lb, SqList &Lc);

/*ɾ����������ֵ����mink��С��maxk��Ԫ��*/
Status DeleteBetween_min_max(SqList *L, ElemType mink, ElemType maxk);    

//ɾ����������ֵ��ͬ�Ķ���Ԫ��*/
void DeleteEqualElem(SqList *L); 

#endif

