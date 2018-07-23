
#include<stdio.h>
#include <stdlib.h>
#include "LinkList.h"

void visit(int e){
	printf("%d ", e);
}

int main(int argc, char * argv[])
{
	int n;
	LinkList la , lb, lc;
	InitList(&la);
	
	for (int i = 0; i < 5;i++)
		ListInsert(&la, i+1, i+1);
	ListTraverse(la, visit);

	ListInsert(&la, la.length, 9);
	ListTraverse(la, visit);
	DestroyList(&la);

	printf("%d", la.length);
	system("pause");
	return 0;
}