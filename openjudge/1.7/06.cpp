#include<stdio.h>
#include<string.h>
using namespace std;
char a[25];
int b=1,c=0,len;
int main()
{
	scanf("%s",a);
	len=strlen(a);
	if(a[0]>=65&&a[0]<=90) c=2;
	if(a[0]>=97&&a[0]<=122) c=2;
	if(a[0]==95) c=2;
	if(c!=2)
	{
		printf("no");
		return 0;
	}
	else if(len==1){
		printf("yes");
		return 0;
	}
	while(true){
		if(a[b]>=65&&a[b]<=90) c=2;
		if(a[b]>=97&&a[b]<=122) c=2;
		if(a[b]>=48&&a[b]<=57) c=2;
		if(a[b]==95) c=2;
		if(c!=2)
		{
			printf("no");
			return 0;
		}
		else c=0;
		b++;
		if(b==len)break;
	}
	printf("yes");
	return 0;
 } 
