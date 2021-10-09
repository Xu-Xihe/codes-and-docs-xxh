#include<iostream>
#include<climits>
#include<cstring>
using namespace std;
int h[101][101];
int f[101][101];
int n, m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int calc(int i, int j)
{
	if(f[i][j] != -1)
		return f[i][j];
	f[i][j] = 1;
	for(int k = 0; k < 4; ++k)
	{
		int x = i + dx[k];
		int y = j + dy[k];
		if(x && x <= n && y && y <= m)
			if(h[x][y] < h[i][j])
				f[i][j] = max(f[i][j], calc(x, y) + 1);
	}
	return f[i][j];
}
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
		{
			cin >> h[i][j];
			f[i][j] = -1;
		}
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			calc(i, j);
	int mx = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			mx = max(mx, f[i][j]);
	cout << mx;
	return 0;
}




