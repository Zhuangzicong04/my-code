#include<iostream>
#include<cstdio>
using namespace std;
struct patient{
	char id[10];
	int age;
	int k; 
};
int main()
{
	patient p[100],tmp;
	int n;
	cin >> n;
	for(int i = 0;i < n; ++ i)
	{
		cin  >> p[i].id >> p[i].age;
		p[i].k = i + 1;
	}
	for(int i = 1;i < n;++ i)
	{
		for(int j = 0;j < i;++ j)
		{
			if(p[i].age >= 60 && p[j].age < p[i].age || (p[i].age < 60 && p[j].age < 60 && p[i].k < p[j].k))
			{
				tmp = p[i];
				for(int k = i;k > j;k --)
					p[k] = p[k - 1];
				p[j] = tmp;
				break;
			}
		}
	}
	for(int i = 0; i < n; ++ i)
	cout << p[i].id << endl;
	return 0;
}
