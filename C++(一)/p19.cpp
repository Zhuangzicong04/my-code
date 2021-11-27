#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,sum,a,b,c;
	int x = 0,y = 0,z = 0;
	cin >> n;
	for(int i = 0; i < n; ++ i)
	{
		cin >> a >> b >> c;
		x += a;
		y += b;
		z += c;
	}
	sum = x + y +z;
	printf("%d %d %d %d",x,y,z,sum);
	return 0;
	
}
