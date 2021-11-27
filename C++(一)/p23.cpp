#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,a,b,sum = 0,max = 0;//a为收缩，b为舒张压 
	cin >> n;
	for(int i = 0;i < n;++ i)
	{
		cin >> a >> b;
		if(90 <= a && a <= 140 && 60 <= b && b <= 90)
		sum ++;
		else
		sum = 0;
		if(sum > max)
		max = sum;
	}
	cout << max;
	return 0;
}
