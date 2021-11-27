#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	long long a,n,t = 0;
	cin >> n;
	for(;n != 0;n /= 10)
	{
		a = n % 10;
		t = t * 10 + a;
	}
	cout << t ;
	return 0;
}
