#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a;
	cin>>b;
	cin>>c;
	cout<<setw(8) <<right<<a;
	cout<<" ";
	cout<<setw(8) <<right<<b;
	cout<<" ";
	cout<<setw(8) <<right<<c;
}
