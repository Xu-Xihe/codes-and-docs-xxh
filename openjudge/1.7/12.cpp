#include<stdio.h>
#include<string.h>
using namespace std;
char in[58],out[58];
int len;
int main(){
	scanf("%s",in);
	len=strlen(in);
	for(int i=0;i<len;i++){
		if(in[i]=='X')in[i]='A';
		else if(in[i]=='x')in[i]='a';
		else if(in[i]=='Y')in[i]='B';
		else if(in[i]=='y')in[i]='b';
		else if(in[i]=='Z')in[i]='C';
		else if(in[i]=='z')in[i]='c';
		else in[i]+=3;
		if(in[i]<91)in[i]+=32;
		else in[i]-=32;
	}
	for(int i=0;i<len;i++)
		out[i]=in[len-1-i];
	printf("%s",out);
	return 0;
}

