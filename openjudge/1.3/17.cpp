#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
	double xa,xb,ya,yb,xc,yc,p,a,b,c;
	cin>>xa>>ya;
	cin>>xb>>yb;
	cin>>xc>>yc;
	a=sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
	b=sqrt((xb-xc)*(xb-xc)+(yb-yc)*(yb-yc));
	c=sqrt((xc-xa)*(xc-xa)+(yc-ya)*(yc-ya));
	p=(a+b+c)/2;
	printf("%.2f",sqrt(p*(p-a)*(p-b)*(p-c)));
}
