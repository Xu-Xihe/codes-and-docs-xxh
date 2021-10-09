#include<stdio.h>
using namespace std;
int main()
{
	int a,b,c;
	scanf("%d%d",&a,&b);
	a=a/10;
	b=b/20;
	c=a+b;
	if(c>=1) printf("1");
	else printf("0");
}
