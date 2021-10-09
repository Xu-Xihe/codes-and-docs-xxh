#include<bits/stdc++.h>
using namespace std;
int main()
{
	double a[100],c=0,d;
	int b;
	cin>>d;
	b=0;
	while(true)
	{
		cin>>a[b];
		b++;
		if(b==d)break;
	}
	b=0;
	while(true)
	{
		c=c+a[b];
		b++;
		if(b==d)break;
	}
	c=c/d;
	printf("%.2f",c);
}
