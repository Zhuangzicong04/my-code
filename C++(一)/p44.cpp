#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char a[80];
	cin.getline(a,sizeof(a));
	for(int i = 0 ; a[i] ; ++ i)
	{
		if(('a' <= a[i] && a[i] < 'z') || ('A' <= a[i] && a[i] < 'Z'))
		a[i] += 1;
		else if(a[i] == 'z' || a[i] == 'Z')
		a[i] -= 25;
		cout << a[i];
	}
	return 0;
}
