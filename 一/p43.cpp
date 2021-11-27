#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char a[20001];
	int max = 1,min = 201,sum = 0;
	int min_location = 0,max_location = 0;
	//freopen("D:\\Desktop\\C++\\1.txt","r",stdin);
	cin.getline(a,sizeof(a)); 
	int len = strlen(a);
	a[len] = ' ';
	for(int i = 0; a[i] ;++ i)
	{
		if(a[i] != ' ' && a[i] != ',') sum++;
		else if(sum > 0 )
		{
			if(sum > max)
			{
				max = sum;
				max_location = i - sum;
			}
			if(sum < min)
			{
				min = sum;
				min_location = i - sum;
			}
			sum = 0;
		}
	}
	/*if(max_location == 0 && min_location == 0)
	{
		cout << a << endl;
		cout << a;
		return 0;
	}*/
	for(int i = max_location;i < max_location + max; ++ i)
	cout << a[i];
	cout << endl;
	for(int i = min_location;i < min_location + min;++ i)
	cout << a[i];
	return 0;
}
