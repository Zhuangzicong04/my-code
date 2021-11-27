#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define N 1000
using namespace std;
void heapSort(int * );
void heapInsert(int *);
void heapify(int *,int,int);
void swap(int *,int,int);
int main() {
    int arr[N + 5];
	srand((unsigned int)time(0));
	for(int i = 0;i < N; ++ i)
	arr[i] = rand() % N + 1;
    heapSort(arr);
    for(int i = 0;i < N; ++ i)
    cout << arr[i] << endl;
    return 0;
}
void heapSort(int * arr)
{
	heapInsert(arr);
	int size = sizeof(arr) / sizeof(int);
	while(size > 1)
	{
		swap(arr,0,size - 1);
		size --;
		heapify(arr,0,size);
	}
}
//构造大根堆 
void heapInsert(int * arr)
{
	int length = sizeof(arr) / sizeof(int);
	for(int i = 0;i < length;++ i)
	{
		int currentIndex = i;
		int fatherIndex  = (currentIndex - 1) / 2;
		while(arr[currentIndex] > arr[fatherIndex])
		{
			swap(arr,currentIndex,fatherIndex);
			currentIndex = fatherIndex;
			fatherIndex  = (currentIndex - 1) / 2;
		}
	}
}

void heapify(int * arr,int index,int size)
{
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	while(left < size)
	{
		int largestIndex;
		if(arr[left] < arr[right] && right < size)
		largestIndex = right;
		else
		largestIndex = left;
		if(arr[index] > arr[largestIndex])
		break;
		swap(arr,largestIndex,index);
		index = largestIndex;
		left = 2 * index + 1;
		right = 2 * index + 2;
	 } 
}
void swap(int * arr,int i,int j)
{
	int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
