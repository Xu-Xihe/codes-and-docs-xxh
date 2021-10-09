#include<stdio.h>
#include<string.h>
using namespace std;
char in[105];
int len;
int main(){
	scanf("%[^\n]",in);
	len=strlen(in);
	for(int i=0;i<len;i++){
		if(in[i]<91&&in[i]>64)in[i]+=32;
		if(in[i]<123&&in[i]>96)in[i]-=32;
	}
	printf("%s",in);
	return 0;
}
