#include<iostream>
using namespace std;
int main()
{
	int a,b,c,can=1;
	cin>>a>>b>>c;
	if ((a+b)<=c || (a+c)<=b || (b+c)<=a) can = 0;
    cout << (can?"yes":"no");
}
