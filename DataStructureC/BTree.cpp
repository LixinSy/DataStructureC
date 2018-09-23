//BTree.cpp ������

#include "BTree.h"
#include <iostream>

//ǰ���������,�ո�Ϊ�ս��
BTreeNode* CreateBitTree() 
{
	TElemType e;
	BTreeNode *p;
	//std::cin>>e;
	scanf_s("%c", &e);
	if (e == ' ')
		return NULL;
	else{
		if (!(p = (BTreeNode *)malloc(sizeof(BTreeNode))))
			exit(ERROR);
		p->data = e;
		p->lchild = CreateBitTree();
		p->rchild = CreateBitTree();
	}
	return p;
}
//���Ҹ����ٶ�����
Status DestroyBitTree(BTreeNode *T)
{
	if (T){
		if (DestroyBitTree(T->lchild) && DestroyBitTree(T->rchild))
		{
			free(T);
			return OK;
		}
	}
	return OK;
}

Status PreOrderTraverse(BTreeNode *T, Status(*visit)(TElemType)) //�ݹ�ǰ�����������
{
	if (T){
		if (visit(T->data))
			if (PreOrderTraverse(T->lchild, visit))
				if (PreOrderTraverse(T->rchild, visit))
					return OK;
		return ERROR;
	}
	return OK;
}
Status InOrderTraverse(BTreeNode *T, Status(*visit)(TElemType)); //�ݹ��������������
Status PostOrderTraverse(BTreeNode *T, Status(*visit)(TElemType)); //�ݹ�������������
Status LevelorderTraverse(BTreeNode *T, Status(*visit)(TElemType)); //�ݹ��α���������
Status RPreOrderTraverse(BTreeNode *T, Status(*visit)(TElemType)); //�ǵݹ�ǰ�����������
Status RInOrderTraverse(BTreeNode *T, Status(*visit)(TElemType)) //�ǵݹ��������������
{
	/*
	SqStack S;
	BTreeNode *p = T;
	InitStack(&S);
	while (p || !StackEmpty(S)){
		if (p){
			Push(&S, p);
			p = p->lchild;
		}
		else{
			Pop(&S, &p);
			if (!visit(p->data))
				return ERROR;
			p = p->rchild;
		}
	}
	DestroyStack(&S);
	*/
	return OK;
}
Status RPostOrderTraverse(BTreeNode *T, Status(*visit)(TElemType)); //�ǵݹ�������������
Status RLevelorderTraverse(BTreeNode *T, Status(*visit)(TElemType)); //�ǵݹ��α���������