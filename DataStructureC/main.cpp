
#include<stdio.h>
#include <stdlib.h>
#include "SqList.h"

void visit(int e){
	printf("%d ", e);
}

int main(int argc, char * argv[])
{
	int n;
	SqList l ;
	InitList(&l);
	for (int i = 0; i < 5;i++)
		ListInsert(&l, i+1, i+1);
	printf("%d\n", l.length);
	ListTraverse(l, visit);



	DestroyList(&l);
	printf("\n");
	system("pause");
	return 0;
}