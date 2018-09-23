
#include <iostream>
#include <sstream>
#include <string>

using namespace std;


int index(string s, string t, int start = 0);
int index_normal(string s, string t, int start = 0);
int index_kmp(string s, string t, int start = 0 );

void test()
{
	string s = "acabaabaabcacaabca";
	string t = "abaabc";
	int pos;
	//pos = index(s, t);
	//pos = index_normal(s, t);
	pos = index_kmp(s, t);
	cout << s << endl << t << endl << pos << endl;

}

void get_next(string t, int next[])
{
	int i, j;
	i = 0;
	j = -1;
	next[0] = -1;
	while (i < t.length() - 1)
	{
		if (j == -1){
			i++;
			j++;
			next[i] = j;
			continue;
		}
		else if (t[i] == t[j]){
			i++;
			j++;
			next[i] = j;
		}
		else{
			j = next[j];
		}
	}
}

int index_kmp(string s, string t, int start)
{
	if (t.empty())
		return -1;
	int i = 0;
	int j = 0;
	int next[16];
	get_next(t, next);
	
	int  n1 = s.length(), n2 = t.length();
	while (i < n1 && j < n2){
		if (j == -1){
			i++; j++; continue;
		}
		else if (s[i] == t[j]){
			i++; j++;
		}
		else{
			j = next[j];
		}
	}
	cout << i << "," << j << "," << endl;
	if (j >= t.length())
		return i - t.length();
	else
		return -1;
}

int index(string s, string t, int start)
{
	int pos = -1;
	int j = 0;
	for (int i = start; i < s.length(); i++)
	{
		for (j = 0; j < t.length(); j++)
		{
			if (t[j] != s[i + j])
				break;
		}
		if (j == t.length())
		{
			pos = i;
			break;
		}
	}
	return pos;
}

int index_normal(string s, string t, int start)
{
	int i = start;
	int j = 0;
	while (i < s.length() && j < t.length()){
		if (s[i] == t[j])
		{
			i++;
			j++;
		}
		else{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j >= t.length())
		return i - t.length();
	else
		return -1;
}

string tostr(int i)
{
	stringstream ss;
	ss << i;
	return ss.str();
}
