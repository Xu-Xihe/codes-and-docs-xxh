#include<iostream>
#include<climits>
using namespace std;
int main()
{
	int n;
	int a[1001];
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= n; ++i)
		for(int j = i; j >= 2; --j)
			if(a[j - 1] > a[j])
				swap(a[j - 1], a[j]);
			else
				break;
	
	for(int i = 1; i <= n; ++i)
		cout << a[i] << ' ';
	return 0;
}



