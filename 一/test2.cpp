#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int a[3] = {1,2,3};
	int b[3] = {4,5,6};
	int i = 0, j = 0;
	a[i ++] = b[j ++];
	cout << a[0] << a[1];
	return 0;
}
