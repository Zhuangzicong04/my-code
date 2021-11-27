#include<iostream>
#include<cstdio>
using namespace std;
int max(int a,int b)
{
	if(a%b == 0)
	return b;
	else
	{
		int c;
		c = a%b;
		a = b;
		b = c;
		return max(a,b);
	}
}
int main()
{
	int n,m;
	cin >> n >> m;
	if(n > m)
	cout << max(n,m);
	else
	cout << max(m,n);
}
