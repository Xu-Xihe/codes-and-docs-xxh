#include<iostream>
using namespace std;
int main()
{
	double a,ax,bx;
	cin>>a;
	ax=27+23+a/3;
	bx=a/1.2;
	if(ax==bx) cout<<"All";
	if(ax>bx) cout<<"Walk";
	if(ax<bx) cout<<"Bike";
}
