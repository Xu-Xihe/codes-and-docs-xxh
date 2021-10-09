#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n ;
	cin >> n;
	int a[10001];
	int len1[10001], len2[10001];
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	int ans = 0;
	for(int i = 1; i <= n; ++i)
	{
		int maxlen = 0;
		for(int j = 1; j < i; ++j) 
			if(a[j] < a[i])
				maxlen = max(maxlen, len1[j]);
		len1[i] = maxlen + 1;
	}
	for(int i = n; i >= 1; --i)
	{
		int maxlen = 0;
		for(int j = n; j > i; --j) 
			if(a[j] < a[i])
				maxlen = max(maxlen, len2[j]);
		len2[i] = maxlen + 1;
	}
	for(int i = 1; i <= n; ++i)
		ans = max(ans, len1[i] + len2[i] - 1);
	cout << ans;
    return 0;
}
