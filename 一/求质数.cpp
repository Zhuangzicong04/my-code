#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for(int i = 2;i < n + 1; ++ i)
	{
		int j;
		for(j = 2;j < i; ++ j)
		{
			if(i % j == 0)
			break;
	     } 
	     if( j == i)
	     cout << i << endl;
	}
	return 0;
}
