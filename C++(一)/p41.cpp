#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char a[100001];
	cin.getline(a,sizeof(a));
	for(int i = 0;a[i];i ++)
	{
		int j = 0;
		for(;a[j];j ++)
		{
			if(a[j] == a[i] && i != j)
			break;
		}
		if(a[j] == 0)
		{
			cout << a[i];
			return 0;
		}
	}
	cout << "no";
	return 0;
}
