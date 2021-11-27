#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int l,r,c = 0,k;
	cin >> l >> r;
	for(l ;l <= r; ++ l)
	{
		k = l;
		while(k > 0)
		{
			if(k % 10 == 2) 
			c++;
			k /= 10; 
		}
	}
	cout << c;
	return 0;
}
