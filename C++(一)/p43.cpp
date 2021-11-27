#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char a[20001];
	int max_location = 0,min_location = 0;
	int max = 0,min = 201,sum = 0;
	cin.getline(a,sizeof(a));
	int len = strlen(a);
	a[len] = ' ';
	for(int i = 0;a[i];++ i)
	{
		if(a[i] != ' ' && a[i] != ',')
		sum ++;
		else if(sum > 0)
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
	for(int i = max_location;i < max + max_location;++ i)
	cout << a[i];
	cout << endl;
	for(int i = min_location;i < min + min_location;++ i)
	cout << a[i];
	return 0;
}
