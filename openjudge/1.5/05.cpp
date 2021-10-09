#include<iostream>
using namespace std;
int main()
{
	int a[100],b,c=0,d;
	cin>>d;
	while(true)
	{
		cin>>a[c];
		c++;
		if(c==d)break;
	}
	c=1;
	b=a[0];
	while(true)
	{
		if(a[c]>b) b=a[c];
		c++;
		if(c==d)break;
	}
	cout<<b;
} 
