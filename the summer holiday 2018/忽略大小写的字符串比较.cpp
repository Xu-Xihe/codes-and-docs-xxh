#include<iostream>
#include<climits>
#include<cstring>
using namespace std;
int main()
{
	char a[10001];
	char b[10001];
	gets(a);
	gets(b);
	for(int i = 0; a[i]; ++i)
		a[i] = tolower(a[i]);
	for(int i = 0; b[i]; ++i)
		b[i] = tolower(b[i]);
	for(int i = 0; ; ++i)
		if(a[i] == '\0' && b[i] == '\0')
		{
			cout << '=';
			return 0;
		}
		else if(a[i] < b[i])
		{
			cout << '<';
			return 0;
		}
		else if(a[i] > b[i])
		{
			cout << '>';
			return 0;
		}
	return 0;
}



