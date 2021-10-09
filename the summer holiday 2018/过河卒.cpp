#include<iostream>
#include<cmath>
using namespace std;
long long f[30][30];
int main()
{
	f[1][0] = 1;
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	++x;
	++y;
	++n;
	++m;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			if(i == x && j == y || abs(i - x) == 1 && abs(j - y) == 2 || abs(i - x) == 2 && abs(j - y) == 1)
				f[i][j] = 0;
			else	
				f[i][j] = f[i - 1][j] + f[i][j - 1];
	cout << f[n][m];
	return 0;
}
