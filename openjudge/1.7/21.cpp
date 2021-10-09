#include<stdio.h>
#include<string.h>
using namespace std;
char in[10000][10000],ina[1000],inb[1000];
int lena,lenb,chang;
int main(){
	for(int i=0;~scanf("%s",in[i]);i++)
	while(true){
		if(in[chang][0]==0)break;
		else chang++;
	}
	strcpy(inb,in[chang-1]);
	strcpy(ina,in[chang-2]);
	lena=strlen(ina);
	lenb=strlen(inb);
	for(int i=0;i<chang-2;i++)
		if(strcmp(in[i],ina)==0)
			strcpy(in[i],inb);
	for(int i=0;i<chang-2;i++)
	printf("%s ",in[i]);
	return 0;
}
