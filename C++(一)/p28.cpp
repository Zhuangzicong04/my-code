#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,m,sum = 0;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; ++ i)
	cin >> a[i];
	cin >> m;
	for(int i = 0;i < n; ++ i)
	{
		if(a[i] == m)
		sum ++ ;
	}
	cout << sum;
	return 0;
}
