#include<stdio.h>
#include<string.h>
using namespace std;
char in[1000],ina[305],inb[20],inc[20];
int aq,az,bq=-1;
int zichuan(char a[300],char b[205],int i){
	char t=b[0];
	int lena=strlen(a),lenb=strlen(b);
	int z=0;
	for(;i<lena;i++){
		if(a[i]==t){
			z=0;
			for(int j=0;j<lenb;j++)
				if(a[i+j]==b[j])z++;
		}
		if(z==lenb){
			return i;
		}
	}
	return -1;
}
int main(){
	scanf("%s",in);
	int len=strlen(in);
	int i=0;
	for(;i<len;i++){
		if(in[i]==',')break;
		else ina[i]=in[i];
	}
	for(int j=0,z=0;i<len;i++){
		if(in[i]==','&&z==888)break;
		if(in[i]!=','){
			z=888;
			inb[j]=in[i];
			j++;
		}
	}
	for(int j=0,z=0;i<len;i++){
		if(in[i]=='\n'&&z==888)break;
		if(in[i]!=','){
			z=888;
			inc[j]=in[i];
			j++;
		}
	}
	aq=zichuan(ina,inb,0);
	if(aq==-1){
		printf("-1");
		return 0;
	}
	az=aq+strlen(inb);
	while(true){
		if(zichuan(ina,inc,bq+1)==-1)break;
		if(az>=zichuan(ina,inc,bq+1)){
			printf("-1");
			return 0;
		}
		bq=zichuan(ina,inc,bq+1);
	}
	if(bq==-1){
		printf("-1");
		return 0;
	}
	printf("%d",bq-az);
	return 0;
}
