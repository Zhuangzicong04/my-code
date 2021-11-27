#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int row,col;
	cin >> row >> col;
	int a[row][col],b[row][col];
	for(int i = 0;i < row;i ++)
	{
		for(int j = 0;j < col; ++ j)
			{
				cin >> a[i][j];
				b[i][j] = a[i][j];
			}
	}
	double avg;
	for(int i = 1;i < row - 1;i ++)
	{
		for(int j = 1;j < col - 1; ++ j)
			{
				avg = (double)(a[i+1][j] + a[i-1][j] + a[i][j+1] + a[i][j-1] + a[i][j])/5;
				b[i][j] = int(avg - 0.5) + 1;
			}
	}
		for(int i = 0;i < row;i ++)
	{
		for(int j = 0;j < col; ++ j)
				cout << b[i][j] << " ";
				cout << endl;
	}
	return 0;
}
