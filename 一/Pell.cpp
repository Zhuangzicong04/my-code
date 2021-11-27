#include<iostream>
#include<cstdio>
using namespace std;
int Pell(int x)
{
	if(x <= 2)
	return x;
	else
	return 2 * Pell(x - 1) + Pell(x - 2);
}
int main()
{
	int n,x;
	//freopen("D:\\Desktop\\C++\\1.txt","r",stdin);
	cin >> n;
	for(int i = 0;i < n; ++ i )
	{
		cin >> x;
		cout << Pell(x) % 32767 << endl;
	}
	return 0;
}
