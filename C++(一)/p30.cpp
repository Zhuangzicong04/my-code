#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	double sum[4];
	cin >> n;
	int a[n];
	for(int i = 0;i < n; ++ i)
	{
		cin >> a[i];
		if(0 <= a[i] && a[i] <= 18 )
		sum[0] ++;
		else if(19 <= a[i] && a[i] <= 35 )
		sum[1] ++;
		else if(36 <= a[i] && a[i] <= 60 )
		sum[2] ++;
		else if(a[i] >= 61 )
		sum[3] ++;
		else
		cout <<"输入非法数据";
	}
	printf("%.2lf%\n",sum[0] / n * 100);
	printf("%.2lf%\n",sum[1] / n * 100);
	printf("%.2lf%\n",sum[2] / n * 100);
	printf("%.2lf%\n",sum[3] / n * 100);
	return 0;
	
}
