#include<iostream>
#include<cstdio>
using namespace std;
int f(int a,int b)
{
	if(a % b)
	return f(b,a % b);
	return b;
}
int main()
{
	int a,b;
	cin >> a >> b;
	cout << f(a,b);
	return 0;
}
