#include<stdio.h>
using namespace std;
int ina,inb[10005],inc;
int cha(int in[10005],int len,int ca){
	for(int i=0;i<len;i++){
		if(in[i]==ca)return i+1;
	}
	return -1;
}
int main(){
	scanf("%d",&ina);
	for(int i=0;i<ina;i++)scanf("%d",&inb[i]);
	scanf("%d",&inc);
	printf("%d",cha(inb,ina,inc));
	return 0;
}
