#include<stdio.h>
#include<string.h>
using namespace std;
char ina[40],inb[40];
int lena,lenb,z;
int panduan(char ina[50],char inb[50]){//aÊÇbµÄ×Ó´® 
	char shou=ina[0];
		for(int i=0;i<lenb;i++)
			if(inb[i]==shou){
				z=0;
				for(int j=0;j<lena;j++)
					if(inb[i+j]==ina[j])z++;
				if(z==lena){
					printf("true",ina,inb);
					return 1;
				}
			}
}
void jiaohuan(char in[40]){
	int len=strlen(in);
	char a=in[0];
	for(int i=1;i<len;i++)
		in[i-1]=in[i];
	in[len-1]=a;
	return ;
}
void shuchu(char ina[50],char inb[50]){//lena<lenb
	int len=strlen(ina);
	for(int i=0;i<len;i++){
			jiaohuan(ina);
			//printf("%d:%s\n",i+1,ina);
			if(panduan(inb,ina)==1)return ;
		}
		printf("false");
		return ;
}
int main(){
	scanf("%s%s",ina,inb);
	lena=strlen(ina);
	lenb=strlen(inb);
	if(strcmp(ina,inb)==0){
		printf("true");
		return 0;
	}
	else if(lena==lenb){
		shuchu(ina,inb);
		return 0;
	}
	if(lena<lenb){
		shuchu(inb,ina);
		return 0;
	}
	if(lena>lenb){
		shuchu(ina,inb);
		return 0;
	}
}
