#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char a[256];
	int num = 0;
	cin.getline(a,sizeof(a));
	for(int i = 0;a[i]; ++ i)
	{
		if('0' <= a[i] && a[i] <='9')
		num ++;
	}
	cout << num;
	return 0;
}
