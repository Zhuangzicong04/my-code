#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,x,y,t;
	cin >> n >> x >>  y;
	if(y % x == 0)
	{
		t = n - (y/x);
		if(t > 0)
		cout << t;
	    else
	    cout << 0;
	}
	else
	{
	  	t =  n - (y/x) - 1;
		if(t > 0)
		cout << t;
		else
		cout << 0;	
	}
	return 0;
}
