#include<stdio.h>
using namespace std;
int len,inb[105],inc[105],ind[105],zong[105];
char ina[105][105];
bool ine[105],inf[105];
bool jia(int ina,int inb){
	if(ina<=80)return false;
	if(inb==0)return false;
	else return true;
}
bool jib(int ina,int inb){
	if(ina<=85)return false;
	if(inb<=80)return false;
	else return true;
}
bool jic(int ina){
	if(ina<=90)return false;
	else return true;
}
bool jid(int ina,bool inb){
	if(ina<=85)return false;
	if(inb==0)return false;
	else return true;
}
bool jif(int ina,bool inb){
	if(ina<=80)return false;
	if(inb==0)return false;
	else return true;
}
int main(){
	scanf("%d",&len);
	for(int i=0;i<len;i++){
		scanf("%s%d%d",ina[i],&inb[i],&inc[i]);
		char a[5];
		scanf("%s",a);
		if(a[0]=='Y')ine[i]=true;
		else ine[i]=false;
		scanf("%s",a);
		if(a[0]=='Y')inf[i]=true;
		else inf[i]=false;
		scanf("%d",&ind[i]);
	}
	for(int i=0;i<len;i++){
		if(jia(inb[i],ind[i]))zong[i]+=8000;
		if(jib(inb[i],inc[i]))zong[i]+=4000;
		if(jic(inb[i]))zong[i]+=2000;
		if(jid(inb[i],inf[i]))zong[i]+=1000;
		if(jif(inc[i],ine[i]))zong[i]+=850;
	}
	int big=0,z=0,ji;
	for(int i=0;i<len;i++){
		if(zong[i]>big){
			big=zong[i];
			ji=i;
		}
		z+=zong[i];
	}
	printf("%s\n%d\n%d",ina[ji],zong[ji],z);
}
