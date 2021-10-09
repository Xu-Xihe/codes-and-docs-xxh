#include<iostream>
#include<climits>
#include<cstring>
using namespace std;
int a[1001][1001];
int f[1001][1001];
int pre[1001][1001];
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
				if(f[i][j] < f[i - 1][k] + a[i][j])
				{
					f[i][j] = f[i - 1][k] + a[i][j];
					pre[i][j] = k;
				}
	int mx = 1;
	for(int i = 1; i <= m; ++i)
		if(f[n][mx] < f[n][i])
			mx = i;
	cout << f[n][mx] << endl;
	int pos[1001];
	for(int k = n; k >= 1; --k)
	{
		pos[k] = mx;
		mx = pre[k][mx];
	}
	for(int i = 1; i <= n; ++i)
		cout << pos[i] << ' ';
	return 0;
}




