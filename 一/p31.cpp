#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int L,M,x,y,c = 0;
	//freopen("D:\\Desktop\\C++\\1.txt","r",stdin);
	cin >> L >> M;
	int a[L];
	for(int i = 0;i <= L; ++ i)
	a[i] = 1;
	for(int i = 0;i < M;++ i)
	{
		cin >> x >> y;
		for(int j = x;j <= y;++ j)
		a[j] = 0;
	}
	for(int i = 0;i <= L;++ i)
	{
		if(a[i] == 1)
	    c++;
	}
	cout << c;
	return 0;
}
