#include<iostream>
#include<climits> 
using namespace std;
int a[101][101];
int f[101][101];
int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			cin >> a[i][j];
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= n; ++j)
			f[i][j] = INT_MAX;
	f[0][1] = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			f[i][j] = min(f[i - 1][j], f[i][j - 1]) + a[i][j];
	cout << f[n][n] << endl; 
	return 0;
}




