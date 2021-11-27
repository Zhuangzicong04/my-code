#include <iostream>
using namespace std;
//使得函数返回值为一个整数,该整数的第i位和m的第i位相同，其他位和n相同。
int bitManipulation1(int n, int m, int i) {
	int a;
	a = (m >> i) & 1;
	if(a == 1)
	return n | (1 << i);
	else
	return n & ~(1 << i);
}

int main() {
	int n, m, i, t;
	cin >> t;
	while (t--) { 
		cin >> n >> m >> i;
		cout << bitManipulation1(n, m, i) << endl;
	}
	return 0;
}
