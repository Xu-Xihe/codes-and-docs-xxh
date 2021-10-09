#include<stdio.h>
#include<string.h>
using namespace std;
char ina[205],inb[205],shou,z;
int lena,lenb;
int main(){
	scanf("%s%s",ina,inb) ;
	lena=strlen(ina);
	lenb=strlen(inb);
	if(strcmp(ina,inb)==0){
		printf("%s is substring of %s",inb,ina);
		return 0;
	}
	else if(lena==lenb){
		printf("No substring");
		return 0;
	}
	if(lena<lenb){
		shou=ina[0];
		for(int i=0;i<lenb;i++)
			if(inb[i]==shou){
				z=0;
				for(int j=0;j<lena;j++)
					if(inb[i+j]==ina[j])z++;
				if(z==lena){
					printf("%s is substring of %s",ina,inb);
					return 0;
				}
			}
		printf("No substring");
		return 0;
	}
	if(lena>lenb){
		shou=inb[0];
		for(int i=0;i<lena;i++)
			if(ina[i]==shou){
				z=0;
				for(int j=0;j<lenb;j++)
					if(ina[i+j]==inb[j])z++;
				if(z==lenb){
					printf("%s is substring of %s",inb,ina);
					return 0;
				}
			}
		printf("No substring");
		return 0;
	}
}
