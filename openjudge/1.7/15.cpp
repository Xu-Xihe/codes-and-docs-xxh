#include<stdio.h>
#include<string.h>
using namespace std;
char in[100];
int ins,len;
int main(){
	scanf("%d",&ins);
	for(int i=0;i<ins;i++){
		scanf("%s",in);
		len=strlen(in);
		if(in[0]>90&&in[0]<123)in[0]-=32;
		for(int i=1;i<len;i++)
			if(in[i]>64&&in[i]<91)in[i]+=32;
		printf("%s\n",in);
	}
	return 0;
}
