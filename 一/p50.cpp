#include <iostream>
using namespace std;
void Memcpy( void * src, void * dest, int size)
{
  char *p1 = (char *) src;
  char *p2 = (char *) dest;
  int i;
  if(p1 <= p2 && p1 + size > p2 )
  {
  	for(i = size - 1;i >=0; -- i)
  	p2[i] = p1[i];
  }
  else
  {
  	for(i = 0;i < size;++ i)
  	p2[i] = p1[i];
  }
}

void Print(int * p,int size)
{
	for(int i = 0;i < size; ++i)
		cout << p[i] << ",";
	cout << endl;
}

int main()
{
	int a[10];
	int n;
	freopen("D:\\Desktop\\C++\\1.txt","r",stdin);
	cin >> n;
	for(int i = 0;i < n; ++i)
		cin >> a[i];
	int b[10] = {0};
	Memcpy(a,b,sizeof(a));
	Print(b,n);
	
	int c[10] = {1,2,3,4,5,6,7,8,9,10};
	Memcpy(c,c+5,5*sizeof(int)); //将c的前一半拷贝到后一半 
	Print(c,10);

	char s[10] = "123456789";
	Memcpy(s+2,s+4,5); //将s[2]开始的5个字符拷贝到s[4]开始的地方 
	cout << s << endl;
	
	char s1[10] = "123456789";
	Memcpy(s1+5,s1+1,4); //将s1[5]开始的4个字符拷贝到s1[1]开始的地方 
	cout << s1 << endl;
	
	
	return 0;
}
