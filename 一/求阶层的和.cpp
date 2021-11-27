#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,sum = 0,b = 1;
	cin >> n;
	for(int i = 1;i < n + 1; ++ i)
	{
		b *= i;
		sum += b;
	}
	cout << sum;
	return 0;
}
