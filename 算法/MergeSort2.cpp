#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
void MergeSort(int * a,int n);
void _MergeSort(int *a,int left,int right,int * tmp);
int main()
{
	int a[100000];
	srand((unsigned int)time(0));
	for(int i = 0;i < 100000; ++ i)
	a[i] = rand() % 100000 + 1;
	MergeSort(a,100000);
	return 0;
}
void _MergeSort(int * a,int left,int right,int * tmp)
{
	if(left >= right)
	return;
	int mid = left + (right - left)/2;
	_MergeSort(a,left,mid,tmp);
	_MergeSort(a,mid + 1,right,tmp);
	int begin1 = left,begin2 = mid + 1;
	int i = left;
	while(begin1 <= mid && begin2 <= right)
	{
		if(a[begin1] < a[begin2])
		tmp[i ++ ] = a[begin1 ++];
		else
		tmp[i ++ ] = a[begin2 ++];
	}
	while(begin1 <= mid)
	tmp[i++] = a[begin1 ++];
	while(begin2 <= right)
	tmp[i ++ ] = a[begin2 ++];
	for(int j = left;j <= right;++ j)
	a[j] = tmp[j];
}
void MergeSort(int * a,int n)
{
	int * tmp = (int *)malloc(sizeof(int) * n);
	if(tmp == NULL)
	{
		cout << "malloc for fail";
		exit(-1);
	}
	_MergeSort(a,0,n - 1,tmp);
	free(tmp);
}
