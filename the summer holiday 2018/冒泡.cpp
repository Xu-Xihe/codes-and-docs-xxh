#include<iostream>
#include<climits>
using namespace std;
int a[1001];
int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n - 1; ++j)
			if(a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
	for(int i = 1; i <= n; ++i)
		cout << a[i] << ' ';
	return 0;
}



