
#include<stdio.h>
#include <stdlib.h>
#include "SqList.h"

int main(int argc, char * argv[])
{
	SqList l;
	InitList(&l);

	printf("%d", l.length);

	DestroyList(&l);

	system("pause");
	return 0;
}