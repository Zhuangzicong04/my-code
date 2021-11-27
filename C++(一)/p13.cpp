#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	double a,b,c,x1,x2;
	cin >> a >> b >> c;
	if(b * b == 4 * a * c)
	{
		x1 = - b / (2 * a);
		printf("x1=x2=%.5lf",x1);
	}
	else if(b * b > 4 * a * c)
	{
		x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
		x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
		printf("x1=%.5lf;x2=%.5lf",x1,x2);
	}
	else
	{
		double s,i;
		s = - b / (2 * a);
		if(s == 0)
		s = 0; 
		i = sqrt(4 * a * c - b * b) / (2 * a);
		printf("x1=%.5lf+%.5lfi;x2=%.5lf%.5lfi",s,i,s,-i);
	}
	return 0;
	
}
