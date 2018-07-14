#include<stdio.h>
#include<iostream>
#include<vector>
#include<stdlib.h>
#define  ElemType int
#define MAXSIZE 100
using namespace std;

typedef struct  //��Ԫ��
{
	ElemType e;
	int i;
	int j;
}Triple;

typedef struct  //ѹ������
{
	Triple data[MAXSIZE + 1];
	int mu, nu, tu;
}TSMatrix;

//��������
void scan(TSMatrix *M);   //����ѹ������
void print(TSMatrix *M);   //���ѹ������
Triple getELem(TSMatrix M, int i, int j);  //����Ԫ��
void changeElem(TSMatrix *M, int i, int j, ElemType e); //�ı�Ԫ��ֵ
void TransposeTSMatrix(TSMatrix M, TSMatrix *T);	 //ϡ������ת��
void FastTransposeTSMatrix(TSMatrix M, TSMatrix *T); //ϡ��������ת��

int main()     //������
{
	TSMatrix M, T;
	int i = 4, j = 5;
	M.mu = 4;
	M.nu = 5;
	M.tu = 4;
	scan(&M);
	//printf("M(%d, %d) = %d\n",i, j, getELem(M,i,j).e );
	//changeElem(&M, i, j, 22);
	//print(&M);
	//TransposeTSMatrix(M, &T);
	FastTransposeTSMatrix(M, &T);
	print(&T);
	system("pause");
	return 0;
}

//���������
void scan(TSMatrix *M)   ////����ѹ������
{
	int n;
	for (n = 1, M->tu = 0; ; n++)
	{
		cin>>M->data[n].e>>M->data[n].i>> M->data[n].j;
		//����0 0 0��ʾ��������
		if (M->data[n].e == 0 && M->data[n].i == 0 && M->data[n].j == 0)
		{
			break;
		}
		M->tu++;
	}
}

void print(TSMatrix *M)   //���ѹ������
{
	int n;
	for (n = 1; n <= M->tu; n++)
	{
		printf("%4d %d %d\n", M->data[n].e, M->data[n].i, M->data[n].j);
	}
}

Triple getELem(TSMatrix M, int i, int j)  ////����Ԫ��
{
	Triple zero = { 0, i, j };
	int n;
	if (i<1 || i>M.mu || j < 1 || j > M.nu)
	{
		exit(1);
	}
	for (n = 1; n <= M.tu; n++)
	{
		if (M.data[n].i == i && M.data[n].j == j)
		{
			return M.data[n];
		}
	}
	return zero;
}

void changeElem(TSMatrix *M, int i, int j, ElemType e)	//�ı�Ԫ��ֵ
{
	int n, k = 0;
	if (i<1 || i>M->mu || j < 1 || j > M->nu)
	{
		printf("error");
		return;
	}
	for (n = 1; n <= M->tu; n++)
	{
		if (M->data[n].i == i)
		{
			if (M->data[n].j == j)
			{
				M->data[n].e = e;
				return;
			}
			else if (M->data[n].j > j)
			{
				k = n;
				break;
			}
			else
			{
				k = n + 1;
				if (M->data[n + 1].i != i)
				{
					break;
				}
			}
		}
		else if (M->data[n].i > i)
		{
			k = n;
			break;
		}
	}
	M->tu ++;
	for (n = M->tu; n != k; n--)
	{
		M->data[n] = M->data[n - 1];
	}
	M->data[n].e = e;
	M->data[n].i = i;
	M->data[n].j = j;
}

void TransposeTSMatrix(TSMatrix M, TSMatrix *T) //ϡ������ת��
{
	int p, col, q = 1;
	if (!M.tu)
	{
		return;
	}
	T->mu = M.nu;
	T->nu = M.mu;
	T->tu = M.tu;
	for (col = 1; col <= M.nu; col++)
	{
		for (p = 1; p <= M.tu; p++)
		{
			if (col == M.data[p].j)
			{
				T->data[q].i = M.data[p].j;
				T->data[q].j = M.data[p].i;
				T->data[q].e = M.data[p].e;
				q++;
			}
		}
	}
}

void FastTransposeTSMatrix(TSMatrix M, TSMatrix *T) //ϡ��������ת��
{
	int p, q, col;
	vector<int>num(M.nu+1, 0);
	vector<int>cpot(M.nu+1, 0);
	if (!M.tu)
	{
		return;
	}
	T->mu = M.nu;
	T->nu = M.mu;
	T->tu = M.tu;
	cpot[1] = 1;
	for (int t = 1; t <= M.tu; t++)//��ÿ�з���Ԫ����
	{
		num[M.data[t].j] ++;
	}
	//���col�е�һ������Ԫ��T.data[]�е����
	for (col = 2; col <= M.nu; col++)
	{
		cpot[col] = cpot[col - 1] + num[col - 1];
	}
	for (p = 1; p <= M.tu; p++)
	{
		col = M.data[p].j;
		q = cpot[col];
		T->data[q].i = M.data[p].j;
		T->data[q].j = M.data[p].i;
		T->data[q].e = M.data[p].e;
		cpot[col]++;
	}
}