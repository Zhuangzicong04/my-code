#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int x,y;
	char c;
	cin >> x >> y >> c;
	switch(c)
	{
		case '+':
		cout << x + y;
		break;
		case '-':
		cout << x - y;
		break;
		case '*':
		cout << x * y;
		break;
		case '/':
		if(y == 0)
		{
			cout << "Divided by zero!";
			break;
		}
		else
		cout << x/y;
		break;
		default:
		cout << "Invalid operator!";
	}
	return 0;
}
