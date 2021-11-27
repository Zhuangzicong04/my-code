#include<iostream>
#include<cstdio>
#include<cmath>
#define eps 1e-7
using namespace std;
int main()
{
	double a,b,c,x1,x2;
	scanf("%lf %lf %lf",&a,&b,&c);
	if ((b * b - 4 * a * c) > -eps && (b * b - 4 * a * c) < eps){
		x1 = x2 = -b /(2*a);
		printf("x1=x2=%.5lf",x1);
	}
	else if( b * b > 4 * a * c){
		x1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
		x2 = (-b - sqrt(b*b - 4*a*c))/(2*a);
		printf("x1=%.5lf;x2=%.5lf",x1,x2);
	}
	else{
		x1 = -b / (2*a);
		x2 = sqrt(- b * b + 4 * a * c) / (2 * a);
		if( x1 > -eps && x1 < eps)
		x1 = 0.00000;
		printf("x1=%.5lf+%.5lfi;x2=%.5lf-%.5lfi",x1,x2,x1,x2);
	}
	return 0;
}
