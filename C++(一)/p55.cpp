#include<iostream>
#include<cstdio>
using namespace std;
struct player{
	int id;
	int score;
};
int main()
{
    int n,m;
    cin >> n >> m;
	player p[n + 1],tmp;
	for(int i = 0;i < n;i ++ )
	cin >> p[i].id >> p[i].score;
    for(int i = n - 1;i > 0;-- i)
    {
    	for(int j = 0;j < i;++ j)
    	{
    		if(p[j].score < p[j + 1].score || (p[j].score == p[j + 1].score && p[j+1].id < p[j].id))
    		{
    			tmp = p[j];
    			p[j] = p[j + 1];
    			p[j + 1] = tmp;
			}
		}
	}
	int a = (int)(1.5 * m);
	int s = p[a - 1].score;
	int count = 0;
	for(int i = 0;i < n; ++ i)
	{
		if(p[i].score >= s)
		count ++;
	 } 
	 cout << s << " " << count << endl;
	 for(int i = 0;i < count; ++ i)
	 cout << p[i].id << " " << p[i].score << endl;
	 return 0;
}
