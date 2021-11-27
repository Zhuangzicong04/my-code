#include<iostream>
#include<cstdio>
using namespace std;
#define M 1000010
long long a[M] = {0,1,2};
int main()
{
	int n,k;
	freopen("D:\\Desktop\\C++\\1.txt","r",stdin);
	cin >> n;
	for(int i = 3;i < M; ++ i)
	{
		a[i] = (2 * a[i - 1] + a[i - 2]) % 32767;
 	}
	for(int i = 0;i < n ; ++ i)
	{
		cin >> k;
		cout << a[k] << endl;
	}
	 return 0;
}
