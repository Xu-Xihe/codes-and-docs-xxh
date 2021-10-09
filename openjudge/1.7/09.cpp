#include<stdio.h>
#include<string.h>
using namespace std;
char in[85];
int main()
{
	scanf("%[^\n]",in);
	int len=strlen(in),a=0,b;
	while(true){
		b=0;
		if(in[a]>=65&&in[a]<=90)b=5;
		if(in[a]>=97&&in[a]<=122)b=5;
		if(b==5){
			if(in[a]=='Z')in[a]='A';
			else if(in[a]=='z')in[a]='a';
				else in[a]++;
			a++;
		}
		else a++;
		if(a==len)break;
	}
	printf("%s",in);
	return 0;
}
