#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char s[] = "Hello";
	char * p;
	for(p = &s[0]; *p != 0;++ p)
	cout << *p;
	return 0;
}
