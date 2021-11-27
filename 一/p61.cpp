#include<iostream>
#include<cstdio>
#include<set>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int n,a,f[100006];
    string s;
    multiset<int> st;
    memset(f,0,sizeof(f));
    //freopen("D:\\Desktop\\C++\1.txt","r",stdin);
    cin >> n;
    for(int i = 0;i < n; ++ i)
    {
        cin >> s >> a;
        if(s == "add")
        {
            st.insert(a);
            f[a] = 1;
            cout << st.count(a) << endl;
        }
        else if(s == "del")
        {
            cout << st.count(a) << endl;
            st.erase(a);
        }
        else if(s == "ask")
        {
            cout << f[a] << " ";
            cout << st.count(a) << endl;
        }
    }
    return 0;
}
