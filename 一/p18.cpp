#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,max = 0,min = 200,a[1000];
	cin >> n;
	for(int i = 0;i < n; ++ i)
	{
		cin >> a[i];
	}
	for(int i = 0;i < n; ++ i)
	{
		if(a[i] > max) max = a[i];
		if(a[i] < min) min = a[i];
	}
	/*while(n)
	{
		if(a[n-1] > max) max = a[n-1];
		if(a[n-1] < min) min = a[n-1];
		n -- ;
	}*/
	cout << max - min;
	return 0;
}
