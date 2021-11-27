#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char a[81];
	cin.getline(a,sizeof(a));
	for(int i = 0;a[i];++ i)
	{
		if(a[i] == 'z' || a[i] == 'Z')
		a[i] -= 25;
		else if((a[i] >= 65 && a[i] <= 89)||(a[i] >= 97 && a[i] <= 121))
		a[i] += 1;
		cout << a[i];
		
	 } 
	 return 0;
}
