#include<iostream>
using namespace std;
int main()
{
	int a,b=0;
	cin>>a;
	if((a%4)==0) b=100;
	if((a%100)==0&&(a%400)!=0) b=58;
	if((a%3200)==0) b=99;
	if(b==100) cout<<"Y";
	else cout<<"N";
}
