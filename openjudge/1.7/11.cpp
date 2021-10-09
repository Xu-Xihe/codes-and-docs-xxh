#include<stdio.h>
#include<string.h>
using namespace std;
char ina[1080],inb[1080],inc[1080],mi[300],out[1080],ma[300];
int lena,lenc,now;
int main(){
	scanf("%s%s%s",ina,inb,inc);
	lena=strlen(ina);
	lenc=strlen(inc);
	for(int i=0;i<lena;i++)
		mi[ina[i]-'A']=inb[i];
	for(int i=0;i<lena;i++)
		ma[inb[i]-'A']=ina[i];
	for(int i=0;i<26;i++)
		for(int j=i+1;j<26;j++)
			if(mi[i]==mi[j]||ma[i]==ma[j]||ma[i]==0||mi[i]==0){
				printf("Failed");
				return 0;
			}
	for(int i=0;i<lenc;i++)
		out[i]=mi[inc[i]-'A'];
	printf("%s",out);
	return 0;
}
