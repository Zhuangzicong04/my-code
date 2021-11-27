#include<iostream>
#include<cstdio>
using namespace std;
int f(int a,int b)
{
	int c;
	while(a % b)
	{
		c = b;
		b = a%b;
		a = c;
		b = f(a,b);
	}
	return b;
}
int main()
{
	int a,b;
	cin >> a >> b;
	cout << f(a,b);
	return 0;
}
