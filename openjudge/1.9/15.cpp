#include<bits/stdc++.h>
using namespace std;
int ji[105],len,in[10005],ng,out;
int zuixiao(int in[105],int len){
	int small=1e9;
	for(int i=0;i<len;i++){
		if(in[i]<small){
			small=in[i];
		}
	}
	return small;
}
int main(){
	scanf("%d%d",&len,&ng);
	for(int i=0;i<len;i++)
		scanf("%d",&in[i]);
	for(int i=0;i<ng;i++){
		ji[i]=in[i];
	}
	for(int i=ng;i<len;){
		int small=zuixiao(ji,ng);
		out+=small;
		for(int j=0;j<ng;j++){
			ji[j]-=small;
			if(ji[j]==0){
				ji[j]=in[i];
				i++;
			}
		}
	}
	int big=0;
	for(int i=0;i<ng;i++){
		if(ji[i]>big){
			big=ji[i];
		}
	}
	printf("%d",out+big);
	return 0;
}
