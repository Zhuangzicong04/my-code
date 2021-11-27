#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,m;
	freopen("D:\\Desktop\\C++\\1.txt","r",stdin);
	cin >> n >>m;
	int a[n][m],b[n][m];
	double avg;
	for(int i = 0;i < n ; ++ i)
	{
		for(int j = 0;j < m ; ++ j)
		cin >> a[i][j];
	}
	for(int i = 1;i < n - 1;++ i)
	{
		for(int j = 1;j < m - 1;++ j)
		{
			avg = (a[i][j] + a[i][j-1] + a[i][j+1] + a[i+1][j] + a[i-1][j])/5.0;
			b[i][j] = (int)(avg - 0.5) + 1;
		}
	}
		for(int i = 1;i < n - 1;++ i)
	{
		for(int j = 1;j < m - 1;++ j)
		{
			a[i][j] = b[i][j];
		}
	}
	for(int i = 0;i < n ; ++ i)
	{
		for(int j = 0;j < m ; ++ j)
		cout << a[i][j] << " ";
		cout << endl;
	}
	return 0;
}
