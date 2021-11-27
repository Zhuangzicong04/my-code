#include<cstdio>
#include<iostream>
#include<set>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	int n,x,f[10006];
	memset(f,0,sizeof(f));
	string c;
	multiset<int> st;
	multiset<int>::iterator i;
	//freopen("D:\\Desktop\\C++\1.txt","r",stdin);
	cin >> n;
	for(int a = 0;a < n; ++ a)
	{
		cin >> c >> x;
		if(c == "add")
		{
			st.insert(x);
			f[x] = 1;
			cout << st.count(x) << endl;
		}
		else if(c == "del")
		{
			cout << st.count(x) << endl;
			st.erase(x);
		}
		else if(c == "ask")
		{
			cout << f[x] << " " << st.count(x) << endl;
		}
		else
		cout << "error";
	}
	return 0;
}
