#include<iostream>
#include<cstdio>
using namespace std;
#define ROWS 5
#define COLS 5
int a[ROWS][COLS];
int main()
{
	int x,b,MAX,MIN;
	freopen("D:\\Desktop\\C++\\1.txt","r",stdin);
	for(int i = 0;i < ROWS; ++ i)
	{
		for(int j = 0;j < COLS; ++ j)
		cin >> a[i][j];
	}
	for(int i = 0;i < ROWS; ++ i)
	{
		MAX = a[i][0];
		for(int j = 0;j < COLS; ++ j)
		{
			if(a[i][j] >= MAX)
		    {
		    	MAX = a[i][j];
		    	b = j;
		    	x = i;
			}
		}
		MIN = MAX;
		for(int k = 0;k < ROWS; ++ k)
		{
		 	if(a[k][b] <= MIN)
	    	{
		    	MIN = a[k][b];
		    }
		}
			if(MAX == MIN)
        	{
        		cout << x+1 << " " << b+1 << " " << MAX;
        		x = -1;
        		b = -1;
        		break;
			}
	}
	if(x != -1 || b != -1)
	cout << "not found";
	return 0;
}
