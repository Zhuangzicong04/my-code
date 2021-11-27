#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int a,n,x = 1;
	cin >> a >> n;
	for(int i = 0;i < n ; ++ i)
		x *= a;
		cout << x;
	return 0;
}
