#include<iostream>
#include<climits>
#include<cstring>
using namespace std;
char a[100001], b[100001];
int f[1001][1001];
int main()
{
	while(cin >> a + 1 >> b + 1)
	{
		int n = strlen(a + 1), m = strlen(b + 1);
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j)
				if(a[i] == b[j])
					f[i][j] = f[i - 1][j - 1] + 1;
				else
					f[i][j] = max(f[i - 1][j], f[i][j - 1]);
		cout << f[n][m] << endl;
	}
	return 0;
}




