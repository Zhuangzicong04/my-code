#include<iostream>
#include<cstdio>
using namespace std;
#define PI 3.14 
int main()
{
	double r,v;
	scanf("%lf",&r);
	v = (double)4/3*PI*r*r*r;
	printf("%.2lf",v);
	return 0;
}
