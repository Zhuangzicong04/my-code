#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 100001
int main()
{
	char a[N];
	int s,i = 0;
	cin >> a;
	for(;a[i] ; ++ i)
	{
		s = 1;
		for(int j = 0;a[j]; ++ j)
		{
			if(a[j] == a[i] && i != j)
			s = 0;
		}
		if(s == 1)
		{
			cout << a[i];
			break;
		}
	}
			if(a[i] == 0)
		    cout << "no";
	return 0;
}
