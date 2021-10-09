#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	double x;
	cin>>x;
	if(x>=0&&x<5) printf("%.3f",-x+2.5);
	if(x>=5&&x<10) printf("%.3f",2-1.5*(x-3)*(x-3));
	if(x>=10&&x<20) printf("%.3f",x/2-1.5);
}
