#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,sum = 0,a;
	double avg;
	cin >> n;
	for(int i = 0;i < n;++ i)
	{
		cin >> a;
		sum += a;
	}
	avg = (double)sum / n;
	printf("%d %.5lf",sum,avg);
	return 0;
}
