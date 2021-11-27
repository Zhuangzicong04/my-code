#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,sum[20],total[20];
	double x,y;
	cin >> n;
	for(int i = 0;i < n;++ i)
	{
		cin >> sum[i] >> total[i];
	}
	x = (double)total[0]/sum[0];
	for(int i = 1;i < n;++ i)
	{
		y = (double)total[i]/sum[i];
		if(x - y > 0.05)
		cout << "worse" << endl;
		else if(y - x > 0.05)
		cout << "better" << endl;
		else
		cout << "same" << endl;
	} 
	return 0;
}
