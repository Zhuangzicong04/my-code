#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,a,b;//a为总病例，b为治疗有效病例 ,x为有效率
	double x,y; 
	cin >> n;
	cin >> a >> b;
	x = (double)b/a;
	for(int i = 1;i < n;++ i)
	{
		cin >> a >> b;
		y = (double)b/a;
		if(x - y > 0.05)
		cout << "worse" << endl;
		else if(y - x > 0.05)
		cout << "better" << endl;
		else
		cout << "same" << endl;
	}
	return 0;
 } 
