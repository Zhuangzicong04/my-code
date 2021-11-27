#include <iostream>
using namespace std;
//整数的左边i位是n的左边i位取反，其余位和n相同
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
