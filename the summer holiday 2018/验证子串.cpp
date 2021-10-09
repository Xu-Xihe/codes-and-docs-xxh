#include<iostream>
#include<climits>
#include<cstring>
using namespace std;
int main()
{
	char a[1001];
	char b[1001];
	cin >> a >> b;
	for(int i = 0; a[i] != '\0'; ++i)
	{
		bool found_diff = false;
		for(int j = 0; b[j]; ++j)
			if(a[i + j] != b[j])
				found_diff = true;
		if(!found_diff)
		{
			cout << b << " is substring of " << a;
			return 0;
		} 
	}
	for(int i = 0; b[i] != '\0'; ++i)
	{
		bool found_diff = false;
		for(int j = 0; a[j]; ++j)
			if(b[i + j] != a[j])
				found_diff = true;
		if(!found_diff)
		{
			cout << a << " is substring of " << b;
			return 0;
		} 
	}
	cout << "No substring";
	return 0;
}



