#include<iostream>
#include<map>
#include<cstdio>
using namespace std;
typedef map<int,int> MP;
int main()
{
	int n;
	MP mp;
	mp[1000000000] = 1;
	MP::iterator i;
	freopen("D:\\Desktop\\C++\\1.txt","r",stdin);
	scanf("%d",&n);
	while(n --)
	{
		int id,power;
		scanf("%d %d",&id,&power);
		i = mp.lower_bound(power);
		if(i == mp.begin())
			printf("%d %d\n",id,i -> second);
			else if(i == mp.end())
			{
				i --;
				//cout << id << " " << i -> second << endl;
					printf("%d %d\n",id,i -> second);
			}
			else
			{
				int right = i-> first;
				i --;
				int left = i -> first;
				if(power - left <= right - power)
				printf("%d %d\n",id,i -> second);
				else
				{
					i ++;
					printf("%d %d\n",id,i -> second);
				}
			}
			mp[power] = id;
	}
	return 0;
}
