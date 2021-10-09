#include<iostream>
#include<climits>
#include<cstring>
using namespace std;
int a[1001][1001];
int f[1001][1001];
int main()
{
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			cin >> a[i][j];
		
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= m; ++j)
			f[i][j] = INT_MIN / 2;	
	f[0][0] = 0;	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			for(int k = 0; k < j; ++k)
				f[i][j] = max(f[i][j], f[i - 1][k] + a[i][j]);
	int ans = INT_MIN;
	for(int i = 1; i <= m; ++i)
		ans = max(ans, f[n][i]);
	cout << ans << endl;	
	return 0;
}




