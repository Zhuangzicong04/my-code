#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,max = 0,min = 1001,a;
	cin >> n;
	for(int i = 0;i < n; ++ i)
	{
		cin >> a;
		if(a >= max)
		max = a;
		if(a <= min)
		min = a; 
	}
	cout << max - min;
	return 0;
}
