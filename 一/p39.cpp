#include <iostream>
using namespace std;
//���������iλ��n�����iλȡ��������λ��n��ͬ
int bitManipulation3(int n, int i) {
    int t;
	t = -1 << (8 * sizeof(int) - i);
	return n^t;
}

int main() {
	int t, n, i;
	cin >> t;
	while (t--) {
		cin >> n >> i;
		cout << bitManipulation3(n, i) << endl;
	}
	return 0;
}
