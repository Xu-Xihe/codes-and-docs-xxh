#include<iostream>
#include<climits>
#include<cstring>
using namespace std;
char a[100001], b[100001];
int f[3001][3001];
int main()
{
	while(cin >> a + 1 >> b + 1)
	{
		int n = strlen(a + 1), m = strlen(b + 1);
		for(int i = 1; i <= n; ++i)
			f[i][0] = i;
		for(int i = 1; i <= m; ++i)
			f[0][i] = i;	
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j)
				if(a[i] == b[j])
					f[i][j] = f[i - 1][j - 1];
				else
					f[i][j] = min(f[i - 1][j - 1], min(f[i - 1][j], f[i][j - 1])) + 1;
		cout << f[n][m] << endl;
	}
	return 0;
}




