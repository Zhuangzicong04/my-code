#include <iostream>
using namespace std;
//�����������iλ��n�����iλȡ��������λ��n��ͬ
int bitManipulation3(int n, int i) {
  int x;
  x = -1 << (sizeof(int) * 8 - i);
  return n ^ x;
  
}

int main() {
	int t, n, i;
	freopen("D:\\Desktop\\C++\\1.txt","r",stdin);
	cin >> t;
	while (t--) {
		cin >> n >> i;
		cout << bitManipulation3(n, i) << endl;
	}
	return 0;
}
