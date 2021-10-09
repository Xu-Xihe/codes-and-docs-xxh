#include<iostream>
#include<climits>
using namespace std;
int a[1000001];
int f[1000001];
int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	int mx = a[1];
	for(int i = 1; i <= n; ++i)
	{
		f[i] = max(0, f[i - 1]) + a[i];
		mx = max(mx, f[i]);
	}
	cout << mx;
	return 0;
}




