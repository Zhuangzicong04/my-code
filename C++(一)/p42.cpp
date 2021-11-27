#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n;
	char a[10],b[10];
	cin >> n;
	for(int i = 0;i < n;++ i)
	{
		cin >> a >> b;
		if(a[0] == b[0])
		cout << "Tie" << endl;
		else if((a[0] == 'R' && b[0] == 'S') || (a[0] == 'S' && b[0] == 'P') || (a[0] == 'P' && b[0] == 'R'))
		cout << "Player1" << endl;
		else
		cout << "Player2" << endl;
	}
	return 0;
}
//更多题解请看以下链接 
//https://blog.csdn.net/lq1990717/article/details/113533101
