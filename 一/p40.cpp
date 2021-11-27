#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char a[256];
	int c = 0;
	cin.getline(a , sizeof(a));
	for(int i = 0;a[i]; ++ i)
	{
		if(a[i] >= '0' && a[i] <= '9')
		c ++ ;
	}
	cout << c;
	return 0;
}
