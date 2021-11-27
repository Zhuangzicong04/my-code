#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n10,n7,n9;
	n10 = 49;
	for(n10;n10 < 343;n10 ++)
	{
		if(n10 / 49 == n10 % 9 && n10 % 49 / 7 == n10 % 81 / 9 && n10 % 7 == n10 / 81)
		break;
	}
	n7 = n10 / 49 * 100 + n10 % 49 / 7 * 10 + n10 % 7;
	n9 = n10 / 81 * 100 + n10 % 81 / 9 * 10 + n10 % 9;
	cout << n10 << endl;
	cout << n7 << endl;
	cout << n9 << endl;
	return 0;
}
