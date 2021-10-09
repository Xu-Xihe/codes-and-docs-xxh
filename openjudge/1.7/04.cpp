#include<bits/stdc++.h>
using namespace std;
int main()
{
	char a[20],b[20];
	int d,e[100],f,g;
	cin>>d;
	f=0;
	while(true)
	{
		scanf("%s %s",a,b);
		if(strlen(a)==8&&strlen(b)==4||strlen(a)==5&&strlen(b)==8||strlen(a)==4&&strlen(b)==5)cout<<"Player2\n";
		if(strlen(a)==8&&strlen(b)==5||strlen(a)==5&&strlen(b)==4||strlen(a)==4&&strlen(b)==8)cout<<"Player1\n";
		if(strlen(a)==5&&strlen(b)==5||strlen(a)==8&&strlen(b)==8||strlen(a)==4&&strlen(b)==4)cout<<"Tie\n";
		f++;
		if(f==d)break;
	}
	return 0;
}
