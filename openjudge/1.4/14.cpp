#include<iostream>
#include<stdio.h> 
#include<string.h>
using namespace std;
int main()
{
	int a,b,c,h;
	scanf("%d %c",&a,&c);
	if(c==121) h=5;
	else h=0;
	h=h+8;
	if(a>1000) 
	{
		a=a-1000;
		b=a/500;
		h=h+b*4;
		b=a%500;
		if(b!=0) h=h+4; 
	}
	cout<<h;
}
