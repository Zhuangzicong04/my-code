#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int N,m,x = 0;
	cin >> N;
	int a [N];
	for(int i = 0;i < N	; ++ i)
		cin >> a[i];
		cin >> m;
	for(int i = 0;i < N; ++ i)
	{
		 if(m == a[i])
		 x ++;
	}
	cout << x ;
	return 0;
}
