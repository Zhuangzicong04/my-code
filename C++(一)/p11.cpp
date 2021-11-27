#include<iostream>
#include<cstdio>
using namespace std;
#define Pi 3.14159
int main()
{
	int h,r,n;
	cin >>  h >> r;
	n = 20 * 1000 / (Pi * r * r * h) + 1;
	cout << n;
	return 0;
}
