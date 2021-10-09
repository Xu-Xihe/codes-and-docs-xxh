#include<iostream>
using namespace std;
int a[101][101];
int f[101][101];
int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= i; ++j)
			cin >> a[i][j];
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= i; ++j)
		{
			f[i][j] = max(f[i - 1][j - 1], f[i - 1][j]) + a[i][j];
			//cout << f[i][j] << ' ';
		}
		//cout << endl;
	}
	int mx = 0;
	for(int i = 1; i <= n; ++i)
		mx = max(f[n][i], mx);
	cout << mx << endl; 
	return 0;
}




