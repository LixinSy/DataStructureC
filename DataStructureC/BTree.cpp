//BTree.cpp 主函数

#include "BTree.h"
#include <iostream>

//前序构造二叉树,空格为空结点
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
//左右根销毁二叉树
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

Status PreOrderTraverse(BTreeNode *T, Status(*visit)(TElemType)) //递归前序遍历二叉树
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
Status InOrderTraverse(BTreeNode *T, Status(*visit)(TElemType)); //递归中序遍历二叉树
Status PostOrderTraverse(BTreeNode *T, Status(*visit)(TElemType)); //递归后序遍历二叉树
Status LevelorderTraverse(BTreeNode *T, Status(*visit)(TElemType)); //递归层次遍历二叉树
Status RPreOrderTraverse(BTreeNode *T, Status(*visit)(TElemType)); //非递归前序遍历二叉树
Status RInOrderTraverse(BTreeNode *T, Status(*visit)(TElemType)) //非递归中序遍历二叉树
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
Status RPostOrderTraverse(BTreeNode *T, Status(*visit)(TElemType)); //非递归后序遍历二叉树
Status RLevelorderTraverse(BTreeNode *T, Status(*visit)(TElemType)); //非递归层次遍历二叉树