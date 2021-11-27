#include<iostream>
#include<cstdio>
#include<set>
#include<cstring>
#include<algorithm>
using namespace std;
struct player{
	int id;
	int str;
};
struct Rule
{
    bool operator()(const player & a1,const player & a2) const{
        return a1.str < a2.str;
    }
};
int main()
{
	int n;
	multiset<player,Rule> st;
	cin >> n;
	player p[n+1];
	p[0] = {1,1000000000};
	st.insert(p[0]);
	for(int i = 1;i < n + 1;++ i)
	{
		cin >> p[i].id >> p[i].str;
		st.insert(p[i]);
	}	
	for(int i = 2;i < n + 1;++ i)
	{
		
	}
}
