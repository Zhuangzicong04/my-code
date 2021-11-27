#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int a,z = 1;
	unsigned int n;
	cin >> a >> n;
	for(int i = 0;i < n; ++ i )
	{
		z = z * a ;
	}
	cout << z;
	return 0;
}
