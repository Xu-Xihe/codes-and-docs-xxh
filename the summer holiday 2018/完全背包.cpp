#include<iostream>
using namespace std;
int f[1001][1001];
int main()
{
	int m, n;
	int w[101], c[101];
	cin >> m >> n;
	for(int i = 1; i <= n; ++i)
		cin >> w[i] >> c[i];
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
		{
			f[i][j] = f[i - 1][j];
			if(j >= w[i])
				f[i][j] = max(f[i][j], f[i][j - w[i]] + c[i]);
		}
	cout << "max=" << f[n][m];
	return 0;
}




