#include<iostream>
#include<cstdio>
using namespace std;
#define Pi 3.14159
int main()
{
	int x,h,r;
	scanf("%d %d",&h,&r);
	x = 20*1000/(Pi*r*r*h)+1;
	printf("%d",x);
	return 0;
}
