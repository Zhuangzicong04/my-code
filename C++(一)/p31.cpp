#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int l,m,left,right,sum = 0;
	cin >> l >> m;
	int a[l+1];
	for(int i = 0;i <= l; ++ i)
	a[i] = 1;
	for(int i = 0;i < m; ++ i)
	{
		cin >> left >> right;
		for(int j = left;j <= right; ++ j)
		a[j] = 0;
	}
	for(int i = 0;i <= l; ++ i)
	{
		if(a[i] == 1)
		sum ++;
	}
	cout << sum;
	return 0;
}
