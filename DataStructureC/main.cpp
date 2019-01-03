
#include<stdio.h>
#include <stdlib.h>
#include "SqList.h"
#include "SqStack.h"
#include "SqQueue.h"
#include "BTree.h"

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<sstream>

using namespace std;

int v(int e){
	printf("%d¡¢", e);
	return OK;
}

vector<string> split(string str, char del){
	vector<string> strs;
	string word="";
	bool flag = false;
	for (int i = 0; i < str.size(); i++){
		if (str[i] != del){
			word.push_back(str[i]);
			flag = true;
		}
		else if(str[i] == del && flag){
			strs.push_back(word);
			flag = false;
			word = "";
		}
	}
	if (flag){
		strs.push_back(word);
	}
	return strs;
}


int main(int argc, char * argv[])
{
	int n;
	
	BTreeNode* t= CreateBitSortTree();

	RPreOrderTraverse(t, v);

	DestroyBitTree(t);
	
	system("pause");
	return 0;
}

