#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int a,b,na,nb,ha,hb;
	cin>>a>>b>>na;
	hb=b;
	na--;
	na--;
	for(;nb<na;nb++)
	{
		ha=hb+(b-a);
		hb=ha;	
	}
	printf("%d",ha);
}
