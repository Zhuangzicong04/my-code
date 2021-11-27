#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
void InsertSort(int * a,int n);
int main()
{
	int a[100000];
	srand((unsigned int)time(0));
	for(int i = 0;i < 100000; ++ i)
	a[i] = rand() % 100000 + 1;
	InsertSort(a,100000);
/*	for(int i = 0;i < 1000;++ i)
	cout << a[i] << endl;*/
	return 0;
}
void InsertSort(int * a,int n)
{
	for(int i = 0;i < n - 1;++ i)
	{
		int end = i;
		int tmp = a[end + 1];
		while(end >= 0)
		{
			if(tmp < a[end])
			{
				a[end + 1] = a[end];
				end --;
			}
			else
			break;
		}
		a[end + 1] = tmp;
	}
}
