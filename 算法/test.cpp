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
//�ѵ����µ����㷨
void AdjustDown(int * a, int n, int root)
{
	int parent = root;
	int child = 2 * parent + 1;//�������ӽϴ�
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])//�Һ��Ӵ��ڣ����ұ����Ӵ�
			child++;//���Һ��ӵĽϴ�ֵ
			
		if (a[child] > a[parent])
		{
			Swap(a,child,parent);
			parent = child;
			child = 2 * parent + 1;
		}
		else//�ѳɶ�
			break;
	}
}

void HeapSort(int * a, int n)
{
	//�����򣬽����
	//�ӵ�һ����Ҷ�ӽ�㿪ʼ���µ�����һֱ����
	int i = 0;
	for (i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;//��¼�ѵ����һ�����ݵ��±�
	while (end)
	{
		Swap(a,0,end);//���Ѷ������ݺͶѵ����һ�����ݽ���
		AdjustDown(a, end, 0);//�Ը�����һ�����µ���
		end--;//�ѵ����һ�����ݵ��±��һ
	}
}
void Swap(int * a,int i,int j)
{
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}
