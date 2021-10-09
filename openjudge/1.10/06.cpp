#include<bits/stdc++.h>
using namespace std;
int in[12],ji[12],ou[12];
void pai(int in[15],int len){
	for(int j=0;j<len;j++){
		for(int i=1;i<len;i++){
			if(in[i-1]<in[i]){
				int lin=in[i];
				in[i]=in[i-1];
				in[i-1]=lin;
			}
		}
	}
	return ;
}
void pa(int in[15],int len){
	for(int j=0;j<len;j++){
		for(int i=1;i<len;i++){
			if(in[i-1]>in[i]){
				int lin=in[i];
				in[i]=in[i-1];
				in[i-1]=lin;
			}
		}
	}
	return ;
}
int main(){
	for(int i=0;i<10;i++)
		scanf("%d",&in[i]);
	int j=0,z=0;
	for(int i=0;i<10;i++){
		if(in[i]%2==0){
			ou[j]=in[i];
			j++;
		}
		else{
			ji[z]=in[i];
			z++;
		}
	}
	pai(ji,z);
	pa(ou,j);
	for(int i=0;i<z;i++)
		printf("%d ",ji[i]);
	for(int i=0;i<j;i++)
		printf("%d ",ou[i]);
	return 0;
}
