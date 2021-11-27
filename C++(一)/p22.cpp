#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	long long n;
	cin >> n;
	while(n != 1)
	{
		if(n % 2 == 0)
		{
			printf("%lld/2=",n);
			n /= 2;
			printf("%lld\n",n);
		}
		else
		{
			printf("%lld*3+1=",n);
			n = n * 3 + 1;
			printf("%lld\n",n);
		}
	}
	printf("End");
	return 0;
}

