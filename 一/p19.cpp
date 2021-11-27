#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,a,b,c,sum =0,x = 0,y = 0,z = 0;
	cin >> n;
	for(int i = 0;i < n; ++ i)
	{
			cin >> a >> b >> c;
			x += a;
			y += b;
			z += c;
		    sum += a +b +c;
	}
	cout << x << " " << y << " " << z << " " << sum;
	return 0;
}
