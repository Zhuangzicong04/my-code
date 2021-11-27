#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
void _MergeSort(int* a, int left, int right, int* tmp);
void MergeSort(int* a, int n);
int main()
{
    int a[8] = {10,6,7,1,3,9,4,2};
    MergeSort(a,8);
    for(int i = 0;i < 8;i ++)
    cout << a[i] << endl;
	return 0;
}
	//归并排序（子函数）
void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)//归并结束条件：当只有一个数据或是序列不存在时，不需要再分解
	{
		return;
	}
	int mid = (left + right) / 2;//中间下标
	_MergeSort(a, left, mid, tmp);//对左序列进行归并
	_MergeSort(a, mid + 1, right, tmp);//对右序列进行归并
	int begin1 = left;
	int begin2 = mid + 1;
	//将两段子区间进行归并，归并结果放在tmp中
	int i = left;
	while (begin1 <= mid&&begin2 <= right)
	{
		//将较小的数据优先放入tmp
		if (a[begin1] < a[begin2])
			tmp[i++] = a[begin1++];
		else
			tmp[i++] = a[begin2++];
	}
	//当遍历完其中一个区间，将另一个区间剩余的数据直接放到tmp的后面
	while (begin1 <= mid)
		tmp[i++] = a[begin1++];
	while (begin2 <= right)
		tmp[i++] = a[begin2++];
	//归并完后，拷贝回原数组
	int j = 0;
	for (j = left; j <= right; j++)
		a[j] = tmp[j];
}
//归并排序（主体函数）
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);//申请一个与原数组大小相同的空间
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	_MergeSort(a, 0, n - 1, tmp);//归并排序
	free(tmp);//释放空间
}
