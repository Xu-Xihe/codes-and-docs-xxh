#include<stdio.h>
#include<string.h>
using namespace std;
char ina[1000],inc[10005][1000];
int shu,z;
void jiaohuan(char in[100]){
	int len=strlen(in);
	for(int i=0;i<len;i++){
		if(in[i]>='a'&&in[i]<='z')
			in[i]-=32;
		else if(in[i]>='A'&&in[i]<='Z')
			in[i]+=32;
	}
}
bool shuchu(char inaa[1000],char inbb[1000],char incc[1000]){
	if(strcmp(incc,ina)==0){
		jiaohuan(inbb);
		printf("%s %s\n",inaa,inbb);
		return true;
	}
	return false;
}
int main(){
	scanf("%s%d",ina,&shu);
	for(int i=0;i<shu;i++){
		scanf("%s%s%s",inc[0],inc[1],inc[2]);
		if(shuchu(inc[0],inc[1],inc[2]))z++;
	}
	if(z==0)
		printf("empty");
	return 0;
}
