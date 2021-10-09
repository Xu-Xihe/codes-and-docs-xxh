#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
int main()
{
	double a,b,c,ax,bx,cx,dx;
	cin>>a>>b>>c;
	bx=b*b;
	ax=4*a*c;
	if(bx==ax)
	{
		printf("x1=x2=%.5f",(-b + sqrt(b*b-4*a*c))/(2*a));
	}
	if(bx>ax)
	{
		cx=(-b + sqrt(b*b-4*a*c))/(2*a);
		dx=(-b - sqrt(b*b-4*a*c))/(2*a);
		if(cx>dx) printf("x1=%.5f;x2=%.5f",cx,dx);	
		else printf("x1=%.5f;x2=%.5f",dx,cx);
	}
	if(bx<ax)
	{
		cx=-b / (2*a);
		dx=sqrt(4*a*c-b*b);
		if(cx==0) cx=0;
		if(dx==0) dx=0;
		printf("x1=%.5f+%.5fi;x2=%.5f+%.5fi",cx,dx,cx,dx);
	}
}
