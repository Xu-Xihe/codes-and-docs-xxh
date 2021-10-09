#include<iostream>
#include<cstdio>
#include<climits>
using namespace std;
int a[1001];
int f[1001][1001];
int ans[1001];
int main()
{
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= m; ++j)
			f[i][j] = INT_MAX;
	f[0][0] = 0;
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			int sum = 0;
			for(int k = i; k >= 1; --k)
			{
				sum += a[k];
				if(f[i][j] >= max(sum, f[k - 1][j - 1]))
					f[i][j] = max(sum, f[k - 1][j - 1]);
			}
		}
	}
	int pos = m;
	int sum = 0;
	ans[m] = n;
	for(int i = n; i >= 1; --i)
	{
		if(sum + a[i] > f[n][m])
		{
			sum = 0;
			ans[--pos] = i;
		}
		sum += a[i];
	}
	for(int i = 1; i <= m; ++i)
		cout << ans[i - 1] + 1 << ' ' << ans[i] << endl;
    return 0;
}





