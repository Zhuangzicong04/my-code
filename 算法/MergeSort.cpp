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
	//�鲢�����Ӻ�����
void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)//�鲢������������ֻ��һ�����ݻ������в�����ʱ������Ҫ�ٷֽ�
	{
		return;
	}
	int mid = (left + right) / 2;//�м��±�
	_MergeSort(a, left, mid, tmp);//�������н��й鲢
	_MergeSort(a, mid + 1, right, tmp);//�������н��й鲢
	int begin1 = left;
	int begin2 = mid + 1;
	//��������������й鲢���鲢�������tmp��
	int i = left;
	while (begin1 <= mid&&begin2 <= right)
	{
		//����С���������ȷ���tmp
		if (a[begin1] < a[begin2])
			tmp[i++] = a[begin1++];
		else
			tmp[i++] = a[begin2++];
	}
	//������������һ�����䣬����һ������ʣ�������ֱ�ӷŵ�tmp�ĺ���
	while (begin1 <= mid)
		tmp[i++] = a[begin1++];
	while (begin2 <= right)
		tmp[i++] = a[begin2++];
	//�鲢��󣬿�����ԭ����
	int j = 0;
	for (j = left; j <= right; j++)
		a[j] = tmp[j];
}
//�鲢�������庯����
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);//����һ����ԭ�����С��ͬ�Ŀռ�
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	_MergeSort(a, 0, n - 1, tmp);//�鲢����
	free(tmp);//�ͷſռ�
}
