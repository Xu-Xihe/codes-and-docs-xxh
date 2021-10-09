#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,x,y,a,b;
	cin>>n>>x>>y;
	a=y%x;
	b=y/x;
	if(a>0)
	{
		b++;
	}
	printf("%d",n-b);
}
