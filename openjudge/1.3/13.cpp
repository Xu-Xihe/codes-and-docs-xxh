#include<iostream>
using namespace std;
int main()
{
	int a,b,c,d;
	cin>>a;
	b=a%10;
	c=a%100/10;
	d=a%1000/100;
	cout<<b<<c<<d;
}
