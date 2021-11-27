#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	//freopen("D:\\Desktop\\C++\\1.txt","r",stdin);
	int max = 0,n,a,b,h = 0;
	cin >> n;
	for(int i = 0;i < n; ++ i)
	{
		cin >> a >> b;
		if(90 <= a && a <= 140 && 60 <= b && b <= 90 )
		{
			h ++;
		   if(max < h)
		   max = h;
		}
		else 
		h = 0;
	}
	cout << max;
	return 0;
}
