#include<iostream>
#include<cstdio>
using namespace std;
struct student{
	string name;
	int score;
};
int main()
{
	int n;
	student s[20],tmp;
	cin >> n;
	for(int i = 0;i < n; ++ i)
	{
		cin >> s[i].name >> s[i].score;
	}
	for(int i = 0;i < n - 1;++ i)
	{
		int tmpMax = i;
		for(int j = i + 1;j < n;++ j)
		{
			if(s[j].score > s[tmpMax].score || (s[j].score == s[tmpMax].score && s[j].name < s[tmpMax].name))
				tmpMax = j;
		}
		tmp = s[i];
		s[i] = s[tmpMax];
		s[tmpMax] = tmp;
	}
	for(int i = 0;i < n; ++ i)
	cout << s[i].name << " " << s[i].score << endl;
	return 0;
}
