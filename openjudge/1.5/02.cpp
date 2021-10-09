#include<iostream>
using namespace  std;
int main()
{
	double a[12],b;
	int c=0;
	while(true)
	{
		cin>>a[c];
		c++;
		if(c==12)break;
	}
	c=0;
	while(true)
	{
		b=b+a[c];
		c++;
		if(c==12)break;
	}
	printf("$%.2f",b/12);
}
