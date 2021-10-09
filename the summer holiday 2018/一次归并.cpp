#include<iostream>
using namespace std;
int main()
{
	int a[1001], b[1001], c[1001];
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int j = 1; j <= m; ++j)
		cin >> b[j];
	int i = 1, j = 1, po = 0;
	while(true)
	{
		if(i <= n && j <= m)
		{
			if(a[i] < b[j])
				c[++po] = a[i++];
			 else 
			 	c[++po] = b[j++];
			continue;
		}
		if(i <= n && j == m + 1)
		{
			c[++po] = a[i++];
			continue;
		}
		if(j <= m && i == n + 1)
		{
			c[++po] = b[j++];
			continue;
		}
		if(i == n + 1 && j == m + 1)
			break;	
	}
	for(int i = 1; i <= po; ++i)
		cout << c[i] << ' ';
	return 0;
}
