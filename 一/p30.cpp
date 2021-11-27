#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	double x = 0,b = 0,c = 0,d = 0;
	//freopen("D:\\Desktop\\C++\\1.txt","r",stdin);
	cin >> n;
	int a[n];
	for(int i = 0;i < n; ++ i)
	{
		cin >> a[i];
		if( (0 <= a[i]) && (a[i] <= 18))
		x += 1;
		else if( (19 <= a[i]) && (a[i] <= 35))
		b += 1;
		else if( (36 <= a[i]) && (a[i] <= 60))
		c += 1;
		else 
		d += 1;
	}
	x = 100 * x / n;
	b = 100 * b / n;
	c = 100 * c / n;
	d = 100 * d / n;  
	printf("%.2lf%\n%.2lf%\n%.2lf%\n%.2lf%\n",x,b,c,d);
	return 0;
}
