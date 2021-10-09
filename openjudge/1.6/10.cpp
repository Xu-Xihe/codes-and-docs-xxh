#include<stdio.h>
using namespace std;
int ina[205],inb[205],outa[205],lena,lenb,len,z;
int shuru(int in[205]){
	int z=0;
	for(int i=0;;i++){
		char a;
		if(scanf("%c",&a)==EOF)return i;
		if(a=='\n')return i;
		if(a>='1'&&a<='9')z=888;
		if(a>='0'&&a<='9'&&z==888)in[i]=a-'0';
		if(a=='0'&&z==0)i--;
	}
}
void zhuan(int in[205],int len){
	int lin[205];
	for(int i=0;i<len;i++){
		lin[i]=in[i];
	}
	for(int i=0;i<len;i++){
		in[i]=lin[len-i-1];
	}
}
int main(){
	lena=shuru(ina);
	lenb=shuru(inb);
	if(lena>lenb)len=lena;
	else len=lenb;
	zhuan(ina,lena);
	zhuan(inb,lenb);
	for(int i=0;i<len;i++){
		outa[i]=ina[i]+inb[i];
	}
	for(int i=0;i<len;i++){
		int lin=outa[i]/10;
		outa[i]%=10;
		outa[i+1]+=lin;
	}
	for(len=204;len>=0;len--){
		if(outa[len]!=0)break;
	}
	for(int i=len;i>=0;i--){
		printf("%d",outa[i]);
	}
	if(len<0)printf("0");
}
