#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int x,y;
	cin >> x >> y;
	if(-1 <= x && x <= 1){
		if(-1 <= y && y <= 1)
	    cout << "yes";
	    else cout << "no";
	}
	else
	cout << "no";
	return 0;
}
