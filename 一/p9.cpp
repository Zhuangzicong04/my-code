#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	char a;
	int b;
	float c;
	double d;
	scanf("%c",&a);
	scanf("%d",&b);
	scanf("%f",&c);
	scanf("%lf",&d);
	printf("%c %d %.6f %.6lf",a,b,c,d);
	return 0;
}
