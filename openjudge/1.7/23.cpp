#include<stdio.h>
#include<string.h>
using namespace std;
char in[300];
int len,z=888;
int main(){
	scanf("%[^\n]",in);
	len=strlen(in);
	for(int i=0;i<len;i++){
		if(in[i]==' '&&z==0)continue;
		if(in[i]==' '&&z==888)z=0;
		if(in[i]!=' ')z=888;
		printf("%c",in[i]);
	}
	return 0;
}
