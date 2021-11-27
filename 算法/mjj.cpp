#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
		int i,n=1000000,j;
	int a[1000005]; 
//	printf("*****插入排序*****\n");
//	printf("请输入要生成随机数的个数："); 
	srand((unsigned int)time(NULL));
	for(i=0;i<n;i++){
		a[i]=rand()%100000;
	}
	HEAPSORT(a,n);
/*	for(i=0;i<n;i++){
		printf("%d\n  ",a[i]);
	}*/
	return 0;
}

int HEAPSORT(int* a,int n){
	int i,p,heap;
	heap=BUILD_MAX_HEAP(a,n);
	for(i=n;i>=1;i--){
		p=a[0];
		a[0]=a[i];
		a[i]=p;
		heap--;
		MAX_HEAPIFY(a,0,heap);
	}
	return 0;
}

int BUILD_MAX_HEAP(int* a,int n){
	int heap,i;
	heap=n-1;
	for(i=n/2;i>0;i--)
	MAX_HEAPIFY(a,i,heap);
	return heap;
}

int MAX_HEAPIFY(int* a,int i,int heap){
	int l,r,largest,p;
	l=2*i+1;
	r=2*i+2;
	if(l<=heap&&a[l]>a[i])
		largest=l;
	else
	    largest=i;
	if(r<=heap&&a[r]>a[largest])
		largest=r;
	if(largest!=i){
		p=a[i];
		a[i]=a[largest];
		a[largest]=p;
		MAX_HEAPIFY(a,largest,heap);
	}
	return 0;
}
