#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int m,n,x;
	cin >> m >> n >> x;
	while(x > 0 )
  {
		int t = m / n;
		if(m % n)
		t ++;
		if(x < t)
		break;
		x -= t;
		t = m / n;
		n += t;
  }
	cout << n;
	return 0;
}
