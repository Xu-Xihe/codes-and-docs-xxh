#include<stdio.h>
using namespace std;
char ina[220],inb[220],out[220];
int cang;
void shuru(char out[220]){
	int z=0;
	for(int i=0;~scanf("%c",&out[i]);i++){
		if(out[i]>'0')z=88;
		if(z==0)i--;
		if(out[i]=='\n'){
			out[i]=0;
			if(z==0)out[0]=0;
			return ;
		}
		else out[i]-='0';
	}
}
int changdu(char in[220]){
	for(int i=205;i>=0;i--){
		if(in[i]!=0&&i>0)return i;
	}
	return 0;
}
void jiaohuan(char in[220],int len){
	char linshi[220];
	for(int i=0;i<=len;i++){
		linshi[i]=in[len-i];
	}
	for(int i=0;i<=len;i++)
		in[i]=linshi[i];
	return ;
}
int main(){
	shuru(ina);
	shuru(inb);
	if(changdu(ina)>changdu(inb))cang=changdu(ina);
	else cang=changdu(inb);
	jiaohuan(ina,changdu(ina));
	jiaohuan(inb,changdu(inb));
	for(int i=0;i<=cang;i++){
		int z=ina[i]+inb[i];
		out[i]=z%10;
		ina[i+1]+=z/10;
	}
	cang=changdu(out);
	for(int i=cang;i>=0;i--)
		printf("%d",out[i]);
	return 0;
}
