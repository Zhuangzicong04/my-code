#include<iostream>
#include<cstdio>
using namespace std;
struct volunteer
{
    int k;
    int s;
};

int main()
{
    int n,m;
    cin >> n >> m;
    volunteer v[n + 1],tmp;
    for(int i = 0;i < n; ++ i)
    {
          cin >> v[i].k >> v[i].s;
    }
    int t ;
    t = (int) m * 1.50;
    for(int i = 0;i < n; ++ i)
    {
        for(int j = i + 1;j <= n; ++ j)
        if(v[i].s < v[j].s)
        {
            tmp = v[i];
            v[i] = v[j];
            v[j] = tmp;
        }
        else if(v[i].s == v[j].s)
        {
              if(v[i].k > v[j].k )
              {
                   tmp = v[i];
                   v[i] = v[j];
                   v[j] = tmp;
              }
        }
    }
    for(int i = t - 1;i < n; ++ i)
    {
        if(v[i].s > v[i + 1].s)
        break;
        else if(v[i].s == v[i + 1].s)
        t += 1;
    }
    cout << v[t - 1].s << " " <<  t << endl;
    for(int i = 0;i < t; i ++ )
    cout <<  v[i].k << " " << v[i].s << endl;
    return 0;
}
