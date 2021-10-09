#include<stdio.h>
#include<iostream>
using namespace std;
int len;
double in[305],big,small=1e9,all,lin;
int main(){
	scanf("%d",&len);
	for(int i=0;i<len;i++){
		cin>>in[i];
	}
		
	for(int i=0;i<len;i++){
		if(in[i]>big)
			big=in[i];
		if(in[i]<small)
			small=in[i];
	}
	for(int i=0,z=0,j=0;i<len;i++){
		if(in[i]==big&&z==0){
			in[i]=0;
			z=5;
		}
		if(in[i]==small&&j==0){
			in[i]=0;
			j=8;
		}
	}
	for(int i=0;i<len;i++){
		all+=in[i];
	}
	all/=(len-2);
	printf("%.2f ",all);
	for(int i=0;i<len;i++){
		if(in[i]>lin)
			lin=in[i];
	}
	lin-=all;
	if(lin<0)lin*=-1;
	printf("%.2f",lin);
	return 0;
}
