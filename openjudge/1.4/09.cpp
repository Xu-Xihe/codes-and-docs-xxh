#include<iostream>
using namespace std;
int main()
{
	int a,b,c,d,e,f,g,h;
	cin>>a;
	b=a%105;
	c=a%15;
	d=a%21;
	e=a%35;
	f=a%3;
	g=a%5;
	h=a%7;
	if(b==0) cout<<"3 5 7";
	else if(c==0) cout<<"3 5";
		 else if(d==0) cout<<"3 7";
		 	  else if(e==0) cout<<"5 7";
				   else if(f==0) cout<<"3";
				   		else if(g==0) cout<<"5";
				   			 else if(h==0) cout<<"7";
				   			 	  else cout<<"n";
}
