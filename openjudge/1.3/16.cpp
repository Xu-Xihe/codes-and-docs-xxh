#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
	double xa,xb,ya,yb;
	cin>>xa>>ya;
	cin>>xb>>yb;
	printf("%.3f",sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb)));
}
