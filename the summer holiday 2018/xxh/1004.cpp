#include<bits/stdc++.h>
using namespace std;
int len,ji[3005],suan[3005];
int main(){
	scanf("%d",&len);
	for(int i=0;i<len;i++){
		scanf("%d",&ji[i]); 
	}
	for(int i=1;i<len;i++){
		suan[i-1]=ji[i]-ji[i-1];
		if(suan[i]<0)suan[i]*=-1;
	}
	for(int i=1;i<len;i++){
		for(int j=1;j<len-1;j++){
			if(suan[j-1]>suan[j]){
				int lin=suan[j];
				suan[j]=suan[j-1];
				suan[j-1]=lin;
			}
			if(suan[j-1]==suan[j]){
				printf("Not jolly");
				return 0;
			}
		}
	}
	for(int i=1;i<len-1;i++){
		if(suan[i-1]!=i){
			printf("Not jolly");
			return 0;
		}
	}
	printf("Jolly");
	return 0;
}
