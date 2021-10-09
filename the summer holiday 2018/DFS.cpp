#include<bits/stdc++.h>
#define MAXN 500002
using namespace std;
int n, m;
int f[1001][1001];
int vis[1001];
void dfs(int u)
{
	vis[u] = true;
	cout << "found:" << u << endl;
	for(int i = 1; i <= n; ++i)
		if(f[u][i] == 1 && vis[i] == false)
			dfs(i);
}
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= m; ++i)
	{
		int a, b;
		cin >> a >> b;
		f[a][b] = f[b][a] = 1;
	}
	dfs(1);
	return 0;	
}
