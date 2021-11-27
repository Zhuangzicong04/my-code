#include<iostream>
#include<cstdio>
using namespace std;
int Pell(int a)
{
	if(a <= 2)
	return a;
	else
	{
		int f1 = 1,f2 = 2,f3;
		for(int i = 0;i < a - 2;++ i)
		{
			f3 = (2 * f2 + f1) % 32767;
			f1 = f2;
			f2 = f3;
		}
		return f2;
	}
	
 } 
int main()
{
	int n,x;
	cin >> n;
	for(int i = 0;i < n; ++ i)
	{
		cin >> x;
		cout << Pell(x)  << endl;
	}
	return 0;
}
