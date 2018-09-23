
#include<stdio.h>
#include <stdlib.h>
#include "SqList.h"
#include "SqStack.h"
#include "SqQueue.h"
#include "BTree.h"

int v(int e){
	printf("%d ", e);
	return OK;
}

int main(int argc, char * argv[])
{
	int n;
	
	SqList l;
	InitList(&l);

	for (int i = 1; i <= 10; i++){
		ListInsert(&l, i, i);
	}
	ListTraverse(l,v);
	n = BinarySearch(l, 21);
	printf("%d\n", n);
	DestroyList(&l);
	
	system("pause");
	return 0;
}

