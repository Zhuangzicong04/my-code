#include<iostream>
#include<cstdio>
using namespace std;
#define N 10
int a[N];
int main()
{
	int c = 0,t;
	//freopen("D:\\Desktop\\C++\\1.txt","r",stdin);
	for(int i = 0; i < N; ++ i)
	cin >> a[i];
	cin >> t;
	t += 30;
	for(int i = 0;i < N; ++ i)
	{
		if(t >= a[i])
		c ++;
	}
	cout << c;
	return 0;
}
