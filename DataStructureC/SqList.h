
#ifndef SQ_LIST_H
#define SQ_LIST_H


	#define ElemType int

	#ifndef LIST_INIT_SIZE
	#define LIST_INIT_SIZE 100
	#endif

	#ifndef LIST_INCREMENT
	#define LIST_INCREMENT 10
	#endif

#define  TRUE			1#define  FALSE			0#define  OK				1#define  ERROR			0#define  INFEASIBLE		-1#define  OVERFLOW		-2typedef   int  Status;

//定义顺序表
typedef struct
{
	ElemType *list;
	int length;
	int listsize;
}SqList;


//函数声明
Status InitList(SqList *L);  //初始化一个顺序表
Status DestroyList(SqList *L); //销毁
int ListEmpty(SqList L); //是否为空表
Status ClearList(SqList *L);  //重置为空表
int ListLength(SqList L); //返回L的元素个数
Status GetElem(SqList L, int i, ElemType *e); //返回L第i（i>=1）个元素，下标为i-1
Status NextElem(SqList L, ElemType cur_e, ElemType *next_e); //返回cur_e的后继
Status PriorElem(SqList L, ElemType cur_e, ElemType *pre_e); //返回cur_e的前驱
int LocateElem(SqList L, ElemType e, int(*fun)(ElemType, ElemType));//判断e和L的元素的关系
Status ListInsert(SqList *L, int i, ElemType e); //插入第i个元素，下标为i-1
Status ListDelete(SqList *L, int i, ElemType* e);//删除第i个元素， 下标为i-1，, 用e返回
Status ListTraverse(SqList L, void(*visit)(void)); //

void Union(SqList *La, SqList Lb);
Status DeleteBetween_min_max(SqList *L, ElemType mink, ElemType maxk);    //删除表中所有值大于mink且小于maxk的元素
void DeleteEqualElem(SqList *L); //删除表中所有值相同的多余元素

#endif

