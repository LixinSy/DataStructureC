
#ifndef BIT_TREE_H
#define BIT_TREE_H

#include "macro.h"
#include "SqStack.h"

#define TElemType char

/**************************** ������ ***************************/

//�������ڵ�
typedef struct BTreeNode
{
	TElemType data;
	BTreeNode *lchild;
	BTreeNode *rchild;
}BTreeNode;

//����������

BTreeNode* CreateBitTree(); //ǰ���������
Status DestroyBitTree(BTreeNode *T); //���ٶ�����
Status PreOrderTraverse(BTreeNode *T, Status (*visit)(TElemType)); //�ݹ�ǰ�����������
Status InOrderTraverse(BTreeNode *T, Status(*visit)(TElemType)); //�ݹ��������������
Status PostOrderTraverse(BTreeNode *T, Status(*visit)(TElemType)); //�ݹ�������������
Status LevelorderTraverse(BTreeNode *T, Status(*visit)(TElemType)); //�ݹ��α���������
Status RPreOrderTraverse(BTreeNode *T, Status(*visit)(TElemType)); //�ǵݹ�ǰ�����������
Status RInOrderTraverse(BTreeNode *T, Status(*visit)(TElemType)); //�ǵݹ��������������
Status RPostOrderTraverse(BTreeNode *T, Status(*visit)(TElemType)); //�ǵݹ�������������
Status RLevelorderTraverse(BTreeNode *T, Status(*visit)(TElemType)); //�ǵݹ��α���������

/**************************** ���������� ***************************/

typedef enum Tag
{
	Link, //ָ��
	Thread //����
};

//�����������ڵ�
typedef struct BiThrNode
{
	TElemType data;
	Tag LTag, RTag;
	BiThrNode *lchild, *rchild;
}BiThrNode;


/**************************** ����˫�ױ�ʾ�� ***************************/

#define MAX_TREE_SIZE 100
typedef struct PTNode //���Ľ��
{
	TElemType data;
	int parent;
}PTNode;

typedef struct		//��
{
	PTNode nodes[MAX_TREE_SIZE];
	int root, num;
}PTree;

/**************************** ���ĺ��ӱ�ʾ�� ***************************/

typedef struct CTNode //���ӽ��
{
	int child; //����λ����
	CTNode *next;
}CTNode;

typedef struct  //���Ľ��
{
	TElemType data;
	CTNode *firstChild;
}CTBox;

typedef struct //��
{
	CTBox nodes[MAX_TREE_SIZE];
	int root, num;
}CTree;

/**************************** ���ĺ����ֵܱ�ʾ�� ***************************/

typedef struct CSNode  //���Ľ��
{
	TElemType data;
	CSNode *firstChild;
	CSNode *nextSibling;
}CSNode;


/**************************** �շ������ͺշ�������Ĵ洢��ʾ ***************************/

#define NS 10  //Ҷ�ӽ����Ϊ NS���ܽ�� 2 * NS -1

typedef struct  //���
{
	unsigned int weight;
	unsigned int parent, lchild, rchild;
}HTNode;

//HTNode huffmanTree[2 * NS - 1];

#endif