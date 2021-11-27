#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define N 100
using namespace std;
void AdjustDown(int * a, int n, int root);
void HeapSort(int * a, int n);
void Swap(int * ,int ,int );
int main() 
{
    int array[N + 5];
	srand((unsigned int)time(0));
	for(int i = 0;i < N; ++ i)
	array[i] = rand() % N + 1;
    int size = sizeof(array) / sizeof(int);
    HeapSort(array,size);
	for(int i = 0;i < N; ++ i)
	cout << array[i] << endl; 
    return 0;
}
//堆的向下调整算法
void AdjustDown(int * a, int n, int root)
{
	int parent = root;
	int child = 2 * parent + 1;//假设左孩子较大
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])//右孩子存在，并且比左孩子大
			child++;//左右孩子的较大值
			
		if (a[child] > a[parent])
		{
			Swap(a,child,parent);
			parent = child;
			child = 2 * parent + 1;
		}
		else//已成堆
			break;
	}
}

void HeapSort(int * a, int n)
{
	//排升序，建大堆
	//从第一个非叶子结点开始向下调整，一直到根
	int i = 0;
	for (i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;//记录堆的最后一个数据的下标
	while (end)
	{
		Swap(a,0,end);//将堆顶的数据和堆的最后一个数据交换
		AdjustDown(a, end, 0);//对根进行一次向下调整
		end--;//堆的最后一个数据的下标减一
	}
}
void Swap(int * a,int i,int j)
{
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}
