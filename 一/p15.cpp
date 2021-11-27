#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,x,y,a;
	cin >> n >> x >> y;
	if(y % x)
	{
		a = n - y/x - 1;
		if(a >0)
		cout << a;
		else cout << 0;
	}
	else if(y % x == 0)
	{
		a = n - y/x ;
		if(a >0)
		cout << a;
		else cout << 0;
	 } 
	return 0;
}
