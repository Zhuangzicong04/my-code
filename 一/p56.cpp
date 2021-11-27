#include<iostream>
#include<cstdio>
using namespace std;
struct patient
{
    char ID[20];
    int age;
    int k;
};
int main()
{
    int n,q = 0;
    freopen("C:\\Codefield\\CODE_C\\C_Single\\Online Judge\\1.txt","r",stdin);
    cin >> n;
    patient p[200],tmp;
    for(int i = 0;i < n; ++ i)
    {
         cin >> p[i].ID >> p[i].age;
         q ++ ;
         p[i].k = q;
    }
    for(int i = 0;i < n; ++ i)
    {
        for(int j = i + 1;j < n;++ j)
        {
            if(p[i].age >= 60 )
            {
                if(p[i].age < p[j].age)
                {
                     tmp = p[i];
                     p[i] = p[j];
                     p[j] = tmp;
                }
                if(p[i].age == p[j].age && p[i].k > p[j].k)
                {
                     tmp = p[i];
                     p[i] = p[j];
                     p[j] = tmp;
                }
            }
            else if(p[i].age < 60 && p[j].age >= 60)
            {
                     tmp = p[i];
                     p[i] = p[j];
                     p[j] = tmp;
            }
            else if(p[i].age < 60 && p[j].age < 60)
            {
                    if(p[i].k > p[j].k)
                    {
                        tmp = p[i];
                        p[i] = p[j];
                        p[j] = tmp;
                    }
            }
        }
        cout << p[i].ID << endl;
    }
    return 0;
}