#include<stdio.h>
#include<string.h>
using namespace std;
char in[10000][10000];
int chang;
int main(){
	for(int i=0;~scanf("%s",in[i]);i++)
	while(true){
		if(in[chang][0]!=0)chang++;
		else break;
	}
	for(int i=0;i<chang-1;i++)
	printf("%d,",strlen(in[i]));
	printf("%d",strlen(in[chang-1]));
	return 0;
}
