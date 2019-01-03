//BTree.cpp ������

#include "BTree.h"
#include <stack>
#include <queue>
#include <string>

//��ι��������
BTreeNode* CreateBitTree()
{
	puts("���˳������ڵ㣺");
	TElemType e;
	TElemType non = '#';
	BTreeNode *T=NULL, *p = NULL, *l = NULL, *r = NULL;
	std::queue<BTreeNode*> q;
	e = getchar();
	if (e == non)
		return NULL;
	else{
		if (!(T = (BTreeNode *)malloc(sizeof(BTreeNode))))
			exit(ERROR);
		T->data = e;
		q.push(T);
		while (!q.empty()){

			//����
			e = getchar();
			if (e == non)
				l = NULL;
			else{
				if (!(l = (BTreeNode *)malloc(sizeof(BTreeNode))))
					exit(ERROR);
				l->data = e;
				q.push(l);
			}
			//�Һ���
			e = getchar();
			if (e == non)
				r = NULL;
			else{
				if (!(r = (BTreeNode *)malloc(sizeof(BTreeNode))))
					exit(ERROR);
				r->data = e;
				q.push(r);
			}
			p = q.front(); q.pop();
			p->lchild = l;
			p->rchild = r;
		}
	}
	return T;
}

//�������������
BTreeNode* CreateBitSortTree()
{
	BTreeNode *T = NULL, *p = NULL, *pt = NULL, *newNode = NULL;
	int val;
	int arr[] = { 5, 7, 12, 4, 17, 2, 1, 10 };
	std::vector<int> datas(arr, arr+8);
	if (datas.size() == 0)
		return NULL;
	if (!(T = (BTreeNode *)malloc(sizeof(BTreeNode))))
		exit(ERROR);
	T->data = datas[0]; T->lchild = T->rchild = NULL;

	for (int i = 1; i < datas.size(); i++){
		val = datas[i];
		if (!(newNode = (BTreeNode *)malloc(sizeof(BTreeNode))))
			exit(ERROR);
		newNode->data = val; newNode->lchild = newNode->rchild = NULL;
		pt = T;
		while (pt){
			p = pt;
			if (val < pt->data)
				pt = pt->lchild;
			else if (val > pt->data)
				pt = pt->rchild;
		}
		if (val < p->data)
			p->lchild = newNode;
		else if (val > p->data)
			p->rchild = newNode;
	}
	return T;
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
//�ݹ�ǰ�����������
Status PreOrderTraverse(BTreeNode *T, Status(*visit)(TElemType)) 
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
//�ݹ��������������
Status InOrderTraverse(BTreeNode *T, Status(*visit)(TElemType))
{
	if (T){
		if (InOrderTraverse(T->lchild, visit))
			if (visit(T->data))
				if (InOrderTraverse(T->rchild, visit))
					return OK;
		return ERROR;
	}
	return OK;
}

//�ݹ�������������
Status PostOrderTraverse(BTreeNode *T, Status(*visit)(TElemType))
{
	if (T){
		if (PostOrderTraverse(T->lchild, visit))
			if (PostOrderTraverse(T->rchild, visit))
				if (visit(T->data))
					return OK;
		return ERROR;
	}
	return OK;
}

Status LevelorderTraverse(BTreeNode *T, Status(*visit)(TElemType)); //�ݹ��α���������

//�ǵݹ�ǰ�����������
Status RPreOrderTraverse(BTreeNode *T, Status(*visit)(TElemType))
{
	BTreeNode *p = T;
	std::stack<BTreeNode*> s;
	while (p || !s.empty()){
		if (p){
			if (!visit(p->data))
				return ERROR;
			s.push(p->rchild);
			s.push(p->lchild);
		}
		p = s.top(); s.pop();
	}
	return OK;
}
//�ǵݹ��������������
Status RInOrderTraverse(BTreeNode *T, Status(*visit)(TElemType))
{
	std::stack<BTreeNode *> S;
	BTreeNode *p = T;

	while (p || !S.empty()){
		if (p){
			S.push(p);
			p = p->lchild;
		}
		else{
			p = S.top(); S.pop();
			if (!visit(p->data))
				return ERROR;
			p = p->rchild;
		}
	}
	return OK;
}


Status RPostOrderTraverse(BTreeNode *T, Status(*visit)(TElemType)) //�ǵݹ�������������
{

	return OK;
}

//�ǵݹ��α���������
Status RLevelorderTraverse(BTreeNode *T, Status(*visit)(TElemType))
{
	std::queue<BTreeNode*> q;
	BTreeNode *p = NULL;
	q.push(T);
	while (!q.empty()){
		p = q.front(); q.pop();
		if (p){
			if (!visit(p->data))
				return ERROR;
			q.push(p->lchild);
			q.push(p->rchild);
		}
		else{
			//putchar('#');
		}
	}
	return OK;
}
//������������
int Deep(BTreeNode *T)
{
	int n;
	if (!T)
		return 0;
	else{
		n = Deep(T->lchild) > Deep(T->rchild) ? Deep(T->lchild) : Deep(T->rchild);
		return n + 1;
	}
}