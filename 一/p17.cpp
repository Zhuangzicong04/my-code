#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,x,sum = 0;
	double avg;
	scanf("%d",&n);
	for(int i = 0;i < n;++i)
	{
		scanf("%d",&x);
		sum += x;
	}
	avg = (double)sum/n;
	printf("%d %.5lf",sum,avg);
	return 0;
}
