#include<iostream>
#include<map>
#include<cstdio>
#include<set>
using namespace std;
typedef map<int,set<int> > MP;
int main()
{
	MP mp;
	mp[1000000000].insert(1);
	MP::iterator i,t;
	int n;
	freopen("D:\\Desktop\\C++\\1.txt","r",stdin);
	scanf("%d",&n);
	while(n -- )
	{
		int id,power;
		scanf("%d %d",&id,&power);
		i = mp.upper_bound(power);
		if(i == mp.begin())
		printf("%d %d\n",id,*(i -> second.begin()));
		else if(i == mp.end())
		{
			i --;
			printf("%d %d\n",id,*(i -> second.begin()));
		}
		else
		{
			int right = i -> first;
			i --;
			int left = i -> first;
			if(power - left < right - power)
			printf("%d %d\n",id,*(i -> second.begin()));
			else if(power - left == right - power)
			{
				t = i ++;
				if(*(i -> second.begin()) < *(t -> second.begin()))
				printf("%d %d\n",id,*(i -> second.begin()));
				else
				printf("%d %d\n",id,*(t -> second.begin()));
			}
			else
			{
				i ++;
				printf("%d %d\n",id,*(i -> second.begin()));
			}
		}
		mp[power].insert(id);
	}
	return 0;
}
