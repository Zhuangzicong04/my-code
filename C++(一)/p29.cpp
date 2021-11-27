#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int a[10],high,sum = 0;
	for(int i = 0; i < 10; ++ i)
	cin >> a[i];
	cin >> high;
	high += 30;
	for(int i = 0; i < 10; ++ i)
	{
		if(a[i] <= high)
		sum ++;
	}
	cout << sum;
	return 0;
}
