#include<bits/stdc++.h>
using namespace std;
int main()
{
	double b[10000],c;
	int a,d;
	cin>>a;
	d=0;
	while(true)
	{
		cin>>b[d];
		c=c+b[d];
		d++;
		if(d==a)break;
	}
	cout<<c;
	printf(" %.5f",c/a);
}
