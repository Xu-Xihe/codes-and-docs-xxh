#include<bits/stdc++.h>
using namespace std;
int len,lenm,leng;
float man[45],gril[45];
int main(){
	scanf("%d",&len);
	for(int i=0;i<len;i++){
		char a[50];
		float gao;
		scanf("%s",a);
		cin>>gao;
		if(a[0]=='m'){
			man[lenm]=gao;
			lenm++;
		}
		else{
			gril[leng]=gao;
			leng++;
		}
	}
	for(int j=0;j<lenm;j++){
		for(int i=1;i<lenm;i++){
			if(man[i-1]>man[i]){
				double lin=man[i];
				man[i]=man[i-1];
				man[i-1]=lin;
			}
		}
	}
	for(int j=0;j<leng;j++){
		for(int i=1;i<leng;i++){
			if(gril[i-1]<gril[i]){
				double lin=gril[i];
				gril[i]=gril[i-1];
				gril[i-1]=lin;
			}
		}
	}
	for(int i=0;i<lenm;i++)
		printf("%.2f ",man[i]);
	for(int i=0;i<leng;i++)
		printf("%.2f ",gril[i]);
	return 0;
}
