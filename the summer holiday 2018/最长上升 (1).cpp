#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a[10001];
	int len[10001];
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	int ans = 0;
	for(int i = 1; i <= n; ++i)
	{
		int maxlen = 0;
		for(int j = 1; j < i; ++j) 
			if(a[j] < a[i])
				maxlen = max(maxlen, len[j]);
		len[i] = maxlen + 1;
		ans = max(ans, len[i]);
	}
	cout << ans;
    return 0;
}
