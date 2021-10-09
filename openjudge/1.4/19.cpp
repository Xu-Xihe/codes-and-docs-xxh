#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
	int a,b;
	char c[3];
	cin>>a>>b>>c;
	if(strcmp(c,"+")==0) cout<<a+b;
	else if(strcmp(c,"-")==0) cout<<a-b;
		else if(strcmp(c,"*")==0) cout<<a*b;
			else if(strcmp(c,"/")==0&&a!=0) cout<<a/b;
				else if(strcmp(c,"/")==0&&a==0) cout<<"Divided by zero!";
					else cout<<"Invalid operator!";
}
