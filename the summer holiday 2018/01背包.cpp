#include<iostream>
#include<cstring>
using namespace std;
int f[1001][1001];
int main()
{
	int m, n,nll;
	scanf("%d",&nll);
	int w[101], c[101];
	while(nll--){
		memset(f,0,sizeof(f));
		cin >> m >> n;
		for(int i = 1; i <= n; ++i)
			cin >> w[i] ;
		for (int i = 1; i <= m; i++)
		{
			cin >> c[i];
		}
		
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j)
			{
				f[i][j] = f[i - 1][j];
				if(j >= w[i])
					f[i][j] = max(f[i][j], f[i - 1][j - w[i]] + c[i]);
			}
		cout << f[n][m];
	}
	return 0;
}