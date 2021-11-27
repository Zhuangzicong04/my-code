#include<iostream>
#include<cstdio>
using namespace std;
#define row 5
#define col 5
int a[row][col];
int main()
{
	int max,min,x,y;
	//freopen("D:\\Desktop\\C++\\1.txt","r",stdin);
	for(int i = 0;i < row; ++ i)
	{
		for(int j = 0;j < col; ++ j)
		cin >> a[i][j];
	}
	for(int i = 0;i < row; ++ i)
	{
		max = a[i][0];
		for(int j = 0;j < col;++ j)
		{
			if(a[i][j] >= max)
			{
				max = a[i][j];
				x = i;
				y = j;
			}
		}
		min = max;
		for(int k = 0;k < col; ++ k)
		{
			if(min >= a[k][y])
			min = a[k][y];
		}
		if(max == min)
		{
			cout << x + 1<< " " << y + 1 << " " << max;
			x = 0;
			y = 0;
			break;
		}
    } 
		if(x != 0 || y != 0)
		cout << "not found";
		return 0;
}
