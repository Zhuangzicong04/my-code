#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,a,b;//aΪ�ܲ�����bΪ������Ч���� ,xΪ��Ч��
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
