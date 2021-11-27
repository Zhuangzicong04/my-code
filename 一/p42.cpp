#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n;
	cin >> n;
	char s1[10],s2[10];
	for(int i = 0;i < n; ++ i)
	{
		cin >> s1 >> s2;
		if(s1[0] == s2[0])
		cout << "Tie" << endl;
		else if((s1[0] == 'R' && s2[0] == 'S') || (s1[0] == 'S' && s2[0] == 'P') || (s1[0] == 'P' && s2[0] == 'R'))
		cout << "Player1" << endl;
		else
		cout << "Player2" << endl;
	}
	return 0;
}
