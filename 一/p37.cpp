#include <iostream>
using namespace std;
//���ص������ĵ�iλ��m�ĵ�iλ��ͬ������λ��n��ͬ 
int bitManipulation1(int n, int m, int i) {
	int a ;
	a = (m >> i) & 1 ;
	if(a == 1)
	{
		a = a << i;
		a |= n;
	}
	else
	{
		a = 1;
		a = n & ~(a << i);
	}
	return a;
}

int main() {
	int n, m, i, t;
	freopen("D:\\Desktop\\C++\\1.txt","r",stdin);
	cin >> t;
	while (t--) { 
		cin >> n >> m >> i;
		cout << bitManipulation1(n, m, i) << endl;
	}
	return 0;
}
