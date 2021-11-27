#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	long long a;
	cin >> a;
	while( a != 1)
	{
		if(a % 2 == 0){
			cout << a << "/2=";
			a /= 2;
	    	cout << a << endl;
		}
		else{
			cout << a << "*3+1="; 
			a = a*3 +1;
			cout << a << endl;
		}
	}
	cout << "End";
	return 0;
}
