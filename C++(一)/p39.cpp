#include <iostream>
using namespace std;
//该整数的左边i位是n的左边i位取反，其余位和n相同
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
