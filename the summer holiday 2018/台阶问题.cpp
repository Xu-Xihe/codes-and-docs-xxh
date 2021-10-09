#include<iostream>
using namespace std;
int f[1000001];
int main()
{
	int n, k;
	cin >> n >> k;
	f[0] = 1;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= k; ++j)
			if(i - j >= 0)
				f[i] = (f[i - j] + f[i]) % 100003;
	cout << f[n];
	return 0;
}
