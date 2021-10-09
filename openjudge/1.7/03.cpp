#include<bits/stdc++.h>
using namespace std;
int main()
{
	double c,d;
	char a[501],b[501];
	int e=0;
	cin>>c;
	scanf("%s\n%s",a,b);
	d=strlen(a);
	while(true)
	{
		if(a[e]!=b[e])d--;
		e++;
		if(e>strlen(a))break;
	}
	d=d/strlen(a);
	if(d>=c)cout<<"yes";
	else cout<<"no";
}
