#include<iostream>
#include<cstdio>
using namespace std;
#define Pi 3.14 
int main()
{
	double r,v;
	cin >> r;
	v = (double)4/3*(Pi * r * r *r);
	printf("%.2lf",v);
	return 0;
}
