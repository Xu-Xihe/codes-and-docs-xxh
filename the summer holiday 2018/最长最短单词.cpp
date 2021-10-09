#include<iostream>
#include<climits>
#include<cstring>
using namespace std;
int main()
{
	string a[200];
	int n = 0;
	while(cin >> a[n++]);
	--n;
	int len = 0;
	for(int i = 0; i < n; ++i)
		if(a[i].size() > len)
			len = a[i].size();
	for(int i = 0; i < n; ++i)
		if(a[i].size() == len)
		{
			cout << a[i] << endl;
			break;
		}
	len = 100000;
	for(int i = 0; i < n; ++i)
		if(a[i].size() < len)
			len = a[i].size();
	for(int i = 0; i < n; ++i)
		if(a[i].size() == len)
		{
			cout << a[i];
			break;
		}
	return 0;
}



